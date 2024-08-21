#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<string>
#include<vector>
#include"student.h"
#include"teacher.h"

using namespace std;

class schoolclass{
    public:
    int classID;
    string classname;
    vector<student> students;
    vector<teacher> teachers;

    schoolclass(int classID, string classname); // constructor
    void display() const;
};

void addclass(int classID,const string& classname);
void updateclass(int classID, const string& classname);
void deleteclass(int classID);
void viewclass();
void assignstudents(int classID, const student& student); //object "student" will be constant among the function and nect student is the vector(dynamic)
void assignteachers(int classID, const teacher& teacher);
void loadtimetable(int ClassID);

#endif