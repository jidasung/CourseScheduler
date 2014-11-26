#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Room {
private:
	int roomNo;
	string description;
	int type;
	//int addRoom();
public:
	Room() { roomNo=0; description=""; type=0; }
	Room(string d) { roomNo=0; description=d; type=0; } // When read course file, it is easy to input just description.
	Room(int no, string d, int t) { roomNo=no; description=d; type=t; }
	int getRoomNo() { return roomNo; }
	string getDescription() { return description; }
	int getType() { return type; }

	void printTitle();
	void print();
};

void Room::printTitle()
	{
		cout << "========== Room List ==========" <<endl;
		cout << setw(15) << setiosflags(ios::left) << "RoomNo";
		cout << setw(15) << setiosflags(ios::left) << "Description";
		cout << setw(10) << setiosflags(ios::left) << "Type" <<endl;
	}
void Room::print()
	{
		cout << setw(15) << setiosflags(ios::left) << roomNo;
		cout << setw(15) << setiosflags(ios::left) << description;
		cout << setw(10) << setiosflags(ios::left) << type <<endl;
	}