#include <stdio.h>
#include <cs50.h>

int height(int height)
{
    for(int i = 1; i <= height; i++)
    {
        for(int j = height - 1; j >= i; j--)
        {
            printf(" ");
        }
        for(int k = 1; k <= i*2; k++)
        {
            printf("#");
            if(k == i)
            {
                printf("  ");   
            }
        }
        printf("\n");
    }
    
    return(1);
}

int main(void)
{
    int h = 0;
    do
    {
        h = get_int("Height: "); 
        if(h <= 0 || h > 8)
        {
            printf("ERROR! Height has to be between and including 1 and 8\n");
        }
    }
    while(h <= 0 || h > 8);
    
    height(h);
}
