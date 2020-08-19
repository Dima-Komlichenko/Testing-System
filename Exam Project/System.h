#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<list>
#include"Tester.h"
#include"Admin.h"
#include"Test.h"

using namespace std;


class System
{
	list<Tester> tester;
	Admin admin;
	Categories categories;

public:
	void menu();
	void methodTester(Tester& t);	// ����� ������ ���� ����������, ���� ��� - ����
	void methodAdmin();		// ����� ����� ������������ ����

	//for Admin
	void addTester();
	void delTester();
	void redactTester(); //������������� ������������
	void SignInAdmin();
	void checkTestCategory();  // Need Test						//�������� ����������� �� ����������
	void checkTestTester();	   // Need Test
	void addPredmet();
	void addTheme();
	void addTest();
	
	//for Tester
	void DoTest(Tester& t);
	void SignInTester(string log);
	void LogInTester();
	void RegistrationTester(string log);

	// for System
	void importTestsInFile();
	void exportTestInProgram();
	void importUsers();
	void exportUsers();
};


void System::menu()
{
	system("cls");
	cout << "��� ������ � �������?\n"
		<< "1 - �����\n"
		<< "2 - �����������\n"
		<< "3 - �����\n";
	int who;
	cin >> who;
	while (who < 1 || who > 3) cin >> who;
	switch (who)
	{
	case 1:
		SignInAdmin();

		break;
	case 2:
		LogInTester();
		break;
	case 3:
		
		return;
	}
}

void System::SignInAdmin()
{
	if (admin.getLogin() == "-")
	{
		string st;
		cout << "�����������: \n";
		admin.setLogin();
		admin.setPassword();
		admin.setName();
		cout << "�� ������������������\n";
		system("pause");
		system("cls");
		//��� ����� ��������� ��� ������ � ����(������ - �����������)
	}
	else
	{
		string log;
		string pass;
		bool a = false;
		do
		{
			cout << "������� ��� �����: ";
			cin >> log;
			cout << "������� ��� ������: ";
			cin >> pass;
			if (log != admin.getLogin() || pass != admin.getPassword())
			{
				cout << "�� ����� �������� ����� ��� ������";
			}
			else
				a = true;

		} while (a == 0);
		//��� �� ����� � ������
	}
	methodAdmin();
}

void System::methodAdmin()
{
	system("cls");
	cout << "��� �� ������ �������?\n"
		<< "�������� ����� - 1\n"
		<< "�������� ������ - 2\n"
		<< "������� ������������ - 3\n"
		<< "������� ������������ - 4\n"
		<< "�������������� ������������ - 5\n"
		<< "���������� ���������� ������������ �� ���������� - 6\n"
		<< "���������� ��������� ������������  ������������ - 7\n"
		<< "�������� ������� - 8\n"
		<< "�������� ���� - 9\n"
		<< "�������� ���� - 10\n"//��� ��� ����� ���������� ���������� � ������������ �������
		<< "����� - 11\n";
	int num;
	cin >> num;
	while (num < 1 || num > 13)	cin >> num;
	switch (num)
	{
	case 1:		admin.setLogin();		break; //
	case 2:		admin.setPassword();	break; //
	case 3:		addTester();			break; //
	case 4:		delTester();			break; //
	case 5:		redactTester();			break; //
	case 6:		checkTestCategory();	break; // Need Test
	case 7:		checkTestTester();		break; // Need Test
	case 8:		addPredmet();			break;
	case 9:		addTheme();				break;
	case 10:	addTest();				break;
	case 11:	system("cls");  menu();	break;
	}

	system("pause");
	system("cls");
	menu();

}

void System::SignInTester(string log)
{
	cout << "������� ������:\n";
	string pas;
	cin >> pas;
	for (auto& x : tester)
	{
		if (x.getLogin() == log && x.getPassword() == pas)
		{
			methodTester(x);
		}
	}
}

void System::RegistrationTester(string log)
{
	cout << "������� ������:\n";
	string pas;
	cin >> pas;
	cout << "������� ���:\n";
	string name;
	cin >> name;
	cout << "������� �����:\n";
	string address;
	cin >> address;
	cout << "������� ����� ��������:\n";
	string phone;
	cin >> phone;
	Tester x(log, pas, name, address, phone);
	tester.push_back(x);
	auto it = tester.begin();
	for (auto& x : tester)
	{
		if (it == tester.end())
		{
			methodTester(x);
		}
		it++;
	}
}

void System::LogInTester()
{
	cout << "������������������ ��� �����?(1, 2)\n";
	int in;
	cin >> in;
	while (in < 1 || in > 2) cin >> in;
	while (in == 1)
	{
		cout << "������� �����:\n";
		string log;
		cin >> log;
		bool check = false;
		for (auto x : tester)
		{
			if (x.getLogin() == log)
			{
				check = true;
			}
		}
		if (check == true)
		{
			cout << "����� ����� ��� ����������\n"
				<< "������������������ � ������ ������� - '1'\n"
				<< "����� � ���� ������� - '2'\n";
			cin >> in;
			if (in == 1)	continue;

			else if (in == 2)
			{
				SignInTester(log);
			}
		}
		else
		{
			RegistrationTester(log);
			in = 0;
		}
	}
	if (in == 2)
	{
		cout << "������� �����:\n";
		string log;
		cin >> log;
		SignInTester(log);
	}

}

void System::methodTester(Tester& t)
{
	system("cls");
	cout << "��� �� ������ �������?\n"
		<< "����� ����� ���� - '1'\n"
		<< "���������� ���������� ���������� ������������ - '2'\n"
		<< "����� - '3'\n";
	int num;
	cin >> num;
	while (num < 1 || num > 3) cin >> num;
	switch (num)
	{	
	case 1:		DoTest(t);			break;
	case 2:		t.checkStat();		break;
	case 3:		menu();				break;
	}

	system("pause");
	system("cls");
	menu();
}
void  System::addTester()
{
	cout << "������� �����:\n";
	string log;
	cin >> log;
	cout << "������� ������:\n";
	string pas;
	cin >> pas;
	cout << "������� ���:\n";
	string name;
	cin >> name;
	cout << "������� �������� �����:\n";
	string home;
	cin >> home;
	cout << "������� ����� ��������:\n";
	string phone;
	cin >> phone;
	Tester _new(log, pas, name, home, phone);
	tester.push_back(_new);
}

void System::delTester()
{
	cout << "������� ����� ������������ �������� ������ �������:\n";
	string log;
	cin >> log;
	list<Tester>::iterator it;
	it = tester.begin();

	for (auto& x : tester)
	{
		if (x.getLogin() == log)
		{
			tester.erase(it);
			break;
		}
		it++;
	}
}

void System::redactTester()
{
	cout << "������� ����� ������������ �������� ������ �������������:\n";
	string log;
	cin >> log;

	list<Tester>::iterator it;
	it = tester.begin();

	for (auto& x : tester)
	{
		if (x.getLogin() == log)
			//////////////////////////////////
		{
			int num = 0;
			while (num != 6)
			{
				cout << "��� �� ������ �������������\n"
					<< "����� - '1'\n"
					<< "������ - '2'\n"
					<< "��� - '3'\n"
					<< "�������� ����� - '4'\n"
					<< "����� �������� - '5'\n"
					<< "������ - '6'\n";
				cin >> num;
				while (num < 1 || num > 6) 	cin >> num;
				switch (num)
				{
				case 1:
					x.setLogin();
					break;
				case 2:
					x.setPassword();
					break;
				case 3:
					x.setName();
					break;
				case 4:
					x.setHome_Address();
					break;
				case 5:
					x.setPhone();
					break;
				case 6:
					break;
				}
			}
			break;
		}
		////////////////////////////////////
		it++;
	}
	system("pause");
	system("cls");
	menu();
}

void System::checkTestCategory()
{
	cout << "����� ���������� ������ �� ������ ����������?\n"
		<< "���������� - '1'\n"
		<< "������ - '2'\n";
	int num;
	cin >> num;
	int i = 0; // ����� ������
	while (num < 1 || num > 2) cin >> num;
	switch (num)
	{
	case 1:

		// ������ ���� ���������� ��  ������� ����������
		for (auto& x : tester)
		{
			cout << x.getName() << endl;
			//		for (auto& c : maths)
			{
				//			cout << c.getQuestion() << setw(5) << x.getMarkMaths(i);
				i++;
			}
		}
		break;
	case 2:
		// ������ ���� ���������� �� ������� �������
		for (auto& x : tester)
		{
			cout << x.getName() << endl;
			//			for (auto& c : physics)
			{
				//				cout << c.getQuestion() << setw(5) << x.getMarkPhysics(i);
				i++;
			}
		}
		break;
	}
	system("pause");
	system("cls");
	methodAdmin();
}

void System::checkTestTester()
{
	cout << "������� ����� ������������ �������� ������ ���������� ����������: ";
	string log;
	cin >> log;
	int i = 0;
	for (auto& x : tester)
	{
		if (x.getLogin() == log)
		{
			cout << "����������:\n";
			//			for (auto& c : maths)
			{
				//				cout << c.getQuestion() << setw(5) << x.getMarkMaths(i);
				i++;
			}
			cout << "������:\n";
			//			for (auto& c : physics)
			{
				//				cout << c.getQuestion() << setw(5) << x.getMarkPhysics(i);
				i++;
			}
		}
	}
	system("pause");
	system("cls");
	methodAdmin();
}

void System::addPredmet()
{
	cout << "������� �������� ��������� ������� ������ ��������:\n";
	string name;
	cin >> name;
	Predmet _new(name);
	categories.addPredmet(_new);
}

void System::addTheme()
{
	cout << "������� �������� �������� � �������� ������ �������� ����:\n";
	string predmetName;
	cin >> predmetName;

	list<Predmet> predmets = categories.getPredmets();
	for (auto& x : predmets)
	{
		if (predmetName == x.getName())
		{
			cout << "������� �������� ���� ������� ������ ������:\n";
			string themeName;
			cin >> themeName;
			Theme _new(themeName);
			categories.addTheme(predmetName, &_new);
		}
	}
}

void System::addTest()
{
	cout << "������� �������� �������� � �������� ������ �������� ����:\n";
	string predmetName;
	cin >> predmetName;

	cout << "������� �������� ���� � ������� ������ �������� ����:\n";
	string themeName;
	cin >> themeName;

	list<Predmet> predmets = categories.getPredmets();
	for (auto& x : predmets)
	{
		if (predmetName == x.getName())
		{
			list<Theme> thems = x.getThemes();
			for (auto& c : thems)
			{
				if (themeName == c.getName())
				{
					Test newTest;
					//c.addTest(&newTest);
					categories.addTest(predmetName, themeName, &newTest);

				}
			}

		}
	}
}

void System::importTestsInFile()
{
	ofstream ofs("test.txt");
	ofs << categories;
	ofs.close();
}

void System::exportTestInProgram()
{
	ifstream ifs("test.txt");
	ifs >> categories;
	ifs.close();
}

void System::DoTest(Tester& t)
{
	system("cls");

	list<Predmet> predmets = categories.getPredmets();
	cout << "�� ������ �������� �� ������ ����� ����?\n";
	int i = 1;
	for (auto x : predmets)
	{
		cout << x.getName() << " -'" << i << "'\n";
		i++;
	}
	int num;
	cin >> num;
	while (num < 1 || num > i) cin >> num;
	i = 1;
	for (auto& x : predmets)
	{
		if (i == num)
		{
			cout << "�� ����� ���� �� ������ ����� ����?\n";
			i = 1;
			list<Theme> themes = x.getThemes();
			for (auto& c : themes)
			{
				cout << c.getName() << "-'" << i << "'\n";
				i++;
			}
			cin >> num;
			while (num < 1 || num > i) cin >> num;
			i = 1;
			for (auto& c : themes)
			{
				if (i == num)
				{
					list<Test> tests = c.getTests();
					int mark = 0;
					for (auto& v : tests)
					{
						mark += v.work();
					}
					string name = x.getName() + " " + c.getName();
					pair<string, int> temp(name, mark);
					cout << temp.first << "-" << temp.second;
					t.addMark(temp);

					i = 0;
				}
			}
		}
	}

	system("pause");
	system("cls");
	methodTester(t);
}

void System::importUsers() // in File
{
	ofstream ofs("Users.txt");
	ofs << admin;
	for (auto& x : tester)
		ofs << x;
	ofs.close();
}

void System::exportUsers()
{
	ifstream in("Users.txt");
	if (in >> admin)	{}
	Tester temp;
	string x;
	while (!in.eof())
	{
		in >> temp;
		tester.push_back(temp);
	}

}