#include <stdio.h>
#include <windows.h>

void change_color(int color_number) //�ܼ� ��»��� ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
//15���� ���� �ִ�.15�� �̻��� ���ڸ� �Է��ϸ� ��罺ũ������ ���������� �߸鼭 ��µȴ�


int main() {
	system("mode con cols=37 lines=24");
	//â�� ũ�⸦ �����ϴ� �Լ� cols=����, lines=����
	int change;
	for (change = 0; change <= 15; change++) {
		change_color(change);
		printf("%d�� ���� ���\n", change);
	}
}