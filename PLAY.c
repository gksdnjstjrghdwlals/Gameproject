#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

//���α׷� ���� �����
int RUN = 1;


int premise = 1;//��������
int gameover = 0;
int direction = 1;
int totalmap[30][30] = { {0}, {0} };
int Mtotalmap[20][20] = { {0}, {0} };
int Ltotalmap[10][10] = { {0}, {0} };


int cnt_ai = 0;
//�÷��̾� ��ġ
int Px = 15, Py = 15;
//�ΰ����� ����
int Ax = 7, Ay = 7;
int confirm_U = 0;
int confirm_D = 0;
int confirm_R = 0;
int confirm_L = 0;
//
int Bpx, Bpy;

int BART_CLEAR_CNT = 0;
int AI_BART_CLEAR_CNT = 0;
void change_color(int color_number);
void AI();
void gotoxy(int x, int y);
void Pmove();
void Player();
void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth);

int randomize();
void L_Dcraft();
void L_Ucraft();
void R_Dcraft();
void R_Ucraft();

void TMP(int map[][30], int height, int width);

void MAI();
void MPmove();
void MPlayer();
void MbaseC(int map[][10], int Lheight, int Hheight, int Lwidth, int Hwidth);

void ML_Dcraft();
void ML_Ucraft();
void MR_Dcraft();
void MR_Ucraft();

void MTMP(int map[][20], int height, int width);

void LAI();
void LPmove();
void LPlayer();
void LbaseC(int map[][10], int Lheight, int Hheight, int Lwidth, int Hwidth);



void LTMP(int map[][20], int height, int width);
char name[10];

void opening();
char input_name();
void finish(int BART_CLEAR_CNT, int AI_BART_CLEAR_CNT);
void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
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

void db_saving(int buffmap[][TWIDTH]) {//int�� �ٲ۴�


	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			buffmap[i][j] = totalmap[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�

void double_buff() {
	int tmpx = 0, tmpy = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < THEIGHT; i++) {
		for (int j = 0; j < TWIDTH; j++) {
			if (backbuff[i][j] != frontbuff[i][j]) {
				if (backbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					change_color(5);
					printf("��");
				}
				else if (backbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				else if (backbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (backbuff[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (backbuff[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//�ҿϼ�

int randomize(void) {//�������� ���� ����������
	srand(time(NULL));
	int random = 0;
	random = rand() % 8 + 1;//1~10
	return random;
}

void L_Ucraft() {
	//���� �� �� ����
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
	//�� �߰��ؾ���



}
void L_Dcraft() {
	//���� �Ʒ� �� ����
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
	//������ �Ʒ� �� ����
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
	//������ �� �� ����
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

void TMP(int map[][30], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}
			else if (map[i][j] == 2) {

				printf("��");
			}

		}
		printf("\n");
	}
}

void change_color(int color_number) //�ܼ� ��»��� ��Ÿ���� �Լ�
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
	//{��,�Ʒ�,��,��}

	Pmove();
}

void Pmove() {
	int tmpx = Px;
	int tmpy = Py;
	int direction = randomize();
	totalmap[Py][Px] = 2;

	//�̵�
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
		totalmap[tmpy][tmpx] = 3;
	}
}
//Ű�Է¿� ���� ������



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

int bart_detect() {

	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			if (totalmap[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (totalmap[i][j] == 6) {
				AI_BART_CLEAR_CNT++;

			}



		}
	}
	if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		premise = 0;

	}
	else {
		gameover = 1;
		premise = 0;
	}

}

void timer() {

	clock_t start = clock();
	clock_t end = clock();
	int time = ((int)end - start / CLOCKS_PER_SEC) / 1000; //�ʴ��� ��ȯ


	if (time == 5) {
		bart_detect();

	}



}

void AI() {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	int lazy = randomize();
	tmpx = Ax;
	tmpy = Ay;

	if (cnt_ai % 3000 == 0) {
		if (totalmap[Ay][Ax] != 1) {
			if (direction == 1) {//�� 1
				--Ay;
			}
			else if (direction == 2) {//�Ʒ� 2
				++Ay;
			}
			else if (direction == 3) {//�� 3
				--Ax;
			}
			else if (direction == 4) {//���� 4
				++Ax;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (totalmap[Ay][Ax] == 1) {
			if (select <= 2 && confirm_U != 1) {//�� 1

				direction = 1;
				//�缳��
				confirm_U = 1;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && confirm_D != 1) {//�Ʒ� 2
				direction = 2;
				//�缳��
				confirm_U = 0;
				confirm_D = 1;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && confirm_L != 1) {//�� 3
				direction = 3;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && confirm_R != 1) {//���� 4
				direction = 4;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			Ax = tmpx;
			Ay = tmpy;
		}

	}

	/*Sleep(500);*/
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	totalmap[tmpy][tmpx] = 6;
	totalmap[Ay][Ax] = 5;
	cnt_ai++;
}


//2�ܰ� 
//����������������������������������������������������������������������������
//������������������������������������������������������������������������������





void MbaseC(int map[][10], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
	int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			Mtotalmap[i][j] = map[i2][j2];
			j2++;
		}
		i2++;
	}
}

void Mdb_saving(int mbuffmap[][20]) {//int�� �ٲ۴�


	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			mbuffmap[i][j] = Mtotalmap[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�

void Mdouble_buff() {
	int tmpx = 0, tmpy = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (mbackbuff[i][j] != mfrontbuff[i][j]) {
				if (mbackbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					change_color(5);
					printf("��");
				}
				else if (mbackbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				else if (mbackbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (mbackbuff[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (mbackbuff[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//�ҿϼ�


void ML_Ucraft() {
	//���� �� �� ����
	int select = randomize();
	if (select <= 2) {
		MbaseC(left2_u1, 0, 10, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		MbaseC(left2_u2, 0, 10, 0, 10);
	}
	else if (select > 4 && select <= 6) {
		MbaseC(left2_u3, 0, 10, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		MbaseC(left2_u4, 0, 10, 0, 10);
	}
	//�� �߰��ؾ���



}
void ML_Dcraft() {
	//���� �Ʒ� �� ����
	int select = randomize();
	if (select <= 2) {
		MbaseC(left2_d1, 10, 20, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		MbaseC(left2_d2, 10, 20, 0, 10);
	}
	else if (select > 4 && select <= 6) {
		MbaseC(left2_d3, 10, 20, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		MbaseC(left2_d4, 10, 20, 0, 10);
	}

}
void MR_Dcraft() {
	//������ �Ʒ� �� ����
	int select = randomize();
	if (select <= 2) {
		MbaseC(right2_d1, 10, 20, 10, 20);
	}
	else if (select > 2 && select <= 4) {
		MbaseC(right2_d2, 10, 20, 10, 20);
	}
	else if (select > 4 && select <= 6) {
		MbaseC(right2_d3, 10, 20, 10, 20);
	}
	else if (select > 6 && select <= 8) {
		MbaseC(right2_d4, 10, 20, 10, 20);
	}

}
void MR_Ucraft() {
	//������ �� �� ����
	int select = randomize();
	if (select <= 2) {
		MbaseC(right2_u1, 0, 10, 10, 20);
	}
	else if (select > 2 && select <= 4) {
		MbaseC(right2_u2, 0, 10, 10, 20);
	}
	else if (select > 4 && select <= 6) {
		MbaseC(right2_u3, 0, 10, 10, 20);
	}
	else if (select > 6 && select <= 8) {
		MbaseC(right2_u4, 0, 10, 10, 20);
	}

}

void MTMP(int map[][20], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}
			else if (map[i][j] == 2) {

				printf("��");
			}

		}
		printf("\n");
	}
}


void MPlayer() {
	//{��,�Ʒ�,��,��}

	MPmove();
}

void MPmove() {
	int tmpx = Px;
	int tmpy = Py;
	int direction = randomize();
	Mtotalmap[Py][Px] = 2;

	//�̵�
	if (_kbhit()) {
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py -= 1;
			if (Mtotalmap[Py][Px] == 1) {
				Py = tmpy;
			}

			break;
		case DOWN:

			Py += 1;
			if (Mtotalmap[Py][Px] == 1) {
				Py = tmpy;
			}
			break;
		case LEFT:
			Px -= 1;
			if (Mtotalmap[Py][Px] == 1) {
				Px = tmpx;
			}

			break;
		case RIGHT:
			Px += 1;
			if (Mtotalmap[Py][Px] == 1) {
				Px = tmpx;
			}

			break;
		}
		Mtotalmap[tmpy][tmpx] = 3;
	}
}
//Ű�Է¿� ���� ������




void Minitialize() {
	Cursorhide();

	ML_Dcraft();
	ML_Ucraft();
	MR_Ucraft();
	MR_Dcraft();
	Mtotalmap[Py][Px] = 2;

}

int Mbart_detect() {

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			if (Mtotalmap[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (Mtotalmap[i][j] == 6) {
				AI_BART_CLEAR_CNT++;

			}



		}
	}
	if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		premise = 0;

	}
	else {
		gameover = 1;
		premise = 0;
	}

}


void MAI() {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	int lazy = randomize();
	tmpx = Ax;
	tmpy = Ay;

	if (cnt_ai % 3000 == 0) {
		if (Mtotalmap[Ay][Ax] != 1) {
			if (direction == 1) {//�� 1
				--Ay;
			}
			else if (direction == 2) {//�Ʒ� 2
				++Ay;
			}
			else if (direction == 3) {//�� 3
				--Ax;
			}
			else if (direction == 4) {//���� 4
				++Ax;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (Mtotalmap[Ay][Ax] == 1) {
			if (select <= 2 && confirm_U != 1) {//�� 1

				direction = 1;
				//�缳��
				confirm_U = 1;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && confirm_D != 1) {//�Ʒ� 2
				direction = 2;
				//�缳��
				confirm_U = 0;
				confirm_D = 1;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && confirm_L != 1) {//�� 3
				direction = 3;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && confirm_R != 1) {//���� 4
				direction = 4;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			Ax = tmpx;
			Ay = tmpy;
		}

	}

	/*Sleep(500);*/
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	Mtotalmap[tmpy][tmpx] = 6;
	Mtotalmap[Ay][Ax] = 5;
	cnt_ai++;
}

//3�ܰ� 
//����������������������������������������������������������������������
//����������������������������������������������������������������������
//������������������������������������������������������������������������������������������������������������������������������

void LbaseC(int map[][10], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
	//int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		//j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			Ltotalmap[i][j] = map[i][j];
			//j2++;
		}
		//i2++;
	}
}

void Ldb_saving(int lbuffmap[][10]) {//int�� �ٲ۴�


	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			lbuffmap[i][j] = Ltotalmap[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�

void Ldouble_buff() {
	int tmpx = 0, tmpy = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (lbackbuff[i][j] != lfrontbuff[i][j]) {
				if (lbackbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					change_color(5);
					printf("��");
				}
				else if (lbackbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				else if (lbackbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (lbackbuff[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (lbackbuff[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//�ҿϼ�
void L_craft() {
	int select = randomize();
	if (select <= 2) {
		LbaseC(last_1, 0, 10, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		LbaseC(last_2, 0, 10, 0, 10);
	}
	else if (select > 4 && select <= 6) {
		LbaseC(last_3, 0, 10, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		LbaseC(last_4, 0, 10, 0, 10);
	}
}



void LTMP(int map[][10], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}
			else if (map[i][j] == 2) {

				printf("��");
			}

		}
		printf("\n");
	}
}


void LPlayer() {
	//{��,�Ʒ�,��,��}

	LPmove();
}

void LPmove() {
	int tmpx = Px;
	int tmpy = Py;
	int direction = randomize();
	Ltotalmap[Py][Px] = 2;

	//�̵�
	if (_kbhit()) {
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py -= 1;
			if (Ltotalmap[Py][Px] == 1) {
				Py = tmpy;
			}

			break;
		case DOWN:

			Py += 1;
			if (Ltotalmap[Py][Px] == 1) {
				Py = tmpy;
			}
			break;
		case LEFT:
			Px -= 1;
			if (Ltotalmap[Py][Px] == 1) {
				Px = tmpx;
			}

			break;
		case RIGHT:
			Px += 1;
			if (Ltotalmap[Py][Px] == 1) {
				Px = tmpx;
			}

			break;
		}
		Ltotalmap[tmpy][tmpx] = 3;
	}
}
//Ű�Է¿� ���� ������




void Linitialize() {
	Cursorhide();
	L_craft();

	Ltotalmap[Py][Px] = 2;

}

int Lbart_detect() {

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			if (Ltotalmap[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (Ltotalmap[i][j] == 6) {
				AI_BART_CLEAR_CNT++;

			}



		}
	}
	if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		premise = 0;

	}
	else {
		gameover = 1;
		premise = 0;
	}

}


void LAI() {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	int lazy = randomize();
	tmpx = Ax;
	tmpy = Ay;

	if (cnt_ai % 3000 == 0) {
		if (Ltotalmap[Ay][Ax] != 1) {
			if (direction == 1) {//�� 1
				--Ay;
			}
			else if (direction == 2) {//�Ʒ� 2
				++Ay;
			}
			else if (direction == 3) {//�� 3
				--Ax;
			}
			else if (direction == 4) {//���� 4
				++Ax;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (Ltotalmap[Ay][Ax] == 1) {
			if (select <= 2 && confirm_U != 1) {//�� 1

				direction = 1;
				//�缳��
				confirm_U = 1;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && confirm_D != 1) {//�Ʒ� 2
				direction = 2;
				//�缳��
				confirm_U = 0;
				confirm_D = 1;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && confirm_L != 1) {//�� 3
				direction = 3;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && confirm_R != 1) {//���� 4
				direction = 4;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			Ax = tmpx;
			Ay = tmpy;
		}

	}

	/*Sleep(500);*/
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	Ltotalmap[tmpy][tmpx] = 6;
	Ltotalmap[Ay][Ax] = 5;
	cnt_ai++;
}
void timer1() {

	clock_t start = clock();
	clock_t end = clock();
	int time = ((int)end - start / CLOCKS_PER_SEC) / 1000; //�ʴ��� ��ȯ


	if (time == 5) {
		bart_detect();

	}



}void timer2() {

	clock_t start = clock();
	clock_t end = clock();
	int time = ((int)end - start / CLOCKS_PER_SEC) / 1000; //�ʴ��� ��ȯ


	if (time == 5) {
		bart_detect();

	}



}
char input_name() {
	printf("�̸��� �Է��ϼ���. : ");
	scanf("%s", &name);
	printf("�ȳ��ϼ��� %s ��\n", name);
	return name;
}
void opening() {
	printf("���� �� ���� �汸 �������� ���� ��� �̾߱�.....\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("���丮 ��¼�� ��¼��.....");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("������ �����մϴ�.");
}
void finish(int BART_CLEAR_CNT, int AI_BART_CLEAR_CNT) {
	if (BART_CLEAR_CNT <= AI_BART_CLEAR_CNT) {
		printf("�ᱹ %s�� ���� �̱��� ���ϰ� ������ȴ�......", name);

		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		change_color(4);
		printf("\n  ������     ����       ���       ��� ��������      ��������   ���     ��� �������� ��������� ");	Sleep(100);
		printf("\n���    ���    ��� ���     ����   ���� ���              ���          ��� ���     ��� ���           ���          ���");	Sleep(100);
		printf("\n���           ���   ���    ����� ���� ���              ���          ��� ���     ��� ���           ���          ���");	Sleep(100);
		printf("\n���   ����  ����  ���   ���  ��� ��� �������      ���          ��� ���     ��� ������     ��������� ");	Sleep(100);
		printf("\n���    ���   �������� ���       ��� ���              ���          ���  ���   ���  ���           ���      ���     ");	Sleep(100);
		printf("\n���    ���   ���     ���  ���       ��� ���              ���          ���   ��� ���   ���           ���        ��� ");	Sleep(100);
		printf("\n �������  ���     ���  ���       ��� ��������      ��������       ����    �������� ���          ���");	Sleep(100);

		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	}
	else if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		printf("���� ��� %s�� ���� ��ҷ� ���ϴµ�.........", name);
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	}

}
int main() {
	input_name();
	opening();
	system("cls");
	//���α׷��� ���� ����
	while (RUN) {
		//initialize
		initialize();
		//------------------
		//�Ƹ� while��

		TMP(totalmap, 30, 30);//�̰͵� �ӽ�... �ʱ�ȭ�� �־���ϳ�? �ϴ��� ������

		while (premise) {
			{

				timer();
				db_saving(frontbuff);

				/*TMP(frontbuff, TWIDTH, THEIGHT);*/
				//����Ʈ���� ��������
				AI();
				Player();//�̻���� �۵��ߵ�
				//��� ó���� ������ ����� �������� 
				db_saving(backbuff);
				/*TMP(backbuff, TWIDTH, THEIGHT);*/
				double_buff();//�ҿϼ� ������������
				/*TMP(totalmap, TWIDTH, THEIGHT);*///�̰� ����۹�����
				//system("cls");//�̰� �ӽ�

				//�ð��� ������ �÷��̾��� ������ ��������

			}
		}
		gotoxy(31, 31);
		printf("\n");
		change_color(11);
		if (gameover == 1) {
			printf("���ӿ���\n");
			Sleep(3000);
			premise = 1;

		}
		printf("�������� Ŭ����\n");
		printf("���� ���� %d��\n", AI_BART_CLEAR_CNT);
		printf("����� ���� %d��\n", BART_CLEAR_CNT);
		Sleep(3000);
		premise = 1;

		finish(BART_CLEAR_CNT, AI_BART_CLEAR_CNT);
		BART_CLEAR_CNT = 0;
		AI_BART_CLEAR_CNT = 0;

		//�ϴ� �⺻���� Ʋ�� ���������
		//�Ѱ��� �� ��
		system("cls");



		Px = 15, Py = 15;
		//�ΰ����� ����
		Ax = 7, Ay = 7;
		Minitialize();
		//------------------
		//�Ƹ� while��

		MTMP(Mtotalmap, 20, 20);//�̰͵� �ӽ�... �ʱ�ȭ�� �־���ϳ�? �ϴ��� ������


		while (premise) {
			{

				timer1();
				Mdb_saving(mfrontbuff);

				/*TMP(frontbuff, TWIDTH, THEIGHT);*/
				//����Ʈ���� ��������
				MAI();
				MPlayer();//�̻���� �۵��ߵ�
				//��� ó���� ������ ����� �������� 
				Mdb_saving(mbackbuff);
				/*TMP(backbuff, TWIDTH, THEIGHT);*/
				Mdouble_buff();//�ҿϼ� ������������
				/*TMP(totalmap, TWIDTH, THEIGHT);*///�̰� ����۹�����
				//system("cls");//�̰� �ӽ�

				//�ð��� ������ �÷��̾��� ������ ��������

			}
		}
		gotoxy(31, 31);
		printf("\n");
		change_color(11);
		if (gameover == 1) {
			printf("���ӿ���\n");
			Sleep(3000);
			premise = 1;

		}
		printf("�������� Ŭ����\n");
		printf("���� ���� %d��\n", AI_BART_CLEAR_CNT);
		printf("����� ���� %d��\n", BART_CLEAR_CNT);
		Sleep(3000);
		premise = 1;
		finish(BART_CLEAR_CNT, AI_BART_CLEAR_CNT);
		BART_CLEAR_CNT = 0;
		AI_BART_CLEAR_CNT = 0;

		//�ϴ� �⺻���� Ʋ�� ���������
		//�Ѱ��� �� ��
		system("cls");


		Px = 5, Py = 5;
		//�ΰ����� ����
		Ax = 7, Ay = 7;

		Linitialize();
		//------------------
		//�Ƹ� while��

		LTMP(Ltotalmap, 10, 10);//�̰͵� �ӽ�... �ʱ�ȭ�� �־���ϳ�? �ϴ��� ������


		while (premise) {
			{

				timer2();
				Ldb_saving(lfrontbuff);

				/*TMP(frontbuff, TWIDTH, THEIGHT);*/
				//����Ʈ���� ��������
				LAI();
				LPlayer();//�̻���� �۵��ߵ�
				//��� ó���� ������ ����� �������� 
				Ldb_saving(lbackbuff);
				/*TMP(backbuff, TWIDTH, THEIGHT);*/
				Ldouble_buff();//�ҿϼ� ������������
				/*TMP(totalmap, TWIDTH, THEIGHT);*///�̰� ����۹�����
				//system("cls");//�̰� �ӽ�

				//�ð��� ������ �÷��̾��� ������ ��������

			}
		}
		gotoxy(31, 31);
		printf("\n");
		change_color(11);
		if (gameover == 1) {
			printf("���ӿ���\n");
			Sleep(3000);
			premise = 1;

		}
		printf("�������� Ŭ����\n");
		printf("���� ���� %d��\n", AI_BART_CLEAR_CNT);
		printf("����� ���� %d��\n", BART_CLEAR_CNT);
		Sleep(3000);
		premise = 1;
		finish(BART_CLEAR_CNT, AI_BART_CLEAR_CNT);
		BART_CLEAR_CNT = 0;
		AI_BART_CLEAR_CNT = 0;

		//�ϴ� �⺻���� Ʋ�� ���������
		//�Ѱ��� �� ��
		system("cls");
	}
	

};