#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

int go = 0;
int* ptr_go;
*ptr_go = &go;

int game_time = 10;

int totalmap[30][30] = { {0}, {0}


};
//�÷��̾� ��ġ
int Px = 15, Py = 15;
// �� ��ġ
int Bx = 2, By = 2;

void change_color(int color_number);
void gotoxy(int x, int y);
void Pmove();
void Player();
int crash(int* map, int x, int y);
void print_map();
void baseC();
void double_buff_render();
void Bot();
void Bmove();
void printf_time();
int randomize();
void L_Dcraft();
void L_Ucraft();
void R_Dcraft();
void R_Ucraft();
void printf_time();
void opening();

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
					printf("��");
				}
				else if (backbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(10);
					printf("��");
				}
				else if (backbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
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
			else if (map[i][j] == 3) {
				change_color(10);
				printf("��");
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


	Pmove(&ptr_go);

}
void collision(int direction[]) {

}
void Pmove(int* ptr_go) {
	ptr_go = 0;
	int tmpx = Px;
	int tmpy = Py;

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
			ptr_go = 1;
			break;
		case DOWN:

			Py += 1;
			if (totalmap[Py][Px] == 1) {
				Py = tmpy;
			}
			ptr_go = 1;
			break;
		case LEFT:
			Px -= 1;
			if (totalmap[Py][Px] == 1) {
				Px = tmpx;
			}
			ptr_go = 1;
			break;
		case RIGHT:
			Px += 1;
			if (totalmap[Py][Px] == 1) {
				Px = tmpx;
			}
			ptr_go = 1;
			break;
		}
		totalmap[tmpy][tmpx] = 0;
	}
	return ptr_go;

}
//Ű�Է¿� ���� ������
void Bot() {
	Bmove(&ptr_go);
}
void Bmove(int* ptr_go) {
	int random_bot = randomize();
	int tmpx = Bx;
	int tmpy = By;

	totalmap[By][Bx] = 3;

	//�̵�
	if (ptr_go == 1) {
		switch (random_bot) {
		case 1:
			By -= 1;
			if (totalmap[By][Bx] == 1) {
				By = tmpy;
			}

			break;
		case 2:
			By -= 1;
			if (totalmap[By][Bx] == 1) {
				By = tmpy;
			}

			break;
		case 3:

			By += 1;
			if (totalmap[By][Bx] == 1) {
				By = tmpy;
			}
			break;
		case 4:

			By += 1;
			if (totalmap[By][Bx] == 1) {
				By = tmpy;
			}
			break;
		case 5:
			Bx -= 1;
			if (totalmap[By][Bx] == 1) {
				Bx = tmpx;
			}

			break;
		case 6:
			Bx -= 1;
			if (totalmap[By][Bx] == 1) {
				Bx = tmpx;
			}

			break;
		case 7:
			Bx += 1;
			if (totalmap[By][Bx] == 1) {
				Bx = tmpx;
			}

			break;
		case 8:
			Bx += 1;
			if (totalmap[By][Bx] == 1) {
				Bx = tmpx;
			}

			break;
		}
		totalmap[tmpy][tmpx] = 0;
	}
	
	
}


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

void opening() {
	printf("���� �� ���� �汸 �������� ���� ��� �̾߱�.....\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("�汸�� ���� �� ���� ��簡 �汸�� �̿��Ͽ� ���͸� ��� �Ǵµ�...");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("������ �����մϴ�.");
}
void printf_time(int time) {
	
	while (1) {
		time -= 1;
		Sleep(1000);


		if (time == 0) {
			printf("Ÿ�ӿ���\n");
			break;
		}
	}
	return time;
}
int main() {
	int time = 10;
	for (int i = 0; i < 15; i++) {
		gotoxy(10, 11);
		change_color(i);
		printf("���� �� ���� �汸 �������� ���� ��� �̾߱�");
		Sleep(100);

		system("cls");
	}
	opening();
	Sleep(1000);
	system("cls");


	//initialize
	initialize();
	//------------------
	//�Ƹ� while��
	Bot();
	Player();
	//Bot();
	TMP(totalmap, 30, 30);//�̰͵� �ӽ�... �ʱ�ȭ�� �־���ϳ�? �ϴ��� ������
	//printf_time();
	while (1) {
		time -= 1;
		Sleep(1000);


		if (time == 0) {
			printf("Ÿ�ӿ���\n");
			break;
		}
	}
	while (1) {
		{
			db_saving(frontbuff);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//����Ʈ���� ��������
			Player();//�̻���� �۵��ߵ�
			//��� ó���� ������ ����� �������� 
			Bot();
			db_saving(backbuff);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff();//�ҿϼ� ������������
			/*TMP(totalmap, TWIDTH, THEIGHT);*///�̰� ����۹�����
			//system("cls");//�̰� �ӽ�
			
			
		}
		if (time == 0) {
			printf("Ÿ�ӿ���\n");
			break;
		}
	}


	//�Ѱ��� �� ��

};
//*���� ���� ��Ʈ�ѷ��� �а� �ִ� ���۸� ����Ʈ ���۷� ����,
//ȭ�鿡 ���뿡 ������ ������ �׷��� ���μ����� ������� ���۰� ������̴�.
//���� ���۴� ����Ʈ���ۿ� ����۸� �ݺ��Ѵ�.