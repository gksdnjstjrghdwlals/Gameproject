#define HEIGHT 15
#define WIDTH 15
#define HEIGHT2 10
#define WIDTH2 10
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define THEIGHT 30
#define TWIDTH 30
#define THEIGHT2 20
#define TWIDTH2 20
#define THEIGHT3 10
#define TWIDTH3 10
#define LMIT_TICK 1000000

int totalmap[30][30] = { {0}, {0} };
int totalmap2[THEIGHT2][TWIDTH2] = { {0}, {0} };
int totalmap3[THEIGHT3][TWIDTH3] = { {0}, {0} };


int backbuff[THEIGHT][TWIDTH];
int frontbuff[THEIGHT][TWIDTH];
int backbuff2[THEIGHT2][TWIDTH2];
int frontbuff2[THEIGHT2][TWIDTH2];
int backbuff3[THEIGHT3][TWIDTH3];
int frontbuff3[THEIGHT3][TWIDTH3];

//���α׷� ���� �����
int RUN = 1;


int premise = 1;//��������
int gameover = 0;
int direction1 = 1;
int direction1_2 = 1;
int direction2 = 1;
int direction3 = 1;
int direction4 = 1;

int cnt_ai = 0;
int cnt_ai_2 = 0;
int cnt_ai2 = 0;
int cnt_ai3 = 0;
int tmp_cnt = 0;
//�÷��̾� ��ġ
int Px = 15, Py = 15;
int Px2 = 12, Py2 = 12;
int Px3 = 4, Py3 = 4;
//�ΰ����� ����
int Ax_1 = 7, Ay_1 = 7;
int Ax_2 = 20, Ay_2 = 20;
int Ax_3 = 2, Ay_3 = 26;
int Ax_4 = 26, Ay_4 = 7;
//1��������
int Ax2_1 = 5, Ay2_1 = 5;
int Ax2_2 = 8, Ay2_2 = 10;
int Ax2_3 = 10, Ay2_3 = 3;

int Ax3 = 3, Ay3 = 3;
int Ax4 = 3, Ay4 = 3;

int confirm_U_1 = 0;
int confirm_D_1 = 0;
int confirm_R_1 = 0;
int confirm_L_1 = 0;

int confirm_U_2 = 0;
int confirm_D_2 = 0;
int confirm_R_2 = 0;
int confirm_L_2 = 0;

int confirm_U_3 = 0;
int confirm_D_3 = 0;
int confirm_R_3 = 0;
int confirm_L_3 = 0;

int confirm_U_4 = 0;
int confirm_D_4 = 0;
int confirm_R_4 = 0;
int confirm_L_4 = 0;


int confirm_U2_1 = 0;
int confirm_D2_1 = 0;
int confirm_R2_1 = 0;
int confirm_L2_1 = 0;

int confirm_U2_2 = 0;
int confirm_D2_2= 0;
int confirm_R2_2 = 0;
int confirm_L2_2 = 0;

int confirm_U2_3 = 0;
int confirm_D2_3 = 0;
int confirm_R2_3 = 0;
int confirm_L2_3 = 0;

int confirm_U3 = 0;
int confirm_D3 = 0;
int confirm_R3 = 0;
int confirm_L3 = 0;
//
int Bpx, Bpy;

int BART_CLEAR_CNT = 0;
int AI_BART_CLEAR_CNT = 0;



//time
int timeTick = 0;

void change_color(int color_number);
void AI();
void stage_end();
void re_quest();
void gotoxy(int x, int y);
void Pmove();
void Player();
void Pmove2();
void Player2();
void Pmove3();
void Player3();
void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth);
void gameoverfuc();
int randomize();
void L_Dcraft();
void L_Ucraft();
void R_Dcraft();
void R_Ucraft();
void draw_cutscene(int map[][TWIDTH], int height, int width);
//
void TMP(int map[][30], int height, int width);

void draw_cutscene(int map[][TWIDTH], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}


		}
		printf("\n");
	}
}
void draw_cutscene2(int map[][50], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}


		}
		printf("\n");
	}
}
void game_OVER_SCENE(int map[][76], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}


		}
		printf("\n");
	}
}

void re_quest() {
	printf("���ӿ���\n");
	
	Sleep(3000);

	int re_loop = 1;
	printf("������ ����Ͻðڽ��ϱ�? Y/N");
	while (re_loop) {
		char a = _getch();
		switch (a) {
		case 'y':
		case 'Y':
			RUN = 1;
			re_loop = 0;
			break;
		case 'n':
		case 'N':
			RUN = 0;
			re_loop = 0;
			break;
		}
	}
	system("cls");
}

void stage_end() {
	gotoxy(31, 31);
	printf("\n");
	change_color(11);
	

	printf("�������� Ŭ����\n");
	printf("���� ���� %d��\n", AI_BART_CLEAR_CNT);
	printf("����� ���� %d��\n", BART_CLEAR_CNT);
	Sleep(3000);
	premise = 1;
	BART_CLEAR_CNT = 0;
	AI_BART_CLEAR_CNT = 0;

	//�ϴ� �⺻���� Ʋ�� ���������
	//�Ѱ��� �� ��
	system("cls");

}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void change_color(int color_number) //�ܼ� ��»��� ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int randomize(void) {//�������� ���� ����������
	srand(time(NULL));
	int random = 0;
	random = rand() % 8 + 1;//1~10
	return random;
}

void Cursorhide() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
