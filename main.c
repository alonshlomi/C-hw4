#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int getWord(char w[])
{
    char ch;
    int num_count = 0;
    while (scanf("%c", &ch) > 0)
    {
        if (num_count == WORD_SIZE)
            break;

        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
            w[num_count] = ch;
        }
        else if ((ch == '\n') || (ch == '\t') || (ch == ' ') || (ch == 0))
        {
            w[num_count] = ch;
            break;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            w[num_count] = ch;
        }
        else
        {
            continue;
        }

        num_count++;
    }
    return num_count;
}

int main(int argc, char *argv[])
{
    if (argc > 2 || (argc == 2 && strcmp(argv[1], "r") != 0))
    {
        printf("Invalid parameters!\n");
        return 1;
    }

    Trie *trie = newTrie();
    char str[WORD_SIZE];
    int size;
    while ((size = getWord(str)) > 0)
    {
        insert(trie, str, size);
    }

    if (argc == 2)
    {
        printTrieR(trie);
    }
    else
    {
        printTrie(trie);
    }

    freeTrie(trie);
    return 0;
}