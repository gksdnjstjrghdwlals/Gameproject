#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


char name[10];

void opening();
char input_name();

char input_name() {
	printf("이름을 입력하세요. : ");
	scanf("%s", &name);
	printf("안녕하세요 %s 님\n", name);
	return name;
}
void opening() {
	printf("멈출 수 없는 방구 추진력을 가진 용사 이야기.....\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("스토리 어쩌구 저쩌구.....");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	Sleep(100);		printf("\n");		Sleep(100);		printf("\n");		Sleep(100);		printf("\n");
	printf("게임을 시작합니다.");
}

int main() {
	opening();
	input_name();
	

	}