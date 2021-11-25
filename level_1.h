void baseC(int map[][WIDTH], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
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


void db_saving(int buffmap[][TWIDTH]) {//int�� �ٲ۴�


	for (int i = 0; i < THEIGHT; i++) {

		for (int j = 0; j < TWIDTH; j++) {
			buffmap[i][j] = totalmap[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�



void double_buff() {
	int tmpx = 0, tmpy = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < THEIGHT; i++) {
		for (int j = 0; j < TWIDTH; j++) {
			if (backbuff[i][j] != frontbuff[i][j]) {
				if (backbuff[i][j] == 2) {
					gotoxy(j * 2, i);
					Beep(260, 15);
					change_color(5);
					printf("��");
					Beep(220, 15);
				}
				else if (backbuff[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				
				else if (backbuff[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (backbuff[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (backbuff[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//1�ܰ迡 ���Ǵ� ���۷���


void L_Ucraft() {
	//���� �� �� ����
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
	//�� �߰��ؾ���



}
void L_Dcraft() {
	//���� �Ʒ� �� ����
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
	//������ �Ʒ� �� ����
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
	//������ �� �� ����
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


void TMP(int map[][TWIDTH], int height, int width) {//int�� �ٲ۴�

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//���ǹ����� �� �����а��� ���� ���ڸ� ����Ѵ�.
			if (map[i][j] == 1) {
				change_color(6);
				printf("��");
			}
			else if (map[i][j] == 0) {

				printf("  ");
			}
			else if (map[i][j] == 2) {

				printf("��");
			}

		}
		printf("\n");
	}
}




void Player() {
	//{��,�Ʒ�,��,��}

	Pmove();
}

void Pmove() {
	int tmpx = Px;
	int tmpy = Py;
	int direction = randomize();
	totalmap[Py][Px] = 2;

	//�̵�
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
//Ű�Է¿� ���� ������



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
			if (*direction == 1) {//�� 1
				
				--*Ay;
			}
			else if (*direction == 2) {//�Ʒ� 2
				++*Ay;
			}
			else if (*direction == 3) {//�� 3
				--*Ax;
			}
			else if (*direction == 4) {//���� 4
				++*Ax;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (totalmap[*Ay][*Ax] == 1) {
			if (select <= 2 && *confirm_U != 1) {//�� 1

				*direction = 1;
				//�缳��
				*confirm_U = 1;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && *confirm_D != 1) {//�Ʒ� 2
				*direction = 2;
				//�缳��
				*confirm_U = 0;
				*confirm_D = 1;
				*confirm_R = 0;
				*confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && *confirm_L != 1) {//�� 3
				*direction = 3;
				//�缳��
				*confirm_U = 0;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && *confirm_R != 1) {//���� 4
				*direction = 4;
				//�缳��
				*confirm_U = 0;
				*confirm_D = 0;
				*confirm_R = 0;
				*confirm_L = 1;
			}
			*Ax = tmpx;
			*Ay = tmpy;
		}

	}

	
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	totalmap[tmpy][tmpx] = 6;
	totalmap[*Ay][*Ax] = 5;
	cnt_ai++;
	
}
