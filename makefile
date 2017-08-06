main: Main.cpp Player.cpp Functions.cpp
	g++ -I /usr/include/SDL2 -o main -g Main.cpp Player.cpp Functions.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
