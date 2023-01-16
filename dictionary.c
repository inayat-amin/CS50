// Implements a dictionary's functionality
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int no_of_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) != 0)
        {
            cursor = cursor->next;
        }
        
        else
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int code = toupper(word[0]) - 64;
    
    if (code > N)
    {
        code = code % N;
        return code;
    }
    
    else
    {
        return code;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary, "r");

    if (fp == NULL)
    {
        return false;
    }

    else
    {
        char word[46];

        while (fscanf(fp, "%s", word) != EOF)
        {
            //Creating new nodes:

            node *nodeNew = malloc(sizeof(node));
            if (nodeNew == NULL)
            {
                return false;
            }

            else
            {
                strcpy(nodeNew->word, word);
                nodeNew->next = NULL;

                int index = hash(word);
                if(table[index] == NULL)
                {
                    table[index] = nodeNew;
                }
                else
                {
                    nodeNew->next = table[index];
                    table[index] = nodeNew;
                }
                
                no_of_words++;
            }
        }
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return no_of_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        
        while (cursor != NULL)
        {
           cursor = cursor->next;
           free(tmp);
           tmp = cursor;
        }
    }
    return true;
}
