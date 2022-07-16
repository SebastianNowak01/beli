CC=gcc
DEPENDENCIES= src/print_help.c src/print_list.c

.PHONY: test clean

test: beli
	bin/beli

beli: src/main.o src/print_help.o src/print_list.o
	$(CC) -o bin/beli src/main.o $(DEPENDENCIES)
	rm -f src/main.o
	rm -f src/print_help.o src/print_list.o

main.o: src/main.c
	$(CC) -c src/main.c

clean:
	rm -f src/main.o src/print_help.o src/print_list.o
