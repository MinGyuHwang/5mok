#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define GRID_SIZE 19



char Grid_arr[GRID_SIZE][GRID_SIZE]; // ���������� ����

void initGrid()
{
	for (int i = 0; i < GRID_SIZE; i++) 
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			Grid_arr[i][j] = '+'; // �ʱⰪ '��'�� ����
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
void replaceStone(int row, int col)
{
	if ((Grid_arr [row][col] == '+') && ~(Grid_arr [row][col] == '��'))
	{
		Grid_arr [row][col] = '�� ';
	}
	else if ((Grid_arr [row][col] == '+') && ~(Grid_arr [row][col] == '��'))
	{
		Grid_arr [row][col] = '�� ';
	}
	else
	{
		printf("���� �Դϴ�.\n");
	}
}

int main()
{
	initGrid();
	int row, col=0;
	while (1)
	{
		printGrid();
		printf("�� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &row);
		printf("\n�� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &col);

		if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
			replaceStone(row - 1, col - 1);
		else
			printf("�߸��� �Է��Դϴ�.");
	}
}