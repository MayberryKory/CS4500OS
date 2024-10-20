# Makefile for the LinkedList project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -I.

# Source files
SRC = LinkedList.c ListTest.c

# Object files
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = ListTest

# Default target to build the project
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# Rule to create object files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up the build
clean:
	rm -f $(OBJ) $(TARGET)
