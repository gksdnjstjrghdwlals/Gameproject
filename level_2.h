
void baseC2(int map[][WIDTH2], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
	int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			totalmap2[i][j] = map[i2][j2];
			j2++;
		}
		i2++;
	}
}

void db_saving2(int buffmap[][TWIDTH2]) {//int�� �ٲ۴�


	for (int i = 0; i < THEIGHT2; i++) {

		for (int j = 0; j < TWIDTH2; j++) {
			buffmap[i][j] = totalmap2[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�

void double_buff2() {
	int tmpx2 = 0, tmpy2 = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < THEIGHT2; i++) {
		for (int j = 0; j < TWIDTH2; j++) {
			if (backbuff2[i][j] != frontbuff2[i][j]) {
				if (backbuff2[i][j] == 2) {
					gotoxy(j * 2, i);
					change_color(5);
					printf("��");
				}
				else if (backbuff2[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				else if (backbuff2[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (backbuff2[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (backbuff2[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//2�ܰ迡 ���Ǵ� ���۷���

void L_Ucraft2() {
	//���� �� �� ����
	int select = randomize();
	if (select <= 2) {
		baseC2(left2_u1, 0, 10, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		baseC2(left2_u2, 0, 10, 0,10);
	}
	else if (select > 4 && select <= 6) {
		baseC2(left2_u3, 0,10, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		baseC2(left2_u1, 0,10, 0, 10);
	}
	//�� �߰��ؾ���



}
void L_Dcraft2() {
	//���� �Ʒ� �� ����
	int select = randomize();
	if (select <= 2) {
		baseC2(left2_d1, 10, 20, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		baseC2(left2_d2, 10, 20, 0, 10);
	}
	else if (select > 4 && select <= 6) {
		baseC2(left2_d3, 10, 20, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		baseC2(left2_d4, 10, 20, 0, 10);
	}

}
void R_Dcraft2() {
	//������ �Ʒ� �� ����
	int select = randomize();
	if (select <= 2) {
		baseC2(right2_d1, 10, 20, 10, 20);
	}
	else if (select > 2 && select <= 4) {
		baseC2(right2_d2, 10, 20, 10, 20);
	}
	else if (select > 4 && select <= 6) {
		baseC2(right2_d3, 10, 20, 10, 20);
	}
	else if (select > 6 && select <= 8) {
		baseC2(right2_d4, 10, 20, 10, 20);
	}

}
void R_Ucraft2() {
	//������ �� �� ����
	int select = randomize();
	if (select <= 2) {
		baseC2(right2_u1, 0, 10, 10, 20);
	}
	else if (select > 2 && select <= 4) {
		baseC2(right2_u2, 0, 10, 10, 20);
	}
	else if (select > 4 && select <= 6) {
		baseC2(right2_u3, 0, 10, 10, 20);
	}
	else if (select > 6 && select <= 8) {
		baseC2(right2_u4, 0, 10, 10, 20);
	}

}

void TMP2(int map[][TWIDTH2], int height, int width) {//int�� �ٲ۴�

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
void Player2() {
	//{��,�Ʒ�,��,��}

	Pmove2();
}


void Pmove2() {
	int tmpx = Px2;
	int tmpy = Py2;
	int direction = randomize();
	totalmap2[Py2][Px2] = 2;

	//�̵�
	if (_kbhit()) {
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py2 -= 1;
			if (totalmap2[Py2][Px2] == 1) {
				Py2 = tmpy;
			}

			break;
		case DOWN:

			Py2 += 1;
			if (totalmap2[Py2][Px2] == 1) {
				Py2 = tmpy;
			}
			break;
		case LEFT:
			Px2 -= 1;
			if (totalmap2[Py2][Px2] == 1) {
				Px2 = tmpx;
			}

			break;
		case RIGHT:
			Px2 += 1;
			if (totalmap2[Py2][Px2] == 1) {
				Px2 = tmpx;
			}

			break;
		}
		totalmap2[tmpy][tmpx] = 3;
	}
}

void initialize2() {
	Cursorhide();

	L_Dcraft2();
	L_Ucraft2();
	R_Ucraft2();
	R_Dcraft2();
	totalmap2[Py][Px] = 2;

}

int bart_detect2() {

	for (int i = 0; i < THEIGHT2; i++) {

		for (int j = 0; j < TWIDTH2; j++) {
			if (totalmap2[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (totalmap2[i][j] == 6) {
				AI_BART_CLEAR_CNT++;

			}



		}
	}
	if (BART_CLEAR_CNT > AI_BART_CLEAR_CNT) {
		premise = 0;

	}
	else {
		gameover = 1;
		premise = 0;
	}

}

void timer2() {

	clock_t start = clock();
	clock_t end = clock();
	int time = ((int)end - start / CLOCKS_PER_SEC) / 1000; //�ʴ��� ��ȯ


	if (time == 20) {//�ٽ� ����ɽÿ��� �̰� �۵��� ���Ѵ�
		bart_detect2();
		printf("%d", time);

	}



}

void AI2() {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	int lazy = randomize();
	tmpx = Ax2;
	tmpy = Ay2;

	if (cnt_ai % 3000 == 0) {
		if (totalmap2[Ay2][Ax2] != 1) {
			if (direction == 1) {//�� 1
				--Ay2;
			}
			else if (direction == 2) {//�Ʒ� 2
				++Ay2;
			}
			else if (direction == 3) {//�� 3
				--Ax2;
			}
			else if (direction == 4) {//���� 4
				++Ax2;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (totalmap2[Ay2][Ax2] == 1) {
			if (select <= 2 && confirm_U != 1) {//�� 1

				direction = 1;
				//�缳��
				confirm_U = 1;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 2 && select <= 4) && confirm_D != 1) {//�Ʒ� 2
				direction = 2;
				//�缳��
				confirm_U = 0;
				confirm_D = 1;
				confirm_R = 0;
				confirm_L = 0;
			}
			else if ((select > 4 && select <= 6) && confirm_L != 1) {//�� 3
				direction = 3;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			else if ((select > 6 && select <= 8) && confirm_R != 1) {//���� 4
				direction = 4;
				//�缳��
				confirm_U = 0;
				confirm_D = 0;
				confirm_R = 0;
				confirm_L = 1;
			}
			Ax2 = tmpx;
			Ay2 = tmpy;
		}

	}

	/*Sleep(500);*/
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	totalmap2[tmpy][tmpx] = 6;
	totalmap2[Ay2][Ax2] = 5;
	cnt_ai++;
}
