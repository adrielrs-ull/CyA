# Variables
CC = g++                 # Compilador
CFLAGS = -Wall -g        # Opciones de compilación (muestra advertencias, habilita debug)
OBJ = check_correct_parameters.o code_analyzer.o comment.o block_comment.o p04_code_analyzer.o loops.o variables.o # Archivos objeto
TARGET = code_analyzer   # Nombre del ejecutable

# Regla principal: compila el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Reglas para generar los archivos objeto
check_correct_parameters.o: check_correct_parameters.cc
	$(CC) $(CFLAGS) -c check_correct_parameters.cc

variables.o: variables.cc
	$(CC) $(CFLAGS) -c variables.cc

loops.o: loops.cc
	$(CC) $(CFLAGS) -c loops.cc

code_analyzer.o: code_analyzer.cc
	$(CC) $(CFLAGS) -c code_analyzer.cc

comment.o: comment.cc
	$(CC) $(CFLAGS) -c comment.cc

block_comment.o: block_comment.cc
	$(CC) $(CFLAGS) -c block_comment.cc

p04_code_analyzer.o: p04_code_analyzer.cc
	$(CC) $(CFLAGS) -c p04_code_analyzer.cc

# Regla clean: elimina los archivos objeto y el ejecutable
clean:
	rm -f $(OBJ)

# Indicamos que 'clean' no es un archivo
.PHONY: clean
