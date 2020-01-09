#define NUM_LETTERS ((int)26)
#define WORD_SIZE 10
#define TO_LOWER 32

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct Node
{
    char letter;                            //represents the letter
    long unsigned int count;                //num word ended by this node
    struct Node * children[NUM_LETTERS];    //Node array, represents the potential children of this node
    boolean isLeaf;                         //indicate whether this node is a end of word
} Node;

typedef struct Trie
{
    Node * root;    //holds the trie root
} Trie;

Trie* newTrie();

Node* newNode(char letter);

void insert(Trie* trie, char word[], int word_size);

void printTrie(Trie * trie,int size);
void display(Node * root, char str[], int level);

void printTrieR(Trie * trie,int size);
void displayR(Node * root, char str[], int level);

void freeTrie(Trie * trie);
void freeNode(Node * node);