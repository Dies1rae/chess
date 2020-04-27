#pragma once
#include <iostream>
#include "chessboard.h"
#include "Figure.h"
#include <windows.h>
#include <iomanip>
#include <wchar.h>
#include "Timer.h"
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
int gametime = 0;

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
	//new game set board and figure
	system("CLS");
	test->set_pice_newgame();
	test->get_board();
	
	//main game loop
	for (int moove = 0; moove < 100000; moove++) {
		int a, c;
		char b, d;
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | 0);
		cout << "Turn: " << moove + 1 << endl;
		cout << "Game time : " << gametime << "/sec" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		if (moove % 2 == 0) {
			//timer---
			Timer* white_t = new Timer();
			white_t->Start();
			//-----
			cout << "Now white turn" << endl;
			cout << "Enter coord. of figure and coord. to move: " << endl;
			cin >> b >> a >> d >> c;
			//stat
			statistics.push_back("White turn: " + to_string(moove) + " | " + b + to_string(a) + '-' + d + to_string(c));
			//-----
			a = 9 - a;
			c = 9 - c;
			gametime += white_t->GetDuration();
			test->moove_pice(a, b - 96, c, d - 96);
			if (propusk == true) {
				M++;
				statistics.pop_back();
				statistics.push_back("Wrong turn: " + to_string(moove) + " | " + b + to_string(a) + '-' + d + to_string(c));
				moove++;
				propusk = false;
			}
			test->get_board();
			cout << "Turn time: " << white_t->GetDuration() << "/sec" << endl;;
			//stat
			M++;
		}
		else if (moove % 2 != 0) {
			Timer* Black_t = new Timer();
			Black_t->Start();
			cout << "Now black turn" << endl;
			cout << "Enter coord. of figure and coord. to move: " << endl;
			cin >> b >> a >> d >> c;
			statistics.push_back("Black turn: " + to_string(moove) + " | " + b + to_string(a) + '-' + d + to_string(c));
			a = 9 - a;
			c = 9 - c;
			//timer---
			gametime += Black_t->GetDuration();
			//------
			//move---
			test->moove_pice(a, b - 96, c, d - 96);
			if (propusk == true) {
				M++;
				statistics.pop_back();
				statistics.push_back("Wrong turn: " + to_string(moove) + " | " + b + to_string(a) + '-' + d + to_string(c));
				moove++;
				propusk = false;
			}
			test->get_board();
			cout << "Turn time: " << Black_t->GetDuration() << "/sec" << endl;
			//stat
			M++;
		}


		//king dies action
		//WIN ENDS
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
			system("PAUSE");
			test->end_game();
			test = new chessboard();
			moove = M;
			break;
		}
		//PATS END
		//END OF TURNS
		if (test->get_king_alive()[1] && test->get_king_alive()[0] && moove == 100000-2) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "---------------------------PAT------------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			system("PAUSE");
			test->end_game();
			test = new chessboard();
			moove = M;
			break;
		}
		//ALL DEAD EXCEPT THE KINGS
		if (test->get_king_alive()[1] && test->get_king_alive()[0] && test->pat_kings() == true) {
			system("CLS");
			cout << "------------------------GAME OVER---------------------" << endl;
			cout << "---------------------------PAT------------------------" << endl;
			cout << "*-------------------------CHESS" << setw(100) << "...by Dies_Irae" << endl;
			system("PAUSE");
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
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		/*
		const wchar_t* white = L"♔♕♖♗♘♙\r\n";
		const wchar_t* black = L"♚♛♜♝♞♟\r\n";
		*/
		cout << endl << "**********************************************************************************************************************************************" << endl;
		cout << endl << "***________________________________________________________________________________________________________________________________________***" << endl;
		cout << endl << "***|                                                  ";
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED| BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
		cout << "Simple CHESS";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "                                                                        |***" << endl;
		cout << endl << "***|                                                   ";
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
		cout << "Main Menu";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "                                                                          |***" << endl;
		cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
		cout << endl << "***|" << "   I----->" << "  New Game|";
		cout << "                                                                                                                 |***" << endl;
		cout << endl << "***|" << "  II----->" << "   Credits|";
		cout << "                                                                                                                 |***" << endl;
		cout << endl << "***|" << " III----->" << "   Options|";
		cout << "                                                                                                                 |***" << endl;
		cout << endl << "***|" << "  IV----->" << "      Exit|";
		cout << "                                                                                                                 |***" << endl;
		cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
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
		if (coice == 4) {
			break;
		}
	}
	exit(1);
}