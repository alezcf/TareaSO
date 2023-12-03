CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -pedantic -O3
LIBS=`pkg-config --cflags --libs opencv4`

all: app

app: Thread.cpp
	$(CC) $(CFLAGS) Thread.cpp -o app $(LIBS) -pthread

clean:
	rm -f app

