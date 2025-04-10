
#ifdef _WIN32
#include <conio.h>
#else 
#include <curses.h>
#endif

#include <iostream>
#include <cstdlib>

class Engine
{
private:
  bool isRunning_;
public:
  Engine(bool IsRunning);
  void Run();
  void HandleInput();
  void Update();
  void Render();
  void ClearConsole();
};

Engine::Engine(bool IsRunning) : isRunning_(IsRunning)
{

  
}
void Engine::Run()
{
  while (isRunning_)
  {
    Update();
    HandleInput();
    ClearConsole();
    Render();
  }
}

void Engine::HandleInput(){
  std::cout << "To quit the game press 'q'" << std::endl;
  if (_kbhit())
  {                     // Проверяем, есть ли нажатие клавиши
    char ch = _getch(); // Получаем нажатую клавишу
    if (ch == 'q')
    { // Например, 'q' для выхода
      isRunning_ = false;
    }
    // Обработка других клавиш
  }
}

void Engine::Update()
{
  // Логика обновления состояния игры
}

void Engine::Render()
{
  std::cout << "test" << std::endl;
  // Логика отрисовки текста и графики
}
// DEL  
void Engine::ClearConsole()
{
  system("cls");
}
