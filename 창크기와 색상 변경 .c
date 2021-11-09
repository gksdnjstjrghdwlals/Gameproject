#include <stdio.h>
#include <windows.h>

void change_color(int color_number) //콘솔 출력색상 나타내는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
//15가지 색이 있다.15번 이상의 숫자를 입력하면 블루스크린색이 바탕색으로 뜨면서 출력된다


int main() {
	system("mode con cols=37 lines=24");
	//창의 크기를 조절하는 함수 cols=가로, lines=세로
	int change;
	for (change = 0; change <= 15; change++) {
		change_color(change);
		printf("%d번 색상 출력\n", change);
	}
}