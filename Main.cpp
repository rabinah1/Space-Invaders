#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <new>
#include "Player.h"
#include "Functions.h"

#define USER "Space_ship.png" // The image of the space ship of the player
#define ENEMY "Enemy.png" // The image of an enemy

int game(SDL_Event e, SDL_Window *w, SDL_Renderer *r);

int main() { // Main-function runs the menu-screen of the game
    unsigned int currentTime = 0; // Variables currentTime and lastTime are used to set the fps of the game to approximately 60
    unsigned int lastTime = 0;
    SDL_Event e; // A union that contains structures for different event types
    SDL_Window *w; // This is the application window
    SDL_Renderer *r; // This is the renderer that is used for drawing
    int quit = 0; // A variable that determines when to exit the program
    int return_value = 0; // This variable contains the return value of the game-function
    int mousex_init = 0;
    int mousey_init = 0;
    int *mousex = &mousex_init; // X-coordinate of the cursor
    int *mousey = &mousey_init; // Y-coordinate of the cursor
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL
    TTF_Init(); // Initialize TTF
    w = SDL_CreateWindow("Space Invaders", // Title of the window.
			 350, // X-coordinate of the upper left corner of the window.
			 130, // Y-coordinate of the upper left corner of the window.
			 1100, // Size of the window in x-direction.
			 800, // Size of the window in y-direction.
			 SDL_WINDOW_OPENGL // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			 );
    if (w == NULL) { // If the creation of the window was not succesfull
	printf("Could not create window: %s\n", SDL_GetError());
	return 1;
    }
    r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED); // Create a renderer
    SDL_SetRenderDrawColor(r, 0,0,0,255); // Set the drawing color of the renderer to black
  
    // Define fonts, textures etc. for the menu-window
    TTF_Font *HeadingFont = TTF_OpenFont("Ubuntu-B.ttf", 140); // Open a font
    TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 35);
    SDL_Color Green = {0,255,0}; // Define a color
    SDL_Color White = {255,255,255};
    SDL_Texture *EnemyAlien;
    SDL_Surface *surfaceHeading1 = TTF_RenderText_Solid(HeadingFont, "Space", Green); // This is a surface that contains a text "Space"
    SDL_Surface *surfaceHeading2 = TTF_RenderText_Solid(HeadingFont, "Invaders", Green);
    SDL_Surface *surfaceStart = TTF_RenderText_Solid(ButtonFont, "Start game", White);
    SDL_Surface *surfaceControls = TTF_RenderText_Solid(ButtonFont, "Controls", White);
    SDL_Surface *surfaceExit = TTF_RenderText_Solid(ButtonFont, "Exit", White);
    SDL_Texture *Heading1 = SDL_CreateTextureFromSurface(r, surfaceHeading1); // Here we create a texture from a surface. A texture will be copied on top of a rectangle
    SDL_Texture *Heading2 = SDL_CreateTextureFromSurface(r, surfaceHeading2);
    SDL_Texture *StartButton = SDL_CreateTextureFromSurface(r, surfaceStart);
    SDL_Texture *ControlsButton = SDL_CreateTextureFromSurface(r, surfaceControls);
    SDL_Texture *ExitButton = SDL_CreateTextureFromSurface(r, surfaceExit);
    SDL_Rect Heading1_Rect; // A structure that contains a definition of a rectangle
    SDL_Rect Heading2_Rect;
    SDL_Rect Start_Rect;
    SDL_Rect Controls_Rect;
    SDL_Rect Exit_Rect;
    // These exampleenemies are the enemies show in the menu-screen
    SDL_Rect ExampleEnemy1;
    SDL_Rect ExampleEnemy2;
    SDL_Rect ExampleEnemy3;
    SDL_Rect ExampleEnemy4;
    SDL_Rect ExampleEnemy5;
    SDL_Rect ExampleEnemy6;
    int w_enemy = 0; // The width of the image of an enemy
    int h_enemy = 0; // The height of the image of an enemy
    EnemyAlien = IMG_LoadTexture(r, ENEMY); // Load the image of an enemy
    SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy); // Get the width and height of the image of an enemy and save them to variables w_enemy and h_enemy

    // Determine sizes and initial positions of rectangles that contain some textures
    ExampleEnemy1.x = 120; // The x-coordinate of a rectangle
    ExampleEnemy1.y = 580; // The y-coordinate of a rectangle
    ExampleEnemy1.w = w_enemy; // The width of a rectangle
    ExampleEnemy1.h = h_enemy; // The height of a rectangle
    ExampleEnemy2.x = 180;
    ExampleEnemy2.y = 400;
    ExampleEnemy2.w = w_enemy;
    ExampleEnemy2.h = h_enemy;
    ExampleEnemy3.x = 90;
    ExampleEnemy3.y = 170;
    ExampleEnemy3.w = w_enemy;
    ExampleEnemy3.h = h_enemy;
    ExampleEnemy4.x = 800;
    ExampleEnemy4.y = 100;
    ExampleEnemy4.w = w_enemy;
    ExampleEnemy4.h = h_enemy;
    ExampleEnemy5.x = 980;
    ExampleEnemy5.y = 350;
    ExampleEnemy5.w = w_enemy;
    ExampleEnemy5.h = h_enemy;
    ExampleEnemy6.x = 890;
    ExampleEnemy6.y = 700;
    ExampleEnemy6.w = w_enemy;
    ExampleEnemy6.h = h_enemy;
    Heading1_Rect.x = 380;
    Heading1_Rect.y = 80;
    Heading1_Rect.w = 300;
    Heading1_Rect.h = 170;
    Heading2_Rect.x = 340;
    Heading2_Rect.y = 230;
    Heading2_Rect.w = 400;
    Heading2_Rect.h = 170;
    Start_Rect.x = 420;
    Start_Rect.y = 410;
    Start_Rect.w = 200;
    Start_Rect.h = 70;
    Controls_Rect.x = 420;
    Controls_Rect.y = 520;
    Controls_Rect.w = 200;
    Controls_Rect.h = 70;
    Exit_Rect.x = 465;
    Exit_Rect.y = 630;
    Exit_Rect.w = 100;
    Exit_Rect.h = 70;
  
    SDL_RenderClear(r); // Clear the window
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy1); // Copy a created texture into a rectangle. Here we copy a texture EnemyAlien on top of a rectangle ExampleEnemy1
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy2);
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy3);
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy4);
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy5);
    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy6);
    SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
    SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
    SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
    SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
    SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
    SDL_RenderPresent(r); // update the screen with any rendering performed since the previous call

    // Start the loop that maintains the menu-window
    while (quit == 0)
	{
	    currentTime = SDL_GetTicks(); // SDL_GetTicks() returns the time elapsed since the initialization of SDL-library in milliseconds
	    if (currentTime - lastTime < 17) // 17 milliseconds results in approximately 60 fps
		continue;
	    else
		lastTime = currentTime;

	    SDL_GetMouseState(mousex, mousey); // Get the x- ja y-coordinates of the mouse and save them to variables mousex and mousey
	    if (SDL_PollEvent(&e)) // Poll for pending events
		{
		    switch(e.type)
			{
			case SDL_QUIT: // If the user clicks on the x-button in the top left corner
			    quit = 1;

			case SDL_MOUSEBUTTONDOWN: // The user clicks the mouse button
			    if (*mousex >= 420 && *mousex <= 620 && *mousey >= 410 && *mousey <= 480) { // The user clicks on the "Start game"-button in the menu-screen
				return_value = game(e, w, r); // Call the game-function to start the game
				if (return_value != 1) // The return_value is not 1, if the player wants to exit the game, not just return back to menu-window
				    quit = 1;
				else // The return_value is 1, if the player wants to return to menu-window but not exit the game
				    {
					// Redraw everything in the menu-screen
					SDL_RenderClear(r);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy1);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy2);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy3);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy4);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy5);
					SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy6);
					SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
					SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
					SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
					SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
					SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
					SDL_RenderPresent(r);
				    }
			    }
	   
			    else if (*mousex >= 465 && *mousex <= 565 && *mousey >= 630 && *mousey <= 700) // The user clicks on the "Exit"-button in the menu-screen
				quit = 1;

			    else if (*mousex >= 420 && *mousex <= 620 && *mousey >= 520 && *mousey <= 590) // The user clicks on the "Controls"-button in the menu-screen
				{
				    GuideWindow(e, w, r); // Go to a function that opens a window that contains instructions for the game
				    // When we return from that function, redraw everything in the menu-screen
				    SDL_RenderClear(r);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy1);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy2);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy3);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy4);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy5);
				    SDL_RenderCopy(r, EnemyAlien, NULL, &ExampleEnemy6);
				    SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
				    SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
				    SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
				    SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
				    SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
				    SDL_RenderPresent(r);
				}
	   
			}
		}
	}

    SDL_DestroyTexture(Heading1);
    SDL_DestroyTexture(Heading2);
    SDL_DestroyTexture(StartButton);
    SDL_DestroyTexture(ControlsButton);
    SDL_DestroyTexture(ExitButton);
    SDL_FreeSurface(surfaceHeading1);
    SDL_FreeSurface(surfaceHeading2);
    SDL_FreeSurface(surfaceStart);
    SDL_FreeSurface(surfaceControls);
    SDL_FreeSurface(surfaceExit);
    TTF_CloseFont(HeadingFont);
    TTF_CloseFont(ButtonFont);
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(w);
    TTF_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
    return 0;
}

int game(SDL_Event event, SDL_Window *window, SDL_Renderer *renderer) {
  
    // Define variables and lists that are used in the program
    int RoundsPassed = 0; // RoundsPassed is a counter that keeps count on how many rounds the player has passed. One round is passed when all 50 enemies are destroyed and new 50 enemies are created
    int dist_left = 2000; // dist_left is the distance between the leftmost enemy and the left edge of the screen
    int dist_right = 2000; // dist_right is the distance between the rightmost enemy and the right edge of the screen
    int currentSize = 0; // currentSize is a variable used to temporariy store the amount of enemies alive
    int currentSize2 = 0; // currentSize2 is a variable used to temporarily store the amount of bullets shot by enemies that are in the game field
    int ret = 0; // ret is a value that is returned by a function "GameOverWindow" (can be found in the file "Functions.cpp")
    float expDelay = 1.5; // This is "expected delay" between two bullets shot by enemies
    float epsilon = -0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(0.7-(-0.7)))); // Select a random number between -0.7 and 0.7
    float time_to_wait = expDelay + epsilon; // time_to_wait is the time difference between two bullets shot by enemies
    int randomIndex = 0; // randomIndex is a random integer in the range [0, number_of_enemies_alive - 1]. This number is used to decide which enemy shoots the next bullet
    unsigned int currentBulletTime = SDL_GetTicks(); // currentBulletTime is the time at which the most recent enemybullet was shot
    unsigned int currentTime = 0; // currentTime and lastTime are used to lock the fps to about 60
    unsigned int lastTime = 0;
    unsigned int currentEnemyTime = 0; // currentEnemyTime and lastEnemyTime are variable used to determine how quickly the enemis move
    unsigned int lastEnemyTime = 0;
    int mousex_init = 0;
    int mousey_init = 0;
    int *mousex = &mousex_init; // mousex contains the x-coordinate of the cursor
    int *mousey = &mousey_init; // mousey contains the y-coordinate of the cursor
    int speed = 12; // This is the speed of the player
    int EnemyAmount = 0; // EnemyAmount controls how quickly the enemies move
    int w_player = 0; // The width of the image of the player's spaceship
    int h_player = 0; // The height of the image of the player's spaceship
    int w_enemy = 0; // The width of the image of an enemy
    int h_enemy = 0; // The height of the image of an enemy
    int init_height = 0;
    int init_width = 0;
    int *WindowHeight = &init_height; // The height of the window
    int *WindowWidth = &init_width; // The width of the window
    int quit = 0; // This variable is used to determine when to exit the main loop
    int dir = 1; // This variable defines the direction to which the enemies move. Enemies can move to left or right
    int PauseFlag = 0; // PauseFlag determines when to exit the loop in which we enter when the player pauses the game
    int CheckIfDestroyed = 1; // This variable checks whether there is a bullet shot by the player in the field or not
    int BulletsExist = 0; // This variable checks whether there are bullets shot by the enemies in the field
    std::vector <SDL_Rect*> EnemyList; // A vector that contains pointers to enemies.
    std::vector <SDL_Rect*> BulletList; // A vector that contains pointers to bullets shot by the enemies

    // Define textures, fonts, rectangles etc. 
    srand (static_cast <unsigned> (time(0))); // Seed the rand()-function
    EnemyList = InitEnemyList(); // Create enemies and add them to a vector. This function can be found in the file "Functions.cpp"
    Player player_1; // Create an object "player_1" of class "Player". The definition of the Player-class can be found in the file "Player.h"
    player_1.Set_lives(3); // Set the lives of the player to be 3
    player_1.Set_score(0); // Set the score of the player to be 0
    std::stringstream score; // The score of the player that will be drawn to the game screen
    std::stringstream lives; // The amount of lives of the player that will be draw to the game screen
    score << player_1.Give_score();
    lives << player_1.Give_lives();
    TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 65); // Open a font
    SDL_Color White = {255,255,255}; // Define a color
    SDL_Surface *surfaceButton1 = TTF_RenderText_Solid(ButtonFont, "Return to menu", White); // Create a surface
    SDL_Surface *surfaceButton2 = TTF_RenderText_Solid(ButtonFont, "Exit", White);
    SDL_Texture *PlayerShip; // A structure that contains representation of pixel data, in this case the image of the player's spaceship
    SDL_Texture *EnemyAlien; // A structure that contas the image of an enemy
    SDL_Rect ShipRect; // A structure that defines a rectangle
    SDL_Rect *PlayerBullet;
    SDL_Rect *EnemyBullet;
    SDL_Surface *surfaceScore = TTF_RenderText_Solid(ButtonFont, score.str().c_str(), White);
    SDL_Surface *surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
    SDL_Surface *scoreTextSurface = TTF_RenderText_Solid(ButtonFont, "Score:", White);
    SDL_Surface *livesTextSurface = TTF_RenderText_Solid(ButtonFont, "Lives:", White);
    PlayerShip = IMG_LoadTexture(renderer, USER); // Load the image of the spaceship of the player
    EnemyAlien = IMG_LoadTexture(renderer, ENEMY);
    SDL_QueryTexture(PlayerShip, NULL, NULL, &w_player, &h_player); // Get the width and height of the player's spaceship and save the to variables w_player and h_player
    SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy);
    SDL_SetRenderDrawColor(renderer, 0,0,0,255); // Set the drawing color of the renderer to black
    SDL_Texture *Button1 = SDL_CreateTextureFromSurface(renderer, surfaceButton1); // Create a texture
    SDL_Texture *Button2 = SDL_CreateTextureFromSurface(renderer, surfaceButton2);
    SDL_Texture *Score = SDL_CreateTextureFromSurface(renderer, surfaceScore);
    SDL_Texture *Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives);
    SDL_Texture *ScoreText = SDL_CreateTextureFromSurface(renderer, scoreTextSurface);
    SDL_Texture *LivesText = SDL_CreateTextureFromSurface(renderer, livesTextSurface);
    SDL_Rect Button1Rect; // Define a rectangle
    SDL_Rect Button2Rect;
    SDL_Rect scoreRect;
    SDL_Rect livesRect;
    SDL_Rect scoreTextRect;
    SDL_Rect livesTextRect;

    // Determine sizes and initial positions of rectangles
    Button1Rect.x = 10; // The x-coordinate of the rectangle's upper left corner
    Button1Rect.y = 5; // The y-coordinate of the rectangle's upper left corner
    Button1Rect.w = 330; // The width of the rectangle
    Button1Rect.h = 100; // The height of the rectangle
    Button2Rect.x = 950;
    Button2Rect.y = 5;
    Button2Rect.w = 120;
    Button2Rect.h = 100;
    scoreRect.x = 1000;
    scoreRect.y = 15;
    scoreRect.w = 60;
    scoreRect.h = 50;
    livesRect.x = 1000;
    livesRect.y = 70;
    livesRect.w = 50;
    livesRect.h = 50;
    scoreTextRect.x = 900;
    scoreTextRect.y = 15;
    scoreTextRect.w = 90;
    scoreTextRect.h = 50;
    livesTextRect.x = 900;
    livesTextRect.y = 70;
    livesTextRect.w = 90;
    livesTextRect.h = 50;
    ShipRect.x = 10;
    ShipRect.y = 655;
    ShipRect.w = w_player;
    ShipRect.h = h_player;
    SDL_RenderClear(renderer);
  
    for (int j = 0; j < EnemyList.size(); ++j) // Set the initial positions and sizes of the enemies. Also copy the image of an enemy on top of the rectangle that represent an enemy
	{
	    EnemyList[j]->x = 10 + j*45 - j/10*10*45;
	    EnemyList[j]->y = 320 - h_enemy*(j/10) - j/10*5;
	    EnemyList[j]->w = w_enemy;
	    EnemyList[j]->h = h_enemy;
	    SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
	}
    SDL_RenderPresent(renderer); // This function is used to update the screen with any rendering performance since the previous call
  
    while (quit == 0) { // Start the main loop of the game
	if (EnemyList.size() > 40 && EnemyList.size() <= 50)
	    EnemyAmount = 0; // EnemyAmount is a variable that controls, how quickly the enemies move
	else if (EnemyList.size() > 30 && EnemyList.size() <= 40)
	    EnemyAmount = 1;
	else if (EnemyList.size() > 20 && EnemyList.size() <= 30)
	    EnemyAmount = 2;
	else if (EnemyList.size() > 10 && EnemyList.size() <= 20)
	    EnemyAmount = 3;
	else if (EnemyList.size() > 0 && EnemyList.size() <= 10)
	    EnemyAmount = 4;
	if (EnemyList.size() == 0) // If all the enemies are destroyed
	    {
		if (RoundsPassed < 8) // One round is passed when all 50 enemies are destroyed and new 50 enemies are created
		    {
			RoundsPassed = RoundsPassed + 1;
			player_1.Increase_lives(); // Increase the lives of the player by 1
			lives.str("");
			lives << player_1.Give_lives();
			SDL_FreeSurface(surfaceLives);
			surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
			Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives); // Draw the current amount of lives of the player to the game screen
		    }
		EnemyList = InitEnemyList(); // Create 50 new enemies. The function InitEnemyList() can be found in the file "Functions.cpp"
		EnemyAmount = 0;
		for (int j = 0; j < EnemyList.size(); ++j) // Set the initial positions and sizes of the enemies. Also copy the image of an enemy on top of the rectangle that represent an enemy
		    {
			EnemyList[j]->x = 10 + j*45 - j/10*10*45;
			EnemyList[j]->y = 320 + RoundsPassed*30 - h_enemy*(j/10) - j/10*5;
			EnemyList[j]->w = w_enemy;
			EnemyList[j]->h = h_enemy;
			SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
		    }
		dir = 1;
	    }
	currentTime = SDL_GetTicks();
	currentEnemyTime = SDL_GetTicks();
	if (currentTime - lastTime < 17) // Ensure that the fps is 60
	    continue;
	else
	    lastTime = currentTime;
    
	if (SDL_GetTicks() - currentBulletTime > time_to_wait*1000 && EnemyList.size() != 0) // If enough time has passed since the previous enemy shot a bullet, next enemy may shoot a bullet. Time_to_wait is the time (in seconds) that the enemies must wait between shots
	    {
		currentBulletTime = SDL_GetTicks();
		randomIndex =  0 + (rand() % static_cast<int>(EnemyList.size()-1 - 0 + 1)); // We choose ranodmly the next enemy to shoot a bullet. This random number is used as an index to the vector that contains all enemies that are alive
		EnemyBullet = new SDL_Rect; // Create a new bullet
		// Determine the initial position and size of the bullet
		EnemyBullet->w = 5;
		EnemyBullet->h = 5;
		EnemyBullet->x = EnemyList[randomIndex]->x + 15;
		EnemyBullet->y = EnemyList[randomIndex]->y + 30;
		BulletList.push_back(EnemyBullet); // Add the created bullet to a vector BulletList
		epsilon = -0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(0.7-(-0.7))));
		time_to_wait = expDelay + epsilon; // Determine the time that must be elapsed until next enemy may shoot a bullet
	    }
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Score, NULL, &scoreRect);
	SDL_RenderCopy(renderer, Lives, NULL, &livesRect);
	SDL_RenderCopy(renderer, ScoreText, NULL, &scoreTextRect);
	SDL_RenderCopy(renderer, LivesText, NULL, &livesTextRect);
    
	for (int i = 0; i < EnemyList.size(); ++i) // Loop through all enemies
	    {
		if (SDL_HasIntersection(EnemyList[i], &ShipRect) == SDL_TRUE) // If an enemy collides with the player
		    {
			ret = GameOverWindow(event, window, renderer, player_1); // Move to a function that opens a window that tells the player that the game has ended
			if (ret == 1) // Player pressed exit-button in the window previously opened
			    {
				quit = 1;
				currentSize = EnemyList.size(); // currentSize contains the amount of enemies that were alive when the game ended
				currentSize2 = BulletList.size(); // currentSize2 contains the amount of bullets shot by enemies that were in the game field when the game ended
				for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
				    {
					delete EnemyList[0];
					EnemyList.erase(EnemyList.begin());
				    }
				if (CheckIfDestroyed == 0) // If there existed a bullet shot by the player when the game ended
				    delete PlayerBullet;
				if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
				    {
					for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets and free the memory allocated for them
					    {
						delete BulletList[0];
						BulletList.erase(BulletList.begin());
					    }
				    }
				//break;
				TTF_CloseFont(ButtonFont);
				SDL_DestroyTexture(Button1);
				SDL_DestroyTexture(Button2);
				SDL_DestroyTexture(Score);
				SDL_DestroyTexture(Lives);
				SDL_DestroyTexture(ScoreText);
				SDL_DestroyTexture(LivesText);
				SDL_DestroyTexture(PlayerShip);
				SDL_DestroyTexture(EnemyAlien);
				SDL_FreeSurface(surfaceButton1);
				SDL_FreeSurface(surfaceButton2);
				SDL_FreeSurface(surfaceScore);
				SDL_FreeSurface(surfaceLives);
				SDL_FreeSurface(scoreTextSurface);
				SDL_FreeSurface(livesTextSurface);
				return 1;
			    }
			else // Player pressed menu-button in the window previously opened
			    {
				currentSize = EnemyList.size();
				currentSize2 = BulletList.size();
				for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
				    {
					delete EnemyList[0];
					EnemyList.erase(EnemyList.begin());
				    }
				if (CheckIfDestroyed == 0)
				    delete PlayerBullet;
				if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
				    {
					for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
					    {
						delete BulletList[0];
						BulletList.erase(BulletList.begin());
					    }
				    }
				TTF_CloseFont(ButtonFont);
				SDL_DestroyTexture(Button1);
				SDL_DestroyTexture(Button2);
				SDL_DestroyTexture(Score);
				SDL_DestroyTexture(Lives);
				SDL_DestroyTexture(ScoreText);
				SDL_DestroyTexture(LivesText);
				SDL_DestroyTexture(PlayerShip);
				SDL_DestroyTexture(EnemyAlien);
				SDL_FreeSurface(surfaceButton1);
				SDL_FreeSurface(surfaceButton2);
				SDL_FreeSurface(surfaceScore);
				SDL_FreeSurface(surfaceLives);
				SDL_FreeSurface(scoreTextSurface);
				SDL_FreeSurface(livesTextSurface);
				return 1;
			    }
		    }
	    }
    
	for (int k = 0; k < BulletList.size(); ++k) // Loop through all bullets shot by enemies
	    {
		SDL_SetRenderDrawColor(renderer, 255,255,255,255); // Set the render drawing color to white
		SDL_RenderFillRect(renderer, BulletList[k]); // Paint the bullet white
		BulletList[k]->y = BulletList[k]->y + 7; // Update the position of a bullet
		if (BulletList[k]->y > 820) // If the bullet has moved outside the window
		    {
			// Free the memory allocated for the bullet and remove it from the vector containing the bullets
			delete BulletList[k];
			BulletList.erase(BulletList.begin() + k);
		    }
		else if (SDL_HasIntersection(BulletList[k], &ShipRect) == SDL_TRUE) // If a bullet collides with the player
		    {
			delete BulletList[k]; // Free the memory allocated for the bullet
			BulletList.erase(BulletList.begin() + k); // Remove the bullet from the vector BulletList
			SDL_SetRenderDrawColor(renderer, 0,0,0,255);
			player_1.Reduce_lives(); // Reduce the lives of a player by one
			lives.str("");
			lives << player_1.Give_lives();
			SDL_FreeSurface(surfaceLives);
			surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
			Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives); // Create an image of the amount of lives of the player that will be drawn to the game screen
			if (player_1.Give_lives() < 0) // If the amount of lives of the player is less than 0
			    {
				ret = GameOverWindow(event, window, renderer, player_1); // Move to a function that opens a window that tells the player that the game has ended
				if (ret == 1) // Exit was pressed in the window previously opened
				    {
					quit = 1;
					currentSize = EnemyList.size();
					currentSize2 = BulletList.size();
					for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
					    {
						delete EnemyList[0];
						EnemyList.erase(EnemyList.begin());
					    }
					if (CheckIfDestroyed == 0)
					    {
						delete PlayerBullet;
						CheckIfDestroyed = 1;
					    }
					if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
					    {
						for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
						    {
							delete BulletList[0];
							BulletList.erase(BulletList.begin());
						    }
					    }
					break;
				    }
		
				else // Menu was pressed in the window previously opened
				    {
					currentSize = EnemyList.size();
					currentSize2 = BulletList.size();
					for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
					    {
						delete EnemyList[0];
						EnemyList.erase(EnemyList.begin());
					    }
					if (CheckIfDestroyed == 0)
					    delete PlayerBullet;
					if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
					    {
						for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
						    {
							delete BulletList[0];
							BulletList.erase(BulletList.begin());
						    }
					    }
					TTF_CloseFont(ButtonFont);
					SDL_DestroyTexture(Button1);
					SDL_DestroyTexture(Button2);
					SDL_DestroyTexture(Score);
					SDL_DestroyTexture(Lives);
					SDL_DestroyTexture(ScoreText);
					SDL_DestroyTexture(LivesText);
					SDL_DestroyTexture(PlayerShip);
					SDL_DestroyTexture(EnemyAlien);
					SDL_FreeSurface(surfaceButton1);
					SDL_FreeSurface(surfaceButton2);
					SDL_FreeSurface(surfaceScore);
					SDL_FreeSurface(surfaceLives);
					SDL_FreeSurface(scoreTextSurface);
					SDL_FreeSurface(livesTextSurface);
					return 1;
				    }
			    }
		    }
	    }
    
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	if (BulletList.size() != 0) // If there exists bullets shot by enemies in the game field
	    BulletsExist = 1;
	else
	    BulletsExist = 0;
	SDL_GetWindowSize(window, WindowWidth, WindowHeight); // Get the height and width of the window and save them to variables WindowWidth and WindowHeight
	ShipRect.y = *WindowHeight - 45; // Set the y-coordinate of the top left corner of the image of the player's spaceship
	if (currentEnemyTime - lastEnemyTime >= (1000 - EnemyAmount*150) && EnemyList.size() != 0) // If enough time has elapsed since the last time the enemies moved
	    {
		lastEnemyTime = currentEnemyTime;
		dist_right = 2000;
		dist_left = 2000;
		for (int j = 0; j < EnemyList.size(); ++j) // Loop through all the enemies
		    {
			// Determine dist_right
			if (*WindowWidth - (EnemyList[j]->x + w_enemy) <= dist_right)
			    dist_right = *WindowWidth - (EnemyList[j]->x + w_enemy);
			// Determine dist_left
			if (EnemyList[j]->x <= dist_left)
			    dist_left = EnemyList[j]->x;
		    }
		if (dist_right <= 0) // If the position of the rightmost enemy exceeds the screen width
		    {
			dir = 0;
			for (int j = 0; j < EnemyList.size(); ++j) // Move all enemies lower on the screen
			    EnemyList[j]->y = EnemyList[j]->y + 30;
		    }
		else if (dist_left <= 0) // If the position of the leftmost enemy is less than 0
		    {
			dir = 1;
			for (int j = 0; j < EnemyList.size(); ++j) // Move all enemies lower on the screen
			    EnemyList[j]->y = EnemyList[j]->y + 30;
		    }
		for(int i = 0; i < EnemyList.size(); ++i) // Loop through all enemies
		    {
			if (dir == 0)
			    (EnemyList[i])->x = (EnemyList[i])->x - 30; // Move an enemy to the left
			else
			    (EnemyList[i])->x = (EnemyList[i])->x + 30; // Move an enemy to the right
		    }
	    }
    
	SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
	for (int j = 0; j < EnemyList.size(); ++j) // Loop through all the enemies
	    SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]); // Copy the image of an enemy on top the rectangle that represents the enemy
	if (CheckIfDestroyed == 0) // If there exists a bullet shot by the player in the game field
	    {
		for(int j = 0; j < EnemyList.size(); ++j) // Loop through all enemies
		    {
			if (SDL_HasIntersection(EnemyList[j], PlayerBullet) == SDL_TRUE) // If the bullet shot by the player collides with an enemy
			    {
				delete EnemyList[j]; // Free the memroy allocated for the enemy
				delete PlayerBullet; // Free the memory allocated for the bullet
				EnemyList.erase(EnemyList.begin()+j); // Remove the enemy from the vector that contains the enemies
				CheckIfDestroyed = 1;
				player_1.Increase_score(); // Increase the score of the player by 50
				score.str("");
				score << player_1.Give_score();
				SDL_FreeSurface(surfaceScore);
				surfaceScore = TTF_RenderText_Solid(ButtonFont, score.str().c_str(), White);
				Score = SDL_CreateTextureFromSurface(renderer, surfaceScore); // Create the image of the score of the player that will be draw on the game screen
				break;
			    }
		    }
		if (CheckIfDestroyed == 0) // If there exists a bullet shot by the player in the game field
		    {
			SDL_SetRenderDrawColor(renderer, 255,255,255,255);
			SDL_RenderFillRect(renderer, PlayerBullet); // Paint the bullet white
			PlayerBullet->y = PlayerBullet->y - 11; // Move the bullet upper on the screen
			SDL_SetRenderDrawColor(renderer, 0,0,0,255);
			if (PlayerBullet->y < 0) // If the bullet has moved outside the window
			    {
				CheckIfDestroyed = 1;
				delete PlayerBullet;
			    }
		    }
	    }
    
	SDL_RenderPresent(renderer);
	currentSize = EnemyList.size();
	currentSize2 = BulletList.size();
	if (SDL_PollEvent(&event)) // Poll for pending events
	    {
		switch(event.type)
		    {
		    case SDL_QUIT: // If the user clicks on the x-button in the top left corner
			quit = 1;
			for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
			    {
				delete EnemyList[0];
				EnemyList.erase(EnemyList.begin());
			    }
			if (CheckIfDestroyed == 0)
			    delete PlayerBullet; // Free the memory allocated for a bullet shot by the player if a exists in the game field
			if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
			    {
				for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
				    {
					delete BulletList[0];
					BulletList.erase(BulletList.begin());
				    }
			    }
			break;
	   
		    case SDL_KEYDOWN: // If some keyboard key is pressed down
			if (event.key.keysym.sym == SDLK_RIGHT) // If the pressed key is the right arrow
			    ShipRect.x = ShipRect.x + speed; // Move the spaceship to the right
	   
			else if (event.key.keysym.sym == SDLK_LEFT) // If the pressed key is the left arrow
			    ShipRect.x = ShipRect.x - speed; // Move the spaceship to the left
	   
			else if (event.key.keysym.sym == SDLK_SPACE && CheckIfDestroyed == 1) { // If the pressed key is the space button and there does not exist a bullet shot by the player in the field
			    PlayerBullet = new SDL_Rect; // Allocate memory for new bullet
			    CheckIfDestroyed = 0;
			    // Determine the initial location and size of the bullet
			    PlayerBullet->x = ShipRect.x + 32;
			    PlayerBullet->y = ShipRect.y;
			    PlayerBullet->w = 5;
			    PlayerBullet->h = 5;
			}
	   
			else if (event.key.keysym.sym == SDLK_ESCAPE) { // If the pressed key is esc
			    while (1) // Pause the game
				{
				    SDL_GetMouseState(mousex, mousey);
				    SDL_RenderClear(renderer);
				    // Create some new buttons on the screen
				    SDL_RenderCopy(renderer, Button1, NULL, &Button1Rect);
				    SDL_RenderCopy(renderer, Button2, NULL, &Button2Rect);
				    SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
				    for (int j = 0; j < EnemyList.size(); ++j) // Loop through all the enemies
					SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]); // Copy the image of an enemy on top of the rectangle representing the enemy
				    if (CheckIfDestroyed == 0) // If there exists a bullet shot by the player in the game field
					{
					    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
					    SDL_RenderFillRect(renderer, PlayerBullet); // Paint the bullet white.
					    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
					}
				    if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
					{
					    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
					    for (int k = 0; k < BulletList.size(); ++k) // Loop through all the bullets
						SDL_RenderFillRect(renderer, BulletList[k]); // Paint bullets white
					    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
					}
				    SDL_RenderPresent(renderer);
				    if (SDL_PollEvent(&event)) // Loop through events
					{
					    switch(event.type)
						{
						case SDL_QUIT:
						    quit = 1;
						    PauseFlag = 1; // PauseFlag controls, when to exit this loop and continue the game
						    currentSize = EnemyList.size();
						    currentSize2 = BulletList.size();
						    for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
							{
							    delete EnemyList[0];
							    EnemyList.erase(EnemyList.begin());
							}
						    if (CheckIfDestroyed == 0)
							delete PlayerBullet; // Free the memory allocated for a bullet shot by the player
						    if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
							{
							    for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
								{
								    delete BulletList[0];
								    BulletList.erase(BulletList.begin());
								}
							}
						    break;
			 
						case SDL_KEYDOWN:
						    if (event.key.keysym.sym == SDLK_ESCAPE) // If esc is pressed
							{
							    PauseFlag = 1;
							    break;
							}

						case SDL_MOUSEBUTTONDOWN:
						    if (*mousex >= 10 && *mousex <= 340 && *mousey >= 5 && *mousey <= 105) // If the player clicks on the menu-button shown on the screen
							{
							    currentSize = EnemyList.size();
							    currentSize2 = BulletList.size();
							    for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
								{
								    delete EnemyList[0];
								    EnemyList.erase(EnemyList.begin());
								}
							    if (CheckIfDestroyed == 0)
								delete PlayerBullet; // Free the memory allocated for the bullet shot by the player
							    if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
								{
								    for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
									{
									    delete BulletList[0];
									    BulletList.erase(BulletList.begin());
									}
								}
							    TTF_CloseFont(ButtonFont);
							    SDL_DestroyTexture(Button1);
							    SDL_DestroyTexture(Button2);
							    SDL_DestroyTexture(Score);
							    SDL_DestroyTexture(Lives);
							    SDL_DestroyTexture(ScoreText);
							    SDL_DestroyTexture(LivesText);
							    SDL_DestroyTexture(PlayerShip);
							    SDL_DestroyTexture(EnemyAlien);
							    SDL_FreeSurface(surfaceButton1);
							    SDL_FreeSurface(surfaceButton2);
							    SDL_FreeSurface(surfaceScore);
							    SDL_FreeSurface(surfaceLives);
							    SDL_FreeSurface(scoreTextSurface);
							    SDL_FreeSurface(livesTextSurface);
							    return 1; // When the return value is 1, the main()-function knows not to stop the execution of the program
							}
						    else if (*mousex >= 950 && *mousex <= 1070 && *mousey >= 5 && *mousey <= 105) // If the player clicks on the exit-button shown on the screen
							{
							    currentSize = EnemyList.size();
							    currentSize2 = BulletList.size();
							    for (int j = 0; j < currentSize; ++j) // Free the memory allocated for each enemy
								{
								    delete EnemyList[0];
								    EnemyList.erase(EnemyList.begin());
								}
							    if (CheckIfDestroyed == 0)
								delete PlayerBullet;
							    if (BulletsExist == 1) // If there exists bullets shot by the enemies in the game field
								{
								    for (int k = 0; k < currentSize2; ++k) // Loop through all the bullets
									{
									    delete BulletList[0];
									    BulletList.erase(BulletList.begin());
									}
								}
							    TTF_CloseFont(ButtonFont);
							    SDL_DestroyTexture(Button1);
							    SDL_DestroyTexture(Button2);
							    SDL_DestroyTexture(Score);
							    SDL_DestroyTexture(Lives);
							    SDL_DestroyTexture(ScoreText);
							    SDL_DestroyTexture(LivesText);
							    SDL_DestroyTexture(PlayerShip);
							    SDL_DestroyTexture(EnemyAlien);
							    SDL_FreeSurface(surfaceButton1);
							    SDL_FreeSurface(surfaceButton2);
							    SDL_FreeSurface(surfaceScore);
							    SDL_FreeSurface(surfaceLives);
							    SDL_FreeSurface(scoreTextSurface);
							    SDL_FreeSurface(livesTextSurface);
							    return 0;
							}
						}
					    if (PauseFlag == 1) // If the player wants to unpause the game
						{
						    PauseFlag = 0;
						    break;
						}
					}
				}
			}
		    }
	    }
    }
    TTF_CloseFont(ButtonFont);
    SDL_DestroyTexture(Button1);
    SDL_DestroyTexture(Button2);
    SDL_DestroyTexture(Score);
    SDL_DestroyTexture(Lives);
    SDL_DestroyTexture(ScoreText);
    SDL_DestroyTexture(LivesText);
    SDL_DestroyTexture(PlayerShip);
    SDL_DestroyTexture(EnemyAlien);
    SDL_FreeSurface(surfaceButton1);
    SDL_FreeSurface(surfaceButton2);
    SDL_FreeSurface(surfaceScore);
    SDL_FreeSurface(surfaceLives);
    SDL_FreeSurface(scoreTextSurface);
    SDL_FreeSurface(livesTextSurface);
    return 0;
}
