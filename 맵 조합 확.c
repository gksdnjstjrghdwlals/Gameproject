#include <stdio.h>
#include <stdlib.h>
int main() {
	srand(time(NULL));
	int left_top = rand() % 4 + 1, 
		left_lower = rand() % 4 + 1, 
		right_top = rand() % 4 + 1, 
		right_lower = rand() % 4 + 1;
	switch (left_top) {
	case 1:
		printf("1��°�� �´� ���� �ִ´�.");
		break;
	case 2:
		printf("2��°�� �´� ���� �ִ´�.");
		break;
	case 3:
		printf("3��°�� �´� ���� �ִ´�.");
		break;
		
	case 4:
		printf("4��°�� �´� ���� �ִ´�.");
		break;
	}
	switch (left_lower) {
	case 1:
		printf("1��°�� �´� ���� �ִ´�.");
		break;
	case 2:
		printf("2��°�� �´� ���� �ִ´�.");
		break;
	case 3:
		printf("3��°�� �´� ���� �ִ´�.");
		break;

	case 4:
		printf("4��°�� �´� ���� �ִ´�.");
		break;
	}
	
	switch (right_top) {
	case 1:
		printf("1��°�� �´� ���� �ִ´�.\n");
		break;
	case 2:
		printf("2��°�� �´� ���� �ִ´�.\n");
		break;
	case 3:
		printf("3��°�� �´� ���� �ִ´�.\n");
		break;

	case 4:
		printf("4��°�� �´� ���� �ִ´�\n.");
		break;

	}
	switch (right_lower) {
	case 1:
		printf("1��°�� �´� ���� �ִ´�\n.");
		break;
	case 2:
		printf("2��°�� �´� ���� �ִ´�\n.");
		break;
	case 3:
		printf("3��°�� �´� ���� �ִ´�\n.");
		break;

	case 4:
		printf("4��°�� �´� ���� �ִ´�\n.");
		break;
	}
	printf("%d %d %d %d", left_top, left_lower, right_top, right_lower);
	
}