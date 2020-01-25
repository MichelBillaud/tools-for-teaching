CFLAGS = -std=c17
CFLAGS += -Wall -Wextra -pedantic -Werror
CFLAGS += -MMD

execs = main

how-to-use-it: how-to-use-it.o get_next_token.o

# for strndup
how-to-use-it.o : CFLAGS += -D_POSIX_C_SOURCE=200809L

-include $(wildcard *.d)

clean:
	$(RM) *~ *.d *.o

mrproper: clean
	$(RM) $(execs)

