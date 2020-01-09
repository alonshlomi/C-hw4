#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

//Constructors:
Trie *newTrie()
{
    Trie *new_trie = (Trie *)malloc(sizeof(Trie)); //Memory allocate
    new_trie->root = newNode(0);                   //Build node with no data for the root

    return new_trie;
}

Node *newNode(char l)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); //Memory allocate
    new_node->letter = l;
    new_node->count = 0;
    new_node->isLeaf = FALSE;
    for (int i = 0; i < NUM_LETTERS; i++) //Initialize the children array
    {
        new_node->children[i] = NULL;
    }

    return new_node;
}
//

//Insert new node to Trie
void insert(Trie *trie, char *word, int word_size)
{
    Node *curr = trie->root;

    for (int i = 0; i < word_size; i++)
    {
        char ch = word[i];
        if (ch == 0) //Word end
            break;
        if (curr->children[ch - 'a'] == NULL) //Check if there is a child with this letter
        {
            Node *new_node = newNode(ch); //Build new Node
            curr->children[ch - 'a'] = new_node;
        }

        curr = curr->children[ch - 'a'];
    }
    curr->isLeaf = TRUE;
    curr->count++;
}

void printTrie(Trie *trie,int size)
{
     char s[size];  //Init a String(char array)
    //char *s = (char *)malloc(WORD_SIZE);
    display(trie->root, s, 0); //Recursive call
}

//helper function for printing the trie in alphabetic order
void display(Node *root, char *str, int level)
{
    //Stop condition:
    if (root == NULL)
        return;
    //

    if (root->isLeaf == TRUE) //Check whether this node is a leaf
    {   
        str[level] = '\0';
        printf("%s\t%ld\n", str, root->count); //Print the String contains the word until this node
    }

    int i;
    for (i = 0; i < NUM_LETTERS; i++) //Running from the lower to upper
    {
        
        if (root->children[i] != NULL)
        {

            str[level] = i + 'a';                       //Add the letter to the String
            display(root->children[i], str, level + 1); //Recursive call
        }
    }
}

void printTrieR(Trie *trie,int size)
{
    char s[size];          //Init a String(char array)
    displayR(trie->root, s, 0); //Recursive call
}

//Backwords display() function
void displayR(Node *root, char str[], int level)
{
    //Stop condition:
    if (root == NULL)
        return;
    //

    int i;
    for (i = NUM_LETTERS - 1; i >= 0; i--) //Running for upper to lower
    {
        if (root->children[i] != NULL)
        {
            str[level] = i + 'a';
            displayR(root->children[i], str, level + 1);
        }
    }

    if (root->isLeaf == TRUE)
    {
        str[level] = '\0';
        printf("%s\t%ld\n", str, root->count);
    }
}

//free trie and nodes:
void freeTrie(Trie *trie)
{
    freeNode(trie->root);
    free(trie);
}

void freeNode(Node *node)
{
    int i;
    for (i = 0; i < NUM_LETTERS; i++)
    {
        if (node->children[i] != NULL)
        {
            freeNode(node->children[i]);
        }
    }
    free(node);
}
//