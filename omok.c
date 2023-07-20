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
    printf("열 번호를 입력하세요 : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row-1][col-1] == '+') && (Grid_arr[row-1][col-1] != 'O'))
        {
            Grid_arr[row-1][col-1] = 'X';
        }   
        else if (Grid_arr[row-1][col-1] == 'O')
        {
            printf("이미 O의 자리입니다. 다른 곳을 선택해주세요. \n");
            replacestone1();
        }
        else
        {
            printf("오류 입니다. 1~19 내의 숫자를 입력하세요 \n");
            replacestone1();
        }
    }

 
}
void replacestone2()
{
    printf("행 번호를 입력하세요 : ");
    scanf("%d", &row);
    printf("열 번호를 입력하세요 : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE) )
    {
        if ((Grid_arr[row-1][col-1] == '+') && (Grid_arr[row-1][col-1] != 'X'))
        {
            Grid_arr[row-1][col-1] = 'O';
        }
        else if (Grid_arr[row-1][col-1] == 'X')
        {
            printf("이미 X의 자리입니다. 다른 곳을 선택해주세요. \n");
            replacestone2();
        }
        else
        {
            printf("오류 입니다. 1~19 내의 숫자를 입력하세요 \n");
            replacestone2();
        }
    }
    else if ((sizeof(row) != 1) || (sizeof(col) != 1))
    {
        printf("제대로 된 숫자를 입력하세요. \n");
        replacestone2();
    }
    
}

void CompareWinOrLose_Player2(int row, int col)
{
    if ((Grid_arr[row][col] == 'O') && (Grid_arr[row + 1][col + 1] == 'O') && (Grid_arr[row + 2][col + 2] == 'O') && (Grid_arr[row + 3][col + 3] == 'O') && (Grid_arr[row + 4][col + 4] == 'O'))
    {
        printf("게임이 종료되었습니다. O 가 승리하였습니다. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col]== 'O') && (Grid_arr[row+1][col]== 'O') && (Grid_arr[row +2][col] == 'O') && (Grid_arr[row + 3][col] == 'O') && (Grid_arr[row + 4][col] == 'O'))
    {
        printf("게임이 종료되었습니다. O 가 승리하였습니다. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col] == '0') && (Grid_arr[row][col + 1] == 'O') && (Grid_arr[row][col + 2] == 'O') && (Grid_arr[row][col + 3] == 'O') && (Grid_arr[row][col + 4] == 'O'))
    {
        printf("게임이 종료되었습니다. O 가 승리하였습니다. \n");
        exit(0);
        return 0;
    }
}
void CompareWinOrLose_Player1()
{
    if ((Grid_arr[row][col] == 'X') && (Grid_arr[row + 1][col + 1] == 'X') && (Grid_arr[row + 2][col + 2] == 'X') && (Grid_arr[row + 3][col + 3] == 'X') && (Grid_arr[row + 4][col + 4] == 'X'))
    {
        printf("게임이 종료되었습니다. X 가 승리하였습니다. \n ");
        system("exit");
        return 0;
    }
    else if ((Grid_arr[row][col] == 'X') && (Grid_arr[row + 1][col] == 'X') && (Grid_arr[row + 2][col] == 'X') && (Grid_arr[row + 3][col] == 'X') && (Grid_arr[row + 4][col] == 'X'))
    {
        printf("게임이 종료되었습니다. X 가 승리하였습니다. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col] == 'X') && (Grid_arr[row][col + 1] == 'X') && (Grid_arr[row][col + 2] == 'X') && (Grid_arr[row][col + 3] == 'X') && (Grid_arr[row][col + 4] == 'X'))
    {
        printf("게임이 종료되었습니다. X 가 승리하였습니다. \n");
        exit(0);
        return 0;
    }
}
int main()
{
    initGrid(); // grid 초기화작업

    int player = 1; // 플레이어 번갈아가며 돌을 놓을 차례

    while (1)
    {
        int p1_i, p1_j = 0;
        int p2_i, p2_j = 0;
        printGrid();
        if (player == 1)
        {
            printf("플레이어 1의 차례 (돌: X)\n");
            replacestone1();
            for ( p1_i = 0; p1_i < 19; p1_i++)
            {
                for ( p1_j = 0; p1_j < 19; p1_j++)
                {
                    CompareWinOrLose_Player1 (p1_i, p1_j);

                    CompareWinOrLose_Player2( p1_i, p1_j);
                }
            }
            player = 2;
        }
        else
        {
            printf("플레이어 2의 차례 (돌: O)\n");
            replacestone2();
            for (p2_i = 0; p2_i < 19; p2_i++)
            {
                for (p2_j = 0; p2_j < 19; p2_j++)
                {
                    CompareWinOrLose_Player1(p2_i, p2_j);
                    CompareWinOrLose_Player2(p2_i, p2_j);

                }
            }
            
            player = 1;
        }       
    }
       return 0;
}