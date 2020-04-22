#pragma once
#include <iostream>
#include "chessboard.h"
#include "Figure.h"
#include <windows.h>
#include <iomanip>
using namespace std;

//ОБЪЯВЛЕНИЕ ВНЕШНИХ ПЕРЕМЕННЫХ
//string for work with statistics
vector <string> statistics;
//calc moove
int M = 0;
//wrong turn pointer
bool propusk = 0;
//create board and figure
chessboard* test = new chessboard();

void hidecursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void start_new_game() {
	//position console
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 300, 300, SWP_NOSIZE | SWP_NOZORDER);
	system("mode con cols=160 lines=30");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor = { 0,0 };
	cor.X = 50;
	cor.Y = 0;
	SetConsoleCursorPosition(hConsole, cor);
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | 15);
	cout << "**CHESS**" << setw(100) << "...by Dies_Irae" << endl;
	//language
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//new game set board and figure
	test->set_pice_newgame();
	test->get_board();
	//main game loop
	for (int moove = 0; moove < 100000; moove++) {
		int a, c;
		char b, d;
		cout << "Ход: " << moove + 1 << endl;
		if (moove % 2 == 0) {
			cout << "Ход белых" << endl;
			cout << "Введите координаты фигуры и координаты хода: " << endl;
			cin >> b >> a >> d >> c;
			statistics.push_back("Ход: " + to_string(moove + 1) + " | " + b + to_string(a) + '-' + d + to_string(c));
			a = 9 - a;
			c = 9 - c;
			test->moove_pice(a, b - 96, c, d - 96);
			if (propusk == true) {
				M++;
				statistics.pop_back();
				moove++;
				propusk = false;
			}
			test->get_board();
		}
		else if (moove % 2 != 0) {
			cout << "Ход черных" << endl;
			cout << "Введите координаты фигуры и координаты хода: " << endl;
			cin >> b >> a >> d >> c;
			statistics.push_back("Ход: " + to_string(moove + 1) + " | " + b + to_string(a) + '-' + d + to_string(c));
			a = 9 - a;
			c = 9 - c;
			test->moove_pice(a, b - 96, c, d - 96);
			if (propusk == true) {
				M++;
				statistics.pop_back();
				moove++;
				propusk = false;
			}
			test->get_board();
		}
		M++;
		//king dies action
		if (test->get_king_alive()[0] == false) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "------------------------WHITE WINS---------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			system("PAUSE");
			test->end_game();
			test = new chessboard();
			moove = M;
			break;
		}
		if (test->get_king_alive()[1] == false) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "------------------------BLACK WINS---------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			test->end_game();
			test = new chessboard();
			moove = M;
			break;
		}
	}
}

void MainMenu() {
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 300, 300, SWP_NOSIZE | SWP_NOZORDER);
	system("mode con cols=160 lines=30");
	int coice = 9;
	while (coice != 0){
		hidecursor();
		int opt;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << endl << "**********************************************************************************************************************************************" << endl;
		cout << endl << "****                                                  ";
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED| BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
		cout << "Simple CHESS";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "                                                                        ****" << endl;
		cout << endl << "****                                                   ";
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
		cout << "Main Menu";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "                                                                          ****" << endl;
		cout << endl << "**********************************************************************************************************************************************" << endl;
		cout << endl << "****" << "|   I----->" << "  New Game|";
		cout << "                                                                                                                ****" << endl;
		cout << endl << "****" << "|  II----->" << "   Credits|";
		cout << "                                                                                                                ****" << endl;
		cout << endl << "****" << "| III----->" << "      Exit|";
		cout << "                                                                                                                ****" << endl;
		cout << endl << "**********************************************************************************************************************************************" << endl;
		cout << endl << "**********************************************************************************************************************************************" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl << "                                                                                                                               ...by Dies_Irae" << endl;;

		cin >> coice;
		cout << "\n" << endl;

		if (coice == 1) {
			start_new_game();
		}
		if (coice == 3) {
			break;
		}
	}
	exit(1);
}