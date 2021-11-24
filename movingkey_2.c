#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "pre_progress.h"
#include "map.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
void level_1() {


	//1스테이지 시작
	//initialize
	initialize();
	//------------------
	//아마 while문

	TMP(totalmap, 30, 30);//이것도 임시... 초기화에 넣어야하나? 일단은 움직임

	while (premise) {
		{

			timer();
			db_saving(frontbuff);

			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			AI();
			Player();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving(backbuff);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시

			//시간이 끝난후 플레이어의 흔적이 더많을때

		}
	}
	gotoxy(31, 31);
	printf("\n");
	change_color(11);
	if (gameover == 1) {
		printf("게임오버\n");
		Sleep(3000);
		premise = 1;


	}
	printf("스테이지 클리어\n");
	printf("봇의 흔적 %d개\n", AI_BART_CLEAR_CNT);
	printf("사람의 흔적 %d개\n", BART_CLEAR_CNT);
	Sleep(3000);
	premise = 1;
	BART_CLEAR_CNT = 0;
	AI_BART_CLEAR_CNT = 0;

	//일단 기본적인 틀은 만들어졌다
	//한개의 씬 끝
	system("cls");

}
void level_2(){
	initialize2();
	//------------------
	//아마 while문
	TMP2(totalmap2, 20, 20);//이것도 임시... 초기화에 넣어야하나? 일단은 움직임
	while (premise) {
		{

			timer2();
			db_saving2(frontbuff2);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			AI2();
			Player2();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving2(backbuff2);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff2();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시

			//시간이 끝난후 플레이어의 흔적이 더많을때

		}
	}
	gotoxy(31, 31);
	printf("\n");
	change_color(11);
	if (gameover == 1) {
		printf("게임오버\n");
		Sleep(3000);
		premise = 1;


	}
	printf("스테이지 클리어\n");
	printf("봇의 흔적 %d개\n", AI_BART_CLEAR_CNT);
	printf("사람의 흔적 %d개\n", BART_CLEAR_CNT);
	Sleep(3000);
	premise = 1;
	BART_CLEAR_CNT = 0;
	AI_BART_CLEAR_CNT = 0;

	//일단 기본적인 틀은 만들어졌다
	//한개의 씬 끝
	system("cls");

}
void level_3() {
	initialize3();
	//------------------
	//아마 while문
	TMP3(totalmap3, 10, 10);//이것도 임시... 초기화에 넣어야하나? 일단은 움직임
	while (premise) {
		{

			timer3();
			db_saving3(frontbuff3);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			AI3();
			Player3();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving3(backbuff3);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff3();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시

			//시간이 끝난후 플레이어의 흔적이 더많을때

		}
	}
	gotoxy(31, 31);
	printf("\n");
	change_color(11);
	if (gameover == 1) {
		printf("게임오버\n");
		Sleep(3000);
		premise = 1;


	}
	printf("스테이지 클리어\n");
	printf("봇의 흔적 %d개\n", AI_BART_CLEAR_CNT);
	printf("사람의 흔적 %d개\n", BART_CLEAR_CNT);
	Sleep(3000);
	premise = 1;
	BART_CLEAR_CNT = 0;
	AI_BART_CLEAR_CNT = 0;

	//일단 기본적인 틀은 만들어졌다
	//한개의 씬 끝
	system("cls");

}
int main() {
	//프로그램의 실행 제어
	while (RUN) {
		//메뉴만들것 if문으로 메뉴창 만들기
		level_1();

		level_2();

		level_3();


		//-------------------------------------------------------2단계
		//initialize

	}
}
//*현재 비디오 컨트롤러가 읽고 있는 버퍼를 프론트 버퍼로 정의,
//화면에 내용에 보이지 않지만 그래픽 프로세서가 기록중인 버퍼가 백버퍼이다.
//따라서 버퍼는 프론트버퍼와 백버퍼를 반복한다.

