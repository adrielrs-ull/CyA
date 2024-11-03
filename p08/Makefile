# Variables
CC = g++                            # Compilador
CFLAGS = -Wall -g                   # Opciones de compilación (muestra advertencias, habilita debug)
OBJ = alfabeto.o grammar_cnf.o main.o # Archivos objeto
TARGET = Grammar2CNF      # Nombre del ejecutable

# Regla principal: compila el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Reglas para generar los archivos objeto
alfabeto.o: alfabeto.cc alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.cc

grammar_cnf.o: grammar_cnf.cc grammar_cnf.h
	$(CC) $(CFLAGS) -c grammar_cnf.cc

main.o: main.cc grammar_cnf.h alfabeto.h
	$(CC) $(CFLAGS) -c main.cc

# Regla clean: elimina los archivos objeto y el ejecutable
clean:
	rm -f $(OBJ)

# Indicamos que 'clean' no es un archivo
.PHONY: clean
