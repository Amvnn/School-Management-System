#include"teacher.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

vector<teacher> teachers;

teacher :: teacher(int ID,string name , string subject , string address)
: ID(ID),name(name),subject(subject),address(address){}

void teacher :: display() const{
    cout<< " ID : " <<ID<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Subject : "<<subject<<endl;
    cout<<"Address : "<<address<<endl;
}

void addteacher(int ID, const string& name, const string& subject , const string& address ){
    teachers.emplace_back(ID,name,subject,address);
    cout<<"Teacher added successfully ! "<<endl;
}

void updateteacher(int ID , const string& name, const string& subject , const string& address ){
    for(auto& teacher : teachers){
        if(teacher.ID==ID){
            teacher.name=name;
            teacher.subject=subject;
            teacher.address=address;
            cout<<"Details updated successfully ! "<<endl;
            return;
        }
    }
    cout<<"Teacher with ID"<<ID<<"Note Found."<<endl;
}

void deleteteacher(int ID){
    for(auto it = teachers.begin(); it != teachers.end();++it){
        if(it->ID==ID){
            teachers.erase(it);
            cout<<"Teacher deleted successfully !"<<endl;
            return;
        }
    }
    cout<<"Teacher with ID " <<ID <<"Not Found."<<endl;
}

void viewteachers(){
    for(auto& teacher : teachers){
        teacher.display();
        cout<<endl;
        cout<<"-------------------------------";
        cout<<endl;
    }
}
void loadteachers(){
    ifstream file("teachers.csv");
    if(!file.is_open()){
        cout<<"Error opening file 'teachers.csv' "<<endl;
        return;
    }

    string line,word;
    while(getline(file,line)){
        stringstream ss(line);
        int ID;
        string name,subject,address;

        getline(ss,name,',');
        ID= stoi(word);
        getline(ss,name,',');
        getline(ss,subject,',');
        getline(ss,address,',');

        teachers.emplace_back(ID,name,subject,address);
    }
    file.close();
}

void saveteacehrs(){
    ofstream file("teachers.csv");
    if(!file.is_open()){
        cout<<"Error ! file is noe opening 'teacher.csv' "<<endl;
        return;
    }
    for(const auto& teacher : teachers){
        file<<teacher.ID << " , " <<teacher.name<< " , " <<teacher.subject << " , " << teacher.address << endl;
    }
    file.close();
}
