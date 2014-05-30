all: main

main: main.o entity.o ship.o bullet.o asteroid.o
	g++ main.o entity.o ship.o bullet.o asteroid.o -o exec -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lXcursor

main.o: main.cpp
	g++ -c main.cpp

entity.o: entity.cpp
	g++ -c entity.cpp entity.h

ship.o: ship.cpp
	g++ -c ship.cpp ship.h

bullet.o: bullet.cpp
	g++ -c bullet.cpp bullet.h

asteroid.o: asteroid.cpp
	g++ -c asteroid.cpp asteroid.h

clean:
	rm -rf *o main
