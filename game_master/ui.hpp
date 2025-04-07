#include <iostream>
#include <windows.h>

#ifdef _WIN32
  enum Color
  {
    GREEN = 2,  // TALK
    RED = 4,    // ATTACK
    YELLOW = 6, // INVETORY
    WHITE = 7   // TEXT
  };
#elif __linux__
  enum Color
  {
    GREEN = 32,  // TALK
    RED = 31,    // ATTACK
    YELLOW = 33, // INVETORY
    WHITE = 37   // TEXT
  };
#else
  std::cout << "Your OS not supported" << std::endl;
  std::cin.get();
  exit(1);
#endif


enum OS {
  WIN,
  LINUX
};

class UserInterface
{
private:
  OS os_;
  Color printColor_;
  HANDLE hConsole_;
public:
  UserInterface();
  void SetColor(Color color);
};

UserInterface::UserInterface()
{
  #ifdef _WIN32
    hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
    os_ = WIN;
  #elif __linux__
    os_ = LINUX;
  #else
    std::cout << "Your OS not supported" << std::endl;
  #endif
}

void UserInterface::SetColor(Color color)
{
  
  if (os_ == WIN)
  {
    SetConsoleTextAttribute(hConsole_, color);
  }
  else{
    std::cout << "\033[" << color << "m";
  }
}
