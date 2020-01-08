#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char * argv[])
{
    printf("%d\n",argc);
    printf("%s\n%s\n",argv[0],argv[1]);


    Trie * trie = newTrie();
    
    insert(trie,"lee",3);
    insert(trie,"abc",3);
    insert(trie,"abcdd",5);
    insert(trie,"abcc",4);


    printTrie(trie);
    printf("\n");
    printTrieR(trie);

}