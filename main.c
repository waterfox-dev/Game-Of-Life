#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "reader.c"
#include "writer.c"

#define DIML 40
#define DIMC 40
#define Living '@'
#define Dead '.'

void generate(char array[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for (int j = 0; j < DIMC; j++)
        {
            int rm = rand() % 2 + 1;
            if (rm == 1)
            {
                array[i][j] = Dead;
            }
            else
            {
                array[i][j] = Living;
            }
        }
    }
}

void display_column(){
    if(DIMC >= 10){
        printf("        ");
        for (int j = 0; j < DIMC/10; j++)
        {
            printf("%d═══════════════════", j);
        }
        printf("\n");
    }
    printf("        ");
    for (int j = 0; j < DIMC/10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("        ");
    for (int j = 0; j < DIMC/10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("══");
        }
    }
    printf("\n");
}

void display(char array[DIML][DIMC])
{
    display_column();
    for (int i = 0; i < DIML; i++)
    {
        if(DIML >= 10){
            if(i%10 == 0){
                printf("%d ║ %d ║ ", i/10, i%10);
            }
            else{
                printf("  ║ %d ║ ", i%10);
            }
        }
        for (int j = 0; j < DIMC; j++)
        {
            if(array[i][j] == Living){
                printf("■ ");
            }
            if(array[i][j] == Dead){
                printf("  ");
            }
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
                if(array[i][j] == Living)
                {
                    vivant++;
                }
            }
            if(i==0)
            {
                if(array[DIMC-1][j] == Living)
                {
                    vivant++;
                }
            }
            if(i==DIMC-1)
            {
                if(array[0][j] == Living)
                {
                    vivant++;
                }
            }
            if(j==0)
            {
                if(array[i][DIML-1] == Living)
                {
                    vivant++;
                }
            }
            if(j==DIML-1)
            {
                if(array[i][0] == Living)
                {
                    vivant++;
                }
            }
        }
    }
    if(array[x][y] == Living)
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
                array[i][j] = Dead;
            }
            if(state == 3)
            {
                array[i][j] = Living;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    char a[DIML][DIMC];
    generate(a);
    while(1)
    {
        printf("\033[2J");
        display(a);
        suivant(a);
        usleep(100000);
    }
    return 0;
}