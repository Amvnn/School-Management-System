#include"class.h"
#include<iostream>
#include<algorithm>

using namespace std;

vector<schoolclass> classes;

schoolclass :: schoolclass(int classID,string classname)
 : classID(classID),classname(classname){}

 void schoolclass :: display() const{
    cout<<"Class ID : "<<classID<<endl;
    cout<<"Class name : "<<classname<<endl;
    cout<<"students : "<<classID<<endl;

    for (const auto& student : students)
    {
        student.display();
        cout<<endl;
    }
    cout<<"Teachers : "<<endl;
    for (const auto& teacher : teachers)
    {
        teacher.display();
        cout<<endl;
    }
 }

 void addclass(int classID, const string& classname){
    classes.emplace_back(classID,classname);
    cout<<"Class added successfully !"<<endl;
 }

 void updateclass(int classID, const string& classname){
    for (auto& schoolclass: classes)
    {
        if (schoolclass.classID==classID)
        {
            schoolclass.classname=classname;
           cout<<"Class Updated successfully !"<<endl;
            return;
        }
        
    }
     cout<<"Class with ID" <<classID<<"Not found."<<endl;
    
 }
 void deleteclass(int classID){
    for(auto it = classes.begin();it != classes.end();it++){
        if(it->classID==classID){
            classes.erase(it);
            cout<<"Class deleted successfully!"<<endl;
            return; // delete the function once the class is deleted.
        }
    }
    cout<<"class with ID"<<classID<<"not found."<<endl;
 }

 void viewclass(){
    for(const auto& schoolclass : classes){
        schoolclass.display();
        cout<<"-------------------------"<<endl;
    }
 }

 void assignstudenttoclass(int classID,const student& student){
    for(auto& schoolclass : classes){
        if(schoolclass.classID==classID){
            schoolclass.students.push_back(student); //push_back adds the element to the vector.
            cout<<"Student assigned to class successfully ! "<<endl;
            return;
        }
    }
    cout<<"Student with ID "<< classID<<"not found. "<<endl;
 }

  void assignteachertoclass(int classID,const teacher& teacher){
    for(auto& schoolclass : classes){
        if(schoolclass.classID==classID){
            schoolclass.teachers.push_back(teacher);
            cout<<"teacher assigned to class successfully ! "<<endl;
            return;
        }
    }
    cout<<"teacher with ID "<< classID<<"not found. "<<endl;
 }

 void loadtimetable(int classID){  // load timetable according to the class of the student.
    string filename = "timetable_"+ to_string(classID)+".csv";
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Timetable for class "<< classID<<" not found. "<<endl;
        return;
    }

    string line;
    cout<<"Timetable for class "<<classID << ": \n";
    while(getline(file,line)){
        cout << line << endl;
    }
    file.close();
}