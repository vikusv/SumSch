CC = g++

CC_FLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

all: main

run: main 
	 @$(BUILD_DIR)/main.elf

runtest: test 
	 @$(BUILD_DIR)/test.elf

test: $(BUILD_DIR)/test.elf

main: $(BUILD_DIR)/main.elf

$(BUILD_DIR)/main.elf: $(SRC_DIR)/main.cpp $(SRC_DIR)/common.cpp $(SRC_DIR)/quad_eq.cpp 
		  			   $(CC) $^ $(CC_FLAGS) -o $(BUILD_DIR)/main.elf

$(BUILD_DIR)/test.elf: $(SRC_DIR)/test.cpp $(SRC_DIR)/common.cpp $(SRC_DIR)/quad_eq.cpp  $(SRC_DIR)/test_quad_eq.cpp
		  			   $(CC) $^ $(CC_FLAGS) -o $(BUILD_DIR)/test.elf

clean: 
		rm -rf $(BUILD_DIR)/*
