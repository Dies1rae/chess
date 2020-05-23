#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include "Header.h"
using namespace std;

//func declar
void figure_options_menu_view();
void main_menu_view();
void options_menu_view();
void hidecursor();

//display main menu
void main_menu_view() {
	hidecursor();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|                                                  ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
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
	cout << endl << "                                                                                                                               ...by Dies_Irae" << endl;
}

//opt menu
void options_menu_view() {
	hidecursor();
	system("CLS");
	int optm;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|                                                  ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Simple CHESS";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                        |***" << endl;
	cout << endl << "***|                                                     ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Options";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                          |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|" << "   I----->" << "  Set figure view|";
	cout << "                                                                                                          |***" << endl;
	cout << endl << "***|" << "  II----->" << "             Back|";
	cout << "                                                                                                          |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << "                                                                                                                               ...by Dies_Irae" << endl;
	cin >> optm;
	if (optm == 1) {
		figure_options_menu_view();
	}
	else if (optm == 2) {
		main_menu_view();
	}
}
//figure opt menu
void figure_options_menu_view() {
	hidecursor();
	system("CLS");
	int optm;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|                                                       ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Options";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                        |***" << endl;
	cout << endl << "***|                                                     ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Figure view";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                      |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|" << "   I----->" << "  Simple char|";
	cout << "                                                                                                              |***" << endl;
	cout << endl << "***|" << "  II----->" << "        UTF-8|";
	cout << "                                                                                                              |***" << endl;
	cout << endl << "***|" << " III----->" << "         Back|";
	cout << "                                                                                                              |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << "                                                                                                                               ...by Dies_Irae" << endl;
	cin >> optm;
	if (optm == 1) {
		FigureView = 1;
		cout << "Simple char - OK" << endl;
	}
	else if (optm == 2) {
		FigureView = 2;
		cout << "UTF-8 - OK" << endl;
	}
	else if (optm == 3) {
		options_menu_view();
	}
}
//about menu
void Credits_menu() {
	hidecursor();
	system("CLS");
	int optm;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|                                                  ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Simple CHESS";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                        |***" << endl;
	cout << endl << "***|                                                     ";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 4);
	cout << "Credits";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "                                                                          |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "***|" << "   I----->" << "  This dump version of chess made Poltavskiy Nick aka. Dies Irae|";
	cout << "                                                           |***" << endl;
	cout << endl << "***|" << "  II----->" << "             Back|";
	cout << "                                                                                                          |***" << endl;
	cout << endl << "***|______________________________________________________________________________________________________________________________________|***" << endl;
	cout << endl << "**********************************************************************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << "                                                                                                                               ...by Dies_Irae" << endl;
	cin >> optm;
	if (optm == 1) {
		Credits_menu();
	}
	else if (optm == 2) {
		main_menu_view();
	}
}