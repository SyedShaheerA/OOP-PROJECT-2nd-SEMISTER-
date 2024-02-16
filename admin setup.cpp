#include <fstream> 
#include <istream> 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include<conio.h>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	string user,pass;
	cout << "user:" << endl;
	cin >> user;
	cout << "pass:" << endl;
	cin >> pass;
	ofstream blah("Admininfo.txt",ios::app);
	blah << user << "\t" << pass << "\n";
	blah.close();
}
