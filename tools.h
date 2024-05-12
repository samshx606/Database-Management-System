#ifndef DS_PROJECT_tools_H
#define DS_PROJECT_tools_H
#include "LinkedList.h"
class tools {
public:
    static vector<Employee> ReadFileLines(const string &path) {
        vector<Employee> lines;
        fstream fin(path);
        if (fin.fail()) {
            cout << "\n\nERROR: Can't open the file\n\n";
            return lines;
        }
        string line;
        while (getline(fin, line)) {
            if (line.empty())
                continue;
            vector<string> strs = SplitString(line);
            lines.emplace_back(ToInt(strs[0]),strs[1],ToInt(strs[2]),ToInt(strs[3]),ToInt(strs[4]));
        }
        fin.close();
        return lines;
    }
    static void WriteFile(const string &path , LinkedList l , bool state){
        auto st = ios::trunc;// 1 for append
        if(state)st = ios ::app;
        ofstream fout(path,st);
        if (fout.fail()){
            cout<<"can't open file\n";
            return;
        }
        for(node* cur=l.get_head() ; cur ; cur=cur->next){
            fout << cur->val.get_id() << "," << cur->val.get_name() << "," <<cur->val.get_state() << "," << cur->val.get_salary() << "," << cur->val.get_join_date() << "\n";
        }
        fout.close();
    }
    static vector<string> SplitString(string s, const string& delimiter = ",") {
        vector<string> strs;

        int pos = 0;
        string substr;
        while ((pos = (int) s.find(delimiter)) != -1) {
            substr = s.substr(0, pos);
            strs.push_back(substr);
            s.erase(0, pos + delimiter.length());
        }
        strs.push_back(s);
        return strs;
    }
    static bool isNumber(string s){
        for (int i = 0; i < s.length(); i++){
            if (isdigit(s[i]) == false)return false;
        }
        return true;
    }
    static int ToInt(const string& str) {
        istringstream iss(str);
        int num;
        iss >> num;

        return num;
    }
    static string ReadInt(const string& low, const string& high) {
        cout << "\nEnter number in range " << low << " - " << high << ": ";
        string value;

        cin >> value;

        if (low <= value && value <= high && value.length()==1)
            return value;

        cout << "ERROR: invalid number...Try again\n";
        return ReadInt(low, high);
    }
    static bool check_admin(const string &user , const string &pass){
        ifstream fin("admin.txt");
        if(fin.fail()){
            cout<<"can't open root file.\n";
            return false;
        }
        string u , p;
        fin >> u >> p;
        fin.close();
        if(user == u && pass == p)return true;
        return false;
    }
    static void check_id(LinkedList &l , string &id , const bool &state){ //adding new id state should = 0
        while (!isNumber(id)){
            cout<<"Invalid ID, Enter again: ";
            cin>>id;
        }
        bool c = false;
        for(node* cur=l.get_head() ; cur ; cur=cur->next){
            if(cur->val.get_id() == ToInt(id)){
                c = true;
                if(!state){
                    cout<<"ID used, Try again: ";
                    cin>>id;
                    check_id(l,id,state);
                }
                break;
            }
        }
        if(state&&!c){
            cout<<"Can't find this ID, Try again: ";
            check_id(l,id,state);
        }
    }
    static void check_state(string &value){
        while (value!="0" && value!="1"){
            cout<<"Invalid state, Enter 1 or 0: ";
            cin>>value;
        }
    }
    static void check(string &value){
        while (!isNumber(value)){
            cout<<"Invalid input, Enter again: ";
            cin>>value;
        }
    }
    static void list_mod(){
        cout<<"\n1- Add a new employee’s details.\n";
        cout<<"2- Update the details of an existing employee.\n";
        cout<<"3- Delete employee from database.\n";
        cout<<"4- Search for the details of an employee.\n";
        cout<<"5- Display the list of all employees.\n";
        cout<<"6- Sort the list.\n";
        cout<<"7- Display list sorted without changing in database.\n";
        cout<<"8- Exit\n";
    }
};
#endif