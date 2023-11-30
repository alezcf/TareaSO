# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -std=c++11 `pkg-config --cflags opencv4`

# Definir las bibliotecas para enlazar
LIBS = `pkg-config --libs opencv4`

# Definir el nombre del archivo de salida
OUTPUT = app

# Definir los archivos fuente
SRCS = Secuencial.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUTPUT) $(LIBS)

clean:
	rm -f $(OUTPUT)
