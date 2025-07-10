# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Source files and object files
SRCS = main.c sorting.c
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = test_runner

# Default target: build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile a .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to run the tests
# It depends on 'all' to ensure the code is compiled first.
test: all
	@echo "--- Running tests ---"
	./$(TARGET)

# Target to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets are not files.
.PHONY: all test clean
