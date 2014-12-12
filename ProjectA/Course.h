#include "Instructor.h"
#include "Subject.h"
#include "Room.h"
#include "Time.h"


using namespace std;

class Course {
private:
	int courseNo;
	Subject subject;
	Room room;
	Instructor instructor;
	char day;
	int timeStart;	// Conveniently, save Time with Integer (Hour) 
	int timeEnd;		// Conveniently, save Time with Integer (Hour) 
public:
	Course();
	Course(int no, Subject s, Room r, Instructor i, char d, int ts, int te );
	int getCourseNo() { return courseNo; }
	Subject getSubject() { return subject; }
	Room getRoom() { return room; }
	Instructor getInstructor() { return instructor; }
	char getDay() { return day; }	// T for Tuesday, H for Thursday
	int getTimeStart() { return timeStart; }
	int getTimeEnd() { return timeEnd; }

	void printTitle();
	void print();
};

Course::Course() { courseNo=0; subject=Subject(); room=Room(); instructor=Instructor(); day=' '; timeStart=0; timeEnd=0; }
Course::Course(int no, Subject s, Room r, Instructor i, char d, int ts, int te ) {
		courseNo=no; subject=s; room=r; instructor=i; day=d; timeStart=ts; timeEnd=te; }

void Course::printTitle()
	{
		cout << "========================= Course List =========================" <<endl;
		cout << setw(10) << setiosflags(ios::left) << "CourseNo";
		cout << setw(20) << setiosflags(ios::left) << "Subject";
		cout << setw(10) << setiosflags(ios::left) << "Room";
		cout << setw(15) << setiosflags(ios::left) << "Instructor";
		cout << setw(5) << setiosflags(ios::left) << "Day";
		cout << setw(10) << setiosflags(ios::left) << "Start";
		cout << setw(10) << setiosflags(ios::left) << "End" <<endl;
	}
void Course::print()
	{
		cout << setw(10) << setiosflags(ios::left) << courseNo;
		cout << setw(20) << setiosflags(ios::left) << subject.getDescription();
		cout << setw(10) << setiosflags(ios::left) << room.getDescription();
		cout << setw(15) << setiosflags(ios::left) << instructor.getName();
		cout << setw(5) << setiosflags(ios::left) << day;
		cout << setw(10) << setiosflags(ios::left) << timeStart;
		cout << setw(10) << setiosflags(ios::left) << timeEnd;
	}

/*
class StudentSchedule {
private:
	int studentNo;
	int sectionNo;
	int noConflict();
public:
};
*/