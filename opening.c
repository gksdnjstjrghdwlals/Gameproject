#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


char name[10];

void opening();
char input_name();

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

int main() {
	opening();
	input_name();
	

	}