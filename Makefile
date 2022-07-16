CC=gcc
DEPENDENCIES= src/printHelp.c src/printFromFile.c

.PHONY: test clean

test: beli
	./beli

beli: src/main.o src/printHelp.o src/printFromFile.o
	$(CC) -o beli src/main.o $(DEPENDENCIES)
	rm -f src/main.o
	rm -f src/printHelp.o src/printFromFile.o

main.o: src/main.c
	$(CC) -c src/main.c

clean:
	rm -f src/main.o src/printHelp.o src/printFromFile.o
