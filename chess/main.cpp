#include <iostream>
#include "chessboard.h"
#include "Figure.h"
#include <windows.h>
#include <iomanip>
using namespace std;

//string for work with statistics
vector <string> statistics;
//calc moove
int M = 0;

//create board and figure
chessboard* test = new chessboard();
int main() {
	//position console
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 300, 300, SWP_NOSIZE | SWP_NOZORDER);
	system("mode con cols=160 lines=30");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor = { 0,0 };
	cor.X = 50;
	cor.Y = 0;
	SetConsoleCursorPosition(hConsole, cor);
	cout << "**CHESS**" << setw(100) << "...by Dies_Irae" << endl;
	//language
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//new game set board and figure
	test->set_pice_newgame();
	test->get_board();
	//main game loop
	for (int moove = 0; moove < 100000; moove ++) {
		M++;
		int tmp = moove;
		int a,c;
		char b, d;
		cout << "’од: " << M << endl;
		if (moove % 2 == 0) {
			cout << "’од белых" << endl;
			cout << "¬ведите координаты фигуры и координаты хода: " << endl;
			cin >> b >> a >> d >> c;
			statistics.push_back("’од: " + to_string(M) + " | " + b + to_string(a) + '-' + d + to_string(c));
			a = 9 - a;
			c = 9 - c;
			test->moove_pice(a, b - 96, c, d - 96);
			test->get_board();
		}
		else if (moove % 2 != 0) {
			cout << "’од черных" << endl;
			cout << "¬ведите координаты фигуры и координаты хода: " << endl;
			cin >> b >> a >> d >> c;
			statistics.push_back("’од: " + to_string(M) + " | " + b + to_string(a) + '-' + d + to_string(c));
			test->moove_pice(a, b - 96, c, d - 96);
			test->get_board();
		}
		//king dies action
		if (test->get_king_alive()[0] == false) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "------------------------WHITE WINS---------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			system("PAUSE");
			break;
		}
		if (test->get_king_alive()[1] == false) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "------------------------BLACK WINS---------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			break;
		}
	}
	return 0;
}