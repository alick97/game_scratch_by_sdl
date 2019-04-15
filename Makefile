OBJS = Game.o TextureManager.o SDLGameObject.o Player.o Enemy.o LoaderParams.o InputHandler.o
OBJS += MenuState.o PlayState.o GameStateMachine.o MenuButton.o
OBJS += PauseState.o GameOverState.o AnimatedGraphic.o
OBJS += GameObjectFactory.o
SRC_DIR = src
CFLAGS := -g -I/usr/include/SDL2 -I$(SRC_DIR) -lSDL2 -lSDL2_image -D_REENTRANT
BUILD_DIR := build
TARGET := $(BUILD_DIR)/out

$(if $(shell test ! -d $(BUILD_DIR) && echo "create dir: build"), $(shell mkdir $(BUILD_DIR)),)

all: $(TARGET)
    
OBJS := $(addprefix $(BUILD_DIR)/, $(OBJS))

$(filter %.o, $(OBJS)): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c $(CFLAGS) -o $@ $<

$(TARGET): $(OBJS) $(SRC_DIR)/main.cpp
	g++ -o $(TARGET) $(OBJS) $(CFLAGS) $(SRC_DIR)/main.cpp

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
