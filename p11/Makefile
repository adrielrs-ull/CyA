# Nombre del ejecutable
EXECUTABLE = emst

# Archivos fuente
SOURCES = emst.cc point_set.cc sub_tree.cc point_types.cc

# Opciones de compilación
CXXFLAGS = -std=c++11

# Objetos compilados
OBJECTS = $(SOURCES:.cpp=.o)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para compilar los archivos objeto
%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f *.o

# Regla por defecto (compila el ejecutable)
all: $(EXECUTABLE)