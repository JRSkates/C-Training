# Variables
CC = gcc


# Target executable
TARGET = program_linking

# Source files
SRCS = program_linking.c math_operations.c

# Default target: directly compile all source files
all: $(TARGET)

# Rule to build the program directly
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up generated files
clean:
	rm -f $(TARGET)
