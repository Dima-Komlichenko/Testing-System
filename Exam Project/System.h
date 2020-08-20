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
	list<Tester> testers;
	Admin admin;
	Categories categories;

public:
	void menu();
	void methodTester(Tester& t);
	void methodAdmin();

	
	void addTester();
	void delTester();
	void redactTester();
	void SignInAdmin();					
	void checkTestTester();
	void addPredmet();
	void addTheme();
	void addTest();

	
	void DoTest(Tester& t);
	void SignInTester(string log);
	void LogInTester();
	void RegistrationTester(string log);

	
	void importTestsInFile();
	void exportTestInProgram();
	void importUsers();
	void exportUsers();
};


void System::menu()
{
	while (true)
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
				cout << "�� ����� �������� ����� ��� ������\n";
			}
			else
				a = true;

		} while (a == 0);
		
	}
	methodAdmin();
}

void System::methodAdmin()
{
	system("cls");
	cout << "��� �� ������ �������?\n"
		<< "1 - �������� �����\n"
		<< "2 - �������� ������\n"
		<< "3 - ������� ������������ \n"
		<< "4 - ������� ������������\n"
		<< "5 - �������������� ������������\n"
		<< "6 - ���������� ��������� ������������  ������������\n"
		<< "7 - �������� �������\n"
		<< "8 - �������� ����\n"
		<< "9 - �������� ����\n"
		<< "10 - �����\n";
	int num;
	cin >> num;
	while (num < 1 || num > 10)	cin >> num;
	switch (num)
	{
	case 1:		admin.setLogin();		break;
	case 2:		admin.setPassword(); 	break;
	case 3:		addTester();			break;
	case 4:		delTester();			break;
	case 5:		redactTester();			break;
	case 6:		checkTestTester();		break;
	case 7:		addPredmet();			break;
	case 8:		addTheme();				break;
	case 9:		addTest();				break;
	case 10:	return;
	}

	system("pause");
	system("cls");
	methodAdmin();

}

void System::SignInTester(string log)
{
	cout << "������� ������:\n";
	string pas;
	cin >> pas;
	bool in = false;
	for (auto& x : testers)
	{
		if (x.getLogin() == log && x.getPassword() == pas)
		{
			methodTester(x);
			in++;
		}
	}if (in == false)
		cout << "�� ������� �����\n";
	system("pause");
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
	testers.push_back(x);
	auto it = testers.begin();
	bool in = false;
	for (auto& x : testers)
	{
		if (it == testers.end())
		{
			methodTester(x);
			in++;
			
		}
	}
	if(in == false)
		cout << "�� ������� �����\n";
	system("pause");
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
		for (auto x : testers)
		{
			if (x.getLogin() == log)
			{
				check = true;
			}
		}
		if (check == true)
		{
			cout << "����� ����� ��� ����������\n"
				<< "1 - ������������������ � ������ �������\n"
				<< "2 - ����� � ���� �������\n";
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
		<< "1 - ����� ����� ����\n"
		<< "2 - ���������� ���������� ���������� ������������\n"
		<< "3 - �����\n";
	int num;
	cin >> num;
	while (num < 1 || num > 3) cin >> num;
	switch (num)
	{
	case 1:		DoTest(t);			break;
	case 2:		t.printMark();		break;
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
	testers.push_back(_new);
}

void System::delTester()
{
	cout << "������� ����� ������������ �������� ������ �������:\n";
	string log;
	cin >> log;
	list<Tester>::iterator it;
	it = testers.begin();

	for (auto& x : testers)
	{
		if (x.getLogin() == log)
		{
			testers.erase(it);
			break;
		}
		it++;
	}
}

void System::redactTester()
{
	cout << "������� ��� ������������ �������� ������ �������������:\n";
	int name;
	int i = 1;
	for (auto& x : testers)
	{
		cout << i << " - " << x.getName() << "\n";
	}
	cin >> name;
	i = 1;
	for (auto& x : testers)
	{
		if (i == name)
		{
			cout << "��� �� ������ �������������\n"
				<< "1 - �����\n"
				<< "2 - ������\n"
				<< "3 - ���\n"
				<< "4 - �������� �����\n"
				<< "5 - ����� ��������\n"
				<< "6 - �����\n";
			int num = 0;
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
	}

	system("pause");
	system("cls");
	menu();
}

void System::checkTestTester()
{
	cout << "�������� ��� ������������, �������� ������ ���������� ���������� ������������:\n";
	int name;
	int i = 1;
	for (auto& x : testers)
	{
		cout << i << " - " << x.getName() << "\n";
		i++;
	}
	cin >> name;
	i = 1;
	for (auto& x : testers)
	{
		if(i == name)
			x.printMark();
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
	int predmetName;
	list<Predmet> predmets = categories.getPredmets();
	int i = 1;
	for (auto& x : predmets)
	{
		cout << i << " - " << x.getName() << "\n";
		i++;
	}
	cin >> predmetName;
	i = 1;
	for (auto& x : predmets)
	{
		if (predmetName == i)
		{
			cout << "������� �������� ���� ������� ������ ������:\n";
			string themeName;
			cin >> themeName;
			Theme _new(themeName);
			categories.addTheme(x.getName(), &_new);
		}
	}
}

void System::addTest()
{
	cout << "������� �������� �������� � �������� ������ �������� ����:\n";
	int predmetName;
	list<Predmet> predmets = categories.getPredmets();
	int i = 1;
	for (auto& x : predmets)
	{
		cout << i << " - " << x.getName() << "\n";
		i++;
	}
	cin >> predmetName;


	cout << "������� �������� ���� � ������� ������ �������� ����:\n";
	int themeName;
	i = 1;
	for (auto& x : predmets)
	{
		if (predmetName == i)
		{
			list<Theme> thems = x.getThemes();
			i = 1;
			for (auto& c : thems)
			{
				cout << i << " - " << c.getName();
				i++;
			}
		}
	}
	cin >> themeName;
	for (auto& x : predmets)
	{
		if (predmetName == i)
		{
			list<Theme> thems = x.getThemes();
			i = 1;
			for (auto& c : thems)
			{
				if (themeName == i)
				{
					Test newTest;
					categories.addTest(x.getName(), c.getName(), &newTest);
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
	for (auto& x : predmets)
	{
		cout << i << " - " << x.getName() << "\n";
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
				cout << i << " - " << c.getName() << "\n";
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

void System::importUsers()
{
	ofstream ofs("Users.txt");
	ofs << admin;
	for (auto& x : testers)
		ofs << x;
	ofs.close();
}

void System::exportUsers()
{
	ifstream in("Users.txt");
	if (in >> admin) {}
	Tester temp;
	string x;
	while (!in.eof())
	{
		in >> temp;
		testers.push_back(temp);
	}

}