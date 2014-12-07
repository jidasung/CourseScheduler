#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Instructor {
private:
	int instructorNo;
	string password;
	string name;
	int rank;
public:
	Instructor() { instructorNo=0; password=""; name=""; rank=0; }
	Instructor(string n) { instructorNo=0; password=""; name=n; rank=0; } // When read course file, it is easy to input just description.
	Instructor(int no, string p, string n, int r) { instructorNo=no; password=p; name=n; rank=r; }
	int getInstructorNo() { return instructorNo; }
	string getPassword() { return password; }
	string getName() { return name; }
	int getRank() { return rank; }

	void setPassword(string newPassword) { this->password = newPassword; }

	void printTitle();
	void print();
};

void Instructor::printTitle()
	{
		cout << "========== Instructor List ==========" <<endl;
		cout << setw(15) << setiosflags(ios::left) << "InstructorNo";
		cout << setw(15) << setiosflags(ios::left) << "Name";
		cout << setw(10) << setiosflags(ios::left) << "Rank" << endl;
	}
void Instructor::print()
	{
		cout << setw(15) << setiosflags(ios::left) << instructorNo;
		cout << setw(15) << setiosflags(ios::left) << name;
		cout << setw(10) << setiosflags(ios::left) << rank << endl;
	}
