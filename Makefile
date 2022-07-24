CC=gcc
DEPENDENCIES= src/print_help.c src/print_list.c src/inline_arguments_check.c src/create_or_blank_list.c src/add_to_list.c src/remove_list.c

.PHONY: test clean

test: beli
	bin/beli

beli: src/main.o src/print_help.o src/print_list.o src/inline_arguments_check.o src/create_or_blank_list.o src/add_to_list.o src/remove_list.o
	$(CC) -o bin/beli src/main.o $(DEPENDENCIES)
	rm -f src/main.o
	rm -f src/print_help.o src/print_list.o src/inline_arguments_check.o src/create_or_blank_list.o src/add_to_list.o src/remove_list.o

main.o: src/main.c
	$(CC) -c src/main.c

clean:
	rm -f src/main.o src/print_help.o src/print_list.o src/inline_arguments_check.o src/create_or_blank_list.o src/add_to_list.o src/remove_list.o
