TARGET = hbnms
SOURCE = src
BIN = bin
INC = -I $(PWD)/headers/

SRC = $(wildcard $(SOURCE)/*.cpp)
OBJ = $(patsubst %,$(BIN)/%, $(notdir $(SRC:.cpp=.o)))

CC = g++
CFLAGS = $(INC) `pkg-config --cflags --libs gtkmm-4.0` -std=c++17

$(BIN)/$(TARGET):	$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN)/%.o:	$(SOURCE)/%.cpp   check
	$(CC) -c $< -o $@ $(CFLAGS)

check:
	mkdir -p bin/

clean:
	rm -r bin/
	
run:	
	./$(BIN)/$(TARGET)