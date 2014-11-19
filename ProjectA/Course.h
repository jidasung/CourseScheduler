#include <iostream>
#include <string>

using namespace std;

class Course {
private:
	int sectionNo;
	string subject;
	Room room;
	string instructor_name;
	char day;
	Time timeStart;
	Time timeEnd;
public:
};

class Student {
private:
	int studentNo;
	int password;
	string name;
	Course course;
public:
};

class Instructor {
private:
	int instructorNo;
	int password;
	string name;
	int rank;
public:
};

class Room {
private:
	int roomNo;
	string description;
	int type;
	int addRoom();
public:
};

class Subject {
private:
	int subjectNo;
	string description;
	int unit;
	int addSubject();
public:
};

class StudentSchedule {
private:
	int studentNo;
	int sectionNo;
	int noConflict();
public:
};

class Time {
	int hour;
	int minute;
};