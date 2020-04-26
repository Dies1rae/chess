#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <wchar.h>
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
	Figure(int a, int b, int c, string d):coordx(a), coordy(b), type(c),root(d),alive(1) {
	}
	void set_figure(Figure A) {
		this->coordx = A.coordx;
		this->coordy = A.coordy;
		this->type = A.type;
		this->root.clear();
		this->root = A.root;
		this->alive = A.alive;
	}
	~Figure() {}

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

};

