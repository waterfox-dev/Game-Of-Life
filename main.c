#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define DIML 20
#define DIMC 20

void genererate(char array[DIML][DIMC])
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

void genererate_canon(char array[DIML][DIMC])
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
            if(((i < 10 &&  i >= 8) && (j < 2 && j >= 0) )||( (i < 12 &&  i >= 10) && (j < 1 &&  j >= 0))){
                array[i][j] = '@';
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
            printf("%c ", array[i][j]);
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
            if((i>=0 && i<DIML) && (j>=0 && j <DIMC))
            {
                if(array[i][j] == '@')
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

void add_living(char array[DIML][DIMC])
{
    int x;
    int y;
    printf("\nx : ");
    scanf("%d", &x);
    printf("\ny : ");
    scanf("%d", &y);
    array[x][y] = '@';
}

int main()
{
    srand(time(NULL));
    //display_column();
    char a[DIML][DIMC];
    genererate(a);
    //generate_canon(a);
    //add_living(a);
    while(1)
    {
        printf("\033[2J");
        display(a);
        //suivant(a);
        usleep(100000);
    }
    return 0;
}
