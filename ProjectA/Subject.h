#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Subject {
private:
	int subjectNo;
	string description;
	int unit;
	//int addSubject();
public:
	Subject() { subjectNo=0; description=""; unit=0; }
	Subject(string d) { subjectNo=0; description=d; unit=0; } // When read course file, it is easy to input just description.
	Subject(int no, string d, int u) { subjectNo=no; description=d; unit=u; }
	int getSubjectNo() { return subjectNo; }
	string getDescription() { return description; }
	int getUnit() { return unit; }
	void setSubject(int no, string d, int u) { subjectNo=no; description=d; unit=u; }

	void printTitle();
	void print();

	void addSubject();
};

void Subject::printTitle()
	{
		cout << "========== Subject List ==========" <<endl;
		cout << setw(15) << setiosflags(ios::left) << "SubjectNo";
		cout << setw(20) << setiosflags(ios::left) << "Description";
		cout << setw(10) << setiosflags(ios::left) << "Unit" << endl;
	}
void Subject::print()
	{
		cout << setw(15) << setiosflags(ios::left) << subjectNo;
		cout << setw(20) << setiosflags(ios::left) << description;
		cout << setw(10) << setiosflags(ios::left) << unit << endl;
	}

void Subject::addSubject() {
	int no;
	string d;
	int u;
	char buf[20];
	cout << "SubjectNo : "; cin>>no; cin.clear();
	cout << "Description : "; cin.getline(buf, 20); cin.clear(); getline(cin, d);
	cout << "Unit : "; cin>>u;
	setSubject(no,d,u);
}