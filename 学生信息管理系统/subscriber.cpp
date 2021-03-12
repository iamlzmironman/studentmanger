// subscriber.cpp: implementation of the subscriber class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "student.h"
#include "subscriber.h"
#include <string>
#include <fstream>
using namespace std;

const string strfname = "st.dat";									//�ļ�����

/*..��������..*/
void subscriber::create()
{
	if (head != NULL)
	{
		cout << "������Ϣ����ѡ�����ѧ����Ϣ" << endl;
		return;
	}
	student *p1, *p2, *p3;
	int i;
	int num_node;
	cout << "���봴���ڵ���: ";
	fflush(stdin);
	cin >> num_node;
	deleteall();  //�����µ�ǰ�Ȱ����е�ȫ��ɾ������ֹ�ڴ�й¶
	p1 = p2 = new student;  //���ﴴ����һ���ڵ�
	cout << "������������ѧ�ţ��Ա𣬰༶�����ң��ֻ��ţ���Դʡ��,��ѧ��ݡ��м��ÿո����: " << endl;
	fflush(stdin);
	cin >> *p1;
	while (p1->num <= 0)
	{
		cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
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
			cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
			cin >> *p2;
		}
		while (p3)
		{
			if (p3->num == p2->num)
			{
				cout << "���д�ѧ�ţ�����������" << endl;
				cin >> *p2;
				while (p2->num <= 0)
				{
					cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
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
	cout << "�����ɹ�" << endl;
}

/*������Ϣ*/
void subscriber::insert()
{
	student *p1, *p2, *p3;
	p3 = head;
	if (head == NULL) {
		cout << "������ԭ����Ϣ���봴��" << endl;
		return;
	}
	else {
		p1 = head;
		while (p1->next != NULL)
			p1 = p1->next;
		p2 = new student;
		cout << "������������ѧ�ţ��Ա𣬰༶�����ң��ֻ��ţ���Դʡ�ݣ���ѧ��ݡ��м��ÿո����: " << endl;
		fflush(stdin);
		cin >> *p2;
		while (p2->num <= 0)
		{
			cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
			cin >> *p2;
		}

		p3 = head;
		while (p3)
		{
			if (p3->num == p2->num)
			{
				cout << "���д�ѧ�ţ�����������" << endl;
				cin >> *p2;
				while (p2->num <= 0)
				{
					cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
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
	cout << "����ɹ�" << endl;
	int ch;
	while (1)
	{

		cout << "�Ƿ��������" << endl;
		cout << "1.yes" << endl;
		cout << "2.no" << endl;
		cin >> ch;
		if (ch == 2)break;
		if (ch == 1)
		{
			p2 = new student;
			cout << "������������ѧ�ţ��Ա𣬰༶�����ң��ֻ��ţ���Դʡ�ݣ���ѧ��ݡ��м��ÿո����: " << endl;
			fflush(stdin);
			cin >> *p2;
			while (p2->num <= 0)
			{
				cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
				cin >> *p2;
			}

			p3 = head;
			while (p3)
			{
				if (p3->num == p2->num)
				{
					cout << "���д�ѧ�ţ�����������" << endl;
					cin >> *p2;
					while (p2->num <= 0)
					{
						cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
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
			cout << "����ɹ�" << endl;
		}
	}
}
/*ɾ����Ϣ*/
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
		cout << "û����Ϣ,�봴������" << endl;
		++flag;
		return;
	}
	int ch;
	cout << "\t1.��ѧ�Ų���" << endl;
	cout << "\t2.����������" << endl;
	cout << "\t3.����ѧ��ݲ���" << endl;
	cout << "\t��ѡ����ҷ�ʽ" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "������ѧ��" << endl;
		cin >> studentnum;
		if (head->num == studentnum)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "ɾ���ɹ�" << endl;
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
					cout << "ɾ���ɹ�" << endl;
					++flag;
				}
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ������Ϣѧ��" << endl;
		}break;
	case 2:
		cout << "����������" << endl;
		cin >> studentname;
		if (head->name == studentname)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "ɾ���ɹ�" << endl;
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
					cout << "ɾ���ɹ�" << endl;
					++flag;
				}
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ������Ϣѧ��" << endl;
		}break;
	case 3:
		cout << "��������ѧ���" << endl;
		cin >> studentterm;
		if (head->term <= studentterm)
		{
			p2 = head;
			head = head->next;
			delete p2;
			cout << "ɾ���ɹ�" << endl;
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
						cout << "ɾ���ɹ�" << endl;
						++flag;
						break;
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ������Ϣѧ��" << endl;
		}break;
	}
}

//�޸�
void subscriber::modify()
{
	student *p1, *p2, *p3, *p4;
	p1 = head;
	int n = 0;
	int studentnum;
	if (head == NULL)
	{
		cout << "û����Ϣ,�봴������" << endl;

		return;
	}
	cout << "������Ҫ�޸ĵ�ѧ��ѧ��" << endl;
	cin >> studentnum;
	while (p1)
	{
		if (p1->num == studentnum)n++;
		p1 = p1->next;
	}
	if (n == 0)
	{
		cout << "δ�ҵ������Ϣѧ��" << endl;
		return;
	}
	p2 = new student;
	p3 = new student;
	int ch;
	cout << "\t1.������Ҫ�޸ĵ�ѧ��" << endl;
	cout << "\t2.������Ҫ�޸ĵ�����" << endl;
	cout << "\t3.������Ҫ�޸ĵ��Ա�" << endl;
	cout << "\t4.������Ҫ�޸ĵİ༶" << endl;
	cout << "\t5.������Ҫ�޸ĵ�����" << endl;
	cout << "\t6.������Ҫ�޸ĵ��ֻ���" << endl;
	cout << "\t7.������Ҫ�޸ĵ���Դʡ��" << endl;
	cout << "\t8.������Ҫ�޸ĵ���ѧ���" << endl;
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
		cout << "������ѧ��" << endl;
		cin >> p3->num;
		while (p3->num <= 0)
		{
			cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
			cin >> p3->num;
		}

		p4 = head;
		while (p4)
		{
			if (p3->num == studentnum)break;
			if (p4->num == p3->num)
			{
				cout << "���д�ѧ�ţ�����������" << endl;
				cin >> p3->num;
				while (p3->num <= 0)
				{
					cout << "ѧ��ѧ�ű�������㣬����������!" << endl;
					cin >> p3->num;
				}
				p4 = head;
			}
			else p4 = p4->next;
		}
		p2->num = p3->num;
		delete p3;
		cout << "�޸ĳɹ�" << endl; break;
	case 2:
		cout << "����������" << endl;
		cin >> p2->name;
		cout << "�޸ĳɹ�" << endl; break;
	case 3:
		cout << "�������Ա�" << endl;
		cin >> p2->sex;
		cout << "�޸ĳɹ�" << endl; break;
	case 4:
		cout << "�����°༶" << endl;
		cin >> p2->classnum;
		cout << "�޸ĳɹ�" << endl; break;
	case 5:
		cout << "����������" << endl;
		cin >> p2->roomnum;
		cout << "�޸ĳɹ�" << endl; break;
	case 6:
		cout << "�������ֻ���" << endl;
		cin >> p2->phonenum;
		cout << "�޸ĳɹ�" << endl; break;
	case 7:
		cout << "��������Դʡ��" << endl;
		cin >> p2->province;
		cout << "�޸ĳɹ�" << endl; break;
	case 8:
		cout << "������ѧ���" << endl;
		cin >> p2->term;
		cout << "�޸ĳɹ�" << endl; break;
	}
}
//���ȫ����Ϣ
void subscriber::print()
{
	student *p;
	p = head;
	if (head == NULL)     //����Ϊ�գ�
	{
		cout << "�ļ�Ϊ��!" << endl;
		return;
	}
	else
		cout << "�������ѧ����Ϣ:" << endl;
	while (p != 0)
	{
		cout << "����:" << p->name << "ѧ��:" << p->num << "�Ա�" << p->sex << "�༶:" << p->classnum << "����:" << p->roomnum << "�ֻ���:" << p->phonenum << "��Դʡ��:" << p->province << "��ѧ���" << p->term << endl;
		p = p->next;
	}
}

//����
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
		cout << "û����Ϣ" << endl;
		return;
	}
	cout << "\t1. ����������" << endl;
	cout << "\t2. ��ѧ�Ų���" << endl;
	cout << "\t3. ������Ų���" << endl;
	cout << "\t4. ����Դʡ�ݲ���" << endl;
	cout << "\t��ѡ����ҷ�ʽ" << endl;

	cin >> ch;
	switch (ch)
	{
	case 1:

		cout << "������Ҫ���ҵ�ѧ������" << endl;
		cin >> stuname;
		while (p1)
		{
			if (p1->name == stuname)
			{
				cout << "����:" << p1->name << "ѧ��:" << p1->num << "�Ա�" << p1->sex << "�༶:" << p1->classnum << "����:" << p1->roomnum << "�ֻ���:" << p1->phonenum << "��Դʡ��:" << p1->province << "��ѧ���" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "�޴�����ѧ����Ϣ" << endl;
		break;
	case 2:

		cout << "������Ҫ���ҵ�ѧ��ѧ��" << endl;
		cin >> stunum;
		while (p1)
		{
			if (p1->num == stunum)
			{
				cout << "����:" << p1->name << "ѧ��:" << p1->num << "�Ա�" << p1->sex << "�༶:" << p1->classnum << "����:" << p1->roomnum << "�ֻ���:" << p1->phonenum << "��Դʡ��:" << p1->province << "��ѧ���" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "�޴�ѧ��ѧ����Ϣ" << endl;
		break;
	case 3:

		cout << "������Ҫ���ҵ�ѧ�����Һ�" << endl;
		cin >> roomnumble;
		while (p1)
		{
			if (p1->roomnum == roomnumble)
			{
				cout << "����:" << p1->name << "ѧ��:" << p1->num << "�Ա�" << p1->sex << "�༶:" << p1->classnum << "����:" << p1->roomnum << "�ֻ���:" << p1->phonenum << "��Դʡ��:" << p1->province << "��ѧ���" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "�޴����Һ�ѧ����Ϣ" << endl;
		break;
	case 4:

		cout << "������Ҫ���ҵ�ѧ��ʡ��" << endl;
		cin >> proname;
		while (p1)
		{
			if (p1->province == proname)
			{
				cout << "����:" << p1->name << "ѧ��:" << p1->num << "�Ա�" << p1->sex << "�༶:" << p1->classnum << "����:" << p1->roomnum << "�ֻ���:" << p1->phonenum << "��Դʡ��:" << p1->province << "��ѧ���" << p1->term << endl;
				++flag;
			}
			p1 = p1->next;
		}
		if (flag == 0)
			cout << "�޴�ʡ��ѧ����Ϣ" << endl;
		break;

	}

}
//����
void subscriber::savef()
{
	if (head == NULL) {
		cout << "������ԭ����Ϣ���봴��" << endl;
		return;
	}
	student *p;
	p = head;
	ofstream outf("st.dat");
	if (outf.fail())
	{
		cout << "���ļ�ʧ��" << endl;
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
//�����ļ�
void subscriber::loadf()
{
	ifstream inf("st.dat");
	if (inf.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	int n;
	inf >> n;
	if (inf.eof())
	{
		cout << "�ļ���ԭ��Ϣ" << endl;
		return;
	}
	student *p1, *p2;
	int i;

	p1 = p2 = new student;//���ﴴ����һ���ڵ�
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
//�����޸�
void subscriber::sys()
{
	ifstream in("password.txt");

	if (in.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	string trupassword;
	string password;

	int i;
	int j;
	int flag = 0, n = 0;
	in >> trupassword;
	cout << "\n**********�����޸�ϵͳ**********\n" << endl;
	cout << "������ԭ����" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "����" << 3 - i << "�λ�����������" << endl;
		cin >> password;
		if (password == trupassword)
		{
			ofstream out("password.txt");
			if (in.fail())
			{
				cout << "���ļ�ʧ��" << endl;
				return;
			}
			cout << "�ɹ���¼�޸�ϵͳ" << endl;
			for (j = 0; j < 3; j++)
			{
				cout << "������������" << endl;
				cin >> trupassword;
				cout << "��ȷ��������" << endl;
				cin >> password;
				if (password == trupassword)
				{
					out << trupassword;
					cout << "�޸�����ɹ�" << endl;
					out.close();
					in.close();
					return;
				}
				else
				{
					cout << "�������벻һ�£�����������" << endl;
					n++;
				}
			}
			if (n == 3)
			{
				cout << "�޸�ʧ��" << endl;
				out.close();
				in.close();
				return;
			}
		}
		else
		{
			cout << "������������!" << endl;
			cout << "����������" << endl;
			flag++;
		}
	}
	if (flag == 3)
	{
		cout << "��¼�޸�ϵͳʧ��" << endl;

		in.close();
		return;
	}

}


//����ڵ���
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

//ɾ��ȫ��
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
