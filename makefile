# Source projects

SOURCE_FILES = src/main.cpp src/window/window.cpp src/life/board.cpp
OBJ_FILES = src/main.o src/window/window.o src/life/board.o
EXE_NAME = a

# Compiler and linker options

CC = gcc
CFLAGS = -Wall -Wextra
LFGLAS = -lstdc++ -lsfml-graphics -lsfml-window -lsfml-system

# Recipe

all: build
	./$(EXE_NAME)

build: $(EXE_NAME)

$(EXE_NAME): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LFGLAS)

%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)


.PHONY: clean

clean:
	rm $(EXE_NAME) $(OBJ_FILES)
	clear
