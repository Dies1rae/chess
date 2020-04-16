#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include"Figure.h"
#include <vector>
#include <Windows.h>
using namespace std;

//for statistics
extern vector <string> statistics;
//calculate moove
extern int M;

class chessboard{
private:
	//Figure in desk
	Figure* figurein[32];
	//Board with board
	int board[12][12];
public:
	//construct
	chessboard() {
		this->figurein;
		this->board;
		for (int ptr1 = 0; ptr1 < size(this->board); ptr1++) {
			for (int ptr2 = 0; ptr2 < size(this->board); ptr2++) {
				if ((ptr1 > 1 && ptr1 < 10) && (ptr2 > 1 && ptr2 < 10)) {
					this->board[ptr1][ptr2] = 0;
				}
				else {
					this->board[ptr1][ptr2] = 9;
				}
			}
		}
	}
	//destruct
	~chessboard();
	
	//every renew and get board
	void get_board() {
		//position
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cor = { 0,0 };
		cor.X = 00;
		cor.Y = 2;
		SetConsoleCursorPosition(hConsole, cor);
		//if figure dead set coor and root
		if_figure_dead();
		//clear stat
		stat_clear(M);
		//printing statistics, board and figure to cout
		for (int ptr1 = 0; ptr1 < size(this->board); ptr1++) {
			for (int ptr2 = 0; ptr2 < size(this->board); ptr2++) {
				//outside contur
				if ((ptr1 == 0 || ptr1 == 11 || ptr2 == 0 || ptr2 == 11) || ((ptr1==1 && ptr2 == 1) || (ptr1 == 1 && ptr2 == 10)) || ((ptr1 == 10 && ptr2 == 1) || (ptr1 == 10 && ptr2 == 10))) {
					//left board and statistics
					if (ptr2 == 11) {
						if (ptr1 == 0) {
							cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "---White mooves---" << setw(5) << '|' <<  "---Black mooves---";
						}
						else if (ptr1 == 1) {
							if (statistics.size() >= 2) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' <<  statistics[ptr1 - 1] << setw(11) << '|' << statistics[ptr1];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 2) {
							if (statistics.size() >= 4) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' <<  statistics[ptr1] << setw(11) << '|' << statistics[ptr1 + 1];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 3) {
							if (statistics.size() >= 6) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 1] << setw(11) << '|' << statistics[ptr1 + 2];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 4) {
							if (statistics.size() >= 8) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 2] << setw(11) << '|' << statistics[ptr1 + 3];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 5) {
							if (statistics.size() >= 10) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' <<  statistics[ptr1 + 3] << setw(11) << '|' << statistics[ptr1 + 4];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 6) {
							if (statistics.size() >= 12) {
							cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 4] << setw(11) << '|' << statistics[ptr1 + 5];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 7) {
							if (statistics.size() >= 14) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 5] << setw(11) << '|' << statistics[ptr1 + 6];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else if (ptr1 == 7) {
							if (statistics.size() >= 16) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 6] << setw(11) << '|' << statistics[ptr1 + 7];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << '|' << "                        ";
							}
						}
						else {
							cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << ""<< setw(5) << '|'<<"";
						}
					}
					//just a board(right, top, bottom)
					else {
						cout << setw(4) << '*' << setw(4);
					}
				}
				//A-H TOP and DOWN
				else if ((ptr1 == 1 && ptr2 > 1) || (ptr1 == 10 && ptr2 > 1)) {
					cout << setw(4) << char(63+ptr2)  << setw(4);
				}
				//1-8 LEFT and RIGHT
				else if ((ptr2 == 1 && ptr1 > 1) || (ptr2 == 10 && ptr1 > 1)) {
					cout << setw(4) << 10-ptr1 << setw(4);
				}
				//chess figure
				else {
					for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
						if ( ptr1-1 == this->figurein[ptr0]->get_figure_coord()[0] && ptr2-1 == this->figurein[ptr0]->get_figure_coord()[1]) {
							if (this->figurein[ptr0]->get_figure_alive() == 1) {
								cout << setw(4) << this->figurein[ptr0]->get_figure_root() << setw(4);
							}
						}
					}
					if (this->board[ptr1][ptr2] == 0) {
						cout << setw(4) << this->board[ptr1][ptr2] << setw(4);
					}
				}
			}
			cout << endl;
		}
	}
	//to clear vector <string> statistics
	void stat_clear(int a) {
		if (a == 8) {
			statistics.clear();
			M = 0;
		}
	}

	//set figure on board for new game(and set its waight and color in figurein)
	void set_pice_newgame() {
		int ptr0 = 0;
		for (int ptr1 = 2; ptr1 < 10; ptr1++) {
			for (int ptr2 = 2; ptr2 < 10; ptr2++) {
				//rooks
				if (ptr1 == 2 && (ptr2 == 2 || ptr2 == 9)) {
					this->board[ptr1][ptr2] = -4;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -4, "bR");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 2 || ptr2 == 9)) {
					this->board[ptr1][ptr2] = 4;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 4, "wR");
					ptr0++;
				}
				//horses
				if (ptr1 == 2 && (ptr2 == 3 || ptr2 == 8)) {
					this->board[ptr1][ptr2] = -2;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -2, "bH");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 3 || ptr2 == 8)) {
					this->board[ptr1][ptr2] = 2;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 2, "wH");
					ptr0++;
				}
				//bishop
				if (ptr1 == 2 && (ptr2 == 4 || ptr2 == 7)) {
					this->board[ptr1][ptr2] = -3;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -3, "bB");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 4 || ptr2 == 7)) {
					this->board[ptr1][ptr2] = 3;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 3, "wB");
					ptr0++;
				}
				//queen
				if (ptr1 == 2 && ptr2 == 5) {
					this->board[ptr1][ptr2] = -5;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -5, "bQ");
					ptr0++;
				}
				if (ptr1 == 9 && ptr2 == 5) {
					this->board[ptr1][ptr2] = 5;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 5, "wQ");
					ptr0++;
				}
				//king
				if (ptr1 == 2 && ptr2 == 6) {
					this->board[ptr1][ptr2] = -6;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -6, "bK");
					ptr0++;
				}
				if (ptr1 == 9 && ptr2 == 6) {
					this->board[ptr1][ptr2] = 6;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 6, "wK");
					ptr0++;
				}
				//pawns
				if (ptr1 == 3) {
					this->board[ptr1][ptr2] = -1;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, -1, "bP");
					ptr0++;
				}
				if (ptr1 == 8) {
					this->board[ptr1][ptr2] = 1;
					this->figurein[ptr0] = new Figure(ptr1-1, ptr2-1, 1, "wP");
					ptr0++;
				}
			}
		}
	}
	//set figure function for complete movement 
	void set_pice(int x, int y, int fig) {
		if (this->board[x + 1][y + 1] == 9) {
			cerr << "Wrong coordinates of the board" << endl;
		}
		else if(this->board[x + 1][y + 1] != 0) {
			cerr << "There is a figure already on that cell" << endl;
		}
		else {
			this->board[x + 1][y + 1] = fig;
		}
	}

	//moove figure by coordinates
	void moove_pice(int x, int y, int c, int z) {
		if (this->board[x + 1][y + 1] == 9 || this->board[c + 1][z + 1] == 9) {
			cerr << "Wrong coordinates of the board" << endl;
			system("pause");
		}
		//bug with mooves if no figure on cell ???????????????????????????????????????????????????????????????? WHAT TO DO MAN!???
		else if (this->board[x + 1][y + 1] == 0) {
			cerr << "Wrong turn, there no figure on this cell" << endl;
			system("pause");
		}
		else {
			//coordinate cout ---> cout << endl << x << ':' << y << ':' << c << ':' << z << endl;
			//if there if a figure in cell
			if (this->board[c + 1][z + 1] != 0) {
				//Kill figure coord c-z
				for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
					if (this->figurein[ptr0]->get_figure_coord()[0] == c && this->figurein[ptr0]->get_figure_coord()[1] == z) {
						if (this->figurein[ptr0]->get_figure_alive() == true) {
							this->figurein[ptr0]->set_figure_live(false);
						}
						else {
							cerr << "Warning its a bug!" << endl;
							system("pause");
						}
					}
				}
				//move figure from xy->cz
				for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
					if (this->figurein[ptr0]->get_figure_coord()[0] == x && this->figurein[ptr0]->get_figure_coord()[1] == y) {
						this->figurein[ptr0]->set_figure_coord(c, z);
						set_pice(c, z, this->figurein[ptr0]->get_figure_type());
					}
				}
				this->board[x + 1][y + 1] = 0;
			}
			//and there is not(done)
			else {
				for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
					if (this->figurein[ptr0]->get_figure_coord()[0] == x && this->figurein[ptr0]->get_figure_coord()[1] == y) {
						this->figurein[ptr0]->set_figure_coord(c, z); 
						set_pice(c, z, this->figurein[ptr0]->get_figure_type());
					}
				}
				this->board[x+1][y+1] = 0;
			}
		}
		//control king alive status
		get_king_alive();
		system("CLS");
	}

	//remove dead bodyes from chessboard
	void if_figure_dead() {
		for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
			if (this->figurein[ptr0]->get_figure_alive() == false) {
				this->figurein[ptr0]->set_figure_coord(0, 0);
				this->figurein[ptr0]->set_figure_root("+");
				//this->figurein[ptr0]->~Figure();
			}
		}
	}



	//BOAR RULES
	//king alive status
	vector <bool> get_king_alive() {
		vector <bool> kings;
		for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
			if (this->figurein[ptr0]->get_figure_type() == -6 || this->figurein[ptr0]->get_figure_type() == 6) {
				kings.push_back(this->figurein[ptr0]->get_figure_alive());
			}
		}
		return kings;
	}
};

