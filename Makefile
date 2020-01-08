CC = gcc
FLAGS = -g -Wall

all: trie.o trie

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

trie: trie.o
	$(CC) $(FLAGS) trie.o -o trie

.PHONY: clean all

clean:
	rm -f *.o trie