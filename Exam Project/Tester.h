#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"Admin.h"
#include"Test.h"
using namespace std;


class Tester
{
	string login;
	string password;
	string name;
	string home_address;
	string phone;
	map<string, int> mark;
public:
	Tester() {}
	Tester(string l, string pas, string n, string h, string p) :login(l), password(pas), name(n), home_address(h), phone(p) {}

	void checkStat() //посмотреть статистику
	{
		for (auto& x : mark)
		{
			cout << x.first << " " << x.second << "\n";
		}
	}


	void addMark(pair<string, int> p)
	{
		bool check = false;
		for (auto& x : mark)
		{
			if (x.first == p.first)
			{
				x.second = p.second;
				check = true;
			}
		}
		if (!check) mark.insert(p);

	}

	string getLogin()
	{
		return login;
	}
	string getPassword()
	{
		return password;
	}
	string getName()
	{
		return name;
	}
	string getHomeAddress()
	{
		return home_address;
	}
	string getPhone()
	{
		return phone;
	}
	map<string, int> getMark()
	{
		return mark;
	}


	void setLogin()
	{
		cout << "¬ведите новый логин: ";
		cin >> login;
	}
	void setPassword()
	{
		cout << "¬ведите новый пароль: ";
		cin >> password;
	}
	void setName()
	{
		cout << "¬ведите новое им€: ";
		cin >> name;
	}
	void setHome_Address()
	{
		cout << "¬ведите новый домашний адрес: ";
		cin >> home_address;
	}
	void setPhone()
	{
		cout << "¬ведите новый номер телефона:";
		cin >> phone;
	}

	void setLogin(string l)
	{
		login = l;
	}
	void setPassword(string p)
	{
		password = p;
	}
	void setName(string n)
	{
		name = n;
	}
	void setHome_Address(string h)
	{
		home_address = h;
	}
	void setPhone(string p)
	{
		phone = p;
	}
	void setMarks(map<string, int> m)
	{
		mark = m;
	}

	friend ofstream& operator<< (ofstream& out, Tester& a);
	friend ifstream& operator>> (ifstream& in, Tester& a);
};

ofstream& operator<< (ofstream& out, Tester& a)
{
	string log = a.getLogin();
	string pas = a.getPassword();

	for (auto& x : log)		x += 3;
	for (auto& x : pas)		x += 3;

	out  << "\n" << log << "\n"
		<< pas << "\n"
		<< a.getName() << "\n"
		<< a.getHomeAddress() << "\n"
		<< a.getPhone() << "\n";
	map<string, int> mark = a.getMark();
	for (auto& x : mark)
	{
		out << x.first << "\n" << x.second << "\n";
	}
	out << "MARKSEND";


	return out;
}

ifstream& operator>> (ifstream& in, Tester& a)
{
	string temp;
	in >> temp;
	for (auto& x : temp)	x -= 3;
	a.setLogin(temp);

	in >> temp;
	for (auto& x : temp)	x -= 3;
	a.setPassword(temp);

	in >> temp;
	a.setName(temp);
	in >> temp;
	a.setHome_Address(temp);
	in >> temp;
	a.setPhone(temp);
	pair<string, int> marks;
	int mark;
	in >> temp;
	while (temp != "MARKSEND")
	{
		in >> mark;
		marks = (make_pair(temp, mark));
		a.addMark(marks);
		in >> temp;
	}
	return in;
}

//string login;
//string password;
//string name;
//string home_address;
//string phone;
//map<string, int> mark;