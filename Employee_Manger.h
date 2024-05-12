#ifndef DS_PROJECT_EMPLOYEE_MANGER_H
#define DS_PROJECT_EMPLOYEE_MANGER_H
#include "tools.h"
class Employee_Manger {
public:
    static void add_employee(LinkedList &l){
        string name,id,state,salary,join_date;
        cout<<"You will add employee to database\n";
        cout<<"id: ";cin>>id;
        tools::check_id(l , id , false);
        cout<<"name: ";cin>>name;
        cout<<"state: ";cin>>state;
        tools::check_state(state);
        cout<<"salary: ";cin>>salary;
        tools::check(salary);
        cout<<"join date: ";cin>>join_date;
        tools::check(join_date);
        Employee e = Employee(
                tools::ToInt(id),
                name,
                tools::ToInt(state),
                tools::ToInt(salary),
                tools::ToInt(join_date));
        l.push_back(e);
        LinkedList l1 =LinkedList(new node(e));
        tools::WriteFile(employee_file,l1, true);
        l.inc_size();
        cout<<"You added new employee!\n";
    }
    static void update(LinkedList &l){
        cout<<"Enter id: ";
        string id;cin>>id;
        tools::check_id(l,id, true);
        cout<<"1- update ID.\n";
        cout<<"2- update name.\n";
        cout<<"3- update state.\n";
        cout<<"4- update salary.\n";
        cout<<"5- update join date.\n";
        string option = tools::ReadInt("1","5");
        cout<<"Enter value: ";
        string val; cin>>val;
        if(option != "2") tools::check(val);
        if(option == "3") tools::check_state(val);
        update_employee(l,tools::ToInt(id),tools::ToInt(option),val);
    }
    static void delete_employee(LinkedList &l){
        cout<<"Enter id: ";
        string id;cin>>id;
        tools::check_id(l,id, true);
        delete_emp(l,tools::ToInt(id));
    }
    static void search_emp(LinkedList &l){
        cout<<"1- Search by ID\n";
        cout<<"2- Search by name\n";
        cout<<"3- Search by state\n";
        cout<<"4- Search by salary\n";
        cout<<"5- Search by join date\n";
        string option = tools::ReadInt("1","5");
        cout<<"Enter value you want to search: ";
        string val;cin>>val;
        if(option != "2")tools::check(val);
        if(option == "3")tools::check_state(val);
        search(l , tools::ToInt(option) , val);
    }
    static void print(LinkedList &l){
        if(!l.get_head()){
            cout<<"There is no employee yet!\n";
        }else{
            for(node* cur = l.get_head(); cur ; cur=cur->next){
                cur->val.print_emp();
            }
        }
    }
    static void sort_list(LinkedList &l){
        cout<<"1-Sort by ID.\n";
        cout<<"2-Sort by name.\n";
        cout<<"3-Sort by salary.\n";
        cout<<"4-Sort by join date.\n";
        string option = tools::ReadInt("1" , "4");
        sort(l , tools::ToInt(option));
        cout<<"Do you want to display the list Y or N: ";
        string x;
        cin>>x;
        if (x.size()== 1 && tolower(x[0])=='y')print(l);
    }
    static void Display_Employee_sorted(LinkedList &l){
        LinkedList temp;
        for(node* cur=l.get_head() ; cur ; cur=cur->next){
            temp.push_back(cur->val);
        }
        cout<<"1-Sort by ID.\n";
        cout<<"2-Sort by name.\n";
        cout<<"3-Sort by salary.\n";
        cout<<"4-Sort by join date.\n";
        string option = tools::ReadInt("1" , "4");
        display_sorted(temp , tools::ToInt(option));
    }
private:
    static void swap(node* i , node* j){
        Employee e = i->val;
        i->val = j->val;
        j->val = e;
    }
    static void update_employee(LinkedList &l ,const int &id,const int& option,const string& val){
        for(node* cur=l.get_head();cur;cur=cur->next){
            if(id==cur->val.get_id()){
                switch (option) {
                    case 1: cur->val.set_id(tools::ToInt(val));cout<<"ID updated!\n";
                        break;
                    case 2: cur->val.set_name(val);cout<<"Name updated!\n";
                        break;
                    case 3: cur->val.set_state(tools::ToInt(val));cout<<"State updated!\n";
                        break;
                    case 4:cur->val.set_salary(tools::ToInt(val));cout<<"Salary updated!\n";
                        break;
                    case 5:cur->val.set_join_date(tools::ToInt(val));cout<<"Join date updated!\n";
                        break;
                    default:
                        return;
                }
            }
        }
        tools::WriteFile(employee_file,l,0);
    }
    static void delete_emp(LinkedList &l , int id){
        for(node* cur=l.get_head(),*prv= nullptr ; cur ; prv=cur,cur=cur->next){
            if(cur->val.get_id() == id){
                if(cur==l.get_head()){
                    l.pop_front();
                }else if(cur==l.get_tail()){
                    l.pop_back();
                }else{
                    prv->next = cur->next;
                    delete cur;
                }
                l.dec_size();
                tools::WriteFile(employee_file , l , false);
                return;
            }
        }
    }
    static void search(LinkedList &l , const int &option , const string &val){
        if(option == 1){
            for(node* cur = l.get_head() ; cur ; cur=cur->next)
                if(cur->val.get_id() == tools::ToInt(val))cur->val.print_emp();
        }else if(option==2){
            for(node* cur = l.get_head() ; cur ; cur=cur->next)
                if(cur->val.get_name() == val)cur->val.print_emp();
        }else if(option==3){
            for(node* cur = l.get_head() ; cur ; cur=cur->next)
                if(cur->val.get_state() == tools::ToInt(val))cur->val.print_emp();
        }else if(option==4){
            for(node* cur = l.get_head() ; cur ; cur=cur->next)
                if(cur->val.get_salary() == tools::ToInt(val))cur->val.print_emp();
        }else if(option==5){
            for(node* cur = l.get_head() ; cur ; cur=cur->next)
                if(cur->val.get_join_date() == tools::ToInt(val))cur->val.print_emp();
        }
    }
    static void sort(LinkedList &l ,const int &option){
        for(node* i=l.get_head() ; i ; i=i->next){
            for(node* j=i->next ; j ; j=j->next){
                if(option == 1){
                    if(i->val.get_id() > j->val.get_id()){
                        swap(i,j);
                    }
                }else if(option == 2) {
                    if (i->val.get_name() > j->val.get_name()) {
                        swap(i, j);
                    }
                }else if(option == 3) {
                    if (i->val.get_salary() > j->val.get_salary()) {
                        swap(i, j);
                    }
                }else if(option == 4) {
                    if (i->val.get_join_date() > j->val.get_join_date()) {
                        swap(i, j);
                    }
                }
            }
        }
        tools::WriteFile(employee_file , l , false);
    }
    static void display_sorted(LinkedList &l , const int &option){
        for(node* i=l.get_head() ; i ; i=i->next){
            for(node* j=i->next ; j ; j=j->next){
                if(option == 1){
                    if(i->val.get_id() > j->val.get_id()){
                        swap(i,j);
                    }
                }else if(option == 2) {
                    if (i->val.get_name() > j->val.get_name()) {
                        swap(i, j);
                    }
                }else if(option == 3) {
                    if (i->val.get_salary() > j->val.get_salary()) {
                        swap(i, j);
                    }
                }else if(option == 4) {
                    if (i->val.get_join_date() > j->val.get_join_date()) {
                        swap(i, j);
                    }
                }
            }
        }
        print(l);
    }
};


#endif //DS_PROJECT_EMPLOYEE_MANGER_H
