#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define GRID_SIZE 19

char Grid_arr[GRID_SIZE][GRID_SIZE]; // 전역변수로 선언
int row, col = 0;

void initGrid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            Grid_arr[i][j] = '+';
        }
    }
}

void printGrid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%c ", Grid_arr[i][j]);
        }
        printf("\n");
    }
}

void replacestone1()
{
    printf("행 번호를 입력하세요 : ");
    scanf("%d", &row);
    printf("\n열 번호를 입력하세요 : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row][col] == '+') && (Grid_arr[row][col] != 'O'))
        {
            Grid_arr[row][col] = 'X';
        }
        else
        {
            printf("오류 입니다.\n");
        }
    }
}

void replacestone2()
{
    printf("행 번호를 입력하세요 : ");
    scanf("%d", &row);
    printf("\n열 번호를 입력하세요 : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row][col] == '+') && (Grid_arr[row][col] != 'X'))
        {
            Grid_arr[row][col] = 'O';
        }
        else
        {
            printf("오류 입니다.\n");
        }
    }
}

int main()
{
    initGrid(); // grid 초기화작업

    int player = 1; // 플레이어 번갈아가며 돌을 놓을 차례

    while (1)
    {
        printGrid();
        if (player == 1)
        {
            printf("플레이어 1의 차례 (돌: X)\n");
            replacestone1();
            player = 2;
        }
        else
        {
            printf("플레이어 2의 차례 (돌: O)\n");
            replacestone2();
            player = 1;
        }

        // 게임 종료 조건 추가 (추가할 조건 필요)
    }

    return 0;
}