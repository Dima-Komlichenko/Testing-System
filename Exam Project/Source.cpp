#include<iostream>
#include"System.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	
	System sys;
	sys.exportTestInProgram();
	sys.exportUsers();

	sys.menu();

	sys.importTestsInFile();
	sys.importUsers();
	
	system("pause");
}

