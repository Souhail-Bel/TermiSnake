# Project configs
debug 		?= 0
NAME		:= termisnake
SRC_DIR		:= src
BUILD_DIR	:= build
INCLUDE_DIR	:= include
BIN_DIR 	:= bin


# Object file paths
OBJS 		:= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)) # it's patsubst not patsubset smh

# Compiler settings
CC 		:= g++

# Flags settings (Compiler and Linker)
CFLAGS 		:= -Wall -Wextra -pedantic -I$(INCLUDE_DIR)
LFLAGS 		:= 

ifeq ($(debug), 1)
	CFLAGS 	:= $(CFLAGS) -g -D DEBUG_MODE
endif


all: $(NAME)

# Build exec
$(NAME): dir $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(BIN_DIR)/$@

# Object build rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | dir
	$(CC) $(CFLAGS) -c $< -o $@

dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean dir
