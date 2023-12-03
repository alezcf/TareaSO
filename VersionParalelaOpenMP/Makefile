# Definir el compilador
CXX = g++

# Definir las banderas del compilador
CXXFLAGS = -std=c++11 `pkg-config --cflags opencv4` -fopenmp

# Definir las bibliotecas para enlazar
LIBS = `pkg-config --libs opencv4`

# Definir el nombre del archivo de salida
OUTPUT = app

# Definir los archivos fuente
SRCS = OpenMP.cpp  

all: $(OUTPUT)

$(OUTPUT): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUTPUT) $(LIBS)

.PHONY: run clean

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)

