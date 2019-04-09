CC=cc

SRC_DIR=src

SRC_EXT=cpp

INCLUDE_DIR=include

OBJ_DIR=obj

CFLAGS=-lstdc++ -std=c++17 -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system

WFLAGS=-Wall -Wextra -std=c++17 -lstdc++fs

EXE=deadMouseSFML

SOURCES := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJECTS := $(SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(EXE)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p obj
	$(CC) $(WFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm $(OBJECTS) $(EXE) -v
