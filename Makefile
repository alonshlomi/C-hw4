CC = gcc
FLAGS = -g -Wall

all: trie.o frequency

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

frequency: trie.o
	$(CC) $(FLAGS) trie.o -o frequency

.PHONY: clean all

clean:
	rm -f *.o frequency