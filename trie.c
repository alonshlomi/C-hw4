#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

//Constructors:
Trie* newTrie()
{
    Trie* new_trie = (Trie*) malloc(sizeof(Trie));
    new_trie->root = newNode(0);

    return new_trie;
}

Node* newNode(char l)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->letter = l;
    new_node->count = 0;
    new_node->isLeaf = FALSE;
    for(int i = 0 ; i < NUM_LETTERS ; i++)
    {
        new_node->children[i] = NULL;
    }
    
    return new_node;
}
//


void insert(Trie* trie, char word[], int word_size) 
{
    Node* curr = trie->root;
    
    for(int i = 0; i< word_size ; i++)
    {
        char ch = word[i];
        if(ch == 0) break;
        if(curr->children[ch - 'a'] == NULL)
        {
            Node* new_node = newNode(ch);
            curr->children[ch - 'a'] = new_node;
        }

        curr = curr->children[ch - 'a'];               
    }
    curr->isLeaf = TRUE;
    curr->count++;
}

void printTrie(Trie * trie) 
{   
    char s[WORD_SIZE];
    display(trie->root,s,0);
}

void display(Node * root, char str[], int level)
{   
    if(root == NULL) return;
    if(root->isLeaf == TRUE)
    {
        str[level] = '\0';
        printf("%s\t%ld\n",str,root->count);
    }

    int i;
    for(i=0;i<NUM_LETTERS;i++)
    {
        if(root->children[i] != NULL)
        {
            str[level] = i + 'a';
            display(root->children[i],str,level+1);
        }
    }
}

void printTrieR(Trie * trie)
{
    char s[WORD_SIZE];
    displayR(trie->root,s,0); 
}

void displayR(Node * root, char str[], int level)
{
    if(root == NULL) return;

    int i;
    for(i=NUM_LETTERS-1;i>=0;i--)
    {
        if(root->children[i] != NULL)
        {
            str[level] = i + 'a';
            displayR(root->children[i],str,level+1);
        }
    }

    if(root->isLeaf == TRUE)
    {
        str[level] = '\0';
        printf("%s\t%ld\n",str,root->count);
    }
}

int main()
{
    Trie * trie = newTrie();
    
    insert(trie,"lee",3);
    insert(trie,"abc",3);
    insert(trie,"abcdd",5);
    insert(trie,"abcc",4);


    printTrie(trie);
    printf("\n");
    printTrieR(trie);

}