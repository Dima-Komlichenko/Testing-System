#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class Test
{
	string question;
	list<string> answers;
	int TrueAnswer;
public:
	//метод дл€ админа
	Test()
	{
		cout << "¬ведите вопрос:\n";
		cin >> question;
		string ans;
		//cin.clear();
		cin.ignore();
		for (size_t i = 0; i < 3; i++)
		{
			cout << "¬ведите вариант ответа:\n";
			//cin.ignore();

			cin >> ans;
			answers.push_back(ans);
		}
		bool yet;
		do
		{
			cout << "¬ведите вариант ответа:\n";
			cin >> ans;
			answers.push_back(ans);
			cout << "≈ще один вариант? (1,0)\n";
			cin >> yet;
		} while (yet);
		cout << "”кажите номер правильного варианта ответа:\n";
		cin >> TrueAnswer;
	}
	Test(int i) {}


	//метод который будет отрабатывать
	//(задавать вопрос и предлагать варианты ответа,
	//давать возможность вывбрать вариант и определить верен ли он)
	//метод дл€ студента
	bool work()
	{
		cout << question << "\n\n";
		int i = 1;
		for (auto& x : answers)
		{
			cout << " " << i << ") " << x << "\n";
			i++;
		}
		cout << "¬ведите ваш вариант ответа:\n";
		int TA;
		cin >> TA;
		return TA == TrueAnswer ? true : false;
	}
	void  print()
	{
		cout << " - " << question << "?\n";
		for (auto x : answers)
			cout << x << endl;
	}

	string getQuestion()
	{
		return question;
	}
	list<string> getAnswers()
	{
		return answers;
	}
	int getTrueAnswer()
	{
		return TrueAnswer;
	}
	void addQuestion(string q)
	{
		question = q;
	}
	void addAnswer(string a)
	{
		answers.push_back(a);
	}
	void addTrueAnswer(int t)
	{
		TrueAnswer = t;
	}
};


class Theme
{
	string name;
	list<Test> tests;
public:
	Theme(const string n) :name(n) {}
	string getName()
	{
		return name;
	}
	void addTest(Test* t)
	{
		tests.push_back(*t);
	}
	void delTest()
	{
		cout << "Ќапишите вопрос теста который хотите удалить:\n";
		string question;
		cin >> question;
		list<Test>::iterator it;
		it = tests.begin();
		for (auto& x : tests)
		{
			if (x.getQuestion() == question)
			{
				tests.erase(it);
			}
			it++;
		}
	}
	list<Test>& getTests()
	{
		return tests;
	}
};




class Predmet
{
	string name;
	list<Theme> thems;
public:
	Predmet(const string n) :name(n) {}
	void addName(const string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}
	void addTheme(Theme* t)
	{
		thems.push_back(*t);
	}
	void delTheme()
	{
		cout << "¬ведите название темы которую хоите удалить:\n";
		string theme;
		cin >> theme;
		list<Theme>::iterator it;
		it = thems.begin();
		for (auto& x : thems)
		{
			if (x.getName() == theme)
			{
				thems.erase(it);
			}
			it++;
		}
	}
	void addTest(const string nameTheme, Test* test)
	{
		for (auto& x : thems)
		{
			if (x.getName() == nameTheme)
				x.addTest(test);
		}
	}
	void delTest(const string nameTheme)
	{
		for (auto& x : thems)
		{
			if (x.getName() == nameTheme)
				x.delTest();
		}
	}

	list<Theme>& getThemes()
	{
		return thems;
	}

};


class Categories
{
	list<Predmet> predmets;
public:
	Categories() {}
	void addPredmet(Predmet& p)
	{
		predmets.push_back(p);
	}
	void delPredmet(Predmet p)
	{
		cout << "¬ведите название предмента который хотите удалить:\n";
		string nam;
		cin >> nam;
		list<Predmet>::iterator it;
		it = predmets.begin();

		for (auto& x : predmets)
		{
			if (x.getName() == nam)
			{
				predmets.erase(it);
			}
			it++;
		}
	}
	void addTheme(const string namePredmet, Theme* th)
	{
		for (auto& x : predmets)
		{
			if (x.getName() == namePredmet)
				x.addTheme(th);
		}
	}
	void delTheme(const string namePredmet)
	{
		for (auto& x : predmets)
		{
			if (x.getName() == namePredmet)
				x.delTheme();
		}
	}
	void addTest(const string namePredmet, const string nameTheme, Test* test)
	{
		for (auto& x : predmets)
			if (x.getName() == namePredmet)
				x.addTest(nameTheme, test);
	}
	void delTest(const string namePredmet, const string nameTheme)
	{
		for (auto& x : predmets)
			if (x.getName() == namePredmet)
			{
				x.delTest(nameTheme);
			}
	}
	Predmet* getPredmet(const string name)
	{
		for (auto& x : predmets)
		{
			if (name == x.getName())
			{
				return &x;
			}
		}
	}

	list<Predmet>& getPredmets()
	{
		return predmets;
	}
	friend  ofstream& operator<<(ofstream& out, Categories& categories);
	friend ifstream& operator>>(ifstream& in,  Categories& p);
};

ofstream& operator<<(ofstream& out, Categories& categories)
{
	list<Predmet> predmets = categories.getPredmets();
	for (auto& x : predmets)
	{
		out << "PREDMET\n";
		out << x.getName() << "\n";
		list<Theme> thems = x.getThemes();
		for (auto c : thems)
		{
			out << "THEME\n";
			out << c.getName() << "\n"; //название темы
			list<Test> tests = c.getTests();
			for (auto v : tests)
			{
				out << "TEST\n";
				out << v.getQuestion() << "\n"; //выгружаем вопрос
				list<string> answers = v.getAnswers();
				for (auto b : answers)
				{
					out << b << "\n"; // ответы
				}
				out << "TRUEANSWER\n";
				out << v.getTrueAnswer() << "\n"; // правильный вариант ответа
			}
		}
	}
	return out;
}

ifstream& operator>>(ifstream& in, Categories& categories)
{
	string temp;
	int TA;
	
	while (in >> temp)
	{
		while (temp == "PREDMET")
		{
			in >> temp;
			Predmet _Predmet(temp);
			in >> temp;
			while (temp == "THEME")
			{
				in >> temp;
				Theme _Theme(temp);
				in >> temp;
				while (temp == "TEST")
				{
					in >> temp;
					Test _Test(1);
					_Test.addQuestion(temp);
					in >> temp;
					while (temp != "TRUEANSWER")
					{
						_Test.addAnswer(temp);
						in >> temp;
					}
					in >> TA;
					_Test.addTrueAnswer(TA);
					in >> temp;
					_Theme.addTest(&_Test);
				}
				_Predmet.addTheme(&_Theme);
			}	
			categories.addPredmet(_Predmet);
		}
	}
	return in;
}