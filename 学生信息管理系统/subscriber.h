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
	void create();		//����ѧ����Ϣ����		
	void insert();		//����ѧ����Ϣ
	void del();			//ɾ��ѧ����Ϣ
	void modify();		//�޸�ѧ����Ϣ
	void print();		//��ʾȫ��ѧ����Ϣ
	void search();		//����ѧ����Ϣ
	void savef();		//����ѧ����Ϣ���ļ�
	void loadf();		//���ļ��ж�ȡѧ����Ϣ
	void sys();	        //�����޸�

private:
	int NumOfLIst();	//��������ڵ���
	void deleteall();	//ɾ��ȫ��
private:
	student* head;
};

#endif 
