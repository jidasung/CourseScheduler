class Schedule {
private:
	int studno;
	int sectionno;
public:
	Schedule();
	Schedule(int stuno, int secno);

	int getstudno() { return studno; }
	void setstudno(int a) { studno = a; }

	int getsectionno() { return sectionno; }
	void setsectionno(int a) { sectionno = a; }
};

Schedule::Schedule(){ studno = 0; sectionno = 0; }
Schedule::Schedule(int stuno, int secno){
	studno = stuno; sectionno = secno;
}