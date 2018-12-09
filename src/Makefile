OBJS = hello.o
SRCS = $(OBJS:.o=.c)
CFLAGS = -g -I/usr/include/SDL2 -lSDL2 -D_REENTRANT

all: out

$(OBJS) : $(SRCS)
	gcc -c $(CFLAGS) -o $@ $<

out: $(OBJS)
	gcc -o out $(OBJS) $(CFLAGS)


.PHONY: clean
clean:
	rm -rf $(OBJS) out
