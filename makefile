NAME = maze
CXX = g++
CXXFLAGS = -std=c++23 -Ofast
SOURCES_DIR = src
BUILD_DIR = build
LIBS = -I./head
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

.PHONY: all

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(OBJECTS)
	@$(CXX) -o $@ $^ $(LIBS)

$(OBJECTS): $(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

.PHONY: clean

clean:
	@-rm $(SOURCES_DIR)/*.o $(BUILD_DIR)/*
