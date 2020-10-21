#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable : 4996)
#define cls system("cls")


void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Cursor(int n)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


int main()
{
    Cursor(0); //커서 가리기
    system("title 타이머 - Timer");

    clock_t start, end;
    float time;

    printf("타이머 시간을 입력해주세요(분) : ");
    scanf("%f", &time);

    time *= 60; //분을 입력받고 초 단위로 변환

    start = clock();

    end = clock();
    cls;
    while (time >= ((float)(end - start) / CLOCKS_PER_SEC))
    {
        gotoxy(0, 0);
        printf("남은 시간(초) : %f\n", time - (float)(end - start) / CLOCKS_PER_SEC);

        end = clock();
    }

    printf("시간이 종료되었습니다. 아무 키나 누르면 알람이 종료됩니다!");
    while (kbhit() == NULL)
    {
        Beep(1000, 500); //알람
        Sleep(800);
    }

    return 0;
}