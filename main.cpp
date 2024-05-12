#include "Employee_Manger.h"
LinkedList list_employee;
void load_list(){
    vector<Employee> e = tools::ReadFileLines(employee_file);
    for (const auto & i : e) {
        list_employee.push_back(i);
    }
}
void login(){
    cout<<"\t\t\tWelcome to administrator mode\n\n";
    string user , pass;
    do{
        cout<<"Username: ";
        cin>>user;
        cout<<"Password:";
        cin>>pass;
        if(tools::check_admin(user,pass)){
            cout<<"You are logged in!\n";
            break;
        } else{
            cout<<"Try again!\n";
        }
    } while (true);
    while (true){
        tools::list_mod();
        string option = tools::ReadInt("1","8");

        if(option=="1"){
            Employee_Manger::add_employee(list_employee);
        }else if(option=="2"){
            Employee_Manger::update(list_employee);
        }else if(option=="3"){
            Employee_Manger::delete_employee(list_employee);
        }else if(option=="4"){
            Employee_Manger::search_emp(list_employee);
        }else if(option=="5"){
            Employee_Manger::print(list_employee);
        }else if(option=="6"){
            Employee_Manger::sort_list(list_employee);
        } else if(option == "7"){
            Employee_Manger::Display_Employee_sorted(list_employee);
        }else{
            break;
        }
        cout<<"Do you want to continue(Y/N): ";
        string x;cin>>x;
        if(x.size()!=1 || tolower( x[0]) != 'y')break;
    }
}
void guest(){
    cout<<"\t\t\tYou are in guest mode\n\n";

    while (true){
        cout<<"1- Search for Employee.\n";
        cout<<"2- Display Employees sorted.\n";
        cout<<"3- Exit.\n";
        string option = tools::ReadInt("1" , "3");
        if(option == "1"){
            Employee_Manger::search_emp(list_employee);
        }else if(option == "2"){
            Employee_Manger::Display_Employee_sorted(list_employee);
        } else{
            break;
        }
        cout<<"Do you want to continue(Y/N): ";
        string x;cin>>x;
        if(x.size()!=1 || tolower( x[0]) != 'y')break;
    }
}
void run_system(){
    cout<<"\t\tWelcome To Data Base Management Project\n\n\n";
    load_list();
    while (true){
        cout<<"1-guest\n"<<"2-admin\n"<<"3-Exit";
        string mod = tools::ReadInt("1","3");
        if(mod=="3")break;
        mod=="2" ? login() : guest();
    }
}
int main() {
    run_system();
}
