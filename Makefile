CC = gcc
CFLAGS = -Wall -Iinclude -I./src -lraylib
SRC = src/main.c src/app.c src/utils/recursion.c
OBJ = $(SRC:.c=.o)
TARGET = my_cpp_raylib_project

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean