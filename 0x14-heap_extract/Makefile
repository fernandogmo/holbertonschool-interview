SHELL	= bash

ifdef NIX_CC_FOR_TARGET
CC	= $$NIX_CC_FOR_TARGET/bin/gcc
else
CC	= gcc
endif

CFLAGS	= -ggdb3 \
	  -Wall \
	  -Werror \
	  -Wextra \
	  -pedantic\
	#   -std=c99

LDFLAGS	= -L.
LDLIBS	= -lheap

.PHONY: test clean fullgrind check_version

% :
	@$(CC) $(CFLAGS) $(LDFLAGS) -I. -o $@.out $^ $(LDLIBS)

0 : 0-main.c 0-heap_extract.c binary_tree_print.c

RED = \033[0;31m
BLUE = \033[0;34m
NC  = \033[0m

TARGET ?= 0
test: $(TARGET)
	@echo -en "${BLUE}"
	@$(CC) --version | head -1
	@echo -en "${NC}"
	timeout --signal=KILL 0.5s ./$<.out

clean:
	@$(RM) *.o *.so *.out

fullgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./0.out

gcc_version:
	$(CC) --version

pycheck :
	@echo $(PYTHONLIB)
