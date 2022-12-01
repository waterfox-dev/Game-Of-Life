#include <stdio.h>
#include <stdlib.h>
#include "reader.c"
#include "writer.c"
#include "main.c"

#define DIML 40
#define DIMC 40

int main()
{
    char a[DIML][DIMC]; 
    char filename[] = "test.txt";
    read_arr(filename, a);
    while(1)
    {
        printf("\033[2J");
        display(a);
        suivant(a);
        usleep(10000000);
    }
    return 0;
}