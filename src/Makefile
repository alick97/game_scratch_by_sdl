OBJS = Game.o TextureManager.o
SRCS = $(OBJS:.o=.cpp)
CFLAGS = -g -I/usr/include/SDL2 -I. -lSDL2 -lSDL2_image -D_REENTRANT

all: out

$(filter %.o, $(OBJS)): %.o: %.cpp
	g++ -c $(CFLAGS) -o $@ $<

out: $(OBJS)
	g++ -o out $(OBJS) $(CFLAGS) main.cpp

.PHONY: clean
clean:
	rm -rf $(OBJS) out
