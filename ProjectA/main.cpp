#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef enum Database { instructor, room, student, subject, course, user };

vector<Instructor> instructorList = vector<Instructor>();
vector<Room> roomList = vector<Room>();
vector<Student> studentList = vector<Student>();
vector<Subject> subjectList = vector<Subject>();
vector<Course> courseList = vector<Course>();

void LoginInterface();
void AdministratorMenu();
void StudentMenu();

void Instructor_SubMenu();
void Room_SubMenu();
void Student_SubMenu();
void Subject_SubMenu();
void Course_SubMenu();
void User_SubMenu();
void BuildFile_SubMenu();

void Enroll();
void ViewAvailable();
void ViewMySchedule();
void UpdatePassword();

void showFile(int);
void updateFile(int);
void addFile(int);
void deleteFile(int);

int Token(char* data[], char *line);


int main() {
	AdministratorMenu();
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

	// check ID/PW and go to admin or student menu.
	AdministratorMenu();
	//StudentMenu();
}
void AdministratorMenu()
{
	char m;

	cout << "* * * * * * * *  Scheduler's Menu(admin)  * * * * * * * *" <<endl;
	cout << "*                                                       *"<<endl;
	cout << "*          (I)NSTRUCTOR INFORMATION                     *" <<endl;
	cout << "*          (R)OOM INFORMATION                           *" <<endl;
	cout << "*          (S)TUDENT INFORMATION                        *" <<endl;
	cout << "*          (J)SUBJECT INFORMATION                       *" <<endl;
	cout << "*          (C)OURSE INFORMATION                         *" <<endl;
	cout << "*          (U)SER INFORMATION                           *" <<endl;
	cout << "*          (B)UILD FILES                                *" <<endl;
	cout << "*          (X)EXIT                                      *" <<endl;
	cout << "*                                                       *"<<endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	cin >> m;
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

	cout << "* * * * * * * *  Student Menu * * * * * * * * *" <<endl;
	cout << "*                                             *"<<endl;
	cout << "*          (E)nroll a Class                   *" <<endl;
	cout << "*          (V)iew Available Courses           *" <<endl;
	cout << "*          (M)iew My Schedule                 *" <<endl;
	cout << "*          (U)pdate password                  *" <<endl;
	cout << "*          (X)EXIT                            *" <<endl;
	cout << "*                                             *"<<endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	cin >> m;
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

void Instructor_SubMenu()
{
	cout << "       * * *  Admin sub-menu for Instructor Information * * *" <<endl;
	cout << "       *                                                    *"<<endl;
	cout << "       *          (S)how Instructor list                    *" <<endl;
	cout << "       *          (U)pdate Instructor                       *" <<endl;
	cout << "       *          (A)dd new Instructor                      *" <<endl;
	cout << "       *          (D)elete Instructor                       *" <<endl;
	cout << "       *          (X)EXIT back to main                      *" <<endl;
	cout << "       *                                                    *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * **" <<endl;

	char m;
	cin >> m;
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
	cout << "       * * *  Admin sub-menu for Room Information * * *" <<endl;
	cout << "       *                                              *"<<endl;
	cout << "       *          (S)how Room list                    *" <<endl;
	cout << "       *          (U)pdate Room                       *" <<endl;
	cout << "       *          (A)dd new Room                      *" <<endl;
	cout << "       *          (D)elete Room                       *" <<endl;
	cout << "       *          (X)EXIT back to main                *" <<endl;
	cout << "       *                                              *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * **" <<endl;

	char m;
	cin >> m;
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
	cout << "       * * *  Admin sub-menu for Student Information * * *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       *          (S)how Student list                    *" <<endl;
	cout << "       *          (U)pdate Student                       *" <<endl;
	cout << "       *          (A)dd new Student                      *" <<endl;
	cout << "       *          (D)elete Student                       *" <<endl;
	cout << "       *          (X)EXIT back to main                   *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	cin >> m;
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
	cout << "       * * *  Admin sub-menu for Subject Information * * *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       *          (S)how Subject list                    *" <<endl;
	cout << "       *          (U)pdate Subject                       *" <<endl;
	cout << "       *          (A)dd new Subject                      *" <<endl;
	cout << "       *          (D)elete Subject                       *" <<endl;
	cout << "       *          (X)EXIT back to main                   *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	cin >> m;
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
	cout << "       * * *  Admin sub-menu for Course Information  * * *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       *          (S)how Course list                     *" <<endl;
	cout << "       *          (U)pdate Course                        *" <<endl;
	cout << "       *          (A)dd new Course                       *" <<endl;
	cout << "       *          (D)elete Course                        *" <<endl;
	cout << "       *          (X)EXIT back to main                   *" <<endl;
	cout << "       *                                                 *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl;

	char m;
	cin >> m;
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
	cout << "       * * * * * *  User Information * * * * * *" <<endl;
	cout << "       *                                       *"<<endl;
	cout << "       *          (U)sername Update            *" <<endl;
	cout << "       *          (P)assword Update            *" <<endl;
	cout << "       *          (X)EXIT back to main         *" <<endl;
	cout << "       *                                       *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * *" <<endl;
}
void BuildFile_SubMenu()
{
	cout << "       * * *  Admin sub-menu for Build File  * * *" <<endl;
	cout << "       *                                         *"<<endl;
	cout << "       *          (I)nstructor List              *" <<endl;
	cout << "       *          (R)oom List                    *" <<endl;
	cout << "       *          (S)tudent List                 *" <<endl;
	cout << "       *          (J)Subject List                *" <<endl;
	cout << "       *          (C)ourse List                  *" <<endl;
	cout << "       *          (U)ser List                    *" <<endl;
	cout << "       *          (X)EXIT back to main           *" <<endl;
	cout << "       *                                         *"<<endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * *" <<endl;
}

void Enroll() {}
void ViewAvailable() {}
void ViewMySchedule() {}
void UpdatePassword() {}


void showFile(int database)
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

		instructorList.at(0).printTitle();				// Print Title
		for(int k=0; k<instructorList.size(); k++)
			instructorList.at(k).print();					// Print Data
		cout <<endl;								// (for readability)
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
		
		roomList.at(0).printTitle();				// Print Title
		for(int k=0; k<roomList.size(); k++)
			roomList.at(k).print();					// Print Data
		cout <<endl;								// (for readability)
		
		break;
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

		studentList.at(0).printTitle();				// Print Title
		for(int k=0; k<studentList.size(); k++)
			studentList.at(k).print();					// Print Data
		cout <<endl;								// (for readability)
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

		subjectList.at(0).printTitle();				// Print Title
		for(int k=0; k<subjectList.size(); k++)
			subjectList.at(k).print();					// Print Data
		cout <<endl;								// (for readability)
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
			//for(int k=0; k<index; k++)
				//cout << "data[" << k << "] = " << data[k] <<endl;
		}
		
		courseList.at(0).printTitle();				// Print Title
		for(int k=0; k<courseList.size(); k++)
			courseList.at(k).print();					// Print Data
		cout <<endl;								// (for readability)
		break;
	case user:
		File.open("user.txt", ios::in|ios::out);
		break;
	}
	
	File.close();

}
void updateFile(int database)
{
	fstream File;
	char line[1000];
	int index;
	char* data[10];

	int n;
	bool isValid=false;
	string record;
	string newRecord;

	string a,b,c,d,e,f,g;

	switch(database)
	{
	case instructor:
		File.open("instructor.txt", ios::in|ios::out);
		break;
	case room:
		File.open("room.txt", ios::in|ios::out);
		break;
	case student:
		File.open("student.txt", ios::in|ios::app);
		break;
	case subject:
		cout << "Enter the number of which you want update : "; cin >> n;

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
				cout << "SubjectNo : " << a <<endl;
				cout << "Description : "; cin>>b;
				cout << "Unit : "; cin>>c;
				record = a+";"+b+";"+c+"\n";
				newRecord += record;
			}
		}

		if(!isValid) {	// If there is no number of which user want to update of
			cout << "There is no record for number " << n << ". Please Check" <<endl; break;
		}

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("subject.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		cout << newRecord <<endl;
		File << newRecord;			// Write New Record (after delete)
		break;
	case course:
		File.open("course.txt", ios::in|ios::out);
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
	string a,b,c,d,e,f,g;
	char buf[20];
	switch(database)
	{
	case instructor:
		File.open("instructor.txt", ios::in|ios::app);
		cout << "InstructorNo : "; cin>>a;
		cout << "Password : "; cin>>b;
		cout << "Name : "; cin>>c;
		cout << "Rank : "; cin>>d;

		File <<"\n" << a << ";" << b << ";" << c << ";" << d;
		break;
	case room:
		File.open("room.txt", ios::in|ios::app);
		cout << "RoomNo : "; cin>>a;
		cout << "Description : "; cin>>b;
		cout << "Type : "; cin>>c;

		File <<"\n" << a << ";" << b << ";" << c;
		break;
	case student:
		File.open("student.txt", ios::in|ios::app);
		cout << "StudentNo : "; cin>>a;
		cout << "Password : "; cin>>b;
		cout << "Description : "; cin>>c;
		cout << "Major : "; cin>>d;

		File <<"\n" << a << ";" << b << ";" << c << ";" << d;
		break;
	case subject:
		File.open("subject.txt", ios::out|ios::app);
		cout << "SubjectNo : "; cin>>a; cin.clear();
		cout << "Description : "; cin>>b;
		cout << "Unit : "; cin>>c;

		File <<"\n" << a << ";" << b << ";" << c;
		break;
	case course:
		File.open("course.txt", ios::in|ios::app);
		cout << "CourseNo : "; cin>>a;
		cout << "Subject Name : "; cin>>b;
		cout << "Room Description : "; cin>>c;
		cout << "Instructor Name : "; cin>>d;
		cout << "Day : "; cin>>e;
		cout << "Time Start : "; cin>>f;
		cout << "Time End : "; cin>>g;

		File <<"\n" << a << ";" << b << ";" << c << ";" << d << ";" << e << ";" << f << ";" << g;
		break;
	case user:
		File.open("user.txt", ios::in|ios::app);
		break;
	}

	File.close();
}

/*
	Delete : Read Lines Except for Delete Record.
				And Re-Write Records to Same File.
*/
void deleteFile(int database)
{
	fstream File;
	char line[1000];
	int index;
	char* data[10];

	int n;
	bool isValid=false;
	string record;
	string newRecord;

	switch(database)
	{
	case instructor:
		File.open("instructor.txt", ios::in|ios::out);
		break;
	case room:
		File.open("room.txt", ios::in|ios::out);
		break;
	case student:
		File.open("student.txt", ios::in|ios::out);
		break;
	case subject:
		cout << "Enter the number of which you want delete : "; cin >> n;

		File.open("subject.txt", ios::in|ios::out);
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
			cout << "There is no record for number " << n << ". Please Check" <<endl; break;

		newRecord = newRecord.substr(0, newRecord.size()-1);	// Remove Last "\n"
		File.close();
		File.open("subject.txt", ios::out|ios::trunc);		// Re-Open with ios::trunc
		File << newRecord;			// Write New Record (after delete)
		break;
	case course:
		File.open("course.txt", ios::in|ios::out);
		break;
	case user:
		File.open("user.txt", ios::in|ios::out);
		break;
	}
	
	File.close();
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