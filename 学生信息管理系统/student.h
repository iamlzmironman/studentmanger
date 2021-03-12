// student.h: interface for the student class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __student__h__
#define __student__h__
//////////////////////////////////////////////////////////////////////

#ifndef __student__h__
#define __student__h__
#include <iostream>
using namespace std;

class student;
istream& operator>>(istream&, student&);
ostream& operator<<(ostream&, student&);

class student
{

	friend class subscriber;
	friend istream& operator>>(istream&, student&);
	friend ostream& operator<<(ostream&, student&);
public:
	student() { num = -1; next = NULL; }
	~student() {}
private:
	string name;			//姓名
	int num;				//学号
	string sex;
	int classnum;
	int roomnum;
	string phonenum;
	string province;
	int term;

	student *next;			//指向下一个学生的指针
};

#endif
