CC  = gcc
CFLAGS = -Wall -Wextra -I./Array

# Directories
BIN_DIR = bin
ARRAY_DIR = Arrays
LIST_DIR = Lists
TREE_DIR = Trees
STACK_DIR = Stack
QUEUE_DIR = Queues

# Source files
SRCS = main.c $(ARRAY_DIR)/array.c $(LIST_DIR)/list.c

# Object files
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

# Executable name
EXEC = $(BIN_DIR)/main

# Phony targets
.PHONY: all clean

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiling
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BIN_DIR)

# Include dependencies
-include $(OBJS:.o=.d)

# Generate dependencies
$(BIN_DIR)/%.d: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MM -MT '$(@:.d=.o)' $< > $@
