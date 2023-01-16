#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long start_size;
    long end_size;
    int population_gained;
    int population_lost;
    int population_growth;
    int n = 0;
    
    // TODO: Prompt for start size
    do
    {
        start_size = get_long("Start size: ");
        if (start_size < 9)
        {
            printf("ERROR! The starting population size must be greater than or equal to 9\n");
        }
    } 
    while(start_size < 9);
    
    // TODO: Prompt for end size
    do
    {
        end_size = get_long("End size: ");
        if(end_size < start_size)
        {
            printf("ERROR! The ending population size must be greater than or equal to the starting population size\n");
        }
    }
    while(end_size < start_size);
    
    // TODO: Calculate number of years until we reach threshold
    do
    {
        population_gained = (int)start_size/3;
        
        population_lost = (int)start_size/4;
      
        population_growth = start_size + population_gained - population_lost;
        
        if(start_size != end_size)
        {
            n++;
        }
        
        start_size = (long)population_growth;
    }
    while(population_growth < end_size);
    
    // TODO: Print number of years
    printf("Years: %i\n", n);
}
