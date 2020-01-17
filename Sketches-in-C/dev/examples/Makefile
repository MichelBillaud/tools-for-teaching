execs = appli1 inputline test-input-and-key


CFLAGS += -std=c11 -Wall -Wextra -Wno-unused -Werror
CFLAGS += -I ../framework
CFLAGS += -MMD

LDFLAGS += `sdl2-config --libs` -lSDL2_ttf -L ../framework -lframework

all: $(execs)

%: %.o prog.o
	$(LINK.c) $< prog.o -o $@


-include $(wildcard *.d)

clean:
	$(RM) *.o *.d *~

mrproper: clean
	$(RM) $(execs)
