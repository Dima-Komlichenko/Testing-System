#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include"Tester.h"
#include"Test.h"

using namespace std;

class Admin
{
	string login;
	string password;
	string name;

public:
	Admin():login("-") {}
	Admin(string l, string p, string n) :login(l), password(p), name(n) {}

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
	
	
	friend ofstream& operator<< (ofstream& out, Admin& a);
	friend ifstream& operator>> (ifstream& in, Admin& a);
};

ofstream& operator<< (ofstream& out, Admin& a)
{
	string log = a.getLogin();
	string name = a.getName();
	string pas = a.getPassword();
	
	for (auto& x : log)		x += 3;
	for (auto& x : pas)		x += 3;

	out << log << "\n" << pas << "\n" << name << "\n";
	return out;
}

ifstream& operator>> (ifstream& in, Admin& a)
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
	return in;
}