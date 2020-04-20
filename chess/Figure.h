#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Figure{
private:
	int coordx;
	int coordy;
	int type;
	bool alive;
	string root;
public:
	Figure() {}
	Figure(int a, int b, int c, string d):coordx(a), coordy(b), type(c),root(d),alive(1) {
	}
	~Figure();

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
	void set_figure_live(bool a) {
		this->alive = a;
	}
	void set_figure_root(char a) {
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

