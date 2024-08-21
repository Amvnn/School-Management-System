#include<iostream>
#include<string>
#include"teacher.h"
#include"student.h"
#include"class.h"

int main(){

    loadstudents();
    loadteachers();
        int choice,ID,studentclass,classID;
        string name,DOB,address,subject,classname;
        

        while(true){
            cout<<"1. Add Student \n 2. update student information \n 3. Delete student \n 4. View Student \n ";
            cout<<"5. Add teacher \n 6. update teacher information \n 7. Delete teacher \n 8. View teacher \n ";
            cout<<"9. Add Class\n10. Update Class\n11. Delete Class\n12. View Classes\n";
            cout<<"13. View Timetable for Class\n14. Exit\n";

            cout<<"Enter your choice : ";
            cin>>choice;

            switch (choice)
            {
            case 1:

                cout<<"Enter ID : ";
                cin>>ID;
                cin.ignore();

                cout<<"Enter Name : ";
                getline(cin,name);

                 cout<<"Enter Date Of Birth (dd-mm-yyyy) : ";
                getline(cin,DOB);

                cout<<"Enter Adress : ";
                getline(cin,address);

                cout<<"Enter the class : ";
                cin>>studentclass;

                addstudent(ID,name,DOB,address,studentclass);
                savestudents();
                break;
            
            case 2:

                cout<<"Enter ID of the student to update : ";
                cin>>ID;
                cin.ignore();

                cout<<"Enter New Name : ";
                getline(cin,name);

                 cout<<"Enter New Date Of Birth (dd-mm-yyyy) : ";
                getline(cin,DOB);

                 cout<<"Enter New Adress : ";
                getline(cin,address);

                cout<<"Enter the class (9,10,11,12) : ";
                cin>>studentclass; 

                updatestudent(ID,name,DOB,address,studentclass);

                savestudents();

                break;

            case 3:
                cout<<"Enter ID of the student to delete : ";
                cin>>ID;
                deletestudent(ID);
                savestudents();
                
                break;

            case 4:
                cout<<endl;
                viewstudents();
                break;
            
            case 5:

                cout<<"Enter ID : ";
                cin>>ID;
                cin.ignore();

                cout<<"Enter Name : ";
                getline(cin,name);

                 cout<<"Enter Subject : ";
                getline(cin,DOB);

                 cout<<"Enter Adress : ";
                getline(cin,address);

                addteacher(ID,name,subject,address);
                saveteachers();
                break;

            case 6:

                cout<<"Enter ID of the teacher to update : ";
                cin>>ID;
                cin.ignore();

                cout<<"Enter New Name : ";
                getline(cin,name);

                 cout<<"Enter New subject : ";
                getline(cin,DOB);

                 cout<<"Enter New Adress : ";
                getline(cin,address);

                updateteacher(ID,name,subject,address);
                saveteachers();
                break;

             case 7:
                cout<<"Enter ID of the teacher to delete : ";
                cin>>ID;
                deleteteacher(ID);
                saveteachers();
                break;

             case 8:
                cout<<endl;
                viewteachers();
                break;

            case 9:
                cout<<"Enter class ID: "<<endl;
                cin>>classID;
                cin.ignore();

                cout<<"Enter class Name : ";
                getline(cin,classname);

                addclass(ID,classname);
                break;
            case 10: 
                cout<<"Enter class ID to update : ";
                cin>>classID;
                cin.ignore();

                cout<<"Enter new class name : ";
                getline(cin,classname);

                updateclass(classID,classname);
            break;

            case 11:
                cout<<"Enter class ID to delete : ";
                cin>>classID;

                deleteclass(classID);
            break;

            case 12:
                cout<<endl;
                viewclass();
            break;

            case 13:
                cout<<"Enter class ID to view time table : ";
                cin>>classID;
                loadtimetable(classID);

            default: 
                cout<<"Invalid choice ! please try again later."<<endl;
            }
        }
        return 0;
    }