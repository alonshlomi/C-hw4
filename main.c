#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

//Read word from standart input. (taken from hw3)
int getWord(char w[])
{
    char ch;
    int num_count = 0;
    while (scanf("%c", &ch) > 0)
    {
        if (num_count == WORD_SIZE)
            break;

        if (ch >= 'A' && ch <= 'Z') //ToLowerCase
        {
            ch += 32;
            w[num_count] = ch;
        }
        else if ((ch == '\n') || (ch == '\t') || (ch == ' ') || (ch == 0)) //End of word
        {
            w[num_count] = ch;
            break;
        }
        else if (ch >= 'a' && ch <= 'z')    // Insert Low letter
        {
            w[num_count] = ch;
        }
        else     //Ignore otherwise
        {
            continue;
        }

        num_count++; //count the letter added
    }
    return num_count; 
}

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
    char str[WORD_SIZE]; 
    int size;
    while ((size = getWord(str)) > 0) //While the program recieve words
    {
        insert(trie, str, size);    //Insert to trie
    }

    if (argc == 2)  //if there is 'r' parameter, print reverse.
    {
        printTrieR(trie);
    }
    else    //Otherwise
    {
        printTrie(trie);
    }

    freeTrie(trie); //free memory
    return 0;
}