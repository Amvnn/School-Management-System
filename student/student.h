#ifndef STUDENT_H // checks and prevent the extra inclusion of file. so that it can avoid errors
#define STUDENT_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

 using namespace std;

class student{
    public:
    int ID;
    string name;
    string DOB;
    string address;
    int studentclass;

    student(int ID,string name, string DOB , string address, int studentclass);
    void display() const;
};

extern vector<student> students;

void addstudent(int ID , const string& name , const string& DOB,const string& address , int studentclass);
void updatestudent(int ID , const string& name , const string& DOB,const string& address , int studentclass);
void deletestudent(int ID);
void viewstudents();
void loadstudents(int classID);
void savestudents();

extern vector<student> students;

#endif 

