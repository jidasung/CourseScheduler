/* 2014. 12. 12. Fri.
 *
 * Project : Course Scheduler
 *
 * Author : Hyeong Gyu Jeong & Wook Jeong
 *
 */

#include "Course.h"
#include "Student.h"
#include "Schedule.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include<Windows.h>
#include<conio.h>

using namespace std;

/* enum list for switch */
typedef enum Database { instructor, room, student, subject, course, user, schedule };

/* STL vector for managing data from file. */
vector<Instructor> instructorList = vector<Instructor>();
vector<Room> roomList = vector<Room>();
vector<Student> studentList = vector<Student>();
vector<Subject> subjectList = vector<Subject>();
vector<Course> courseList = vector<Course>();
vector<Course> myCourseList = vector<Course>(); // For comparing my course list with all list in "viewmyschedule()"
vector<Schedule> scheduleList = vector<Schedule>();
vector<int> choicelist = vector<int>();  // For using available course list in "ViewAvailable()"
/*******************************************************************************************************************************/

/* User Information */
string username, password;	// user/pass
int userNo; char type;
/* For Login Menu */
void xy(int x,int y);
bool LoginInterface();
/*******************************************************************************************************************************/

/* Main Menu */
char checkUser();
void AdministratorMenu();
void StudentMenu();

/* Sub Menu */
void Instructor_SubMenu();
void Room_SubMenu();
void Student_SubMenu();
void Subject_SubMenu();
void Course_SubMenu();
void User_SubMenu();
void BuildFile_SubMenu(); 
/***************************/

/* Delete Function */
void deleteRecord(string);
/*****************************************/

/* Each Functions For Student Menu */
void Enroll();
void ViewAvailable();
void ViewMySchedule();
void UpdatePassword();
/*****************************************/

/* Detail Functions For Student Menu */
void putCourse(int);
bool showAvailableCourses(int);
void showMyCourses(int);
bool changePassword();
/*****************************************/

/* Main Functions for File Operation */
void showFile(int);
void updateFile(int);
void addFile(int);
void deleteFile(int);
/*****************************************/

/* Supporting File I/O */
int Token(char* data[], char *line);
void readDataList(int database);
void writeDataList(int database);
void printDataList(int database);
void getScheudleList(int no);
/*****************************************/

/* User Information Functions */
void UpdateOnlyName();
void changeUsername();
void UpdateinsPassword();
/****************************************/


int main() {

	/* Initialize First Data List */
	readDataList(instructor);
	readDataList(room);
	readDataList(student);
	readDataList(subject);
	readDataList(course);
	readDataList(schedule);
	
	system("cls");
	while(1) {
		if(LoginInterface() == true) {
			if(checkUser() == 'i') {				// Administrator
				system("cls");
				AdministratorMenu();
			}
			else if (checkUser() == 's') {			// Student
				system("cls");
				StudentMenu();
			}
			else {
				char again;
				xy(0,10); cout << " No Valid ID and PW. Try Again? (y/n)"; cin >> again;
				if(again=='n') return 0;
			}
		}
	}
	return 0;
}

/****************************************** Login & Menu *********************************************/

//Display input in user define coordinates
void xy(int x,int y){
	HANDLE h=NULL;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);
}

// Login Interface
bool LoginInterface(){
	system("cls");
	username="", password="";
		cout<<"\n\n\n\t-------------Login Menu ---------------";
		cout<<"\n\t|                                    |";
		cout<<"\n\t|     Enter username  :              |";
		cout<<"\n\t|                                    |";	
		cout<<"\n\t|     Enter password  :              |";
		cout<<"\n\t|                                    |";	
		cout<<"\n\t|------------------------------------|\n\t";

		xy(31,5);cin>>username;     // --- Input is visible/ unmasked
		xy(31,7);
		//-------------------------Input is not visible/ masked (*)
				char ch = _getch();
				while(ch != 13){//character 13 is enter
					password.push_back(ch);
					cout << '*';
					ch = _getch();
				}
										 
		// return true if only we have real user
		if(username == "" && password == "" )	return false;
		return true;
}

char checkUser() {
	type = 'z';
	readDataList(instructor);
	for(int i=0; i<instructorList.size(); i++) {
		if(instructorList.at(i).getName() == username)
			if(instructorList.at(i).getPassword() == password) {
				userNo = instructorList.at(i).getInstructorNo();
				type = 'i'; // instructor
			}
	}
	readDataList(student);
	for(int j=0; j<studentList.size(); j++) {
		if(studentList.at(j).getName() == username)
			if(studentList.at(j).getPassword() == password) {
				userNo = studentList.at(j).getStudentNo();
				type = 's'; // student
			}
	}
	return type;
}

// Menu Inteface
void AdministratorMenu()
{
	char m;

	std::cout << "* * * * * * * *  Scheduler's Menu(admin)  * * * * * * * *" <<endl;
	std::cout << "*                                                       *"<<endl;
	std::cout << "*          (I)NSTRUCTOR INFORMATION                     *" <<endl;
	std::cout << "*          (R)OOM INFORMATION                           *" <<endl;
	std::cout << "*          (S)TUDENT INFORMATION                        *" <<endl;
	std::cout << "*          (J)SUBJECT INFORMATION                       *" <<endl;
	std::cout << "*          (C)OURSE INFORMATION                         *" <<endl;
	std::cout << "*          (U)SER INFORMATION                           *" <<endl;
	std::cout << "*          (B)UILD FILES                                *" <<endl;
	std::cout << "*          (X)EXIT                                      *" <<endl;
	std::cout << "*                                                       *"<<endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	std::cin >> m;
	switch(m) {
	case 'I': Instructor_SubMenu(); break;
	case 'i': Instructor_SubMenu(); break;
	case 'R': Room_SubMenu(); break;
	case 'r': Room_SubMenu(); break;
	case 'S': Student_SubMenu(); break;
	case 's': Student_SubMenu(); break;
	case 'J': Subject_SubMenu(); break;
	case 'j': Subject_SubMenu(); break;
	case 'C': Course_SubMenu(); break;
	case 'c': Course_SubMenu(); break;
	case 'U': User_SubMenu(); break;
	case 'u': User_SubMenu(); break;
	case 'B': BuildFile_SubMenu(); break;
	case 'b': BuildFile_SubMenu(); break;
	case 'X': exit(0); break;
	case 'x': exit(0); break;
	}

}
void StudentMenu()
{
	char m;

	std::cout << "* * * * * * * *  Student Menu * * * * * * * * *" <<endl;
	std::cout << "*                                             *"<<endl;
	std::cout << "*          (E)nroll a Class                   *" <<endl;
	std::cout << "*          (V)iew Available Courses           *" <<endl;
	std::cout << "*          (M)iew My Schedule                 *" <<endl;
	std::cout << "*          (U)pdate password                  *" <<endl;
	std::cout << "*          (X)EXIT                            *" <<endl;
	std::cout << "*                                             *" <<endl;
	std::cout << "* * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	std::cin >> m;
	switch(m) {
	case 'E': Enroll(); break;
	case 'e': Enroll(); break;
	case 'V': ViewAvailable(); break;
	case 'v': ViewAvailable(); break;
	case 'M': ViewMySchedule(); break;
	case 'm': ViewMySchedule(); break;
	case 'U': UpdatePassword(); break;
	case 'u': UpdatePassword(); break;
	case 'X': exit(0); break;
	case 'x': exit(0); break;
	}
}

// SubMenu Inteface
void Instructor_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Instructor Information * * *" <<endl;
	std::cout << "       *                                                    *"<<endl;
	std::cout << "       *          (S)how Instructor list                    *" <<endl;
	std::cout << "       *          (U)pdate Instructor                       *" <<endl;
	std::cout << "       *          (A)dd new Instructor                      *" <<endl;
	std::cout << "       *          (D)elete Instructor                       *" <<endl;
	std::cout << "       *          (X)EXIT back to main                      *" <<endl;
	std::cout << "       *                                                    *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * **" <<endl;

	char m;
	std::cin >> m;
	switch(m)
	{
	case 'S': showFile(instructor); break;
	case 's': showFile(instructor); break;
	case 'U': updateFile(instructor); break;
	case 'u': updateFile(instructor); break;
	case 'A': addFile(instructor); break;
	case 'a': addFile(instructor); break;
	case 'D': deleteFile(instructor); break;
	case 'd': deleteFile(instructor); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	Instructor_SubMenu();
}
void Room_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Room Information * * *" <<endl;
	std::cout << "       *                                              *"<<endl;
	std::cout << "       *          (S)how Room list                    *" <<endl;
	std::cout << "       *          (U)pdate Room                       *" <<endl;
	std::cout << "       *          (A)dd new Room                      *" <<endl;
	std::cout << "       *          (D)elete Room                       *" <<endl;
	std::cout << "       *          (X)EXIT back to main                *" <<endl;
	std::cout << "       *                                              *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * * * **" <<endl;

	char m;
	std::cin >> m;
	switch(m)
	{
	case 'S': showFile(room); break;
	case 's': showFile(room); break;
	case 'U': updateFile(room); break;
	case 'u': updateFile(room); break;
	case 'A': addFile(room); break;
	case 'a': addFile(room); break;
	case 'D': deleteFile(room); break;
	case 'd': deleteFile(room); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	Room_SubMenu();
}
void Student_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Student Information * * *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       *          (S)how Student list                    *" <<endl;
	std::cout << "       *          (U)pdate Student                       *" <<endl;
	std::cout << "       *          (A)dd new Student                      *" <<endl;
	std::cout << "       *          (D)elete Student                       *" <<endl;
	std::cout << "       *          (X)EXIT back to main                   *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	std::cin >> m;
	switch(m)
	{
	case 'S': showFile(student); break;
	case 's': showFile(student); break;
	case 'U': updateFile(student); break;
	case 'u': updateFile(student); break;
	case 'A': addFile(student); break;
	case 'a': addFile(student); break;
	case 'D': deleteFile(student); break;
	case 'd': deleteFile(student); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	Student_SubMenu();
}
void Subject_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Subject Information * * *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       *          (S)how Subject list                    *" <<endl;
	std::cout << "       *          (U)pdate Subject                       *" <<endl;
	std::cout << "       *          (A)dd new Subject                      *" <<endl;
	std::cout << "       *          (D)elete Subject                       *" <<endl;
	std::cout << "       *          (X)EXIT back to main                   *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	std::cin >> m;
	switch(m)
	{
	case 'S': showFile(subject); break;
	case 's': showFile(subject); break;
	case 'U': updateFile(subject); break;
	case 'u': updateFile(subject); break;
	case 'A': addFile(subject); break;
	case 'a': addFile(subject); break;
	case 'D': deleteFile(subject); break;
	case 'd': deleteFile(subject); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	Subject_SubMenu();
}
void Course_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Course Information  * * *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       *          (S)how Course list                     *" <<endl;
	std::cout << "       *          (U)pdate Course                        *" <<endl;
	std::cout << "       *          (A)dd new Course                       *" <<endl;
	std::cout << "       *          (D)elete Course                        *" <<endl;
	std::cout << "       *          (X)EXIT back to main                   *" <<endl;
	std::cout << "       *                                                 *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	std::cin >> m;
	switch(m)
	{
	case 'S': showFile(course); break;
	case 's': showFile(course); break;
	case 'U': updateFile(course); break;
	case 'u': updateFile(course); break;
	case 'A': addFile(course); break;
	case 'a': addFile(course); break;
	case 'D': deleteFile(course); break;
	case 'd': deleteFile(course); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	Course_SubMenu();
}
void User_SubMenu()
{
	std::cout << "       * * * * * *  User Information * * * * * *" <<endl;
	std::cout << "       *                                       *"<<endl;
	std::cout << "       *          (U)sername Update            *" <<endl;
	std::cout << "       *          (P)assword Update            *" <<endl;
	std::cout << "       *          (X)EXIT back to main         *" <<endl;
	std::cout << "       *                                       *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	std::cin >> m;
	switch (m)
	{
	case 'U': UpdateOnlyName(); break;
	case 'u': UpdateOnlyName(); break;
	case 'P': UpdateinsPassword(); break;
	case 'p': UpdateinsPassword(); break;

	case 'X': AdministratorMenu(); break;
	case 'x': AdministratorMenu(); break;
	}

	// recursion
	User_SubMenu();
}
void BuildFile_SubMenu()
{
	std::cout << "       * * *  Admin sub-menu for Build File  * * *" <<endl;
	std::cout << "       *                                         *"<<endl;
	std::cout << "       *          (I)nstructor List              *" <<endl;
	std::cout << "       *          (R)oom List                    *" <<endl;
	std::cout << "       *          (S)tudent List                 *" <<endl;
	std::cout << "       *          (J)Subject List                *" <<endl;
	std::cout << "       *          (C)ourse List                  *" <<endl;
	std::cout << "       *          (U)ser List                    *" <<endl;
	std::cout << "       *          (X)EXIT back to main           *" <<endl;
	std::cout << "       *                                         *"<<endl;
	std::cout << "       * * * * * * * * * * * * * * * * * * * * * *\n\n" <<endl;

	std::cout << "       *  This Program don't need this Function  *\n" << endl;

	AdministratorMenu();

}

/****************************************** Login & Menu *********************************************/

/************************* Student Menu Functions ***********************************/

void Enroll(){
	putCourse(userNo);	// For 'your' course
	StudentMenu();
}
void ViewAvailable() {
	showAvailableCourses(userNo); // For 'your' course
	StudentMenu();
}
void ViewMySchedule(){
	showMyCourses(userNo); // For 'your' course
	StudentMenu();
}
void UpdatePassword() {
	changePassword();
	StudentMenu();
}


void putCourse(int no){
	int wantcourse;

	// 1. Show Available Course
	showAvailableCourses(no);

	// 2. Save to Schedule File.
	int suc=0;  // success or fail
	fstream File;
	File.open("schedule.txt", ios::in | ios::app);
	std::cout << "Enter course number to enroll : ";
	std::cin >> wantcourse;
	for (int i = 0; i < choicelist.size(); i++){
		if (wantcourse == choicelist.at(i)){
			File << "\n" << no << ";" << wantcourse;
			std::cout << "Complete!!" << endl;
			suc = 1; break;
		}
	}if (suc == 0) std::cout << "Conflict!!\n";  // fail... it means conflict.
	File.close();

}
bool showAvailableCourses(int no) {
	
	choicelist.clear();

	// 1. Get Scheudle List
	getScheudleList(no);

	// 2. Get All Course List
	readDataList(course);

	// 3. Save My Courses to myCourseList
	for (int k = 0; k < scheduleList.size(); k++){
		for( int t = 0; t < courseList.size(); t++) {
			int schedule_cNo = scheduleList.at(k).getsectionno();
			int course_cNo = courseList.at(t).getCourseNo();
			if ( schedule_cNo == course_cNo)
				myCourseList.push_back(courseList.at(t));  // Save subjects taken by user to myCourseList
		}
	}

	// 4. Print Available Courses

	//4-0 When a Student has No Schedule
	if(myCourseList.empty()) {
		printDataList(course);
		for(int i=0; i<courseList.size();i++)
			choicelist.push_back(courseList.at(i).getCourseNo());
		return true;
	}

	// 4-1 Not In My Schedule.
	// 4-2 No Conflict With My Scheduel.
	courseList.at(0).printTitle();
	for (int i = 0; i < courseList.size(); i++){
		for (int j = 0; j < myCourseList.size(); j++){
			if (courseList.at(i).getCourseNo() == myCourseList.at(j).getCourseNo()) break;  // Check if these are same courses
			if (courseList.at(i).getDay() == myCourseList.at(j).getDay()){  // Check if day overlaps each other. (DAY)
				/* Conflic Check!
				 *      A----B
				 *  C----D
				 *  1. If A<D and C<B, It is overlaped.
				 *  2. Then except that case.
				 */ 
				if (courseList.at(i).getTimeEnd() > myCourseList.at(j).getTimeStart() && courseList.at(i).getTimeStart() < myCourseList.at(j).getTimeEnd()) break; // Check if time overlaps each other. (TIME)
				if (j == myCourseList.size() - 1){  // Overlap day but not time, just print and save only courseNo
					courseList.at(i).print();  // print available list 
					choicelist.push_back(courseList.at(i).getCourseNo()); // save
					break;
				}
			}
			else{ // Not overlap day
				if (j == myCourseList.size() - 1){  // print and save only courseNo
					courseList.at(i).print();  // print available list
					choicelist.push_back(courseList.at(i).getCourseNo()); // save
					break;
				}
			}
		}
	}
	cout << endl;

	return true;
}
void showMyCourses(int no){ // my studentNo : no.

	fstream File;
	char line[1000];
	int index;
	char* data[10];
	scheduleList.clear();
	File.open("schedule.txt", ios::in | ios::out);
	while (!File.eof()) {
		File.getline(line, 100);
		index = Token(data, line);
		Schedule s = Schedule(atoi(data[0]),atoi(data[1]));
		if (atoi(data[0]) == no){  // Save my schedule to list
			scheduleList.push_back(s);
		}
	}
	File.close();

	// Sort ScheduleList
	sort(scheduleList.begin(), scheduleList.end(),
		[](Schedule s1, Schedule s2)
            {
				return s1.getsectionno() < s2.getsectionno();
            }
	);

	// Search in courseList
	// Print selectively course record from scheduleList in courseList
	readDataList(course);
	courseList.at(0).printTitle(); // Print Titles.
	for (int k = 0; k < scheduleList.size(); k++) {
		for( int t = 0; t < courseList.size(); t++) {
			int schedule_cNo = scheduleList.at(k).getsectionno();
			int course_cNo = courseList.at(t).getCourseNo();
			if ( schedule_cNo == course_cNo)
				courseList.at(t).print();
		}
	}
	std::cout << endl;

}
bool changePassword() {
	string pPW, nPW, aPW;
	cout << "Present Password : ";
			char ch1 = _getch();
			while(ch1 != 13){//character 13 is enter
				pPW.push_back(ch1);
				cout << '*';
				ch1 = _getch();
			}
			cout <<endl;
			if(pPW != password) {
				cout << "Wrong Password" <<endl;
				return false;
			}
	cout << "New Password : ";
			char ch2 = _getch();
			while(ch2 != 13){//character 13 is enter
				nPW.push_back(ch2);
				cout << '*';
				ch2 = _getch();
			}
			cout<<endl;
	cout << "New Password Again : ";
			char ch3 = _getch();
			while(ch3 != 13){//character 13 is enter
				aPW.push_back(ch3);
				cout << '*';
				ch3 = _getch();
			}
			cout <<endl;
			if(nPW != aPW) {
				cout << "New Password is wrong" <<endl;
				return false;
			}

	if(type == 'i') {
		readDataList(instructor);
		Instructor user = Instructor();
		for(int i=0; i<instructorList.size(); i++) {
			if(instructorList.at(i).getInstructorNo() == userNo) {
				user = instructorList.at(i);
				user.setPassword(nPW);
				instructorList[i] = user;
			}
		}
		writeDataList(instructor);
	}
	else if (type == 's') {
		readDataList(student);
		Student user = Student();
		for(int i=0; i<studentList.size(); i++) {
			if(studentList.at(i).getStudentNo() == userNo) {
				user = studentList.at(i);
				user.setPassword(nPW);
				studentList[i] = user;
			}
		}
		writeDataList(student);
	}
	return true;
}

/****************************************** Student Menu Functions *********************************************/

/************************* Administrator Menu Functions ********************************/

void showFile(int database)
{
	switch(database)
	{
		// read and print
	case instructor:
		readDataList(instructor);
		printDataList(instructor);
		break;
	case room:
		readDataList(room);
		printDataList(room);
		break;
	case student:
		readDataList(student);
		printDataList(student);
		break;
	case subject:
		readDataList(subject);
		printDataList(subject);
		break;
	case course:
		readDataList(course);
		printDataList(course);
		break;
	case user:
		break;
	}
}
void updateFile(int database)
{
	/* Provide each information menu for update */

	fstream File;
	char line[1000];
	int index;
	char* data[10];

	int n;
	bool isValid=false;
	string record;
	string newRecord;

	int x1, x2, x3, x4, x5, x6;
	string a,b,c,d,e,f,g,h,z;

	switch(database)
	{
	case instructor:
		std::cout << "Enter the number of which you want update : "; std::cin >> n;

		File.open("instructor.txt", ios::in|ios::out);
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			
			record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
			index = Token(data, line);				// Tokenize in Line
			if(atoi(data[0]) != n) {
				newRecord += record;
				newRecord += "\n";
			}
			else {
				isValid = true;
				a = to_string(n);
				std::cout << "InstructorNo : " << a <<endl;
				std::cout << "Password : "; std::cin>>b;
				std::cout << "Name : "; cin >> z; getline(cin, c, '\n');		// Leave Spaces
				std::cout << "Rank : "; std::cin>>d;
				record = a+";"+b+";"+z+c+";"+d+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			std::cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("instructor.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case room:
		std::cout << "Enter the number of which you want update : "; std::cin >> n;

		File.open("room.txt", ios::in|ios::out);
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			
			record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
			index = Token(data, line);				// Tokenize in Line
			if(atoi(data[0]) != n) {
				newRecord += record;
				newRecord += "\n";
			}
			else {
				isValid = true;
				a = to_string(n);
				std::cout << "RoomNo : " << a <<endl;
				std::cout << "Description : "; std::cin>>b;
				std::cout << "Type : "; std::cin>>c;
				record = a+";"+b+";"+c+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			std::cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("room.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case student:
		std::cout << "Enter the number of which you want update : "; std::cin >> n;

		File.open("student.txt", ios::in|ios::out);
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			
			record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
			index = Token(data, line);				// Tokenize in Line
			if(atoi(data[0]) != n) {
				newRecord += record;
				newRecord += "\n";
			}
			else {
				isValid = true;
				a = to_string(n);
				std::cout << "StudentNo : " << a <<endl;
				std::cout << "Password : "; std::cin>>b;
				std::cout << "Name : "; cin >> z; getline(cin, c, '\n');		// Leave Spaces
				std::cout << "Major : "; cin >> h; getline(cin, d, '\n');
				record = a+";"+b+";"+z+c+";"+h+d+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			std::cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("student.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case subject:
		std::cout << "Enter the number of which you want update : "; std::cin >> n;

		File.open("subject.txt", ios::in|ios::out);
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			
			record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
			index = Token(data, line);				// Tokenize in Line
			if(atoi(data[0]) != n) {
				newRecord += record;
				newRecord += "\n";
			}
			else {
				isValid = true;
				a = to_string(n);
				std::cout << "SubjectNo : " << a <<endl;
				std::cout << "Description : "; cin >> z; getline(cin, b, '\n');
				std::cout << "Unit : "; std::cin>>c;
				record = a+";"+z+b+";"+c+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			std::cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("subject.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case course:
		std::cout << "Enter the number of which you want update : "; std::cin >> n;

		readDataList(subject);
		readDataList(room);
		readDataList(instructor);
		readDataList(course);
		File.open("course.txt", ios::in|ios::out);
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			
			record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
			index = Token(data, line);				// Tokenize in Line
			if(atoi(data[0]) != n) {
				newRecord += record;
				newRecord += "\n";
			}
			else {
				isValid = true;
				a = to_string(n);
				std::cout << "CourseNo : " << a << endl;
				printDataList(subject);
				std::cout << "Subject Name : "; std::cin>>x2;
				for (int i = 0; i < subjectList.size(); i++){
					if (subjectList.at(i).getSubjectNo() == x2){
						b = subjectList.at(i).getDescription();
						break;
					}
				}
				printDataList(room);
				std::cout << "Room Description : "; std::cin>>x3;
				for (int i = 0; i < roomList.size(); i++){
					if (roomList.at(i).getRoomNo() == x3){
						c = roomList.at(i).getDescription();
						break;
					}
				}
				printDataList(instructor);
				std::cout << "Instructor Name : "; std::cin>>x4;
				for (int i = 0; i < instructorList.size(); i++){
					if (instructorList.at(i).getInstructorNo() == x4){
						d = instructorList.at(i).getName();
						break;
					}
				}
				while (1){	  // Prevent Conflict
					int succ = 0;
					std::cout << "Day : "; std::cin >> e;
					std::cout << "Time Start : "; std::cin >> x5;
					f = to_string(x5);
					std::cout << "Time End : "; std::cin >> x6;
					g = to_string(x6);

					for (int i = 0; i < courseList.size(); i++){ // If conflict is occured, exit while loop.
						if (courseList.at(i).getCourseNo() == n){
							i++;
							if (i >= courseList.size()){
								++succ;
								break;
							}
						}
						if (courseList.at(i).getDay() == *e.c_str() && courseList.at(i).getRoom().getDescription() == c){  //Check if day and room overlap each other. (DAY, ROOM)
							if (courseList.at(i).getTimeEnd() > x5 && courseList.at(i).getTimeStart() < x6) break;
							if (i == courseList.size() - 1){ 
								++succ;
								break;
							}
						}
						else{
							if (i == courseList.size() - 1){ 
								++succ;
								break;
							}
						}
					}
					if (succ != 0) break;
					cout << "Conflict!! Please again\n";
				}
				record = a+";"+b+";"+c+";"+d+";"+e+";"+f+";"+g+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			std::cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("course.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case user:
		File.open("user.txt", ios::in|ios::out);
		break;
	}
	
	File.close();
}
void addFile(int database)
{
	fstream File;
	int x1, x2, x3, x4, x5, x6;
	string a,b,c,d,e,f,g,h,z;
	char buf[20];
	switch(database)
	{
	case instructor:
		readDataList(instructor);
		File.open("instructor.txt", ios::in|ios::app);
		while (1){ // Prevent overlapped number.
			int faill = 0;
			std::cout << "InstructorNo : "; std::cin >> x1;
			for (int i = 0; i < instructorList.size(); i++){
				if (instructorList.at(i).getInstructorNo() == x1){
					cout << "There is same Number.\n";
					++faill;
					break;
				}
			}
			if (faill==0) break;
		}
		a = to_string(x1);
		std::cout << "Password : "; std::cin>>b;
		std::cout << "Name : "; cin >> z; getline(cin, c, '\n');		// Leave Spaces
		std::cout << "Rank : "; std::cin>>d;

		File <<"\n" << a << ";" << b << ";" << z+c << ";" << d;
		break;
	case room:
		readDataList(room);
		File.open("room.txt", ios::in|ios::app);
		while (1){ 
			int faill = 0;
			std::cout << "RoomNo : "; std::cin >> x1;
			for (int i = 0; i < roomList.size(); i++){
				if (roomList.at(i).getRoomNo() == x1){
					cout << "There is same Number.\n";
					++faill;
					break;
				}
			}
			if (faill == 0) break;
		}
		a = to_string(x1);
		std::cout << "Description : "; std::cin>>b;
		std::cout << "Type : "; std::cin>>c;

		File <<"\n" << a << ";" << b << ";" << c;
		break;
	case student:
		readDataList(student);
		File.open("student.txt", ios::in|ios::app);
		while (1){
			int faill = 0;
			std::cout << "StudnetNo : "; std::cin >> x1;
			for (int i = 0; i < studentList.size(); i++){
				if (studentList.at(i).getStudentNo() == x1){
					cout << "There is same Number.\n";
					++faill;
					break;
				}
			}
			if (faill == 0) break;
		}
		a = to_string(x1);
		std::cout << "Password : "; cin >> b;
		std::cout << "Name : "; cin >> z; getline(cin, c, '\n');		// Leave Spaces
		std::cout << "Major : "; cin >> h; getline(cin, d, '\n');

		File <<"\n" << a << ";" << b << ";" << z+c << ";" << h+d;
		break;
	case subject:
		readDataList(subject);
		File.open("subject.txt", ios::out|ios::app);
		while (1){
			int faill = 0;
			std::cout << "SubjectNo : "; std::cin >> x1;
			for (int i = 0; i < subjectList.size(); i++){
				if (subjectList.at(i).getSubjectNo() == x1){
					cout << "There is same Number.\n";
					++faill;
					break;
				}
			}
			if (faill == 0) break;
		}
		a = to_string(x1);
		std::cout << "Description : "; std::cin >> z; getline(cin, b, '\n');
		std::cout << "Unit : "; std::cin>>c;

		File <<"\n" << a << ";" << z+b << ";" << c;
		break;
	case course:
		readDataList(subject);
		readDataList(room);
		readDataList(instructor);
		readDataList(course);
		File.open("course.txt", ios::in|ios::app);
		while (1){
			int faill = 0;
			std::cout << "CourseNo : "; std::cin >> x1;
			for (int i = 0; i < courseList.size(); i++){
				if (courseList.at(i).getCourseNo() == x1){
					cout << "There is same Number.\n";
					++faill;
					break;
				}
			}
			if (faill == 0) break;
		}
		a = to_string(x1);
		printDataList(subject);
		std::cout << "Subject Number : "; std::cin>>x2;  // Not enter the string value, Show the subject lists and enter the integer and save.
		for (int i = 0; i < subjectList.size(); i++){
			if (subjectList.at(i).getSubjectNo() == x2){
				b = subjectList.at(i).getDescription();
				break;
			}
		}
		printDataList(room);
		std::cout << "Room Number : "; std::cin>>x3;  // Not enter the string value, Show the subject lists and enter the integer and save.
		for (int i = 0; i < roomList.size(); i++){
			if (roomList.at(i).getRoomNo() == x3){
				c = roomList.at(i).getDescription();
				break;
			}
		}
		printDataList(instructor);
		std::cout << "Instructor Number : "; std::cin>>x4; // Not enter the string value, Show the subject lists and enter the integer and save.
		for (int i = 0; i < instructorList.size(); i++){
			if (instructorList.at(i).getInstructorNo() == x4){
				d = instructorList.at(i).getName();
				break;
			}
		}
		while (1){
			int succ = 0;
			std::cout << "Day : "; std::cin >> e;
			std::cout << "Time Start : "; std::cin >> x5;
			f = to_string(x5);
			std::cout << "Time End : "; std::cin >> x6;
			g = to_string(x6);

			for (int i = 0; i < courseList.size(); i++){
				if (courseList.at(i).getDay()==*e.c_str()&&courseList.at(i).getRoom().getDescription()==c){ 
					if (courseList.at(i).getTimeEnd() > x5 && courseList.at(i).getTimeStart() < x6) break;
					if (i == courseList.size() - 1){ 
						++succ;
						break;
					}
				}
				else{
					if (i == courseList.size() - 1){
						++succ;
						break;
					}
				}
			}
			if (succ != 0) break;
			cout << "Conflict!! Please again\n";
		}
		

		File <<"\n" << a << ";" << b << ";" << c << ";" << d << ";" << e << ";" << f << ";" << g;
		break;
	case user:
		File.open("user.txt", ios::in|ios::app);
		break;
	}

	File.close();
}
void deleteFile(int database)
{
	switch(database)
	{
	case instructor:
		deleteRecord("instructor");
		break;
	case room:
		deleteRecord("room");
		break;
	case student:
		deleteRecord("student");
		break;
	case subject:
		deleteRecord("subject");
		break;
	case course:
		deleteRecord("course");
		break;
	case user:
		break;
	case schedule:
		deleteRecord("schedule");
		break;
	}
}


int Token(char* data[], char *line)
{
	int i=0;

	char* ptr = strtok(line, ";");
	while( ptr != NULL ) {
		data[i] = ptr;
		ptr = strtok(NULL, ";");
		i++;
	}
	return i;
}

/*
	Delete : Read Lines Except for Delete Record.
				And Re-Write Records to Same File.
*/
void deleteRecord(string s) {
	fstream File;
	char line[1000];
	int index;
	char* data[10];

	int n;
	bool isValid=false;
	string record;
	string newRecord;
	
	string filename = s + ".txt";

	std::cout << "Enter the number of which you want delete : "; std::cin >> n;

	File.open(filename, ios::in|ios::out);
	while(!File.eof()) {
		File.getline(line, 100);					// Read by Line

		record = line;	// backup to string value 'record' ---> because, 'Token' function will change the variable 'line'
			
		index = Token(data, line);				// Tokenize in Line
		if(atoi(data[0]) != n) {
			newRecord += record;
			newRecord += "\n";
		}
		else
			isValid = true;
	}

	if(!isValid)	// If there is no number of which user want to delete of
		std::cout << "There is no record for number " << n << ". Please Check" <<endl;
	else {
		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open(filename, ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		std::wcout << "Delete Compete!!" <<endl;
	}
	File.close();
}
void readDataList(int database)
{
	fstream File;
	char line[1000];
	int index;
	char* data[10];

	switch(database)
	{
	case instructor:
		// 0. List Initializing
		instructorList.clear();
		// 1. File Open
		File.open("instructor.txt", ios::in|ios::out);
		// 2. File Read
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			index = Token(data, line);				// Tokenize in Line
			Instructor i = Instructor(atoi(data[0]),data[1],data[2],atoi(data[3]));	// Construct 'Instructor' from tokenized data
			instructorList.push_back(i);				// Insert to instructorList
		}

		// Sort instructorList
		sort(instructorList.begin(), instructorList.end(),
			[](Instructor c1, Instructor c2)
				{
					return c1.getInstructorNo() < c2.getInstructorNo();
				}
		);

		break;
	case room:
		// 0. List Initializing
		roomList.clear();
		// 1. File Open
		File.open("room.txt", ios::in|ios::out);
		// 2. File Read
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			index = Token(data, line);				// Tokenize in Line
			Room r = Room(atoi(data[0]),data[1],atoi(data[2]));	// Construct 'Instructor' from tokenized data
			roomList.push_back(r);				// Insert to roomList
		}

		// Sort roomList
		sort(roomList.begin(), roomList.end(),
			[](Room c1, Room c2)
				{
					return c1.getRoomNo() < c2.getRoomNo();
				}
		);

	case student:
		// 0. List Initializing
		studentList.clear();
		// 1. File Open
		File.open("student.txt", ios::in|ios::out);
		// 2. File Read
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			index = Token(data, line);				// Tokenize in Line
			Student s = Student(atoi(data[0]),data[1],data[2],data[3]);	// Construct 'Instructor' from tokenized data
			studentList.push_back(s);				// Insert to studentList
		}

		// Sort studentList
		sort(studentList.begin(), studentList.end(),
			[](Student c1, Student c2)
				{
					return c1.getStudentNo() < c2.getStudentNo();
				}
		);

		break;
	case subject:
		// 0. List Initializing
		subjectList.clear();
		// 1. File Open
		File.open("subject.txt", ios::in|ios::out);
		// 2. File Read
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			index = Token(data, line);				// Tokenize in Line
			Subject s = Subject(atoi(data[0]),data[1],atoi(data[2]));	// Construct 'Subject' from tokenized data
			subjectList.push_back(s);				// Insert to subjectList
		}

		// Sort subjectList
		sort(subjectList.begin(), subjectList.end(),
			[](Subject c1, Subject c2)
				{
					return c1.getSubjectNo() < c2.getSubjectNo();
				}
		);

		break;
	case course:
		// 0. List Initializing
		courseList.clear();
		// 1. File Open
		File.open("course.txt", ios::in|ios::out);
		// 2. File Read
		while(!File.eof()) {
			File.getline(line, 100);					// Read by Line
			index = Token(data, line);				// Tokenize in Line
			Course c = Course(atoi(data[0]), Subject(data[1]), Room(data[2]), Instructor(data[3]), data[4][0], atoi(data[5]), atoi(data[6]));	// Construct 'Course' from tokenized data
			courseList.push_back(c);				// Insert to courseList
		}

		// Sort courseList
		sort(courseList.begin(), courseList.end(),
			[](Course c1, Course c2)
				{
					return c1.getCourseNo() < c2.getCourseNo();
				}
		);
		break;
	case user:
		break;
	}
	File.close();
}

void writeDataList(int database)
{
	fstream File;
	string newRecord;
	string record;
	switch(database)
	{
	case instructor:
		newRecord = "";
		for(int i=0; i<instructorList.size(); i++) {
			record.clear();
			record = to_string(instructorList.at(i).getInstructorNo()) + ";";
			record += instructorList.at(i).getPassword() + ";";
			record += instructorList.at(i).getName() + ";";
			record += to_string(instructorList.at(i).getRank());
			record += "\n";
			newRecord += record;
		}
		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.open("instructor.txt", ios::out|ios::trunc);
		File << newRecord;
		break;
	case room:
		break;
	case student:
		newRecord = "";
		for(int i=0; i<studentList.size(); i++) {
			record.clear();
			record = to_string(studentList.at(i).getStudentNo()) + ";";
			record += studentList.at(i).getPassword() + ";";
			record += studentList.at(i).getName() + ";";
			record += studentList.at(i).getMajor();
			record += "\n";
			newRecord += record;
		}
		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.open("student.txt", ios::out|ios::trunc);
		File << newRecord;
		break;
	case subject:
		break;
	case course:
		break;
	case user:
		break;
	}
	File.close();
}

void printDataList(int database)
{
	switch(database)
	{
	case instructor:
		if(instructorList.empty()) {
			std::cout << "no entry"; break; }
		instructorList.at(0).printTitle();				// Print Title
		for(int k=0; k<instructorList.size(); k++)
			instructorList.at(k).print();					// Print Data
		std::cout <<endl;								// (for readability)
		break;
	case room:
		if(roomList.empty()) {
			std::cout << "no entry"; break; }
		roomList.at(0).printTitle();				// Print Title
		for(int k=0; k<roomList.size(); k++)
			roomList.at(k).print();					// Print Data
		std::cout <<endl;								// (for readability)
		break;
	case student:
		if(studentList.empty()) {
			std::cout << "no entry"; break; }
		studentList.at(0).printTitle();				// Print Title
		for(int k=0; k<studentList.size(); k++)
			studentList.at(k).print();					// Print Data
		std::cout <<endl;								// (for readability)
		break;
	case subject:
		if(subjectList.empty()) {
			std::cout << "no entry"; break; }
		subjectList.at(0).printTitle();				// Print Title
		for(int k=0; k<subjectList.size(); k++)
			subjectList.at(k).print();					// Print Data
		std::cout <<endl;								// (for readability)
		break;
	case course:
		if(courseList.empty()) {
			std::cout << "no entry"; break; }
		courseList.at(0).printTitle();				// Print Title
		for(int k=0; k<courseList.size(); k++)
			courseList.at(k).print();					// Print Data
		std::cout <<endl;								// (for readability)
		break;
	case user:
		break;
	}
}

void getScheudleList(int no)
{
	fstream File;
	char line[1000];
	int index;
	char* data[10];
	scheduleList.clear();
	File.open("schedule.txt", ios::in | ios::out);
	while (!File.eof()) {
		File.getline(line, 100);
		index = Token(data, line);
		Schedule s = Schedule(atoi(data[0]), atoi(data[1]));
		if (atoi(data[0]) == no){
			scheduleList.push_back(s);
		}
	}
	File.close();
}

void UpdateOnlyName(){
	changeUsername();
	User_SubMenu();
}
void changeUsername(){
	readDataList(instructor);

	string z;
	string temp;
	cout << "New Name : ";
	cin >> z; getline(cin, temp, '\n');
	z += temp;

	Instructor user = Instructor();
	for (int i = 0; i<instructorList.size(); i++) {
		if (instructorList.at(i).getInstructorNo() == userNo) {
			user = instructorList.at(i);
			user.setName(z);
			instructorList[i] = user;
		}
	}
	writeDataList(instructor);
}
void UpdateinsPassword(){
	changePassword();
	User_SubMenu();
}
