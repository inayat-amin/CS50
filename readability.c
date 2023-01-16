#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float compute_letters(string reading_words);
float compute_sentences(string reading_words);

int main(void)
{
    string reading = get_string("Text: ");
    float L = compute_letters(reading);
    float S = compute_sentences(reading);
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", index);
    }
    
    
    return 0;
}

float compute_letters(string reading_words)
{
    int n = strlen(reading_words);
    int letters = 0;
    int words = 0;
    
    //Making sure that if user forgets to put an endpoint in the end of the paragraph, it still counts the last letter:
    
    if (!(reading_words[n - 1] == '.' || reading_words[n - 1] == '!' || reading_words[n - 1] == '?' || reading_words[n - 1] == '"'))
    {
        letters = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        //Counting words at the end of the sentence/paragraph:
        
        if (reading_words[i] == '.' || reading_words[i] == ',' || reading_words[i] == '!' || reading_words[i] == '?'
            || reading_words[i] == ';' || reading_words[i] == ':' || (int)reading_words[i + 1] == 0)
        {
          
            words = words + 1;
        }
        
        //Counting words for when there is just a space and no symbol before the space:
        
        else if (reading_words[i] == ' ')
        {
            if (!(reading_words[i - 1] == '.' || reading_words[i - 1] == ',' || reading_words[i - 1] == '!' || reading_words[i - 1] == '?'
                  || reading_words[i - 1] == ';' || reading_words[i - 1] == ':' || reading_words[i - 1] == '"' || reading_words[i + 1] == '"'
                  || (reading_words[i - 1] == '"' && reading_words[i - 2] == '?') || (reading_words[i - 1] == '"' && reading_words[i - 2] == '!')
                  || (reading_words[i - 1] == '"' && reading_words[i - 2] == '.')))
            {
                words = words + 1;
            }
        }
        
        //If a hyphen is included in the word, it ignores it as a letter:
        
        else if (reading_words[i] == '-')
        {
            letters = letters + 1;
            letters = letters - 1;
        }
        
        //Increases letter count when the character read is not an apostrophe (Example: You're) and it is not a space and also not a double quote:
        
        else
        {
            if ((int)reading_words[i] != 39 && reading_words[i] != ' ' && reading_words[i] != '"')
            {
                letters = letters + 1;
            }
        }
    }
    
    float L = (letters / (float)(words)) * 100;

    return L;
}

float compute_sentences(string reading_words)
{
    int n = strlen(reading_words);
    int sentences = 0;
    int words = 0;
    for (int i = 0; i < n; i++)
    {
        //Computes sentences when the character read is an endpoint or the character after the endpoint is not a double quote:
        
        if (reading_words[i] == '.' || reading_words[i] == ',' || reading_words[i] == '!' || reading_words[i] == '?'
            || reading_words[i] == ';' || reading_words[i] == ':' || (int)reading_words[i + 1] == 0)
        {
            if (reading_words[i] == '.' || reading_words[i] == '!' || (reading_words[i] == '?' && !(reading_words[i + 1] == '"')) 
                || (int)reading_words[i + 1] == 0)
            {
                sentences++;
            }
            words = words + 1;
        }
        
        //Counting words for when there is just a space and no symbol before the space:
        
        else if (reading_words[i] == ' ')
        {
            if (!(reading_words[i - 1] == '.' || reading_words[i - 1] == ',' || reading_words[i - 1] == '!' || reading_words[i - 1] == '?'
                  || reading_words[i - 1] == ';' || reading_words[i - 1] == ':' || reading_words[i - 1] == '"' || reading_words[i + 1] == '"'
                  || (reading_words[i - 1] == '"' && reading_words[i - 2] == '?') || (reading_words[i - 1] == '"' && reading_words[i - 2] == '!')
                  || (reading_words[i - 1] == '"' && reading_words[i - 2] == '.')))
            {
                words = words + 1;
            }
        }
    }
    
    float S = (sentences / (float)(words)) * 100;
 
    return S;
}
