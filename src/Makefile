OBJS = Game.o
SRCS = $(OBJS:.o=.cpp)
CFLAGS = -g -I/usr/include/SDL2 -I. -lSDL2 -D_REENTRANT

all: out

$(OBJS) : $(SRCS)
	g++ -c $(CFLAGS) -o $@ $<

out: $(OBJS)
	g++ -o out $(OBJS) $(CFLAGS) main.cpp

.PHONY: clean
clean:
	rm -rf $(OBJS) out
