#ifndef DS_PROJECT_Employee_H
#define DS_PROJECT_Employee_H
#include "bits/stdc++.h"
using namespace std;
string employee_file = "../employee.txt";

class Employee {
private:
    int id;
    bool state;
    string name;
    int salary;
    int join_date;
    string status = state ? "working" : "fired";
    static int get_Length(long long int number) {
        int length = 0;
        if (number == 0)
            length = 1;
        else
            length = static_cast<int>(log10(number)) + 1;

        return length;
    }
    static string format(int x){
        string s;
        for (int i = 0; i < 15-x; ++i) {
            s+=" ";
        }
        return s;
    }
public:

    Employee(int id , string n , int st , int s , int j):id(id),name(n),state(st),salary(s),join_date(j){}
    bool operator == (const Employee &e){
        return id==e.id && name==e.name;
    }
    int get_id (){return id;}
    string get_name(){return name;}
    int get_salary(){return salary;}
    int get_join_date(){return join_date;}
    int get_state(){return state;}
    void set_id(const int &x){this->id = x;}
    void set_name(const string &x){ this->name = x;}
    void set_salary(const int &x){ this->salary = x;}
    void set_join_date(const int &x){ this->join_date = x;}
    void set_state(const int &x){ this->state = x;}
    void print_emp(){
        cout<<"Name: "<<get_name()<<format(6+get_name().size())<<
            "ID: "<<get_id()<<format(get_Length(get_id())+4)<<
            "State: "<<status<<format(5+status.size())<<
            "Salary: "<<get_salary()<<format(8+ get_Length(get_salary()))<<
            "Join Date: "<<get_join_date()<<"\n";
    }

};
#endif