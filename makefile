main: Main.cpp Player.cpp
	g++ -I /usr/include/SDL2 -o main -g Main.cpp Player.cpp -lSDL2 -lSDL2_image
