main: Main.cpp Player.cpp
	g++ -I /usr/include/SDL2 -o main Main.cpp Player.cpp -lSDL2
	./main
