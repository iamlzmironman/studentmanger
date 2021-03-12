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

		cout << "\n***************学生信息系统***************\n" << endl;
		cout << "\t1. 创建学生信息" << endl;
		cout << "\t2. 添加学生信息" << endl;
		cout << "\t3. 删除学生信息" << endl;
		cout << "\t4. 修改学生信息" << endl;
		cout << "\t5. 显示全部学生" << endl;
		cout << "\t6. 查询学生信息" << endl;
		cout << "\t7. 保存文件" << endl;
		cout << "\t8. 读入文件" << endl;
		cout << "\t9. 口令修改" << endl;
		cout << "\t10.退出" << endl;

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
		cout << "打开文件失败" << endl;
		exit(0);
	}

	string password;
	cout << "\n***************学生信息系统***************\n" << endl;
	cout << "\t请输入密码口令" << endl;

	string trupassword;
	int i;
	int flag = 0;
	in >> trupassword;
	for (i = 0; i < 3; i++)
	{
		cout << "还有" << 3 - i << "次机会输入密码" << endl;
		cin >> password;
		if (password == trupassword)
		{
			cout << "登录成功" << endl;
			break;
		}
		else
		{
			cout << "密码输入有误!" << endl;

			flag++;
		}
	}
	if (flag == 3)
	{
		cout << "登录失败" << endl;
		exit(0);
	}
	else
		return;
}