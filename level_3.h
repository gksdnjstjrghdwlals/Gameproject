
void baseC3(int map[][TWIDTH3], int Lheight, int Hheight, int Lwidth, int Hwidth) {//int�� �ٲ۴�
	//���������� ���� ������ҿ� ����
	int i2 = 0, j2 = 0;
	for (int i = Lheight; i < Hheight; i++) {
		j2 = 0;
		for (int j = Lwidth; j < Hwidth; j++) {
			totalmap3[i][j] = map[i2][j2];
			j2++;
		}
		i2++;
	}
}


void db_saving3(int buffmap[][TWIDTH3]) {//int�� �ٲ۴�


	for (int i = 0; i < THEIGHT3; i++) {

		for (int j = 0; j < TWIDTH3; j++) {
			buffmap[i][j] = totalmap3[i][j];

		}

	}
}//������ �ʻ��¸� ���ۿ� �����ϴ� �Լ�

void double_buff3() {
	int tmpx3 = 0, tmpy3 = 0;
	//���۹��� ����Ʈ���۸� ��
	//����� != ����Ʈ����
	//����Ʈ���ۿ� �ִ� �� �׸��� ����ۿ� �ش��ϴ� ��ǥ�� ���� "  "���� �����.
	for (int i = 0; i < THEIGHT3; i++) {
		for (int j = 0; j < TWIDTH3; j++) {
			if (backbuff3[i][j] != frontbuff3[i][j]) {
				if (backbuff3[i][j] == 2) {
					gotoxy(j * 2, i);
					change_color(5);
					printf("��");
				}
				else if (backbuff3[i][j] == 0) {
					gotoxy(j * 2, i);
					printf("  ");
				}
				else if (backbuff3[i][j] == 3) {
					gotoxy(j * 2, i);
					change_color(2);
					printf("��");
				}
				else if (backbuff3[i][j] == 5) {
					gotoxy(j * 2, i);
					change_color(15);
					printf("��");
				}
				else if (backbuff3[i][j] == 6) {
					gotoxy(j * 2, i);
					change_color(12);
					printf("��");
				}
			}
		}
	}
}//2�ܰ迡 ���Ǵ� ���۷���

void FINAL_MAP() {
	//���� �� �� ����
	int select = randomize();
	if (select <= 2) {
		baseC3(last_1, 0, 10, 0, 10);
	}
	else if (select > 2 && select <= 4) {
		baseC3(last_2, 0, 10, 0, 10);
	}
	else if (select > 4 && select <= 6) {
		baseC3(last_3, 0, 10, 0, 10);
	}
	else if (select > 6 && select <= 8) {
		baseC3(last_4, 0, 10, 0, 10);
	}
	//�� �߰��ؾ���



}

void TMP3(int map[][TWIDTH3], int height, int width) {//int�� �ٲ۴�

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

void Player3() {
	//{��,�Ʒ�,��,��}

	Pmove3();
}

void Pmove3() {
	int tmpx = Px3;
	int tmpy = Py3;
	int direction = randomize();
	totalmap3[Py3][Px3] = 2;

	//�̵�
	if (_kbhit()) {
		int keyhit = _getch();
		switch (keyhit) {
		case UP:
			Py3 -= 1;
			if (totalmap3[Py3][Px3] == 1) {
				Py3 = tmpy;
			}

			break;
		case DOWN:

			Py3 += 1;
			if (totalmap3[Py3][Px3] == 1) {
				Py3 = tmpy;
			}
			break;
		case LEFT:
			Px3 -= 1;
			if (totalmap3[Py3][Px3] == 1) {
				Px3 = tmpx;
			}

			break;
		case RIGHT:
			Px3 += 1;
			if (totalmap3[Py3][Px3] == 1) {
				Px3 = tmpx;
			}

			break;
		}
		totalmap3[tmpy][tmpx] = 3;
	}
}

void initialize3() {
	Cursorhide();
	FINAL_MAP();
	totalmap3[Py][Px] = 2;

}

int bart_detect3() {

	for (int i = 0; i < THEIGHT3; i++) {

		for (int j = 0; j < TWIDTH3; j++) {
			if (totalmap3[i][j] == 3) {
				BART_CLEAR_CNT++;

			}
			if (totalmap3[i][j] == 6) {
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

void timer3() {

	clock_t start = clock();
	clock_t end = clock();
	int time = ((int)end - start / CLOCKS_PER_SEC) / 1000; //�ʴ��� ��ȯ


	if (time == 300) {//�ٽ� ����ɽÿ��� �̰� �۵��� ���Ѵ�
		bart_detect3();
		printf("%d", time);

	}



}

void AI3() {
	int tmpx = 0;
	int tmpy = 0;

	int select = randomize();
	int lazy = randomize();
	tmpx = Ax3;
	tmpy = Ay3;

	if (cnt_ai % 3000 == 0) {
		if (totalmap3[Ay3][Ax3] != 1) {
			if (direction == 1) {//�� 1
				--Ay3;
			}
			else if (direction == 2) {//�Ʒ� 2
				++Ay3;
			}
			else if (direction == 3) {//�� 3
				--Ax3;
			}
			else if (direction == 4) {//���� 4
				++Ax3;
			}

		}
		//��: 1, �Ʒ�: 2, ��: 3, ��: 4
		if (totalmap3[Ay3][Ax3] == 1) {
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
			Ax3 = tmpx;
			Ay3 = tmpy;
		}

	}

	/*Sleep(500);*/
	//�̰ɾ��ϱ� �÷��̾��� �Է��� ���� �������� �̰͸��� ���� ����ϳ�
	totalmap3[tmpy][tmpx] = 6;
	totalmap3[Ay3][Ax3] = 5;
	cnt_ai++;
}
