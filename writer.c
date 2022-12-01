#include <stdio.h>
#include <stdlib.h>

#define DIML 50
#define DIMC 50


void write_arr(char filename[], char array[DIML][DIMC])
{
    FILE* file = fopen(filename, "w");
    for(int i=0; i<DIML; i++)
    {
        for(int j=0; j<DIMC; j++)
        {
            fprintf(file, "%c", array[DIML][DIMC]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}