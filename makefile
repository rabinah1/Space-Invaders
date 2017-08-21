main: Main.cpp Player.cpp Functions.cpp
	g++ -std=c++11 -I /usr/include/SDL2 -o main Main.cpp Player.cpp Functions.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
