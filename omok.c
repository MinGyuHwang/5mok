#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define GRID_SIZE 19

char Grid_arr[GRID_SIZE][GRID_SIZE]; // ���������� ����
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
    printf("�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &row);
    printf("\n�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row][col] == '+') && (Grid_arr[row][col] != 'O'))
        {
            Grid_arr[row][col] = 'X';
        }
        else
        {
            printf("���� �Դϴ�.\n");
        }
    }
}

void replacestone2()
{
    printf("�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &row);
    printf("\n�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row][col] == '+') && (Grid_arr[row][col] != 'X'))
        {
            Grid_arr[row][col] = 'O';
        }
        else
        {
            printf("���� �Դϴ�.\n");
        }
    }
}

int main()
{
    initGrid(); // grid �ʱ�ȭ�۾�

    int player = 1; // �÷��̾� �����ư��� ���� ���� ����

    while (1)
    {
        printGrid();
        if (player == 1)
        {
            printf("�÷��̾� 1�� ���� (��: X)\n");
            replacestone1();
            player = 2;
        }
        else
        {
            printf("�÷��̾� 2�� ���� (��: O)\n");
            replacestone2();
            player = 1;
        }

        // ���� ���� ���� �߰� (�߰��� ���� �ʿ�)
    }

    return 0;
}