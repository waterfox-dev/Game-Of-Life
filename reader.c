#include <stdio.h>
#include <stdlib.h>

#define DIML 40
#define DIMC 40

void read_arr(char filename[], char array[DIML][DIMC])
{
    FILE* file = fopen(filename, "r");
    for(int i=0; i<DIML; i++)
    {
        for(int j=0; j<DIMC; j++)
        {
            char c_char = fgetc(file);  
            
            if(c_char == '@' || c_char == '.')
            {
                array[i][j] = (char)c_char;
            }
        }
    }
}
