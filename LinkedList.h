#ifndef DS_PROJECT_LinkedList_H
#define DS_PROJECT_LinkedList_H
#include "Employee.h"

typedef Employee type;
struct node{
    type val;
    node* next{};
    node(type val):val(val){}
};
class LinkedList {
private:
    int size{};
    node* head{} , *tail{};
public:

    LinkedList(){};
    LinkedList(node* n):head(n),tail(n),size(1){}
    node* get_head(){return head;}
    node* get_tail(){return tail;}
    int get_Size(){return this->size;}
    void set_head(node* x){head=x;}
    void set_tail(node* x){tail=x;}
    void inc_size(){size++;}
    void dec_size(){size--;}
    void push_front(const type &x){
        node* item = new node(x);
        if(!head){
            head = tail = item;
        } else{
            item->next = head;
            head = item;
        }
        size++;
    }
    void push_back(const type &x){
        node* item = new node(x);
        if(!head){
            head = tail = item;
        }else{
            tail->next = item;
            tail = item;
        }
        inc_size();
    }
    void push(int pos , const type &x){
        if(pos>size || pos<=0){
            assert("You have violated the boundaries of the matrix");
            return;
        }
        node* item = new node(x);
        node* prv = head;
        for(int i=0 ; i<pos-1 ; i++)prv = prv->next;
        item->next = prv->next;
        prv->next = item;
        inc_size();
    }
    void pop_front(){
        if(!head){
            cout<<"Linked List is empty!\n";
            return;
        }
        if(head==tail){
            delete head;
            head = tail = nullptr;
        } else{
            node* item = head;
            head = head->next;
            delete item;
        }
        dec_size();
    }
    void pop_back(){
        if(!head){
            cout<<"Linked List is empty!\n";
            return;
        }
        if(head==tail){
            delete head;
            head = tail = nullptr;
        } else{
            node* cur = head;
            while (cur->next->next){
                cur=cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
        }
        dec_size();
    }
};
#endif
