#define NUM_LETTERS ((int)26)
#define WORD_SIZE 30
typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct Node
{
    char letter;
    long unsigned int count;
    struct Node * children[NUM_LETTERS];
    boolean isLeaf;
} Node;

typedef struct Trie
{
    Node * root;
} Trie;

Trie* newTrie();

Node* newNode(char letter);

void insert(Trie* trie, char word[], int word_size);

void printTrie(Trie * trie);
void display(Node * root, char str[], int level);

void printTrieR(Trie * trie);
void displayR(Node * root, char str[], int level);
