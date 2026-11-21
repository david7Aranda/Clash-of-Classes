# Makefile for Clash of Classes
#   make        build ./clash_of_classes
#   make run    build and play
#   make clean  delete build files

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2

SRC    := $(wildcard src/*.cpp)
OBJ    := $(SRC:src/%.cpp=build/%.o)
TARGET := clash_of_classes

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp $(wildcard src/*.h) | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build $(TARGET)

.PHONY: all run clean
