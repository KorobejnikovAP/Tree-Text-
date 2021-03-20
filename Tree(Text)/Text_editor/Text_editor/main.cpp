#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Text.h"
using namespace std;

int main() {

	setlocale(LC_CTYPE, "russian");
	Text t;
	
	while (true) {
		system("cls");
		cout << t;
		cout << "выберете действие" << endl
			<< "0. exit" << endl
			<< "1. down" << endl
			<< "2. next" << endl
			<< "3. top" << endl
			<< "4. addNext" << endl
			<< "5. addDown" << endl
			<< "6. delCurr" << endl;
		int n;
		string s;
		cin >> n;
		try {
			switch (n)
			{
			case 0:
				return 0;
			case 1:
				t.down();
				break;
			case 2:
				t.next();
				break;
			case 3:
				t.top();
				break;
			case 4:
				cin >> s;
				t.addNext(s);
				break;
			case 5:
				cin >> s;
				t.addDown(s);
				break;
			case 6:
				t.delCurr();
				break;
			default:
				break;
			}
		}
		catch (const char* s) {
			cout << s << endl;
			_getch();
		}
	}
	
	return 0;
}