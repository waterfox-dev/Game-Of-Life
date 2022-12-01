#include <stdio.h>
#include <stdlib.h>

#define DIML 41
#define DIMC 41

void write_arr(char filename[], char array[DIML][DIMC])
{
    FILE* file = fopen(filename, "w");
    for(int i=0; i<DIML; i++)
    {
        for(int j=0; j<DIMC; j++)
        {          
            fputc(array[i][j], file);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}