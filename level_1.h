void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int로 바꾼다
	//일정구간을 최종 맵저장소에 저장
	int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			totalmap[i][j] = map[i2][j2];
			j2++;
		}
		i2++;
	}
}


void db_saving(int buffmap[][TWIDTH]) {//int로 바꾼다


	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			buffmap[i][j] = totalmap[i][j];

		}

	}
}//현재의 맵상태를 버퍼에 저장하는 함수



void double_buff() {
	int tmpx = 0, tmpy = 0;
	//백퍼버와 프론트버퍼를 비교
	//백버퍼 != 프론트버퍼
	//프론트버퍼에 있는 걸 그리고 백버퍼에 해당하는 좌표의 값을 "  "으로 지운다.
	for (int i = 0; i < THEIGHT; i++) {
		for (int j = 0; j < TWIDTH; j++) {
			if (backbuff[i][j] != frontbuff[i][j]) {
				if (backbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					Beep(260, 15);
					change_color(5);
					printf("◎");
					Beep(220, 15);
				}
				else if (backbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				
				else if (backbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("♨");
				}
				else if (backbuff[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("☆");
				}
				else if (backbuff[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("★");
				}
			}
		}
	}
}//1단계에 사용되는 버퍼렌더


void L_Ucraft() {
	//왼쪽 위 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(left_u1, 0, 15, 0, 15);
	}
	else if (select > 2 && select <= 4) {
		baseC(left_u2, 0, 15, 0, 15);
	}
	else if (select > 4 && select <= 6) {
		baseC(left_u3, 0, 15, 0, 15);
	}
	else if (select > 6 && select <= 8) {
		baseC(left_u1, 0, 15, 0, 15);
	}
	//맵 추가해야함



}
void L_Dcraft() {
	//왼쪽 아래 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(left_d1, 15, 30, 0, 15);
	}
	else if (select > 2 && select <= 4) {
		baseC(left_d2, 15, 30, 0, 15);
	}
	else if (select > 4 && select <= 6) {
		baseC(left_d3, 15, 30, 0, 15);
	}
	else if (select > 6 && select <= 8) {
		baseC(left_d4, 15, 30, 0, 15);
	}

}
void R_Dcraft() {
	//오른쪽 아래 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(right_d1, 15, 30, 15, 30);
	}
	else if (select > 2 && select <= 4) {
		baseC(right_d2, 15, 30, 15, 30);
	}
	else if (select > 4 && select <= 6) {
		baseC(right_d3, 15, 30, 15, 30);
	}
	else if (select > 6 && select <= 8) {
		baseC(right_d4, 15, 30, 15, 30);
	}

}
void R_Ucraft() {
	//오른쪽 위 맵 선택
	int select = randomize();
	if (select <= 2) {
		baseC(right_u1, 0, 15, 15, 30);
	}
	else if (select > 2 && select <= 4) {
		baseC(right_u2, 0, 15, 15, 30);
	}
	else if (select > 4 && select <= 6) {
		baseC(right_u3, 0, 15, 15, 30);
	}
	else if (select > 6 && select <= 8) {
		baseC(right_u4, 0, 15, 15, 30);
	}

}


void TMP(int map[][TWIDTH], int height, int width) {//int로 바꾼다

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//조건문으로 각 디지털값에 따른 문자를 출력한다.
			if (map[i][j] == 1) {
				change_color(6);
				printf("■");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}
			else if (map[i][j] == 2) {

				printf("◎");
			}

		}
		printf("\n");
	}
}




void Player() {
	//{위,아래,왼,오}

	Pmove();
}

void Pmove() {
	int tmpx = Px;
	int tmpy = Py;
	int direction = randomize();
	totalmap[Py][Px] = 2;

	//이동
	if (_kbhit()) {
		
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py -= 1;

			if (totalmap[Py][Px] == 1) {
				Beep(900, 60);
				Py = tmpy;
				
			}

			break;
		case DOWN:

			Py += 1;
			if (totalmap[Py][Px] == 1) {
				Beep(900, 60);
				Py = tmpy;
			}
			break;
		case LEFT:
			Px -= 1;
			if (totalmap[Py][Px] == 1) {
				Beep(900, 60);
				Px = tmpx;
			}

			break;
		case RIGHT:
			Px += 1;
			if (totalmap[Py][Px] == 1) {
				Beep(900, 60);
				Px = tmpx;
			}

			break;
		}
		totalmap[tmpy][tmpx] = 3;
	}
}
//키입력에 따른 움직임



void initialize() {
	Cursorhide();
	timeTick = 0;
	L_Dcraft();
	L_Ucraft();
	R_Ucraft();
	R_Dcraft();
	totalmap[Py][Px] = 2;

}


void bart_detect() {

	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			if (totalmap[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (totalmap[i][j] == 6) {
				AI_BART_CLEAR_CNT++;

			}



		}
	}
	if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		premise = 0;

	}
	else if (BART_CLEAR_CNT < AI_BART_CLEAR_CNT){
		gameover = 1;
		premise = 0;
	}

}


void AI(int *Ax, int *Ay, int *direction, int *confirm_U, int* confirm_D, int *confirm_R, int *confirm_L) {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	
	tmpx = *Ax;
	tmpy = *Ay;

	if (cnt_ai %3000 == 0) {
		if (totalmap[*Ay][*Ax] != 1) {
			if (*direction == 1) {//위 1
				
				--*Ay;
			}
			else if (*direction == 2) {//아래 2
				++*Ay;
			}
			else if (*direction == 3) {//왼 3
				--*Ax;
			}
			else if (*direction == 4) {//오른 4
				++*Ax;
			}

		}
		//위: 1, 아래: 2, 왼: 3, 오: 4
		if (totalmap[*Ay][*Ax] == 1) {
			if (select <= 2 && *confirm_U != 1) {//위 1

				*direction = 1;
				//재설정
				*confirm_U = 1;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && *confirm_D != 1) {//아래 2
				*direction = 2;
				//재설정
				*confirm_U = 0;
				*confirm_D = 1;
				*confirm_R = 0;
				*confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && *confirm_L != 1) {//왼 3
				*direction = 3;
				//재설정
				*confirm_U = 0;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && *confirm_R != 1) {//오른 4
				*direction = 4;
				//재설정
				*confirm_U = 0;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 1;
			}
			*Ax = tmpx;
			*Ay = tmpy;
		}

	}

	
	//이걸쓰니까 플레이어의 입력이 많이 느려진다 이것말고 딴걸 써야하나
	totalmap[tmpy][tmpx] = 6;
	totalmap[*Ay][*Ax] = 5;
	cnt_ai++;
	
}
