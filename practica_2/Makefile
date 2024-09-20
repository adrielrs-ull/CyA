# Variables
CC = g++                 # Compilador
CFLAGS = -Wall -g        # Opciones de compilación (muestra advertencias, habilita debug)
OBJ = alfabeto_clase.o check_correct_parameters.o operator_overloading.o p02_strings.o codigos_de_operacion.o comprobador_apertura_archivos.o # Archivos objeto
TARGET = p02_strings     # Nombre del ejecutable

# Regla principal: compila el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Reglas para generar los archivos objeto
alfabeto_clase.o: alfabeto_clase.cpp
	$(CC) $(CFLAGS) -c alfabeto_clase.cpp

check_correct_parameters.o: check_correct_parameters.cpp
	$(CC) $(CFLAGS) -c check_correct_parameters.cpp

operator_overloading.o: operator_overloading.cpp
	$(CC) $(CFLAGS) -c operator_overloading.cpp

p02_strings.o: p02_strings.cpp
	$(CC) $(CFLAGS) -c p02_strings.cpp

codigos_de_operacion.o: codigos_de_operacion.cpp
	$(CC) $(CFLAGS) -c codigos_de_operacion.cpp

comprobador_apertura_archivos.o: comprobador_apertura_archivos.cpp
	$(CC) $(CFLAGS) -c comprobador_apertura_archivos.cpp

# Regla clean: elimina los archivos objeto y el ejecutable
clean:
	rm -f $(OBJ)

# Indicamos que 'clean' no es un archivo
.PHONY: clean

