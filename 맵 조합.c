#include <stdio.h>


#define WIDTH 15
#define HEIGHT 14

char totMap[HEIGHT][WIDTH];
int arr[HEIGHT][WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,0,1,0,0,0,0,0,1,0,1,0},
		{1,0,0,0,0,1,1,1,0,1,0,1,0,1,0},
		{1,0,1,1,1,0,1,0,0,1,0,0,0,0,0},
		{1,0,1,0,0,0,1,0,0,1,0,1,0,1,1},
		{1,0,1,0,1,1,1,0,1,1,0,1,0,0,0},
		{1,0,1,0,0,0,1,0,0,1,0,1,0,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,1,0},
		{1,0,0,0,0,0,1,1,0,1,0,1,0,1,0},
		{1,0,1,1,1,0,1,0,0,1,0,0,0,0,0},
		{1,0,0,0,0,0,1,1,0,1,0,1,1,1,0},
		{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0},
		{1,0,0,0,0,0,1,1,1,1,0,1,0,0,0},
		{1,0,1,1,0,0,0,1,0,1,0,1,0,1,1}
};

void draw(int arr[][WIDTH], int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 1) {
				printf("бс");
			}
			else if (arr[i][j] == 0) {
				printf("бр");
			}
		}
		printf("\n");
	}
}


//void Mdupli(int arr[][WIDTH],int height, int width) {
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			printf("%c", arr[i][j] );
//			
//			/*totMap[i][j] = parm[i][j];*/
//		}
//		printf("\n");
//	}
//}

//void draw(int parm[][WIDTH], int height,int width) {
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			printf("%c", parm[i][j]);
//		}
//		printf("\n");
//	}
//}

int main() {

	/*for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}*/

	/*Mdupli(arr,HEIGHT,WIDTH);*/
	draw(arr, HEIGHT, WIDTH);
}