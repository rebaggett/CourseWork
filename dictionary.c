// Implements a dictionary's functionality
#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
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
const unsigned int N = 15000;

// Hash table
node *table[N];

//Counts words in dictionary
int count;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Declarations
    node *trav = NULL; //Creates traversal cursor
    int x; //Creates int used to locate place in hash table
    
    x = hash(word);
    trav = table[x];
    while (trav != NULL)
    {
        if (strcasecmp(word, trav->word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Creates hash funtion
// Copied hash from: https://stackoverflow.com/questions/10696223/reason-for-5381-number-in-djb-hash-function
unsigned int hash(const char *word)
{
    //creates a hash seed value of 401 then loops through the words until NUL
    int hash = 401;
    while (*word != '\0')
    {
        //shifts hash 4bits left (multiplies by 16)
        //takes the int value of the char and converts it to uppercase
        hash = ((hash << 4) + toupper((int)(*word))) % N;
        word++;
    }

    return hash;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Declarations
    FILE *dict = NULL; //Where to open dictionary
    char scan[LENGTH + 1]; //Creates place for scanned word
    node *entry = NULL; //Creates node to enter hash table
    count = 0; //Sets dictionary words to 0 at beginning of load
    int hashed; //Stores hashed value for scanned word
    
    //Opens dictionary to dict
    dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error loading dictionary.\n");
        return false;
    }
    //Scans words into dict file
    while(fscanf(dict, "%s", scan) != EOF)
    {
        entry = malloc(sizeof(node));
        //Returns false if not enough memory.
        if (entry == NULL)
        {
            printf("Error loading dictionary.\n");
            return false;
        }
        strcpy(entry->word, scan);
        hashed = hash(scan);
        if (table[hashed] == NULL)
        {
            entry->next = NULL;
            table[hashed] = entry;
        }
        else
        {
            entry->next = table[hashed];
            table[hashed] = entry;
        }
    count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Declarations
    node *trav = NULL; //Creates traversal node
    node *cursor = NULL; //Creates freeing node
    
    //Iterates over each bucket in table
    for(int i = 0; i < N; i++)
    {
        trav = table[i];
        cursor = trav;
        while (trav != NULL)
        {
            trav = trav->next;
            free(cursor);
            cursor = trav;
        }
    }
    free(trav);
    return true;
}
