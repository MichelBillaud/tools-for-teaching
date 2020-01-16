


CFLAGS += -std=c11 -Wall -Wextra -Wno-unused -Werror
CFLAGS += `sdl2-config --cflags`
CFLAGS += -O9
CFLAGS += -MMD

all: libframework.a

libframework.a: prog.o
	$(AR) rcs $@ $<

-include $(wildcard *.d)

clean:
	$(RM) *.o *.d *~

mrproper: clean
	$(RM) *.a
