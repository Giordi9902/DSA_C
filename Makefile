CC  = gcc
CFLAGS = -Wall -Wextra -I./Array -I./Lists -I./Test/Array -I./Test/List -I./Test

# Directories
BIN_DIR = bin
ARRAY_DIR = Arrays
TEST_DIR = Test
ARR_TEST_DIR = Test/Array
LST_TEST_DIR = Test/List
LIST_DIR = Lists
TREE_DIR = Trees
STACK_DIR = Stack
QUEUE_DIR = Queues

# Source files
SRCS = main.c $(ARRAY_DIR)/array.c $(LIST_DIR)/list.c $(ARR_TEST_DIR)/array.c $(LST_TEST_DIR)/list.c $(TEST_DIR)/test.c

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
