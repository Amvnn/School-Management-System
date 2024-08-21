#include"teacher.h"
#include<iostream>
using namespace std;

vector<teacher> teachers;

teacher :: teacher(int ID,string name , string subject , string address)
: ID(ID),name(name),subject(subject),address(address){}

void teacher :: display() const{
    cout<< " ID : " <<ID;
    cout<<"Name : "<<name;
    cout<<"Subject : "<<subject;
    cout<<"Address : "<<address;
}

void addteacher(int ID, const string& name, const string& subject , const string& address ){
    teachers.emplace_back(ID,name,subject,address);
    cout<<"Teacher added successfully ! "<<endl;
}

void updateteacher(int ID , const string& name, const string& subject , const string& address ){
    for(auto& teacher : teachers){
        if(teacher.ID==ID){
            teacher.name==name;
            teacher.subject==subject;
            teacher.address=address;
            cout<<"Details updated successfully ! "<<endl;
            return;
        }
    }
    cout<<"Teacher with ID"<<ID<<"Note Found."<<endl;
}

void deleteteacher(int ID){
    for(auto it = teachers.begin(); it != teachers.end();++it){
        if(it->ID){
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