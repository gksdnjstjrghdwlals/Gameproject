#include <stdio.h>

#define HEIGHT 30
#define WIDTH 30
#define THEIGHT 60
#define TWIDTH 60

char tmparr2[HEIGHT][WIDTH] = { {0}, {0} };
char arr2[HEIGHT][WIDTH] = {
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"},
	{"����������������"}
};
void crafting()




void MP(char map[][WIDTH], int height, int width) {
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	
}


int main() {

	MP(arr2, HEIGHT-15, WIDTH);
	
	
}