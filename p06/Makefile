# Variables
CC = g++                            # Compilador
CFLAGS = -Wall -g                   # Opciones de compilación (muestra advertencias, habilita debug)
OBJ = alfabeto.o automata.o main.o check_correct_parameters.o # Archivos objeto
TARGET = p06_automata_simulator           # Nombre del ejecutable

# Regla principal: compila el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Reglas para generar los archivos objeto
check_correct_parameters.o: check_correct_parameters.cc check_correct_parameters.h
	$(CC) $(CFLAGS) -c check_correct_parameters.cc

alfabeto.o: alfabeto.cc alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.cc

automata.o: automata.cc automata.h
	$(CC) $(CFLAGS) -c automata.cc

main.o: main.cc automata.h
	$(CC) $(CFLAGS) -c main.cc

# Regla clean: elimina los archivos objeto y el ejecutable
clean:
	rm -f $(OBJ)

# Indicamos que 'clean' no es un archivo
.PHONY: clean
