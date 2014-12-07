#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
private:
	int studentNo;
	string password;
	string name;
	string major;
public:
	Student() { studentNo=0; password=""; name=""; major=""; }
	Student(int no, string p, string n, string m) { studentNo=no; password=p; name=n; major=m; }

	int getStudentNo() { return studentNo; }
	string getPassword() { return password; }
	string getName() { return name; }
	string getMajor() { return major; }

	void setPassword(string newPassword) { this->password = newPassword; }

	void printTitle();
	void print();
};

void Student::printTitle()
	{
		cout << "========== Student List ==========" <<endl;
		cout << setw(15) << setiosflags(ios::left) << "StudentNo";
		cout << setw(20) << setiosflags(ios::left) << "Name";
		cout << setw(15) << setiosflags(ios::left) << "Major" << endl;
	}
void Student::print()
	{
		cout << setw(15) << setiosflags(ios::left) << studentNo;
		cout << setw(20) << setiosflags(ios::left) << name;
		cout << setw(15) << setiosflags(ios::left) << major << endl;
	}