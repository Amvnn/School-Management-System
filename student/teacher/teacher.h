#ifndef teacher_h
#define teacher_h

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class teacher{
    public:

    int ID;
    string name;
    string subject;
    string address;

    teacher(int ID , string name , string subject , string address);
    void display()const;
};

void addteacher(int ID , const string name , const string subject , const string address);
void updateteacher(int ID, const string name , const string subject , const string address);
void deleteteacher(int ID);
void viewteachers();

#endif
