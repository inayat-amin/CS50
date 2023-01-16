#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        if (score1 > score2)
        {
            printf("Player 1 wins!\n");
        }
        else
        {
            printf("Player 2 wins!\n");
        }
    }
}

int compute_score(string word)
{
    
    int score = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        char letter = word[i];
        if ((int)word[i] >= 97 && (int)word[i] <= 122)
        {
            letter = (char)((int)word[i] - 32);
        }
        
        //Letters with 1 point: 
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' || letter == 'O' || letter == 'R' 
            || letter == 'S' || letter == 'T' || letter == 'U')
        {
            score = score + 1;
        }
        
        //Letters with 2 points:
        if (letter == 'D' || letter == 'G')
        {
            score = score + 2;
        }
        
        //Letters with 3 points:
        if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
        {
            score = score + 3;
        }
        
        //Letters with 4 points:
        if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
        {
            score = score + 4;
        }
        
        //Letters with 5 points:
        if (letter == 'K')
        {
            score = score + 5;
        }
        
        //Letters with 8 points:
        if (letter == 'J' || letter == 'X')
        {
            score  = score + 8;
        }
        
        //Letters with 10 points:
        if (letter == 'Q' || letter == 'Z')
        {
            score  = score + 10;
        } 
        
    }
    
    return (score);
}
