#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"



int totalmap[30][30] = { {0}, {0}
	

};
//플레이어 위치
int Px = 15, Py =15;

void change_color(int color_number);
void gotoxy(int x, int y);
void Pmove();
void Player();
int crash(int* map, int x, int y);
void print_map();
void baseC();
void double_buff_render();
int randomize();
void L_Dcraft();
void L_Ucraft();
void R_Dcraft();
void R_Ucraft();

void TMP(int map[][30], int height, int width);

int keeper(int(*map)[36], int X, int Y);

int keeper(int(*map)[36], int X, int Y) {

	int checker;

	if (*(*(map + Y) + X) == 0) {
		checker = 1;
	}
	else if (*(*(map + Y) + X) == 2) {
		checker = 1;
	}
	else { checker = 0; }

	return checker;
}


void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int로 바꾼다
	//일정구간을 최종 맵저장소에 저장
	int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			totalmap[i][j] = map[i2][j2];
			j2++;
		}
		i2++;
	}
}
void db_saving(int buffmap[][TWIDTH]) {//int로 바꾼다
	
	
	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			buffmap[i][j] = totalmap[i][j];
			
		}
		
	}
}//현재의 맵상태를 버퍼에 저장하는 함수

void double_buff() {
	int tmpx = 0, tmpy = 0;
	//백퍼버와 프론트버퍼를 비교
	//백버퍼 != 프론트버퍼
	//프론트버퍼에 있는 걸 그리고 백버퍼에 해당하는 좌표의 값을 "  "으로 지운다.
	for (int i = 0; i < THEIGHT; i++) {
		for (int j = 0; j < TWIDTH; j++) {
			if (backbuff[i][j] != frontbuff[i][j]) {
				if (backbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					printf("◎");
				}else if (backbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
			}
		}
	}
}//불완성

int randomize(void) {//맵조합을 위한 랜덤값생성
	srand(time(NULL));
	int random = 0;
	random = rand() % 8 + 1;//1~10
	return random;
}

void L_Ucraft() {
	//왼쪽 위 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(left_u1, 0, 15, 0, 15);
	}
	else if (select > 2 && select <= 4) {
		baseC(left_u2, 0, 15, 0, 15);
	}
	else if (select > 4 && select <= 6) {
		baseC(left_u3, 0, 15, 0, 15);
	}
	else if (select > 6 && select <= 8) {
		baseC(left_u1, 0, 15, 0, 15);
	}
	//맵 추가해야함



}
void L_Dcraft() {
	//왼쪽 아래 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(left_d1, 15, 30, 0, 15);
	}
	else if (select > 2 && select <= 4) {
		baseC(left_d2, 15, 30, 0, 15);
	}
	else if (select > 4 && select <= 6) {
		baseC(left_d3, 15, 30, 0, 15);
	}
	else if (select > 6 && select <= 8) {
		baseC(left_d4, 15, 30, 0, 15);
	}

}
void R_Dcraft() {
	//오른쪽 아래 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(right_d1, 15, 30, 15, 30);
	}
	else if (select > 2 && select <= 4) {
		baseC(right_d2, 15, 30, 15, 30);
	}
	else if (select > 4 && select <= 6) {
		baseC(right_d3, 15, 30, 15, 30);
	}
	else if (select > 6 && select <= 8) {
		baseC(right_d4, 15, 30, 15, 30);
	}

}
void R_Ucraft() {
	//오른쪽 위 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(right_u1, 0, 15, 15, 30);
	}
	else if (select > 2 && select <= 4) {
		baseC(right_u2, 0, 15, 15, 30);
	}
	else if (select > 4 && select <= 6) {
		baseC(right_u3, 0, 15, 15, 30);
	}
	else if (select > 6 && select <= 8) {
		baseC(right_u4, 0, 15, 15, 30);
	}

}

void TMP(int map[][30], int height, int width) {//int로 바꾼다

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//조건문으로 각 디지털값에 따른 문자를 출력한다.
			if (map[i][j] == 1) {
				change_color(6);
				printf("■");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}else if (map[i][j] == 2) {

				printf("◎");
			}
			
		}
		printf("\n");
	}
}


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

void Player() {
	//{위,아래,왼,오}


	Pmove();
	
}
void collision(int direction[]) {
	
}
void Pmove() {
	int tmpx = Px;
	int tmpy = Py;
	
	totalmap[Py][Px] = 2;
	
	//이동
	if (_kbhit()) {
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py -= 1;
			if (totalmap[Py][Px] == 1) {
				Py = tmpy;
			}
			
			break;
		case DOWN:
			
			Py += 1;
			if (totalmap[Py][Px] == 1) {
				Py = tmpy;
			}
			break;
		case LEFT:
			Px -= 1;
			if (totalmap[Py][Px] == 1) {
				Px = tmpx;
			}
			
			break;
		case RIGHT:
			Px += 1;
			if (totalmap[Py][Px] == 1) {
				Px = tmpx;
			}
			
			break;
		}
		totalmap[tmpy][tmpx] = 0;
	}
	
}
//키입력에 따른 움직임



void Cursorhide() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void initialize() {
	Cursorhide();
	
	L_Dcraft();
	L_Ucraft();
	R_Ucraft();
	R_Dcraft();
	totalmap[Py][Px] = 2;
	
}

int main() {
	
	//initialize
	initialize();
	//------------------
	//아마 while문
	Player();
	TMP(totalmap, 30, 30);//이것도 임시... 초기화에 넣어야하나? 일단은 움ㅁ직임
	
	while (1) {
		{
			db_saving(frontbuff);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			Player();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving(backbuff);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시
		}
	}
	

	//한개의 씬 끝

};
//*현재 비디오 컨트롤러가 읽고 있는 버퍼를 프론트 버퍼로 정의,
//화면에 내용에 보이지 않지만 그래픽 프로세서가 기록중인 버퍼가 백버퍼이다.
//따라서 버퍼는 프론트버퍼와 백버퍼를 반복한다.

