#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define HEIGHT 6
#define WIDTH 10


char s[HEIGHT][WIDTH] = {
	"#########",
	"#  #    #",
	"# #   # #",
	"# # # # #",
	"#   #  @#",
	"#########"
};

void print(char s[HEIGHT][WIDTH], int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << s[i][j];
		}
		cout << endl;
	}
}

bool check(char s[HEIGHT][WIDTH], int x, int y) {
	if (s[x][y] == '#') {
		return false;
	}
	return true;
}

bool win_check(char s[HEIGHT][WIDTH], int x, int y) {
	/*if (s[x][y] == '#') {
		return false;
	}*/
	if (x == 4 && y == 7) {
		return true;
	}
	return false;
}

void move_(char s[HEIGHT][WIDTH], int* x, int* y) {
	if (_kbhit()) {
		char c = _getch();
		if (c == 'w') {
			(*x)--;
			if (!check(s, *x, *y)) {
				(*x)++;
			}
		}
		else if (c == 's') {
			(*x)++;
			if (!check(s, *x, *y)) {
				(*x)--;
			}
		}
		else if (c == 'a') {
			(*y)--;
			if (!check(s, *x, *y)) {
				(*y)++;
			}
		}
		else if (c == 'd') {
			(*y)++;
			if (!check(s, *x, *y)) {
				(*y)--;
			}
		}
	}
	s[*x][*y] = '@';
	print(s, HEIGHT, WIDTH);
	Sleep(5);
	s[*x][*y] = ' ';
	system("cls");
}

int x = 1, y = 1;


int main() {
	while (1) {
		move_(s, &x, &y);
		if (win_check(s, x, y)) {
			cout << "You win!" << endl;
			exit(0);
		}
	}
	return 0;
}