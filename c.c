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
    Cursor(0); //Ŀ�� ������
    system("title Ÿ�̸� - Timer");

    clock_t start, end;
    float time;

    printf("Ÿ�̸� �ð��� �Է����ּ���(��) : ");
    scanf("%f", &time);

    time *= 60; //���� �Է¹ް� �� ������ ��ȯ

    start = clock();

    end = clock();
    cls;
    while (time >= ((float)(end - start) / CLOCKS_PER_SEC))
    {
        gotoxy(0, 0);
        printf("���� �ð�(��) : %f\n", time - (float)(end - start) / CLOCKS_PER_SEC);

        end = clock();
    }

    printf("�ð��� ����Ǿ����ϴ�. �ƹ� Ű�� ������ �˶��� ����˴ϴ�!");
    while (kbhit() == NULL)
    {
        Beep(1000, 500); //�˶�
        Sleep(800);
    }

    return 0;
}