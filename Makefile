CC=gcc
DEPENDENCIES= src/print_help.c src/print_list.c src/inline_arguments_check.c src/create_or_blank_list.c src/add_to_list.c src/remove_list.c

.PHONY: test clean

test: beli
	bin/beli

beli: src/main.o src/print_help.o src/print_list.o src/inline_arguments_check.o src/create_or_blank_list.o src/add_to_list.o src/remove_list.o
	$(CC) -o bin/beli src/main.o $(DEPENDENCIES)
	rm -f src/*.o
	mkdir ~/.config/beli && cd ~/.config/beli && mkdir lists && cd lists && touch list && echo 0\n >> list && cd .. && touch all_lists.beli && echo 1\nlist >> all_lists.beli && cd ~

main.o: src/main.c
	$(CC) -c src/main.c

clean:
	rm -f src/*.o
