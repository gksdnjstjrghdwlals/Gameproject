#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


}

int main(void) {
    int x = 0;
    int y = 0;
    while (1) {
        gotoxy(x, y);
        putchar('A');

        if (GetAsyncKeyState(VK_UP) & 0x8000) y--;
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) y++;
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) x--;
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) x++;
        Sleep(50);
    }
}