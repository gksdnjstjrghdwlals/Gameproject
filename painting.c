#include <stdio.h>
#include <windows.h>
void painting() {
	printf("{                                                                                                    ");
	printf("{                                                                          ��                        ");
	printf("{                                                                        ����                      ");
	printf("{                                                                ��    ���ܡ��    ��              ");
	printf("{                                                              ��ܡ�  ���ܡ��  ��ܡ�            ");
	printf("{                                                            ���ܡ���������ܡ��          ");
	printf("{                                                          �����������������          ");
	printf("{                                                          �����������������          ");
	printf("{                                                          �����������������          ");
	printf("{                                                                  ��        ��                      ");
	printf("{                                                            ���        ���                        ");
	printf("{            ��      ��                                ���        ����                            ");
	printf("{          ��  ��    ��                          ���        ����                                  ");
	printf("{          �ܡ�      ��                    ���        ����                                        ");
	printf("{      ���������              ���        ����                                              ");
	printf("{        �ܡܡ�                ���        ����                                                    ");
	printf("{      �ܡܡ�  ��        ���        ����                                                          ");
	printf("{        ��      ��            ����                                                                ");
	printf("{                                                                                                    ");
	printf("{                                                                                                    ");
};
void change_color(int color_number) //�ܼ� ��»��� ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
//��ܰ��� ���� �ִ�.��ܹ� �̻��� ���ڸ� �Է��ϸ� ��罺ũ������ ���������� �߸鼭 ��µȴ�


int main() {
	printf("                                                                                                    \n");
	printf("                                                                          ��                        \n");
	printf("                                                                        ����                      \n");
	printf("                                                                ��    ���ܡ��    ��              \n");
	printf("                                                              ��ܡ�  ���ܡ��  ��ܡ�            \n");
	printf("                                                            ���ܡ���������ܡ��          \n");
	printf("                                                          �����������������          \n");
	printf("                                                          �����������������          \n");
	printf("                                                          �����������������          \n");
	printf("                                                                  ��        ��                      \n");
	printf("                                                            ���        ���                        \n");
	printf("            ��      ��                                ���        ����                            \n");
	printf("          ��  ��    ��                          ���        ����                                  \n");
	printf("            ��      ��                    ���        ����                                        \n");
	printf("      ���������              ���        ����                                              \n");
	printf("            ��                ���        ����                                                    \n");
	printf("          ��  ��        ���        ����                                                          \n");
	printf("        ��      ��            ����                                                                \n");
	printf("                                                                                                    \n");
	
	//system("mode con cols=50   lines=24");
	//â�� ũ�⸦ �����ϴ� �Լ� cols=���� lines=����
	//painting();
	/*int change;
	for (change = 0; change <= 15; change++) {
		change_color(change);
		printf("%d�� ���� ���\n", change);
	}*/
}