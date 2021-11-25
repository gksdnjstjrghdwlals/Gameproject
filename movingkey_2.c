#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "pre_progress.h"
#include "map.h"
#include "ascii_scene.h"
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
		
		
		
		
		if (timeTick == LMIT_TICK) {
			bart_detect();
			
		}
		db_saving(frontbuff);

		/*TMP(frontbuff, TWIDTH, THEIGHT);*/
		//프론트버퍼 상태저장
		tmp_cnt = cnt_ai;
		AI(&Ax_1, &Ay_1, &direction1, &confirm_U_1, &confirm_D_1, &confirm_R_1, &confirm_L_1);
		cnt_ai = tmp_cnt;
		AI(&Ax_2, &Ay_2, &direction1, &confirm_U_2, &confirm_D_2, &confirm_R_2, &confirm_L_2);
		cnt_ai = tmp_cnt;
		AI(&Ax_3, &Ay_3, &direction1, &confirm_U_3, &confirm_D_3, &confirm_R_3, &confirm_L_3);
		cnt_ai = tmp_cnt;
		AI(&Ax_4, &Ay_4, &direction1, &confirm_U_4, &confirm_D_4, &confirm_R_4, &confirm_L_4);

		Player();//이상없음 작동잘됨
		//모든 처리가 끝난후 백버퍼 상태저장 
		db_saving(backbuff);
		/*TMP(backbuff, TWIDTH, THEIGHT);*/
		double_buff();//불완성 강의참조요함
		/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
		//system("cls");//이건 임시

		//시간이 끝난후 플레이어의 흔적이 더많을때
		timeTick++;
	}
}
void level_2(){
	initialize2();
	tmp_cnt;
	//------------------
	//아마 while문
	TMP2(totalmap2, 20, 20);//이것도 임시... 초기화에 넣어야하나? 일단은 움직임
	while (premise) {
		

			
			if (timeTick == LMIT_TICK) {
				bart_detect2();
			}
			db_saving2(frontbuff2);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			tmp_cnt = cnt_ai2;
			AI2(&Ax2_1, &Ay2_1, &direction2, &confirm_U2_1, &confirm_D2_1, &confirm_R2_1, &confirm_L2_1);
			cnt_ai2 = tmp_cnt;

			AI2(&Ax2_2, &Ay2_2, &direction2, &confirm_U2_2, &confirm_D2_2, &confirm_R2_2, &confirm_L2_2);
			cnt_ai2 = tmp_cnt;
			AI2(&Ax2_3, &Ay2_3, &direction2, &confirm_U2_3, &confirm_D2_3, &confirm_R2_3, &confirm_L2_3);

			Player2();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving2(backbuff2);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff2();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시

			//시간이 끝난후 플레이어의 흔적이 더많을때
			timeTick++;
	}
}
void level_3() {
	initialize3();
	//------------------
	//아마 while문
	TMP3(totalmap3, 10, 10);//이것도 임시... 초기화에 넣어야하나? 일단은 움직임
	while (premise) {
		
			
			if (timeTick == LMIT_TICK) {
				bart_detect3();
			}
			db_saving3(frontbuff3);
			/*TMP(frontbuff, TWIDTH, THEIGHT);*/
			//프론트버퍼 상태저장
			AI3(&Ax3, &Ay3, &direction3, &confirm_U3, &confirm_D3, &confirm_R3, &confirm_L3);
			Player3();//이상없음 작동잘됨
			//모든 처리가 끝난후 백버퍼 상태저장 
			db_saving3(backbuff3);
			/*TMP(backbuff, TWIDTH, THEIGHT);*/
			double_buff3();//불완성 강의참조요함
			/*TMP(totalmap, TWIDTH, THEIGHT);*///이거 백버퍼문제다
			//system("cls");//이건 임시

			//시간이 끝난후 플레이어의 흔적이 더많을때
			timeTick++;
	}
	
	

}

int main() {
	int question = 1;

	//프로그램의 실행 제어
	while (RUN) {
		while (question) {
		
			draw_cutscene(opening, THEIGHT, TWIDTH);
			
			Sleep(500);
			gotoxy(26, 20);
			printf("게임을 시작하시겠습니까? Y/N");
			if (_kbhit) {
				int input = _getch();
				switch (input) {
				case'Y':
				case'y':
					question = 0;
					break;
				case 'N':
				case 'n':
					gotoxy(26, 20);
					printf("게임을 종료하시겠습니까? Y/N");
					int input = _getch();
					switch (input) {
					case'Y':
					case'y':
						exit(0);
						break;
					case 'N':
					case 'n':
						system("cls");
						continue;


					}
					

				}
				
			}
			
			
		}
		system("cls");
		draw_cutscene(opening2, THEIGHT, TWIDTH);
		Sleep(300);
		system("cls");
		//메뉴만들것 if문으로 메뉴창 만들기
		level_1();
		stage_end();
		if (gameover == 1) {
			re_quest();
			continue;
		}

		level_2();
		stage_end();
		if (gameover == 1) {
			re_quest();
			continue;
		}

		level_3();
		stage_end();
		if (gameover == 1) {
			re_quest();
			continue;
		}
		//-------------------------------------------------------2단계
		//initialize
		//엔딩화면


	}
	exit(0);
}
//*현재 비디오 컨트롤러가 읽고 있는 버퍼를 프론트 버퍼로 정의,
//화면에 내용에 보이지 않지만 그래픽 프로세서가 기록중인 버퍼가 백버퍼이다.
//따라서 버퍼는 프론트버퍼와 백버퍼를 반복한다.

