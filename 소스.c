#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char test[225];
	char map[15][15];
	int a = 0;
	FILE* fp = fopen("map.txt", "r");

	fread(test, 225, 1, fp);

	/*for (int i = 0; i < 15; i++) {
		for (int k = 0; k < 15; k++) {
			map[i][k] = test[a];
			printf("%s", test[a]);
			a++;
			if (a == 225) {
				break;
			}
		}
	}
	for (int i = 0; i < 15; i++) {
		for (int k = 0; k < 15; k++) {
			printf("%s", map[i][k]);
		}
	}*/
	/*for (int i = 0; i < 225; i++) {
		printf("%s", test[i]);
		if (i % 15 == 0) {
			printf("\n");
		}
	}*/
	printf("%s\n", test);
	fclose(fp);
}