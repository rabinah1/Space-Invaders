#include <string>
#include <iostream>

class Player {
private:
  int Lives;
  int Score;
  std::string Name;
public:
  void Print_lives()
  {
    std::cout << Lives << "\n";
  }
  void Print_score()
  {
    std::cout << Score << "\n";
  }
  void Print_name()
  {
    std::cout << Name << "\n";
  }
  void Set_name(std::string nm)
  {
    Name = nm;
  }
  void Set_lives(int amnt)
  {
    Lives = amnt;
  }
  void Set_score(int sc)
  {
    Score = sc;
  }
};

int main()
{
  int l;
  int s;
  std::string n;
  Player player_1;
  std::cout << "Enter number of lives: ";
  std::cin >> l;
  player_1.Set_lives(l);
  std::cout << "Enter score: ";
  std::cin >> s;
  player_1.Set_score(s);
  std::cout << "Enter your name: ";
  std::cin >> n;
  player_1.Set_name(n);
  player_1.Print_lives();
  player_1.Print_score();
  player_1.Print_name();
  return 0;
}
