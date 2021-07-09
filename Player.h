#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int Lives;
    int Score;
public:
    void Set_lives(int amnt);
    void Set_score(int sc);
    void Reduce_lives();
    void Increase_lives();
    void Increase_score();
    int Give_lives();
    int Give_score();
};
#endif
