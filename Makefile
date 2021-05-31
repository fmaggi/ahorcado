CC=g++
INC=./src/
OBJ=./obj/rel/

TARGET=ahorcado

OBJECTS=$(OBJ)juego.o $(OBJ)jugador.o $(OBJ)diccionario.o $(OBJ)main.o

all: dir $(TARGET)

$(OBJ)%.o: $(INC)%.cpp
	@echo [CC] $<
	@$(CC) -I $(INC) -o $@ -c $^

$(TARGET): $(OBJECTS)
	@echo [EXE] $@
	@$(CC) -I $(INC) -o $@ $^

dir:
	@mkdir -p $(OBJ)

clean:
	@echo cleaning
	@rm -rf ./obj ahorcado

run: dir $(TARGET)
	@echo [RUN] $(TARGET)
	@-./$(TARGET)

