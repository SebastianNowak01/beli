CC=gcc

.PHONY: test clean

test: beli
	./beli

beli: src/main.o src/functions.o
	$(CC) -o beli src/main.c src/functions.c
	rm -f src/main.o
	rm -f src/functions.o

main.o: src/main.c
	$(CC) -c src/main.c

clean:
	rm -f src/main.o
	rm -f src/functions.o
