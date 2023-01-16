#include <stdio.h>
#include <cs50.h>
#include <math.h>

int cents(int change)
{
    int coins = 0;
    int value_of_coins = 0;
    
    //change owed if amount is greater than $0.25:
    if(change >= 25)
    {
        while (change >= 25)
        {
            change = change - 25;
            coins++;
        }
        value_of_coins = coins;
        printf("%i coins of 25 cents\n", value_of_coins);
    }
        
    //change owed if amount is between 0.25 and 0.10:
    
    if(change < 25 && change >= 10)
    {
        while (change < 25 && change >= 10)
        {
            change = change - 10;
            coins++;
        }
        value_of_coins = coins - value_of_coins;
        printf("%i coins of 10 cents\n", value_of_coins);
    }
    
     
    //change owed if amount is between 0.10 and 0.05:
    
     if(change < 10 && change >= 5)
     {
        while (change < 10 && change >= 5)
        {
            change = change - 5;
            coins++;
        }
        value_of_coins = coins - value_of_coins;
        printf("%i coins of 5 cents\n", value_of_coins);
     }
     
    //change owed if amount is between 0.05 and 0.01:
    
    if(change < 5 && change >= 1)
    {
        while (change < 5 && change >= 1)
        {
            change = change - 1;
            coins++;
        }
        value_of_coins = coins - value_of_coins;
        printf("%i coins of 1 cents\n", value_of_coins);
    }
         
    printf("Total Coins: %i\n", coins);
   
    return (1);
}

int main(void)
{
    //prompt user for for amount
    
    float dollars = 0.00;
    while (dollars <= 0.00)
    {
        dollars = get_float("Change owed: ");
    }
    int change_owed = round(dollars * 100);
    cents(change_owed);
   
}
