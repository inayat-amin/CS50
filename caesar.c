#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int cipher_text(int key, string plain_text);

int main(int argc, string argv[])
{
    //Check if there is only one argument or else print "./caesar key":
    
    if (argc == 2 && argv[1] > 0)
    {
        int n = strlen(argv[1]);
        int x = 0;
        
        for (int i = 0; i < n; i++)
        {
            //Check if each character in the argument is only a decimal and no spaces in between:
            
            if (!((int)argv[1][i] >= 48 && (int)argv[1][i] <= 57))
            {
                //Introduce a counter everytime a non-decimal is found (declaration done before the loop) making the entered key invalid:
                
                x++;
            }
        }
        
        //If the key is invalid, print "./caesar key" otherwise the key was valid and the else condition is executed:
        
        if (x > 0)
        {
            printf("%s key\n", argv[0]); 
        }
        
        else
        {
            printf("Success\n");
            
            //The string is converted to an integer (this is the key) and then the cipher_text function is executed based on the inputted plain text from the user:
            
            int key = atoi(argv[1]);
            printf("Key: %i\n", key);
            string plain_text = get_string("plaintext: ");
            cipher_text(key, plain_text);
        }
        
        return 0;
    }
    
    else
    {
        printf("%s key\n", argv[0]);
        return 1;
    }
    
}

int cipher_text(int key, string plain_text)
{
    int n = strlen(plain_text);
    int restart = 0; //This variable is used for when the key is greater than 26;
    char cipher_text[n];
    int cipher = 0;
    for (int i = 0; i < n; i++)
    {
        //Check if a character is not a symbol or else do not change the character in the cipher text:
        
        if (plain_text[i] != ' ' && plain_text[i] != '?' && plain_text[i] != '"' && plain_text[i] != '!' && plain_text[i] != '.'
            && plain_text[i] != ':' && plain_text[i] != ';' && plain_text[i] != '/' && plain_text[i] != ',' && plain_text[i] != '#'
            && plain_text[i] != '@' && plain_text[i] != '$' && plain_text[i] != '%' && plain_text[i] != '&' && plain_text[i] != '('
            && plain_text[i] != ')' && plain_text[i] != '{' && plain_text[i] != '}' && plain_text[i] != '[' && plain_text[i] != ']'
            && ((int)plain_text[i] < 48 || (int)plain_text[i] > 57))
        {
            //The cipher text is calculated by the sum of the plain text and the key:

            cipher_text[i] = plain_text[i] + key;
            
            //Additionally a variable called cipher is used for preserving lower case letters cause something weird happened when the previous formula was used (line 77):
            
            cipher = (int)plain_text[i] + key;
            
            //If a character is in Upper case and the cipher text calculated is greater than 'Z', then the following if condition is executed:
            
            if (((int)plain_text[i] >= 65 && (int)plain_text[i] <= 90) && (int)cipher_text[i] > 90)
            {
                /* If the key is less than or equal to 26 (since there are 26 letters of the alphabet) then the cipher text calculated is subtracted by Z (integer = 90) 
                and then added to 64 to get the appropriate cipher text: */
                
                if (key <= 26)
                {
                    cipher_text[i] = (char)(64 + ((int)cipher_text[i] - 90)); 
                }
                
                /* If the key is greater than 26, the remained if the key divided by 26 is found and then the plain text is 
                shifted by that many places (this is the variable 'restart') to find the appropriate cipher text: */
                
                else
                {
                    restart = key % 26;
                    cipher_text[i] = plain_text[i] + restart;
                    if ((int)cipher_text[i] > 90)
                    {
                        cipher_text[i] = (char)(64 + ((int)cipher_text[i] - 90));
                    }
                }
            }
            
            /* If the character is in lower case and the cipher text calculated is greater than 'z' (calculated from the 'cipher' variable), 
            then the following else if condition is executed. This is the same logic and math as for upper case however 'cipher' is used instead of 
            cipher_text[i] due to issues found: */
            
            else if (((int)plain_text[i] >= 97 && (int)plain_text[i] <= 122) && cipher > 122)
            {
                if (key <= 26)
                {
                    cipher_text[i] = (char)(96 + (cipher - 122)); 
                }
                else
                {
                    restart = key % 26;
                    cipher_text[i] = plain_text[i] + restart;
                    if ((int)cipher_text[i] > 122)
                    {
                        cipher_text[i] = (char)(96 + ((int)cipher_text[i] - 122));
                    }
                }
            }
        }
        
        //If a symbol, number or space is found the cipher text for that character is unchanged from the plain text:
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    
    printf("ciphertext: %s\n", cipher_text);
    
    return 0;
} 
