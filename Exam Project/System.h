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
	void methodTester(Tester& t);	// логин дожлен быть уникальным, если нет - вход
	void methodAdmin();		// всего может существовать один

	//for Admin
	void addTester();
	void delTester();
	void redactTester(); //редактировать тестировщика
	void SignInAdmin();
	void checkTestCategory();  // Need Test						//просмотр результатов по категориям
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
	cout << "Кто входит в систему?\n"
		<< "1 - Админ\n"
		<< "2 - Тестируемый\n"
		<< "3 - Выход\n";
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
		cout << "Регистрация: \n";
		admin.setLogin();
		admin.setPassword();
		admin.setName();
		cout << "Вы зарегистрировались\n";
		system("pause");
		system("cls");
		//тут нужно выгрузить все данные в файл(пароль - зашифровать)
	}
	else
	{
		string log;
		string pass;
		bool a = false;
		do
		{
			cout << "Введите ваш логин: ";
			cin >> log;
			cout << "Введите ваш пароль: ";
			cin >> pass;
			if (log != admin.getLogin() || pass != admin.getPassword())
			{
				cout << "Вы ввели неверный логин или пароль";
			}
			else
				a = true;

		} while (a == 0);
		//тут мы зашли в админа
	}
	methodAdmin();
}

void System::methodAdmin()
{
	system("cls");
	cout << "Что вы хотите сделать?\n"
		<< "Изменить логин - 1\n"
		<< "Изменить пароль - 2\n"
		<< "Создать пользователя - 3\n"
		<< "Удалить пользователя - 4\n"
		<< "Модифицировать пользователя - 5\n"
		<< "Посмотреть результаты тестирования по категориям - 6\n"
		<< "Посмотреть резльтаты тестирования  пользователя - 7\n"
		<< "Добавить предмет - 8\n"
		<< "Добавить тему - 9\n"
		<< "Добавить тест - 10\n"//тут еще будет добавление правильных и неправильных ответов
		<< "Выйти - 11\n";
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
	cout << "Введите пароль:\n";
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
	cout << "Введите пароль:\n";
	string pas;
	cin >> pas;
	cout << "Введите имя:\n";
	string name;
	cin >> name;
	cout << "Введите адрес:\n";
	string address;
	cin >> address;
	cout << "Введите номер телефона:\n";
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
	cout << "Зарегистрироваться или войти?(1, 2)\n";
	int in;
	cin >> in;
	while (in < 1 || in > 2) cin >> in;
	while (in == 1)
	{
		cout << "Введите логин:\n";
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
			cout << "Такой логин уже существует\n"
				<< "Зарегистрироваться с другим логином - '1'\n"
				<< "Войти с этим логином - '2'\n";
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
		cout << "Введите логин:\n";
		string log;
		cin >> log;
		SignInTester(log);
	}

}

void System::methodTester(Tester& t)
{
	system("cls");
	cout << "Что вы хотите сделать?\n"
		<< "Сдать новый тест - '1'\n"
		<< "Посмотреть результаты предыдущих тестирования - '2'\n"
		<< "Выйти - '3'\n";
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
	cout << "Введите логин:\n";
	string log;
	cin >> log;
	cout << "Введите пароль:\n";
	string pas;
	cin >> pas;
	cout << "Введите имя:\n";
	string name;
	cin >> name;
	cout << "Введите домашний адрес:\n";
	string home;
	cin >> home;
	cout << "Введите номер телефона:\n";
	string phone;
	cin >> phone;
	Tester _new(log, pas, name, home, phone);
	tester.push_back(_new);
}

void System::delTester()
{
	cout << "Введите логин тестировщика которого хотите удалить:\n";
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
	cout << "Введите логин тестировщика которого хотите редактировать:\n";
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
				cout << "Что вы хотите редактировать\n"
					<< "Логин - '1'\n"
					<< "Пароль - '2'\n"
					<< "Имя - '3'\n"
					<< "Домашний адрес - '4'\n"
					<< "Номер телефона - '5'\n"
					<< "Ничего - '6'\n";
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
	cout << "Какую категорифю тестов вы хотите посмотреть?\n"
		<< "Математика - '1'\n"
		<< "Физика - '2'\n";
	int num;
	cin >> num;
	int i = 0; // номер оценки
	while (num < 1 || num > 2) cin >> num;
	switch (num)
	{
	case 1:

		// оценки всех студеньтов по  разделу математики
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
		// оценки всех студеньтов по данному разделу
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
	cout << "Введите логин тестировщика которого хотите посмотреть статистику: ";
	string log;
	cin >> log;
	int i = 0;
	for (auto& x : tester)
	{
		if (x.getLogin() == log)
		{
			cout << "Математика:\n";
			//			for (auto& c : maths)
			{
				//				cout << c.getQuestion() << setw(5) << x.getMarkMaths(i);
				i++;
			}
			cout << "Физика:\n";
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
	cout << "Введите название категории которую хотите добавить:\n";
	string name;
	cin >> name;
	Predmet _new(name);
	categories.addPredmet(_new);
}

void System::addTheme()
{
	cout << "Введите название предмета к которому хотите добавить тему:\n";
	string predmetName;
	cin >> predmetName;

	list<Predmet> predmets = categories.getPredmets();
	for (auto& x : predmets)
	{
		if (predmetName == x.getName())
		{
			cout << "Введите названте темы которую хотите ввести:\n";
			string themeName;
			cin >> themeName;
			Theme _new(themeName);
			categories.addTheme(predmetName, &_new);
		}
	}
}

void System::addTest()
{
	cout << "Введите название предмета к которому хотите добавить тест:\n";
	string predmetName;
	cin >> predmetName;

	cout << "Введите название темы к которой хотите добавить тест:\n";
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
	cout << "По какому предмету вы хотите сдать тест?\n";
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
			cout << "На какую тему вы хотите сдать тест?\n";
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