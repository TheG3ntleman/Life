# Source projects

SOURCE_FILES = src/main.cpp src/app.cpp 
OBJ_FILES = src/main.o src/app.o 
EXE_NAME = sim

# Compiler and linker options

CC = g++
CFLAGS = -Wall -Wextra
LFGLAS = -lsfml-graphics -lsfml-window -lsfml-system 

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
