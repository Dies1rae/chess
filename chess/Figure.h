#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <wchar.h>
#include <iomanip>
#include <windows.h>
#include <cstdio>
#include <sstream>
using namespace std;

class Figure{
private:
	int coordx;
	int coordy;
	int type;
	bool alive;
	string root;
public:
	Figure() {
		this->coordx = 0;
		this->coordy = 0;
		this->type = 0;
		this->alive = 0;
		this->root;
	}
	Figure(int a, int b, int c, string d):coordx(a), coordy(b), type(c),root(d),alive(1) {}
	~Figure() {}

	void set_figure(Figure A) {
		this->coordx = A.coordx;
		this->coordy = A.coordy;
		this->type = A.type;
		this->root.clear();
		this->root = A.root;
		this->alive = A.alive;
	}

	vector<int> get_figure() {
		vector <int> tmp = {this->coordx, this->coordy, this->type, this->alive};
		return tmp;
	}
	int get_figure_type() {
		return this->type;
	}
	bool get_figure_alive() {
		return this->alive;
	}
	void set_figure_coord(int x, int y) {
		this->coordx = x;
		this->coordy = y;
	}
	void set_figure_alive(bool a) {
		this->alive = a;
	}
	void set_figure_root(string a) {
		this->root.clear();
		this->root = a;
	}
	void set_figure_type(int a) {
		this->type = a;
	}
	vector<int> get_figure_coord() {
		vector <int> tmp = { this->coordx, this->coordy};
		return tmp;
	}
	string get_figure_root() {
		return this->root;
	}
	/*
	//set figure wchar_t to char*
	string get_ch_bK() {
		wchar_t bK[] = L"\u265A";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_wK() {
		wchar_t bK[] = L"\u2654";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_bQ() {
		wchar_t bK[] = L"\u265B";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_wQ() {
		wchar_t bK[] = L"\u2655";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_bR() {
		wchar_t bK[] = L"\u265C";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_wR() {
		wchar_t bK[] = L"\u2656";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_bB() {
		wchar_t bK[] = L"\u265D";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_wB() {
		wchar_t bK[] = L"\u2657";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_bH() {
		wchar_t bK[] = L"\u265E";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_wH() {
		wchar_t bK[] = L"\u2658";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	string get_ch_bP() {
		wchar_t bK[] = L"\u265F";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
}
	string get_ch_wP() {
		wchar_t bK[] = L"\u2659";
		int bufferSize = WideCharToMultiByte(CP_UTF8, 0, bK, -1, NULL, 0, NULL, NULL);
		char* BK = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, 0, bK, -1, BK, bufferSize, NULL, NULL);
		char test[sizeof(BK)];
		strncpy_s(test, BK, sizeof(BK));
		string SS;
		SS.assign(test, sizeof(test) + 1);
		return SS;
	}
	*/
};
