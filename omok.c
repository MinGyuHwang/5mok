#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define GRID_SIZE 19



char Grid_arr[GRID_SIZE][GRID_SIZE]; // 전역변수로 선언

void initGrid()
{
	for (int i = 0; i < GRID_SIZE; i++) 
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			Grid_arr[i][j] = '+'; // 초기값 '┼'로 설정
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
	if ((Grid_arr [row][col] == '+') && ~(Grid_arr [row][col] == '○'))
	{
		Grid_arr [row][col] = '● ';
	}
	else if ((Grid_arr [row][col] == '+') && ~(Grid_arr [row][col] == '●'))
	{
		Grid_arr [row][col] = '○ ';
	}
	else
	{
		printf("오류 입니다.\n");
	}
}

int main()
{
	initGrid();
	int row, col=0;
	while (1)
	{
		printGrid();
		printf("행 번호를 입력하세요 : ");
		scanf("%d", &row);
		printf("\n열 번호를 입력하세요 : ");
		scanf("%d", &col);

		if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
			replaceStone(row - 1, col - 1);
		else
			printf("잘못된 입력입니다.");
	}
}