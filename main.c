#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "reader.c"
#include "writer.c"

#define DIML 41
#define DIMC 41

void generate(char array[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for (int j = 0; j < DIMC; j++)
        {
            int rm = rand() % 2 + 1;
            if (rm == 1)
            {
                array[i][j] = '.';
            }
            else
            {
                array[i][j] = '@';
            }
        }
    }
}

void generate_empty(char array[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for(int j = 0;  j < DIMC; j++)
        {
            array[i][j] = '.';
        }
    }
}


void display(char array[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for (int j = 0; j < DIMC; j++)
        {
            printf(" %c ", array[i][j]);  
        }
        printf("\n");
    }

}

int count_alive(char array[DIML][DIMC], int x, int y)
{
    int vivant = 0;
    for(int i=x-1; i<=x+1; i++)
    {
        for(int j=y-1; j<=y+1; j++)
        {
            if((i>0 && i<DIML-1) && (j>0 && j <DIMC-1))
            {
                if(array[i][j] == '@')
                {
                    vivant++;
                }
            }
            if(i==0)
            {
                if(array[DIMC-1][j] == '@')
                {
                    vivant++;
                }
            }
            if(i==DIMC-1)
            {
                if(array[0][j] == '@')
                {
                    vivant++;
                }
            }
            if(j==0)
            {
                if(array[i][DIML-1] == '@')
                {
                    vivant++;
                }
            }
            if(j==DIML-1)
            {
                if(array[i][0] == '@')
                {
                    vivant++;
                }
            }
        }
    }
    if(array[x][y] == '@')
    {
        return vivant - 1;
    }
    else
    {
        return vivant;
    } 
}

void copy(char before[DIML][DIMC], char new[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for (int j = 0; j < DIMC; j++)
        {
           new[i][j] = (char)before[i][j];
        }
    }
}

void suivant(char array[DIML][DIMC])
{
    char new[DIML][DIMC];
    copy(array, new);
    for(int i=0; i< DIML; i++)    
    {
        for(int j=0; j< DIMC; j++)
        {
            int state = count_alive(new, i, j);
            if(state < 2 || state > 3)
            {
                array[i][j] = '.';
            }
            if(state == 3)
            {
                array[i][j] = '@';
            }
        }
    }
}


int main()
{
    srand(time(NULL));
    
    char a[DIML][DIMC];
    char filename[] = "test.txt";
    while(1)
    {
        printf("\033[2J");
        display(a);
        suivant(a);
        usleep(100000);
    }
    return 0;
}
