// subscriber.cpp: implementation of the subscriber class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "student.h"
#include "subscriber.h"
#include <string>
#include <fstream>
using namespace std;

const string strfname = "st.dat";									//文件名称

/*..创建链表..*/
void subscriber::create()
{
	if (head != NULL)
	{
		cout << "已有信息表，请选择添加学生信息" << endl;
		return;
	}
	student *p1, *p2, *p3;
	int i;
	int num_node;
	cout << "输入创建节点数: ";
	fflush(stdin);
	cin >> num_node;
	deleteall();  //创建新的前先把已有的全部删除，防止内存泄露
	p1 = p2 = new student;  //这里创建了一个节点
	cout << "请输入姓名，学号，性别，班级，寝室，手机号，生源省份,入学年份。中间用空格隔开: " << endl;
	fflush(stdin);
	cin >> *p1;
	while (p1->num <= 0)
	{
		cout << "学生学号必须大于零，请重新输入!" << endl;
		cin >> *p1;
	}
	head = p1;
	p3 = head;
	for (i = 1; i < num_node; i++)
	{
		p3 = head;
		p2 = new student;
		cin >> *p2;
		while (p2->num <= 0)
		{
			cout << "学生学号必须大于零，请重新输入!" << endl;
			cin >> *p2;
		}
		while (p3)
		{
			if (p3->num == p2->num)
			{
				cout << "已有此学号，请重新输入" << endl;
				cin >> *p2;
				while (p2->num <= 0)
				{
					cout << "学生学号必须大于零，请重新输入!" << endl;
					cin >> *p2;
				}
				p3 = head;
			}
			else
				p3 = p3->next;
		}

		p1->next = p2;
		p1 = p2;
	}
	p1->next = NULL;
	cout << "创建成功" << endl;
}

/*插入信息*/
void subscriber::insert()
{
	student *p1, *p2, *p3;
	p3 = head;
	if (head == NULL) {
		cout << "不存在原有信息，请创建" << endl;
		return;
	}
	else {
		p1 = head;
		while (p1->next != NULL)
			p1 = p1->next;
		p2 = new student;
		cout << "请输入姓名，学号，性别，班级，寝室，手机号，生源省份，入学年份。中间用空格隔开: " << endl;
		fflush(stdin);
		cin >> *p2;
		while (p2->num <= 0)
		{
			cout << "学生学号必须大于零，请重新输入!" << endl;
			cin >> *p2;
		}

		p3 = head;
		while (p3)
		{
			if (p3->num == p2->num)
			{
				cout << "已有此学号，请重新输入" << endl;
				cin >> *p2;
				while (p2->num <= 0)
				{
					cout << "学生学号必须大于零，请重新输入!" << endl;
					cin >> *p2;
				}
				p3 = head;
			}
			else
				p3 = p3->next;
		}

		p1->next = p2;
		p2->next = NULL;
	}
	cout << "插入成功" << endl;
	int ch;
	while (1)
	{

		cout << "是否继续创建" << endl;
		cout << "1.yes" << endl;
		cout << "2.no" << endl;
		cin >> ch;
		if (ch == 2)break;
		if (ch == 1)
		{
			p2 = new student;
			cout << "请输入姓名，学号，性别，班级，寝室，手机号，生源省份，入学年份。中间用空格隔开: " << endl;
			fflush(stdin);
			cin >> *p2;
			while (p2->num <= 0)
			{
				cout << "学生学号必须大于零，请重新输入!" << endl;
				cin >> *p2;
			}

			p3 = head;
			while (p3)
			{
				if (p3->num == p2->num)
				{
					cout << "已有此学号，请重新输入" << endl;
					cin >> *p2;
					while (p2->num <= 0)
					{
						cout << "学生学号必须大于零，请重新输入!" << endl;
						cin >> *p2;
					}

					p3 = head;
				}
				else
					p3 = p3->next;
			}
			while (p1->next != NULL)
				p1 = p1->next;
			p1->next = p2;
			p2->next = NULL;
			cout << "插入成功" << endl;
		}
	}
}
/*删除信息*/
void subscriber::del()
{
	student *p1, *p2;
	int flag = 0;
	p1 = p2 = head;
	int studentterm;
	int studentnum;
	string studentname;
	if (head == NULL)
	{
		cout << "没有信息,请创建链表" << endl;
		++flag;
		return;
	}
	int ch;
	cout << "\t1.以学号查找" << endl;
	cout << "\t2.以姓名查找" << endl;
	cout << "\t3.以入学年份查找" << endl;
	cout << "\t请选择查找方式" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "请输入学号" << endl;
		cin >> studentnum;
		if (head->num == studentnum)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "删除成功" << endl;
			++flag;

		}
		else
		{
			for (p1 = head; p1->next; p1 = p1->next)
			{
				p2 = p1->next;
				if (p2->num == studentnum)
				{
					p1->next = p2->next;
					delete p2;
					cout << "删除成功" << endl;
					++flag;
				}
			}
		}
		if (flag == 0)
		{
			cout << "未找到相关信息学生" << endl;
		}break;
	case 2:
		cout << "请输入姓名" << endl;
		cin >> studentname;
		if (head->name == studentname)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "删除成功" << endl;
			++flag;

		}
		else
		{
			for (p1 = head; p1->next; p1 = p1->next)
			{
				p2 = p1->next;
				if (p2->name == studentname)
				{
					p1->next = p2->next;
					delete p2;
					cout << "删除成功" << endl;
					++flag;
				}
			}
		}
		if (flag == 0)
		{
			cout << "未找到相关信息学生" << endl;
		}break;
	case 3:
		cout << "请输入入学年份" << endl;
		cin >> studentterm;
		if (head->term <= studentterm)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "删除成功" << endl;
			++flag;

		}
		else
		{
			for (int i = 0; i < subscriber::NumOfLIst(); i++)
			{
				for (p1 = head; p1->next; p1 = p1->next)
				{
					p2 = p1->next;
					if (p2->term <= studentterm)
					{
						p1->next = p2->next;
						delete p2;
						cout << "删除成功" << endl;
						++flag;
						break;
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "未找到相关信息学生" << endl;
		}break;
	}
}

//修改
void subscriber::modify()
{
	student *p1, *p2, *p3, *p4;
	p1 = head;
	int n = 0;
	int studentnum;
	if (head == NULL)
	{
		cout << "没有信息,请创建链表" << endl;

		return;
	}
	cout << "输入想要修改的学生学号" << endl;
	cin >> studentnum;
	while (p1)
	{
		if (p1->num == studentnum)n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
		cout << "未找到相关信息学生" << endl;
		return;
	}
	p2 = new student;
	p3 = new student;
	int ch;
	cout << "\t1.请输入要修改的学号" << endl;
	cout << "\t2.请输入要修改的姓名" << endl;
	cout << "\t3.请输入要修改的性别" << endl;
	cout << "\t4.请输入要修改的班级" << endl;
	cout << "\t5.请输入要修改的寝室" << endl;
	cout << "\t6.请输入要修改的手机号" << endl;
	cout << "\t7.请输入要修改的生源省份" << endl;
	cout << "\t8.请输入要修改的入学年份" << endl;
	cin >> ch;
	p2 = head;
	while (p2)
	{
		if (p2->num == studentnum)break;
		else p2 = p2->next;
	}
	switch (ch)
	{
	case 1:
		cout << "输入新学号" << endl;
		cin >> p3->num;
		while (p3->num <= 0)
		{
			cout << "学生学号必须大于零，请重新输入!" << endl;
			cin >> p3->num;
		}

		p4 = head;
		while (p4)
		{
			if (p3->num == studentnum)break;
			if (p4->num == p3->num)
			{
				cout << "已有此学号，请重新输入" << endl;
				cin >> p3->num;
				while (p3->num <= 0)
				{
					cout << "学生学号必须大于零，请重新输入!" << endl;
					cin >> p3->num;
				}
				p4 = head;
			}
			else p4 = p4->next;
		}
		p2->num = p3->num;
		delete p3;
		cout << "修改成功" << endl; break;
	case 2:
		cout << "输入新姓名" << endl;
		cin >> p2->name;
		cout << "修改成功" << endl; break;
	case 3:
		cout << "输入新性别" << endl;
		cin >> p2->sex;
		cout << "修改成功" << endl; break;
	case 4:
		cout << "输入新班级" << endl;
		cin >> p2->classnum;
		cout << "修改成功" << endl; break;
	case 5:
		cout << "输入新寝室" << endl;
		cin >> p2->roomnum;
		cout << "修改成功" << endl; break;
	case 6:
		cout << "输入新手机号" << endl;
		cin >> p2->phonenum;
		cout << "修改成功" << endl; break;
	case 7:
		cout << "输入新生源省份" << endl;
		cin >> p2->province;
		cout << "修改成功" << endl; break;
	case 8:
		cout << "输入入学年份" << endl;
		cin >> p2->term;
		cout << "修改成功" << endl; break;
	}
}
//输出全部信息
void subscriber::print()
{
	student *p;
	p = head;
	if (head == NULL)     //链表为空；
	{
		cout << "文件为空!" << endl;
		return;
	}
	else
		cout << "输出所有学生信息:" << endl;
	while (p != 0)
	{
		cout << "姓名:" << p->name << "学号:" << p->num << "性别：" << p->sex << "班级:" << p->classnum << "寝室:" << p->roomnum << "手机号:" << p->phonenum << "生源省份:" << p->province << "入学年份" << p->term << endl;
		p = p->next;
	}
}

//查找
void subscriber::search()
{
	student *p1;
	p1 = head;
	int ch;
	int flag = 0;
	string stuname;
	int stunum;
	int roomnumble;
	string proname;
	if (head == NULL)
	{
		cout << "没有信息" << endl;
		return;
	}
	cout << "\t1. 以姓名查找" << endl;
	cout << "\t2. 以学号查找" << endl;
	cout << "\t3. 以宿舍号查找" << endl;
	cout << "\t4. 以生源省份查找" << endl;
	cout << "\t请选择查找方式" << endl;

	cin >> ch;
	switch (ch)
	{
	case 1:

		cout << "请输入要查找的学生姓名" << endl;
		cin >> stuname;
		while (p1)
		{
			if (p1->name == stuname)
			{
				cout << "姓名:" << p1->name << "学号:" << p1->num << "性别：" << p1->sex << "班级:" << p1->classnum << "寝室:" << p1->roomnum << "手机号:" << p1->phonenum << "生源省份:" << p1->province << "入学年份" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "无此姓名学生信息" << endl;
		break;
	case 2:

		cout << "请输入要查找的学生学号" << endl;
		cin >> stunum;
		while (p1)
		{
			if (p1->num == stunum)
			{
				cout << "姓名:" << p1->name << "学号:" << p1->num << "性别：" << p1->sex << "班级:" << p1->classnum << "寝室:" << p1->roomnum << "手机号:" << p1->phonenum << "生源省份:" << p1->province << "入学年份" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "无此学号学生信息" << endl;
		break;
	case 3:

		cout << "请输入要查找的学生寝室号" << endl;
		cin >> roomnumble;
		while (p1)
		{
			if (p1->roomnum == roomnumble)
			{
				cout << "姓名:" << p1->name << "学号:" << p1->num << "性别：" << p1->sex << "班级:" << p1->classnum << "寝室:" << p1->roomnum << "手机号:" << p1->phonenum << "生源省份:" << p1->province << "入学年份" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "无此寝室号学生信息" << endl;
		break;
	case 4:

		cout << "请输入要查找的学生省份" << endl;
		cin >> proname;
		while (p1)
		{
			if (p1->province == proname)
			{
				cout << "姓名:" << p1->name << "学号:" << p1->num << "性别：" << p1->sex << "班级:" << p1->classnum << "寝室:" << p1->roomnum << "手机号:" << p1->phonenum << "生源省份:" << p1->province << "入学年份" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "无此省份学生信息" << endl;
		break;

	}

}
//保存
void subscriber::savef()
{
	if (head == NULL) {
		cout << "不存在原有信息，请创建" << endl;
		return;
	}
	student *p;
	p = head;
	ofstream outf("st.dat");
	if (outf.fail())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	int n = 0;
	n = NumOfLIst();
	outf << n << endl;
	while (p)
	{
		outf << *p << endl;
		p = p->next;
	}
	outf.close();
}
//读入文件
void subscriber::loadf()
{
	ifstream inf("st.dat");
	if (inf.fail())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	int n;
	inf >> n;
	if (inf.eof())
	{
		cout << "文件无原信息" << endl;
		return;
	}
	student *p1, *p2;
	int i;

	p1 = p2 = new student;//这里创建了一个节点
	head = p1;


	inf >> *p1;

	for (i = 1; i < n; i++)
	{
		p1 = new student;
		inf >> *p1;
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;

	inf.close();
}
//密码修改
void subscriber::sys()
{
	ifstream in("password.txt");

	if (in.fail())
	{
		cout << "打开文件失败" << endl;
		return;
	}

	string trupassword;
	string password;

	int i;
	int j;
	int flag = 0, n = 0;
	in >> trupassword;
	cout << "\n**********密码修改系统**********\n" << endl;
	cout << "请输入原密码" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "还有" << 3 - i << "次机会输入密码" << endl;
		cin >> password;
		if (password == trupassword)
		{
			ofstream out("password.txt");
			if (in.fail())
			{
				cout << "打开文件失败" << endl;
				return;
			}
			cout << "成功登录修改系统" << endl;
			for (j = 0; j < 3; j++)
			{
				cout << "请输入新密码" << endl;
				cin >> trupassword;
				cout << "请确认新密码" << endl;
				cin >> password;
				if (password == trupassword)
				{
					out << trupassword;
					cout << "修改密码成功" << endl;
					out.close();
					in.close();
					return;
				}
				else
				{
					cout << "两次密码不一致，请重新输入" << endl;
					n++;
				}
			}
			if (n == 3)
			{
				cout << "修改失败" << endl;
				out.close();
				in.close();
				return;
			}
		}
		else
		{
			cout << "密码输入有误!" << endl;
			cout << "请重新输入" << endl;
			flag++;
		}
	}
	if (flag == 3)
	{
		cout << "登录修改系统失败" << endl;

		in.close();
		return;
	}

}


//链表节点数
int subscriber::NumOfLIst()
{
	int n = 0;
	student *p;
	p = head;
	while (p != 0)
	{
		n++;
		p = p->next;
	}
	return n;
}

//删除全部
void subscriber::deleteall()
{
	student *p1, *p2;
	p1 = head;
	while (p1)
	{
		p2 = p1;
		p1 = p1->next;
		delete p2;
	}
}
