#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <new>
#include "Player.h"
#include "Functions.h"

#define USER "Space_ship.png"
#define ENEMY "Enemy.png"

int game(SDL_Event e, SDL_Window *w, SDL_Renderer *r);

int main() {
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    SDL_Event e;
    SDL_Window *w;
    SDL_Renderer *r;
    int quit = 0;
    int return_value = 0;
    int mousex_init = 0;
    int mousey_init = 0;
    int *mousex = &mousex_init;
    int *mousey = &mousey_init;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    w = SDL_CreateWindow("Space Invaders",
                         350,
                         130,
                         1100,
                         800,
                         SDL_WINDOW_OPENGL
                         );
    if (w == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(r, 0,0,0,255);
  
    TTF_Font *HeadingFont = TTF_OpenFont("Ubuntu-B.ttf", 140);
    TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 35);
    SDL_Color Green = {0,255,0};
    SDL_Color White = {255,255,255};
    SDL_Texture *EnemyAlien;
    SDL_Surface *surfaceHeading1 = TTF_RenderText_Solid(HeadingFont, "Space", Green);
    SDL_Surface *surfaceHeading2 = TTF_RenderText_Solid(HeadingFont, "Invaders", Green);
    SDL_Surface *surfaceStart = TTF_RenderText_Solid(ButtonFont, "Start game", White);
    SDL_Surface *surfaceControls = TTF_RenderText_Solid(ButtonFont, "Controls", White);
    SDL_Surface *surfaceExit = TTF_RenderText_Solid(ButtonFont, "Exit", White);
    SDL_Texture *Heading1 = SDL_CreateTextureFromSurface(r, surfaceHeading1);
    SDL_Texture *Heading2 = SDL_CreateTextureFromSurface(r, surfaceHeading2);
    SDL_Texture *StartButton = SDL_CreateTextureFromSurface(r, surfaceStart);
    SDL_Texture *ControlsButton = SDL_CreateTextureFromSurface(r, surfaceControls);
    SDL_Texture *ExitButton = SDL_CreateTextureFromSurface(r, surfaceExit);
    SDL_Rect Heading1_Rect;
    SDL_Rect Heading2_Rect;
    SDL_Rect Start_Rect;
    SDL_Rect Controls_Rect;
    SDL_Rect Exit_Rect;
    SDL_Rect ExampleEnemy1;
    SDL_Rect ExampleEnemy2;
    SDL_Rect ExampleEnemy3;
    SDL_Rect ExampleEnemy4;
    SDL_Rect ExampleEnemy5;
    SDL_Rect ExampleEnemy6;
    int w_enemy = 0;
    int h_enemy = 0;
    EnemyAlien = IMG_LoadTexture(r, ENEMY);
    SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy);

    ExampleEnemy1.x = 120;
    ExampleEnemy1.y = 580;
    ExampleEnemy1.w = w_enemy;
    ExampleEnemy1.h = h_enemy;
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

    while (quit == 0) {
        currentTime = SDL_GetTicks();
        if (currentTime - lastTime < 17) // 17 milliseconds results in approximately 60 fps
            continue;
        else
            lastTime = currentTime;

        SDL_GetMouseState(mousex, mousey);
        if (SDL_PollEvent(&e)) { // Poll for pending events
            switch(e.type) {
            case SDL_QUIT:
                quit = 1;

            case SDL_MOUSEBUTTONDOWN:
                if (*mousex >= 420 && *mousex <= 620 && *mousey >= 410 && *mousey <= 480) { // The user clicks on the "Start game" button
                    return_value = game(e, w, r);
                    if (return_value != 1) {
                        quit = 1;
                    } else {
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
                } else if (*mousex >= 465 && *mousex <= 565 && *mousey >= 630 && *mousey <= 700) { // The user clicks on the "Exit"-button
                    quit = 1;
                } else if (*mousex >= 420 && *mousex <= 620 && *mousey >= 520 && *mousey <= 590) { // The user clicks on the "Controls"-button
                    GuideWindow(e, w, r);
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
  
    int RoundsPassed = 0;
    int dist_left = 2000; // dist_left is the distance between the leftmost enemy and the left edge of the screen
    int dist_right = 2000; // dist_right is the distance between the rightmost enemy and the right edge of the screen
    int currentSize = 0; // currentSize is a variable used to temporariy store the amount of enemies alive
    int currentSize2 = 0; // currentSize2 is a variable used to temporarily store the amount of bullets shot by enemies that are in the game field
    int ret = 0;
    float expDelay = 1.5; // This is "expected delay" between two bullets shot by enemies
    float epsilon = -0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(0.7-(-0.7)))); // Select a random number between -0.7 and 0.7
    float time_to_wait = expDelay + epsilon; // time_to_wait is the time difference between two bullets shot by enemies
    int randomIndex = 0; // A random integer in the range [0, number_of_enemies_alive - 1]. Used to decide which enemy shoots next
    unsigned int currentBulletTime = SDL_GetTicks(); // currentBulletTime is the time at which the most recent enemybullet was shot
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    unsigned int currentEnemyTime = 0; // currentEnemyTime and lastEnemyTime are variable used to determine how quickly the enemis move
    unsigned int lastEnemyTime = 0;
    int mousex_init = 0;
    int mousey_init = 0;
    int *mousex = &mousex_init;
    int *mousey = &mousey_init;
    int speed = 12; // This is the speed of the player
    int EnemyAmount = 0; // EnemyAmount controls how quickly the enemies move
    int w_player = 0;
    int h_player = 0;
    int w_enemy = 0;
    int h_enemy = 0;
    int init_height = 0;
    int init_width = 0;
    int *WindowHeight = &init_height;
    int *WindowWidth = &init_width;
    int quit = 0; // This variable is used to determine when to exit the main loop
    int dir = 1; // This variable defines the direction to which the enemies move.
    int PauseFlag = 0;
    int CheckIfDestroyed = 1; // This variable checks whether there is a bullet shot by the player in the field
    int BulletsExist = 0; // This variable checks whether there are bullets shot by the enemies in the field
    std::vector <SDL_Rect*> EnemyList;
    std::vector <SDL_Rect*> BulletList;

    srand (static_cast <unsigned> (time(0)));
    EnemyList = InitEnemyList();
    Player player_1;
    player_1.Set_lives(3);
    player_1.Set_score(0);
    std::stringstream score;
    std::stringstream lives;
    score << player_1.Give_score();
    lives << player_1.Give_lives();
    TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 65);
    SDL_Color White = {255,255,255};
    SDL_Surface *surfaceButton1 = TTF_RenderText_Solid(ButtonFont, "Return to menu", White);
    SDL_Surface *surfaceButton2 = TTF_RenderText_Solid(ButtonFont, "Exit", White);
    SDL_Texture *PlayerShip;
    SDL_Texture *EnemyAlien;
    SDL_Rect ShipRect;
    SDL_Rect *PlayerBullet;
    SDL_Rect *EnemyBullet;
    SDL_Surface *surfaceScore = TTF_RenderText_Solid(ButtonFont, score.str().c_str(), White);
    SDL_Surface *surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
    SDL_Surface *scoreTextSurface = TTF_RenderText_Solid(ButtonFont, "Score:", White);
    SDL_Surface *livesTextSurface = TTF_RenderText_Solid(ButtonFont, "Lives:", White);
    PlayerShip = IMG_LoadTexture(renderer, USER);
    EnemyAlien = IMG_LoadTexture(renderer, ENEMY);
    SDL_QueryTexture(PlayerShip, NULL, NULL, &w_player, &h_player);
    SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy);
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_Texture *Button1 = SDL_CreateTextureFromSurface(renderer, surfaceButton1);
    SDL_Texture *Button2 = SDL_CreateTextureFromSurface(renderer, surfaceButton2);
    SDL_Texture *Score = SDL_CreateTextureFromSurface(renderer, surfaceScore);
    SDL_Texture *Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives);
    SDL_Texture *ScoreText = SDL_CreateTextureFromSurface(renderer, scoreTextSurface);
    SDL_Texture *LivesText = SDL_CreateTextureFromSurface(renderer, livesTextSurface);
    SDL_Rect Button1Rect;
    SDL_Rect Button2Rect;
    SDL_Rect scoreRect;
    SDL_Rect livesRect;
    SDL_Rect scoreTextRect;
    SDL_Rect livesTextRect;

    Button1Rect.x = 10;
    Button1Rect.y = 5;
    Button1Rect.w = 330;
    Button1Rect.h = 100;
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
  
    for (int j = 0; j < EnemyList.size(); ++j) {
        EnemyList[j]->x = 10 + j*45 - j/10*10*45;
        EnemyList[j]->y = 320 - h_enemy*(j/10) - j/10*5;
        EnemyList[j]->w = w_enemy;
        EnemyList[j]->h = h_enemy;
        SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
    }
    SDL_RenderPresent(renderer);
  
    while (quit == 0) {
        if (EnemyList.size() > 40 && EnemyList.size() <= 50)
            EnemyAmount = 0;
        else if (EnemyList.size() > 30 && EnemyList.size() <= 40)
            EnemyAmount = 1;
        else if (EnemyList.size() > 20 && EnemyList.size() <= 30)
            EnemyAmount = 2;
        else if (EnemyList.size() > 10 && EnemyList.size() <= 20)
            EnemyAmount = 3;
        else if (EnemyList.size() > 0 && EnemyList.size() <= 10)
            EnemyAmount = 4;
        if (EnemyList.size() == 0) {
            if (RoundsPassed < 8) {
                RoundsPassed = RoundsPassed + 1;
                player_1.Increase_lives();
                lives.str("");
                lives << player_1.Give_lives();
                SDL_FreeSurface(surfaceLives);
                surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
                Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives);
            }
            EnemyList = InitEnemyList();
            EnemyAmount = 0;
            for (int j = 0; j < EnemyList.size(); ++j) {
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
        if (currentTime - lastTime < 17)
            continue;
        else
            lastTime = currentTime;

        if (SDL_GetTicks() - currentBulletTime > time_to_wait*1000 && EnemyList.size() != 0) {
            currentBulletTime = SDL_GetTicks();
            randomIndex =  0 + (rand() % static_cast<int>(EnemyList.size()-1 - 0 + 1)); // We choose randomly the next enemy to shoot a bullet.
            EnemyBullet = new SDL_Rect;
            EnemyBullet->w = 5;
            EnemyBullet->h = 5;
            EnemyBullet->x = EnemyList[randomIndex]->x + 15;
            EnemyBullet->y = EnemyList[randomIndex]->y + 30;
            BulletList.push_back(EnemyBullet);
            epsilon = -0.7 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(0.7-(-0.7))));
            time_to_wait = expDelay + epsilon;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Score, NULL, &scoreRect);
        SDL_RenderCopy(renderer, Lives, NULL, &livesRect);
        SDL_RenderCopy(renderer, ScoreText, NULL, &scoreTextRect);
        SDL_RenderCopy(renderer, LivesText, NULL, &livesTextRect);
    
        for (int i = 0; i < EnemyList.size(); ++i) {
            if (SDL_HasIntersection(EnemyList[i], &ShipRect) == SDL_TRUE) {
                ret = GameOverWindow(event, window, renderer, player_1);
                if (ret == 1) {
                    quit = 1;
                    currentSize = EnemyList.size();
                    currentSize2 = BulletList.size();
                    for (int j = 0; j < currentSize; ++j) {
                        delete EnemyList[0];
                        EnemyList.erase(EnemyList.begin());
                    }
                    if (CheckIfDestroyed == 0)
                        delete PlayerBullet;
                    if (BulletsExist == 1) {
                        for (int k = 0; k < currentSize2; ++k) {
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
                } else {
                    currentSize = EnemyList.size();
                    currentSize2 = BulletList.size();
                    for (int j = 0; j < currentSize; ++j) {
                        delete EnemyList[0];
                        EnemyList.erase(EnemyList.begin());
                    }
                    if (CheckIfDestroyed == 0)
                        delete PlayerBullet;
                    if (BulletsExist == 1) {
                        for (int k = 0; k < currentSize2; ++k) {
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

        for (int k = 0; k < BulletList.size(); ++k) {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            SDL_RenderFillRect(renderer, BulletList[k]);
            BulletList[k]->y = BulletList[k]->y + 7;
            if (BulletList[k]->y > 820) { // If the bullet has moved outside the window
                delete BulletList[k];
                BulletList.erase(BulletList.begin() + k);
            } else if (SDL_HasIntersection(BulletList[k], &ShipRect) == SDL_TRUE) { // If a bullet collides with the player
                delete BulletList[k];
                BulletList.erase(BulletList.begin() + k);
                SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                player_1.Reduce_lives();
                lives.str("");
                lives << player_1.Give_lives();
                SDL_FreeSurface(surfaceLives);
                surfaceLives = TTF_RenderText_Solid(ButtonFont, lives.str().c_str(), White);
                Lives = SDL_CreateTextureFromSurface(renderer, surfaceLives);
                if (player_1.Give_lives() < 0) {
                    ret = GameOverWindow(event, window, renderer, player_1);
                    if (ret == 1) {
                        quit = 1;
                        currentSize = EnemyList.size();
                        currentSize2 = BulletList.size();
                        for (int j = 0; j < currentSize; ++j) {
                            delete EnemyList[0];
                            EnemyList.erase(EnemyList.begin());
                        }
                        if (CheckIfDestroyed == 0) {
                            delete PlayerBullet;
                            CheckIfDestroyed = 1;
                        }
                        if (BulletsExist == 1) {
                            for (int k = 0; k < currentSize2; ++k) {
                                delete BulletList[0];
                                BulletList.erase(BulletList.begin());
                            }
                        }
                        break;
                    } else {
                        currentSize = EnemyList.size();
                        currentSize2 = BulletList.size();
                        for (int j = 0; j < currentSize; ++j) {
                            delete EnemyList[0];
                            EnemyList.erase(EnemyList.begin());
                        }
                        if (CheckIfDestroyed == 0)
                            delete PlayerBullet;
                        if (BulletsExist == 1) {
                            for (int k = 0; k < currentSize2; ++k) {
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
        if (BulletList.size() != 0)
            BulletsExist = 1;
        else
            BulletsExist = 0;
        SDL_GetWindowSize(window, WindowWidth, WindowHeight);
        ShipRect.y = *WindowHeight - 45;
        if (currentEnemyTime - lastEnemyTime >= (1000 - EnemyAmount*150) && EnemyList.size() != 0) {
            lastEnemyTime = currentEnemyTime;
            dist_right = 2000;
            dist_left = 2000;
            for (int j = 0; j < EnemyList.size(); ++j) {
                if (*WindowWidth - (EnemyList[j]->x + w_enemy) <= dist_right)
                    dist_right = *WindowWidth - (EnemyList[j]->x + w_enemy);
                if (EnemyList[j]->x <= dist_left)
                    dist_left = EnemyList[j]->x;
            }
            if (dist_right <= 0) { // If the position of the rightmost enemy exceeds the screen width
                dir = 0;
                for (int j = 0; j < EnemyList.size(); ++j)
                    EnemyList[j]->y = EnemyList[j]->y + 30;
            } else if (dist_left <= 0) { // If the position of the leftmost enemy is less than 0
                dir = 1;
                for (int j = 0; j < EnemyList.size(); ++j)
                    EnemyList[j]->y = EnemyList[j]->y + 30;
            }
            for(int i = 0; i < EnemyList.size(); ++i) {
                if (dir == 0)
                    (EnemyList[i])->x = (EnemyList[i])->x - 30;
                else
                    (EnemyList[i])->x = (EnemyList[i])->x + 30;
            }
        }

        SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
        for (int j = 0; j < EnemyList.size(); ++j)
            SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
        if (CheckIfDestroyed == 0) {
            for(int j = 0; j < EnemyList.size(); ++j) {
                if (SDL_HasIntersection(EnemyList[j], PlayerBullet) == SDL_TRUE) {
                    delete EnemyList[j];
                    delete PlayerBullet;
                    EnemyList.erase(EnemyList.begin()+j);
                    CheckIfDestroyed = 1;
                    player_1.Increase_score();
                    score.str("");
                    score << player_1.Give_score();
                    SDL_FreeSurface(surfaceScore);
                    surfaceScore = TTF_RenderText_Solid(ButtonFont, score.str().c_str(), White);
                    Score = SDL_CreateTextureFromSurface(renderer, surfaceScore);
                    break;
                }
            }
            if (CheckIfDestroyed == 0) {
                SDL_SetRenderDrawColor(renderer, 255,255,255,255);
                SDL_RenderFillRect(renderer, PlayerBullet);
                PlayerBullet->y = PlayerBullet->y - 11;
                SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                if (PlayerBullet->y < 0) {
                    CheckIfDestroyed = 1;
                    delete PlayerBullet;
                }
            }
        }

        SDL_RenderPresent(renderer);
        currentSize = EnemyList.size();
        currentSize2 = BulletList.size();
        if (SDL_PollEvent(&event))  {
            switch(event.type) {
            case SDL_QUIT:
                quit = 1;
                for (int j = 0; j < currentSize; ++j) {
                    delete EnemyList[0];
                    EnemyList.erase(EnemyList.begin());
                }
                if (CheckIfDestroyed == 0)
                    delete PlayerBullet;
                if (BulletsExist == 1) {
                    for (int k = 0; k < currentSize2; ++k) {
                        delete BulletList[0];
                        BulletList.erase(BulletList.begin());
                    }
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    ShipRect.x = ShipRect.x + speed;
                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    ShipRect.x = ShipRect.x - speed;
                } else if (event.key.keysym.sym == SDLK_SPACE && CheckIfDestroyed == 1) {
                    PlayerBullet = new SDL_Rect;
                    CheckIfDestroyed = 0;
                    PlayerBullet->x = ShipRect.x + 32;
                    PlayerBullet->y = ShipRect.y;
                    PlayerBullet->w = 5;
                    PlayerBullet->h = 5;
                } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                    while (1) {
                        SDL_GetMouseState(mousex, mousey);
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, Button1, NULL, &Button1Rect);
                        SDL_RenderCopy(renderer, Button2, NULL, &Button2Rect);
                        SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
                        for (int j = 0; j < EnemyList.size(); ++j)
                            SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
                        if (CheckIfDestroyed == 0) {
                            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
                            SDL_RenderFillRect(renderer, PlayerBullet);
                            SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        }
                        if (BulletsExist == 1) {
                            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
                            for (int k = 0; k < BulletList.size(); ++k)
                                SDL_RenderFillRect(renderer, BulletList[k]);
                            SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        }
                        SDL_RenderPresent(renderer);
                        if (SDL_PollEvent(&event)) {
                            switch(event.type) {
                            case SDL_QUIT:
                                quit = 1;
                                PauseFlag = 1;
                                currentSize = EnemyList.size();
                                currentSize2 = BulletList.size();
                                for (int j = 0; j < currentSize; ++j) {
                                    delete EnemyList[0];
                                    EnemyList.erase(EnemyList.begin());
                                }
                                if (CheckIfDestroyed == 0)
                                    delete PlayerBullet;
                                if (BulletsExist == 1) {
                                    for (int k = 0; k < currentSize2; ++k) {
                                        delete BulletList[0];
                                        BulletList.erase(BulletList.begin());
                                    }
                                }
                                break;

                            case SDL_KEYDOWN:
                                if (event.key.keysym.sym == SDLK_ESCAPE) {
                                    PauseFlag = 1;
                                    break;
                                }

                            case SDL_MOUSEBUTTONDOWN:
                                if (*mousex >= 10 && *mousex <= 340 && *mousey >= 5 && *mousey <= 105) {
                                    currentSize = EnemyList.size();
                                    currentSize2 = BulletList.size();
                                    for (int j = 0; j < currentSize; ++j) {
                                        delete EnemyList[0];
                                        EnemyList.erase(EnemyList.begin());
                                    }
                                    if (CheckIfDestroyed == 0)
                                        delete PlayerBullet;
                                    if (BulletsExist == 1) {
                                        for (int k = 0; k < currentSize2; ++k) {
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
                                } else if (*mousex >= 950 && *mousex <= 1070 && *mousey >= 5 && *mousey <= 105) {
                                    currentSize = EnemyList.size();
                                    currentSize2 = BulletList.size();
                                    for (int j = 0; j < currentSize; ++j) {
                                        delete EnemyList[0];
                                        EnemyList.erase(EnemyList.begin());
                                    }
                                    if (CheckIfDestroyed == 0)
                                        delete PlayerBullet;
                                    if (BulletsExist == 1) {
                                        for (int k = 0; k < currentSize2; ++k) {
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
                            if (PauseFlag == 1) {
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
