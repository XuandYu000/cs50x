// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int siz=0;

// bool strcasecmp(char *a,const char *b)
// {
//     if(strlen(a)!=strlen(b)) return false;
//     for (int i = 0, n = strlen(a); i < n;i++)
//     {
//         if(toupper(a[i])!=toupper(b[i]))
//             return false;
//     }
//     return true;
// }

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashcode = hash(word);
    for (node *ptr = table[hashcode];ptr!=NULL;ptr=ptr->next)
    {
        if(!strcasecmp(ptr->word,word))//这个函数引用会严重拖延时间
            return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary, "r");
    if(input==NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(input,"%s",word)!=EOF)
    {
        node *tmp=malloc(sizeof(node));
        if(tmp==NULL)
        {
            return false;
        }
        strcpy(tmp->word, word);
        int hashcode = hash(word);
        tmp->next=table[hashcode];
        table[hashcode] = tmp;
        siz++;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return siz;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N;i++)
    {
        node *n=table[i];
        while(n!=NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
        if(i==N-1&&n==NULL)
        {
            return true;
        }
    }
    return false;
}
