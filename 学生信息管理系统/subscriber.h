// subscriber.h: interface for the subscriber class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __subscriber__h__
#define __subscriber__h__
#include "student.h"
#include <iostream>
using namespace std;

class subscriber
{

public:
	subscriber() { head = NULL; }
	~subscriber() { ; }
public:
	void create();		//创建学生信息链表		
	void insert();		//插入学生信息
	void del();			//删除学生信息
	void modify();		//修改学生信息
	void print();		//显示全部学生信息
	void search();		//搜索学生信息
	void savef();		//保存学生信息到文件
	void loadf();		//从文件中读取学生信息
	void sys();	        //口令修改

private:
	int NumOfLIst();	//计算链表节点数
	void deleteall();	//删除全部
private:
	student* head;
};

#endif 
