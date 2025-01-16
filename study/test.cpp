#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define HEIGHT 6
#define WIDTH 10

int score = 0;

wchar_t s[HEIGHT][WIDTH] = {
	L"#########",
	L"#  #    #",
	L"#@#@@ # #",
	L"# # # # #",
	L"#   #  @#",
	L"#########"
};

void print(wchar_t s[HEIGHT][WIDTH], int h, int w) {

	//创建新的缓冲区
	HANDLE hOutput = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);


	//隐藏缓冲区的光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);

	//缓冲处理显示
	DWORD bytes = 0;
	COORD coord = { 0, 0 };

	for (int i = 0; i < h; i++) {
		coord.Y = i;
		WriteConsoleOutputCharacter(hOutput, (LPCWSTR)s[i], w, coord, &bytes);
	}
	SetConsoleActiveScreenBuffer(hOutput);
}

bool check(wchar_t s[HEIGHT][WIDTH], int x, int y) {
	if (s[x][y] == '#') {
		return false;
	}
	return true;
}

bool win_check(wchar_t s[HEIGHT][WIDTH], int x, int y) {
	if (s[x][y] == '@') {
		score++;
	}
	if (x == 4 && y == 7) {
		return true;
	}
	return false;
}

void move_(wchar_t s[HEIGHT][WIDTH], int* x, int* y) {
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

	if (win_check(s, *x, *y)) {
		cout << "Your score: " << score << endl;
		exit(0);
	}

	s[*x][*y] = '@';
	print(s, HEIGHT, WIDTH);
	Sleep(5);
	s[*x][*y] = ' ';
}

int x = 1, y = 1;


int main() {
	while (1) {
		move_(s, &x, &y);
	}
	return 0;
}