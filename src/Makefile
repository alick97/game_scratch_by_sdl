OBJS = hello.o
SRCS = $(OBJS:.o=.cpp)
CFLAGS = -g -I/usr/include/SDL2 -lSDL2 -D_REENTRANT

all: out

$(OBJS) : $(SRCS)
	g++ -c $(CFLAGS) -o $@ $<

out: $(OBJS)
	g++ -o out $(OBJS) $(CFLAGS)


.PHONY: clean
clean:
	rm -rf $(OBJS) out
