CC = gcc
FLAGS = -g -Wall

all: main.o trie.o frequency

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

frequency: main.o trie.o
	$(CC) $(FLAGS) main.o trie.o -o frequency

main.o: main.c trie.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o frequency