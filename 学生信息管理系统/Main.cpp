// Main.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include "student.h"
#include "subscriber.h"
#include <fstream>
#include <stdlib.h>
#include<Windows.h>
using namespace std;

void begin();

int main()
{
	int ch;
	subscriber *mysub = new subscriber;
	int i = 0;
	while (1)
	{
		if (i == 0)
		{
			begin();
			i++;
		}

		cout << "\n***************ѧ����Ϣϵͳ***************\n" << endl;
		cout << "\t1. ����ѧ����Ϣ" << endl;
		cout << "\t2. ���ѧ����Ϣ" << endl;
		cout << "\t3. ɾ��ѧ����Ϣ" << endl;
		cout << "\t4. �޸�ѧ����Ϣ" << endl;
		cout << "\t5. ��ʾȫ��ѧ��" << endl;
		cout << "\t6. ��ѯѧ����Ϣ" << endl;
		cout << "\t7. �����ļ�" << endl;
		cout << "\t8. �����ļ�" << endl;
		cout << "\t9. �����޸�" << endl;
		cout << "\t10.�˳�" << endl;

		cout << "\nPlease Enter Your Choice: ";
		fflush(stdin);
		cin >> ch;

		switch (ch)
		{
		case 1:
			mysub->create();
			break;
		case 2:
			mysub->insert();
			break;
		case 3:
			mysub->del();
			break;
		case 4:
			mysub->modify();
			break;
		case 5:
			mysub->print();
			break;
		case 6:
			mysub->search();
			break;
		case 7:
			mysub->savef();
			break;
		case 8:
			mysub->loadf();
			break;
		case 9:
			mysub->sys();
			break;
		case 10:
			break;
		default:
			cout << "\nPlease Enter Choice between 1 and 10." << endl;
			break;
		}
		if (ch == 10)
			break;
	}

	delete mysub;
	mysub = NULL;
	system("pause");
	return 0;
}

void  begin()
{

	ifstream in("password.txt");
	if (in.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		exit(0);
	}

	string password;
	cout << "\n***************ѧ����Ϣϵͳ***************\n" << endl;
	cout << "\t�������������" << endl;

	string trupassword;
	int i;
	int flag = 0;
	in >> trupassword;
	for (i = 0; i < 3; i++)
	{
		cout << "����" << 3 - i << "�λ�����������" << endl;
		cin >> password;
		if (password == trupassword)
		{
			cout << "��¼�ɹ�" << endl;
			break;
		}
		else
		{
			cout << "������������!" << endl;

			flag++;
		}
	}
	if (flag == 3)
	{
		cout << "��¼ʧ��" << endl;
		exit(0);
	}
	else
		return;
}