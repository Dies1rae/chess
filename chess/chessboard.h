#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Figure.h"
#include <vector>
#include <Windows.h>
using namespace std;

//ALL EXTERN DATA
//for statistics
extern vector <string> statistics;
//calculate moove
extern int M;
//wrong turn pointer
extern bool propusk;

class chessboard {
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
	~chessboard() {}

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
				SetConsoleTextAttribute(hConsole,7);
				//outside contur
				if ((ptr1 == 0 || ptr1 == 11 || ptr2 == 0 || ptr2 == 11) || ((ptr1 == 1 && ptr2 == 1) || (ptr1 == 1 && ptr2 == 10)) || ((ptr1 == 10 && ptr2 == 1) || (ptr1 == 10 && ptr2 == 10))) {
					SetConsoleTextAttribute(hConsole, 7);
					//left board and statistics
					if (ptr2 == 11) {
						if (ptr1 == 0) {
							cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "---White mooves---" << setw(5) << '|' << "---Black mooves---";
						}
						else if (ptr1 == 1) {
							if (statistics.size() >= 2) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 - 1] << setw(11) << " " << statistics[ptr1];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 2) {
							if (statistics.size() >= 4) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1] << setw(11) << " " << statistics[ptr1 + 1];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 3) {
							if (statistics.size() >= 6) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 1] << setw(11) << " " << statistics[ptr1 + 2];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 4) {
							if (statistics.size() >= 8) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 2] << setw(11) << " " <<  statistics[ptr1 + 3];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 5) {
							if (statistics.size() >= 10) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 3] << setw(11) << " " << statistics[ptr1 + 4];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 6) {
							if (statistics.size() >= 12) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 4] << setw(11) << " " << statistics[ptr1 + 5];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 7) {
							if (statistics.size() >= 14) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 5] << setw(11) << " " << statistics[ptr1 + 6];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        "  << "                        ";
							}
						}
						else if (ptr1 == 7) {
							if (statistics.size() >= 16) {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << statistics[ptr1 + 6] << setw(11) << " " << statistics[ptr1 + 7];
							}
							else {
								cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "                        " << "                        ";
							}
						}
						else {
							cout << setw(4) << '*' << setw(4) << setw(8) << '|' << setw(20) << "" << setw(5)  << "";
						}
					}
					//just a board(right, top, bottom)
					else {
						SetConsoleTextAttribute(hConsole, 7);
						cout << setw(4) << '*' << setw(4);
					}
				}
				//A-H TOP and DOWN
				else if ((ptr1 == 1 && ptr2 > 1) || (ptr1 == 10 && ptr2 > 1)) {
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN| BACKGROUND_BLUE | FOREGROUND_INTENSITY | 1);
					cout << setw(4) << char(63 + ptr2) << setw(4);
				}
				//1-8 LEFT and RIGHT
				else if ((ptr2 == 1 && ptr1 > 1) || (ptr2 == 10 && ptr1 > 1)) {
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | 1);
					cout << setw(4) << 10 - ptr1 << setw(4);
				}
				//chess figure
				else {
					if (ptr1 % 2 == 0 && ptr2 % 2 == 0) {
						SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
							if (ptr1 - 1 == this->figurein[ptr0]->get_figure_coord()[0] && ptr2 - 1 == this->figurein[ptr0]->get_figure_coord()[1]) {
								if (this->figurein[ptr0]->get_figure_alive() == 1) {
									cout << setw(4) << this->figurein[ptr0]->get_figure_root() << setw(4);
								}
							}
						}
						if (this->board[ptr1][ptr2] == 0) {
							cout << setw(4) << this->board[ptr1][ptr2] << setw(4);
						}
					}
					else if (ptr1 % 2 == 0 && ptr2 % 2 != 0) {
						SetConsoleTextAttribute(hConsole, 4);
						for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
							if (ptr1 - 1 == this->figurein[ptr0]->get_figure_coord()[0] && ptr2 - 1 == this->figurein[ptr0]->get_figure_coord()[1]) {
								if (this->figurein[ptr0]->get_figure_alive() == 1) {
									cout << setw(4) << this->figurein[ptr0]->get_figure_root() << setw(4);
								}
							}
						}
						if (this->board[ptr1][ptr2] == 0) {
							cout << setw(4) << this->board[ptr1][ptr2] << setw(4);
						}
					}
					if (ptr1 % 2 != 0 && ptr2 % 2 == 0) {
						SetConsoleTextAttribute(hConsole, 4);
						for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
							if (ptr1 - 1 == this->figurein[ptr0]->get_figure_coord()[0] && ptr2 - 1 == this->figurein[ptr0]->get_figure_coord()[1]) {
								if (this->figurein[ptr0]->get_figure_alive() == 1) {
									cout << setw(4) << this->figurein[ptr0]->get_figure_root() << setw(4);
								}
							}
						}
						if (this->board[ptr1][ptr2] == 0) {
							cout << setw(4) << this->board[ptr1][ptr2] << setw(4);
						}
					}
					else if (ptr1 % 2 != 0 && ptr2 % 2 != 0) {
						SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
						for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
							if (ptr1 - 1 == this->figurein[ptr0]->get_figure_coord()[0] && ptr2 - 1 == this->figurein[ptr0]->get_figure_coord()[1]) {
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
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -4, "bR");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 2 || ptr2 == 9)) {
					this->board[ptr1][ptr2] = 4;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 4, "wR");
					ptr0++;
				}
				//horses
				if (ptr1 == 2 && (ptr2 == 3 || ptr2 == 8)) {
					this->board[ptr1][ptr2] = -2;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -2, "bH");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 3 || ptr2 == 8)) {
					this->board[ptr1][ptr2] = 2;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 2, "wH");
					ptr0++;
				}
				//bishop
				if (ptr1 == 2 && (ptr2 == 4 || ptr2 == 7)) {
					this->board[ptr1][ptr2] = -3;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -3, "bB");
					ptr0++;
				}
				if (ptr1 == 9 && (ptr2 == 4 || ptr2 == 7)) {
					this->board[ptr1][ptr2] = 3;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 3, "wB");
					ptr0++;
				}
				//queen
				if (ptr1 == 2 && ptr2 == 5) {
					this->board[ptr1][ptr2] = -5;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -5, "bQ");
					ptr0++;
				}
				if (ptr1 == 9 && ptr2 == 5) {
					this->board[ptr1][ptr2] = 5;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 5, "wQ");
					ptr0++;
				}
				//king
				if (ptr1 == 2 && ptr2 == 6) {
					this->board[ptr1][ptr2] = -6;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -6, "bK");
					ptr0++;
				}
				if (ptr1 == 9 && ptr2 == 6) {
					this->board[ptr1][ptr2] = 6;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 6, "wK");
					ptr0++;
				}
				//pawns
				if (ptr1 == 3) {
					this->board[ptr1][ptr2] = -1;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, -1, "bP");
					ptr0++;
				}
				if (ptr1 == 8) {
					this->board[ptr1][ptr2] = 1;
					this->figurein[ptr0] = new Figure(ptr1 - 1, ptr2 - 1, 1, "wP");
					ptr0++;
				}
			}
		}
	}
	//set figure function for complete movement 
	void set_pice(int x, int y, int fig) {
		//�� ��������� � ������� ����� ��� ���������� ���� � ����������� �� 1
		if (this->board[x + 1][y + 1] == 9) {
			cerr << "Wrong coordinates of the board" << endl;
		}
		else if (this->board[x + 1][y + 1] != 0) {
			cerr << "There is a figure already on that cell" << endl;
		}
		else {
			this->board[x + 1][y + 1] = fig;
		}
	}

	//moove figure by coordinates (from x(2) and from y(E) --> to c(4) to z(E))
	void moove_pice(int x, int y, int c, int z) {
		//if its side of board
		//�� ��������� � ������� ����� ��� ���������� ���� � ����������� �� 1, �� ��������� �� � ������� figurein ��� ������ ����������
		if (this->board[x + 1][y + 1] == 9 || this->board[c + 1][z + 1] == 9) {
			propusk = 1;
			cerr << "Wrong coordinates of the board" << endl;
			system("pause");
		}
		//bug with mooves if no figure on cell 
		else if (this->board[x+1][y+1] == 0) {
			propusk = 1;
			cerr << "Wrong turn, there no figure on this cell" << endl;
			system("pause");
		}
		else {
			//coordinate cout ---> cout << endl << x << ':' << y << ':' << c << ':' << z << endl;
			for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
				if (this->figurein[ptr0]->get_figure_coord()[0] == x && this->figurein[ptr0]->get_figure_coord()[1] == y) {
					if ((attack_and_movement(x, y, c, z, this->figurein[ptr0]->get_figure_type())[0] == 0) || (M % 2 == 0 && this->figurein[ptr0]->get_figure_type() < 0) || (M % 2 != 0 && this->figurein[ptr0]->get_figure_type() > 0) ) {
						propusk = 1;
						cerr << "Wrong turn" << endl;
						system("pause");
					}
					else {
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
							this->board[x + 1][y + 1] = 0;
						}
					}
					//control king alive status
					get_king_alive();
					}
				}
			}
		system("CLS");
	}

	//BOARD RULES
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

	//remove dead bodyes from chessboard
	void if_figure_dead() {
		for (int ptr0 = 0; ptr0 < size(this->figurein); ptr0++) {
			if (this->figurein[ptr0]->get_figure_alive() == false) {
				this->figurein[ptr0]->set_figure_coord(0, 0);
				this->figurein[ptr0]->set_figure_root('+');
				//this->figurein[ptr0]->~Figure();
			}
		}
	}

	//Figure mooves and rules (from x(2) and from y(E) --> to c(4) to z(E))
	vector <int> attack_and_movement(int x, int y, int c, int z, int t) {
		//first element of this mass is bool can figure moove or not. And every 1-3-5 is X and every 2-4-6 is Y for possible moove
		vector <int> res;
		res.push_back(0);
		//pawn ---WORKS FINE
		if (t == 1 || t == -1) {
			if (y == z && abs(c - x) == 2) {
				res.push_back(c);
				res.push_back(z);
			}
			if (y == z && abs(c - x) == 1) {
				res.push_back(c);
				res.push_back(z);
			}
			if ((y + 1 == z || y - 1 == z) && abs(c - x) == 1) {
				res.push_back(c);
				res.push_back(z);
			}
		}
		//horseman ---WORKS FINE
		if (t == 2 || t == -2) {
			if (abs((x - c) * (y - z)) == 2) {
				res.push_back(c);
				res.push_back(z);
			}
		}
		//bishop ---WORKS FINE
		if (t == 3 || t == -3) {
			// If pawn is at angle 
			// 45 or 225 degree from 
			// bishop's Position 
			if (c - x == z - y) {
				res.push_back(c);
				res.push_back(z);
			}
			// If pawn is at angle 
			// 135 or 315 degree from 
			// bishop's Position 
			else if (-c + x == z - y) {
				res.push_back(c);
				res.push_back(z);
			}
		}
		//ROOK ---WORKS FINE
		if (t == 4 || t == -4) {
			//add all variants (not board) to vector
			for (int ptr0 = 1; ptr0 < size(this->board) - 1; ptr0++) {
				for (int ptr1 = 1; ptr1 < size(this->board[ptr0])-1; ptr1++) {
					if (ptr0 == x) {
						res.push_back(ptr0);
						res.push_back(ptr1);
					}
					if (ptr1 == y) {
						res.push_back(ptr0);
						res.push_back(ptr1);
					}
				}
			}
		}
		//QUEEN ---WORKS FINE
		if (t == 5 || t == -5) {
			if (((abs(x - c) == 1) && ((y - z) == 0)) || ((abs(y - z) == 1) && ((x - c) == 0)) || ((abs(x - c) == 1) && (abs(y - z) == 1))) {
				res.push_back(c);
				res.push_back(z);
			}
			else if (c - x == z - y) {
				res.push_back(c);
				res.push_back(z);
			}
			else if (-c + x == z - y) {
				res.push_back(c);
				res.push_back(z);
			}
			for (int ptr0 = 1; ptr0 < size(this->board) - 1; ptr0++) {
				for (int ptr1 = 1; ptr1 < size(this->board[ptr0]) - 1; ptr1++) {
					if (ptr0 == x) {
						res.push_back(ptr0);
						res.push_back(ptr1);
					}
					if (ptr1 == y) {
						res.push_back(ptr0);
						res.push_back(ptr1);
					}
				}
			}
		}
		//KING ---WORKS FINE
		if (t == 6 || t == -6) {
			//add all variants (not board) to vector
			if (((abs(x - c) == 1) && ((y - z) == 0)) || ((abs(y - z) == 1) && ((x - c) == 0)) || ((abs(x - c) == 1) && (abs(y - z) == 1))) {
				res.push_back(c);
				res.push_back(z);
			}
		}

		//check if figure t can move from xy to cz
		for (int ptr0 = 1; ptr0 < res.size(); ptr0++) {
			if (ptr0 % 2 != 0 && (res[ptr0] == c && res[ptr0 + 1] == z)) {
				res[0] = 1;
			}
		}
		return res;
	}
	//END_GAME
	void end_game() {
		stat_clear(9);
		set_pice_newgame();
		statistics.clear();
		M = 0;
	}
};

