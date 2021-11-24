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

int totalmap[30][30] = { {0}, {0} };
int totalmap2[THEIGHT2][TWIDTH2] = { {0}, {0} };
int totalmap3[THEIGHT3][TWIDTH3] = { {0}, {0} };


int backbuff[THEIGHT][TWIDTH];
int frontbuff[THEIGHT][TWIDTH];
int backbuff2[THEIGHT2][TWIDTH2];
int frontbuff2[THEIGHT2][TWIDTH2];
int backbuff3[THEIGHT3][TWIDTH3];
int frontbuff3[THEIGHT3][TWIDTH3];

//프로그램 실행 제어변수
int RUN = 1;


int premise = 1;//스테이지
int gameover = 0;
int direction = 1;


int cnt_ai = 0;
//플레이어 위치
int Px = 15, Py = 15;
int Px2 = 12, Py2 = 12;
int Px3 = 4, Py3 = 4;
//인공지능 관련
int Ax = 7, Ay = 7;
int Ax2 = 5, Ay2 = 5;
int Ax3 = 3, Ay3 = 3;

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
void Pmove2();
void Player2();
void Pmove3();
void Player3();
void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth);

int randomize();
void L_Dcraft();
void L_Ucraft();
void R_Dcraft();
void R_Ucraft();

void TMP(int map[][30], int height, int width);
