//#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

void LoginInterface();
void AdministratorMenu();
void StudentMenu();

void Instructor_SubMenu();
void Room_SubMenu();
void Student_SubMenu();
void Subject_SubMenu();
void ClassSchedule_SubMenu();
void User_SubMenu();
void BuildFile_SubMenu();

int main() {
	StudentMenu();
	getchar();
}

void LoginInterface()
{
	string username;
	string password;
	cout << "* * * * * * * *  Login  * * * * * * * * *" <<endl;
	cout << "*"<<endl;
	cout << "*       Enter username : "; cin >> username;
	cout << "*       Enter password : "; cin >> password;
	cout << "*"<<endl;
	cout << "* * * * * * * * * * * * * * * * * * * * *" <<endl;
}

void AdministratorMenu()
{
	cout << "* * * * * * * *  Scheduler's Menu(admin)  * * * * * * * * *" <<endl;
	cout << "*                                                         *"<<endl;
	cout << "*          (I)NSTRUCTOR INFORMATION                       *" <<endl;
	cout << "*          (R)OOM INFORMATION                             *" <<endl;
	cout << "*          (S)TUDENT INFORMATION                          *" <<endl;
	cout << "*          (J)SUBJECT INFORMATION                         *" <<endl;
	cout << "*          (C)LASS SCHEDULE INFORMATION                   *" <<endl;
	cout << "*          (U)SER INFORMATION                             *" <<endl;
	cout << "*          (B)UILD FILES                                  *" <<endl;
	cout << "*          (X)EXIT                                        *" <<endl;
	cout << "*                                                         *"<<endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

}
void StudentMenu()
{
	cout << "* * * * * * * *  Student Menu * * * * * * * * *" <<endl;
	cout << "*                                             *"<<endl;
	cout << "*          (E)nroll a Class                   *" <<endl;
	cout << "*          (V)iew Available Courses           *" <<endl;
	cout << "*          (M)iew My Schedule                 *" <<endl;
	cout << "*          (U)pdate password                  *" <<endl;
	cout << "*          (X)EXIT                            *" <<endl;
	cout << "*                                             *"<<endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * *" <<endl;
}

void Instructor_SubMenu(){}
void Room_SubMenu(){}
void Student_SubMenu()
{
	cout << "       * * *  Admin sub-menu for Student Information * * *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       *          (S)how Student list                    *" <<endl;
	cout << "       *          (U)pdate Student                       *" <<endl;
	cout << "       *          (A)dd new Student                      *" <<endl;
	cout << "       *          (D)elete Student                       *" <<endl;
	cout << "       *          (X)EXIT back to main                   *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;
}
void Subject_SubMenu()
{
	cout << "       * * *  Admin sub-menu for Subject Information * * *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       *          (S)how Subject list                    *" <<endl;
	cout << "       *          (U)pdate Subject                       *" <<endl;
	cout << "       *          (A)dd new Subject                      *" <<endl;
	cout << "       *          (D)elete Subject                       *" <<endl;
	cout << "       *          (X)EXIT back to main                   *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;
}
void ClassSchedule_SubMenu(){}
void User_SubMenu(){}
void BuildFile_SubMenu(){}
