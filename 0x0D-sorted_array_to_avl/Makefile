SHELL	= bash
# CC	= $$NIX_CC_FOR_TARGET/bin/gcc
CC	= gcc
CFLAGS	= -ggdb3 \
	  -Wall \
	  -Wextra \
	  -pedantic \
	  -Werror \
	#   -fno-stack-protector -z execstack -no-pie \
	#   -fsanitize=address \

.PHONY: 0 test clean again fullgrind check_version

0: 0-main.o 0-sorted_array_to_avl.o binary_tree_print.o
	$(CC) $(CFLAGS) -o $@.out $?

test: 0
	timeout --signal=KILL 0.005s ./$<.out # head -30

clean:
	rm -rf *.o

again: clean 0

fullgrind: again
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./0.out

check_version:
	$(CC) --version
