CFLAGS = -std=c17
CFLAGS += -Wall -Wextra -pedantic -Werror
CFLAGS += -MMD

execs = how-to-use-it example-for-manpage

all: $(execs)

how-to-use-it: how-to-use-it.o get_next_token.o

example-for-manpage: example-for-manpage.o get_next_token.o


how-to-use-it.o : CFLAGS += -D_POSIX_C_SOURCE=200809L # for strndup

-include $(wildcard *.d)

clean:
	$(RM) *~ *.d *.o

mrproper: clean
	$(RM) $(execs)

