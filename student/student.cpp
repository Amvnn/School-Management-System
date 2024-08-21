#include "student.h"
#include <iostream>
#include <vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

vector<student> students;

student::student(int ID, string name, string DOB, string address,int studentclass) // constructor
    : ID(ID), name(name), DOB(DOB), address(address), studentclass(studentclass) {}

void student::display() const {
    cout << " ID : " << ID << endl;
    cout << " Name : " << name << endl;
    cout << " Date Of Birth : " << DOB << endl;
    cout << " Address : " << address << endl;
    cout << " Class : " << studentclass << endl;
    cout << endl;
}

void addstudent(int ID, const string& name, const string& DOB, const string& address , int studentclass) {
    students.emplace_back(ID, name, DOB, address, studentclass); // emplace_back will create new object of "student class" in "students vector" directly.
    savestudents();
    cout << "Student added successfully!" << endl;
}

void updatestudent(int ID, const string& name, const string& DOB, const string& address,int studentclass) {
    for (auto& student : students) {
        if (student.ID == ID) {
            student.name = name;
            student.DOB = DOB;
            student.address = address;
            student.studentclass = studentclass;
            savestudents();

            cout << "Details updated successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << ID << " not found." << endl;
}

void deletestudent(int ID) {
    for (auto i = students.begin(); i != students.end(); ++i) { // it will check from start to end until it find the match of of the ID.
        if (i->ID == ID) {
            students.erase(i);// if it found ID matching the ID then it will delete the student from the vector.
            savestudents();
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID: " << ID << " not found!" << endl;
}

void viewstudents() {
    for (const auto& student : students) {
        student.display();
        cout << endl;
        cout << " ------------------------ ";
        cout << endl;
    }
}

void loadstudents(){
    ifstream file("student.csv"); // opened the file for reading.
    if(!file.is_open()) return; // if file is not open then it will exit.

    string line, word; // line - store each line of a file | word - store comma saperated values.
    
    while(getline(file,line)){  // it will read the file line by line (getline stores line as it is).
        stringstream ss(line); // converting the line into a stringstream so that we can read data.
        vector<string> row; // then we will store the data(which is read by ss) in vector name row.

        while(getline(ss,word,',')){  //ss- it will access the line upto comma.
            row.push_back(word); // store the value upto comma into the word.
        }

       if (row.size() == 5) { // string to integer (in reading files all the data read as a string thats why we need stoi to convert string to int)
                students.emplace_back(stoi(row[0]), row[1], row[2], row[3], stoi(row[4]));  
        }
    }
    file.close();
}

void savestudents() {
    ofstream file("students.csv");
    for (const auto& student : students) {
        file << student.ID << "," << student.name << "," << student.DOB << "," << student.address << " , " << student.studentclass<<"\n";
    }
    file.close();
}



