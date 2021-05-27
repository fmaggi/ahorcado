CC=g++
INC=./src/
OBJ=./obj/rel/
BIN=./bin/rel/

TARGET=ahorcado

OBJECTS=$(OBJ)juego.o $(OBJ)jugador.o $(OBJ)diccionario.o $(OBJ)main.o

all: $(TARGET)

$(OBJ)%.o: $(INC)%.cpp
	mkdir -p $(OBJ)
	$(CC) -I $(INC) -o $@ -c $^

$(TARGET): $(OBJECTS)
	$(CC) -I $(INC) -o $@ $^

clean:
	rm -rf $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

