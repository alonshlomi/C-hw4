#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char *argv[])
{
    //Check for invalid parameter. Need to be 'r' or nothing.
    if (argc > 2 || (argc == 2 && strcmp(argv[1], "r") != 0))
    {
        printf("Invalid parameters!\n");
        return 1;
    }
    //

    Trie *trie = newTrie(); //Initialize new trie.
    char *str = (char *)malloc(sizeof(char) * 2);
    int max_size = 0;
    int size = 0;
    char ch;
    while (scanf("%c", &ch) == 1)
    {
        if ((ch == '\n' || ch == ' ' || ch == '\t'))
        {
            if (size != 0)
            {
                insert(trie, str, size);
                if (size > max_size)
                {
                    max_size = size;
                }
                free(str);
                str = (char *)malloc(sizeof(char) * 2);
                size = 0;
            }
            continue;
        }

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += TO_LOWER;
            }
            str[size++] = ch;
            str = (char *)realloc(str, size + 2);
        }
    }

    if (size != 0)
    {
        insert(trie, str, size);
        if (size > max_size)
        {
            max_size = size;
        }
    }
    free(str);

    if (argc == 2) //if there is 'r' parameter, print reverse.
    {
        printTrieR(trie, max_size);
    }
    else //Otherwise
    {
        printTrie(trie, max_size);
    }

    freeTrie(trie); //free memory
    return 0;
}