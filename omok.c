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
    printf("�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE))
    {
        if ((Grid_arr[row-1][col-1] == '+') && (Grid_arr[row-1][col-1] != 'O'))
        {
            Grid_arr[row-1][col-1] = 'X';
        }   
        else if (Grid_arr[row-1][col-1] == 'O')
        {
            printf("�̹� O�� �ڸ��Դϴ�. �ٸ� ���� �������ּ���. \n");
            replacestone1();
        }
        else
        {
            printf("���� �Դϴ�. 1~19 ���� ���ڸ� �Է��ϼ��� \n");
            replacestone1();
        }
    }

 
}
void replacestone2()
{
    printf("�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &row);
    printf("�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &col);
    if ((row >= 1) && (col >= 1) && (row <= GRID_SIZE) && (col <= GRID_SIZE) )
    {
        if ((Grid_arr[row-1][col-1] == '+') && (Grid_arr[row-1][col-1] != 'X'))
        {
            Grid_arr[row-1][col-1] = 'O';
        }
        else if (Grid_arr[row-1][col-1] == 'X')
        {
            printf("�̹� X�� �ڸ��Դϴ�. �ٸ� ���� �������ּ���. \n");
            replacestone2();
        }
        else
        {
            printf("���� �Դϴ�. 1~19 ���� ���ڸ� �Է��ϼ��� \n");
            replacestone2();
        }
    }
    else if ((sizeof(row) != 1) || (sizeof(col) != 1))
    {
        printf("����� �� ���ڸ� �Է��ϼ���. \n");
        replacestone2();
    }
    
}

void CompareWinOrLose_Player2(int row, int col)
{
    if ((Grid_arr[row][col] == 'O') && (Grid_arr[row + 1][col + 1] == 'O') && (Grid_arr[row + 2][col + 2] == 'O') && (Grid_arr[row + 3][col + 3] == 'O') && (Grid_arr[row + 4][col + 4] == 'O'))
    {
        printf("������ ����Ǿ����ϴ�. O �� �¸��Ͽ����ϴ�. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col]== 'O') && (Grid_arr[row+1][col]== 'O') && (Grid_arr[row +2][col] == 'O') && (Grid_arr[row + 3][col] == 'O') && (Grid_arr[row + 4][col] == 'O'))
    {
        printf("������ ����Ǿ����ϴ�. O �� �¸��Ͽ����ϴ�. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col] == '0') && (Grid_arr[row][col + 1] == 'O') && (Grid_arr[row][col + 2] == 'O') && (Grid_arr[row][col + 3] == 'O') && (Grid_arr[row][col + 4] == 'O'))
    {
        printf("������ ����Ǿ����ϴ�. O �� �¸��Ͽ����ϴ�. \n");
        exit(0);
        return 0;
    }
}
void CompareWinOrLose_Player1()
{
    if ((Grid_arr[row][col] == 'X') && (Grid_arr[row + 1][col + 1] == 'X') && (Grid_arr[row + 2][col + 2] == 'X') && (Grid_arr[row + 3][col + 3] == 'X') && (Grid_arr[row + 4][col + 4] == 'X'))
    {
        printf("������ ����Ǿ����ϴ�. X �� �¸��Ͽ����ϴ�. \n ");
        system("exit");
        return 0;
    }
    else if ((Grid_arr[row][col] == 'X') && (Grid_arr[row + 1][col] == 'X') && (Grid_arr[row + 2][col] == 'X') && (Grid_arr[row + 3][col] == 'X') && (Grid_arr[row + 4][col] == 'X'))
    {
        printf("������ ����Ǿ����ϴ�. X �� �¸��Ͽ����ϴ�. \n");
        exit(0);
        return 0;
    }
    else if ((Grid_arr[row][col] == 'X') && (Grid_arr[row][col + 1] == 'X') && (Grid_arr[row][col + 2] == 'X') && (Grid_arr[row][col + 3] == 'X') && (Grid_arr[row][col + 4] == 'X'))
    {
        printf("������ ����Ǿ����ϴ�. X �� �¸��Ͽ����ϴ�. \n");
        exit(0);
        return 0;
    }
}
int main()
{
    initGrid(); // grid �ʱ�ȭ�۾�

    int player = 1; // �÷��̾� �����ư��� ���� ���� ����

    while (1)
    {
        int p1_i, p1_j = 0;
        int p2_i, p2_j = 0;
        printGrid();
        if (player == 1)
        {
            printf("�÷��̾� 1�� ���� (��: X)\n");
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
            printf("�÷��̾� 2�� ���� (��: O)\n");
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