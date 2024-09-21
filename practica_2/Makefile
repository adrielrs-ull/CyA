# Variables
CC = g++                 # Compilador
CFLAGS = -Wall -g        # Opciones de compilación (muestra advertencias, habilita debug)
OBJ = clase_alfabeto.o check_correct_parameters.o operator_overloading.o p02_strings.o codigos_de_operacion.o comprobador_apertura_archivos.o clase_cadena.o clase_lenguaje.o # Archivos objeto
TARGET = p02_strings     # Nombre del ejecutable

# Regla principal: compila el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clase_lenguaje.o: clase_lenguaje.cpp
	$(CC) $(CFLAGS) -c clase_lenguaje.cpp

clase_cadena.o: clase_cadena.cpp
	$(CC) $(CFLAGS) -c clase_cadena.cpp
# Reglas para generar los archivos objeto
clase_alfabeto.o: clase_alfabeto.cpp
	$(CC) $(CFLAGS) -c clase_alfabeto.cpp

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

