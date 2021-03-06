#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int map[30][30] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1},
		{1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1},
		{1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1},
		{1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1},
		{1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1},
		{1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1},
		{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void change_color(int color_number);
void gotoxy(int x, int y);
void move();
int crash(int* map, int x, int y);
void print_map();

void change_color(int color_number) //콘솔 출력색상 나타내는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


}
//방향키를 계속 눌러서 진행하려면 오류가 발생함
//흔적을 남겼을 때 같이 문제가 발생하는 것으로 생각함
void move() {
	int x = 2;
	int y = 2;
	int move_c;
	int check;
	gotoxy(x, y);
	change_color(3);
	printf("@");
	while (1) {
		
		move_c = getch();
		change_color(3);
		
		switch (move_c) {

			case UP: gotoxy(x, y);
				printf(" ");
				y -= 1;
				gotoxy(x, y);
				//위에 있는 함수로 흔적을 없앤다.
				printf("@");
				break;

			case DOWN: gotoxy(x, y);
				printf(" ");
				y += 1;
				gotoxy(x, y);
				printf("@");
				break;

			case LEFT: gotoxy(x, y);
				printf(" ");
				x -= 1;
				gotoxy(x, y);
				printf("@");
				break;

			case RIGHT: gotoxy(x, y);
				printf(" ");
				x += 1;
				gotoxy(x, y);
				printf("@");
				break;
		 
	

		
		}
	}
	
	
}
int crash(int (*map) [30], int x, int y) {
	int check;
	if (*(*(map + y) + x) == 1) {
		check = 1;
	}
	//else if (*(*(map + y) + x) == 2) {
		//check = 1;
	//}
	//몹충돌
	else {
		check = 0; 
	} 

	return check;
}
void print_map() {
	for (int i = 0; i < 30; i++) {
		for (int k = 0; k < 30; k++) {
			if (map[i][k] == 0) {
				printf(" ");
			}
			else if (map[i][k] == 1) {
				change_color(3);
				printf("#");
			}

		}
		printf("\n");
	}
	
}
int main() {
	int x = 1;
	int y = 1;
	print_map();
	
	move();
}