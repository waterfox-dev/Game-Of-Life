#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

<<<<<<< HEAD
#define DIML 20
#define DIMC 20
=======
#define DIML 10
#define DIMC 10
>>>>>>> f4935b3bd4a8a8841d2801ffaa64d27693b21e27

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

<<<<<<< HEAD
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

=======
void generate_empty(char array[DIML][DIMC])
{
    for (int i = 0; i < DIML; i++)
    {
        for(int j = 0;  j < DIMC; j++)
        {
            array[i][j] = '.';
>>>>>>> f4935b3bd4a8a8841d2801ffaa64d27693b21e27
        }
    }
}

<<<<<<< HEAD
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
=======
>>>>>>> f4935b3bd4a8a8841d2801ffaa64d27693b21e27

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
<<<<<<< HEAD
            printf("%c ", array[i][j]);
=======
            printf(" %c ", array[i][j]);  
>>>>>>> f4935b3bd4a8a8841d2801ffaa64d27693b21e27
        }
<<<<<<< HEAD
    }
    printf("\n");
}
=======
        printf("\n");
    }
>>>>>>> 72eea1ba6764ff6768e3f99f292b58a55c2e81e0

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
<<<<<<< HEAD
    genererate(a);
    //generate_canon(a);
    //add_living(a);
=======
    char filename[] = "test.txt";
    char b[DIML][DIMC];
    generate_empty(b);
    generate(a);
    write_arr(filename, b);
>>>>>>> f4935b3bd4a8a8841d2801ffaa64d27693b21e27
    while(1)
    {
        printf("\033[2J");
        display(a);
        //suivant(a);
        usleep(100000);
    }
    return 0;
}
