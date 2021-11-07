#include <stdio.h>
#define HEIGHT 15
#define WIDTH 30
#define THEIGHT 30
#define TWIDTH 60

char totalmap[THEIGHT][TWIDTH] = { {0}, {0} };

char tmparr2[HEIGHT][WIDTH] = { {0}, {0} };

char arr2[HEIGHT][WIDTH] = {
	{"■□■□□■■■□■■□□■■"},
	{"■□□□■■□□□■■□■■□"},
	{"■□■□□□□■□□□□■■■"},
	{"■□□■■□■■□■■□□□■"},
	{"■■■■□□□■□■■■■□□"},
	{"■■□□□■□□□■□□□□□"},
	{"■■□■□■■□■■□■■■■"},
	{"■■□■□■■□■■□□□■□"},
	{"■■□■□□□□■□□■□■■"},
	{"■□□□□■■■■□■■□□□"},
	{"■■■□■□□□□□□■□■■"},
	{"■□■□□□■■□■□■□□■"},
	{"■□■■□■■□□■□■■□□"},
	{"■□□□□□□□■■□□□□□"},
	{"■■■■■■■■■■■■■■■"}
};
char arr3[HEIGHT][WIDTH] = {
	{"■□■□□■■■□■■□□■■"},
	{"□□□□■■□□□■■□■■■"},
	{"□□■□□□□■□□□□■■■"},
	{"■□□■■□■■□■■□□□■"},
	{"■■■■□□□■□■■■■□■"},
	{"□■□□□■□□□■□□□□■"},
	{"□■□■□■■□■■□■■■■"},
	{"□■□■□■■□■■□□□■■"},
	{"□■□■□□□□■□□■□■■"},
	{"□□□□□■■■■□■■□□■"},
	{"■■■□■□□□□□□■□■■"},
	{"□□■□□□■■□■□■□□■"},
	{"■□■■□■■□□■□■■□■"},
	{"□□□□□□□□■■□□□□■"},
	{"■■■■■■■■■■■■■■■"}
};
char arr4[HEIGHT][WIDTH] = {
	{"■■■■■■■■■■■■■■■"},
	{"□□□□■■□□□■■□■■■"},
	{"□□■□□□□■□□□□■■■"},
	{"■□□■■□■■□■■□□□■"},
	{"■■■■□□□■□■■■■□■"},
	{"□■□□□■□□□■□□□□■"},
	{"□■□■□■■□■■□■■■■"},
	{"□■□■□■■□■■□□□■■"},
	{"□■□■□□□□■□□■□■■"},
	{"□□□□□■■■■□■■□□■"},
	{"■■■□■□□□□□□■□■■"},
	{"□□■□□□■■□■□■□□■"},
	{"■□■■□■■□□■□■■□■"},
	{"□□□□□□□□■■□□□□■"},
	{"■□□■□■□■■■□■■■■"}
};

char arr5[HEIGHT][WIDTH] = {
	{"■■■■■■■■■■■■■■■"},
	{"■□□□■■□□□■■□□□□"},
	{"■□■□□□□■□□□□■■■"},
	{"■□□■■□■■□■■□□□□"},
	{"■■■■□□□■□■■■■□■"},
	{"■■□□□■□□□■□□□□□"},
	{"■■□■□■■□■■□■■■□"},
	{"■■□■□■■□■■□□□■■"},
	{"■■□■□□□□■□□■□■■"},
	{"■□□□□■■■■□■■□□□"},
	{"■■■□■□□□□□□■□■■"},
	{"■□■□□□■■□■□■□□□"},
	{"■□■■□■■□□■□■■□■"},
	{"■□□□□□□□■■□□□□■"},
	{"■□□■□■□■■■□■■■■"}
};
//유니코드는 배열 2칸을 차지하는듯
void baseC(char map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth) {
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
//토탈맵의 배열첨자와 맵의 첨자를 따로 구현할것

void TEST(char map[][TWIDTH],  int Hheight, int Hwidth) {
	//그냥 최종 맵의 크기가 잘 나왔는지 테스트해보기위한 함수
	for (int i = 0; i < Hheight; i++) {
		
		for (int j = 0; j < Hwidth; j++) {
			map[i][j] = '@';
		}
		
	}
	/*for (int i2 = 0; i2 < Hheight; i2++) {

		for (int j2 = 0; j2 < Hwidth; j2++) {
			printf("%c", map[i2][j2]);
		}
		printf("\n");
	}*/
}

void MP(char map[][WIDTH], int height, int width) {
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void TMP(char map[][TWIDTH], int height, int width) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main() {

	/*MP(arr2, HEIGHT-15, WIDTH);
	crafting()*/
	/*baseC(arr2, 0,7,0,15);
	
	MP(totalmap, THEIGHT, TWIDTH);*/
	TEST(totalmap, THEIGHT, TWIDTH);
	baseC(arr2, 15, 30, 0, 30);
	baseC(arr3, 15, 30,  30, 60);
	baseC(arr4, 0, 15, 30, 60);
	baseC(arr5, 0, 15, 0, 30);
	TMP(totalmap, THEIGHT, TWIDTH);
}