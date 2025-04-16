
#include <iostream>
#include <memory>
#include "interface.hpp"

class Engine
{
private:
  void InitInterface();
  void HandleInput();
  void Update();
  void Render();
  void CleanupCurses();

  bool isRunning_;

  std::unique_ptr<Interface> Interface_;

public:
  Engine();
  void Run();
};


Engine::Engine(): isRunning_(false){}


void Engine::Run()
{
  isRunning_ = true;
  InitInterface();
  while (isRunning_)
  {
    Update();
    Render();
    HandleInput();
  }
  CleanupCurses();
}

void Engine::InitInterface()
{
  Interface_ = std::make_unique<Interface>();
}

void Engine::HandleInput(){
  int ch = getch();
  switch (ch)
  {
  case 'q':
  case 'Q':
    isRunning_ = false;
    break;
  case '1':
    isRunning_ = false;
    break;
  default:
    break;
  }
}

void Engine::Update()
{
  // Логика обновления состояния игры
}

void Engine::Render()
{
  // Логика отрисовки текста и графики
  erase(); // Очищаем виртуальный экран (аналог clear, но без мерцания)

  Interface_->ChooseMove();

  mvprintw(LINES - 1, 0, "Press (q - quit): "); // LINES - высота экрана

  refresh(); // Обновляем реальный экран содержимым виртуального
}

inline void Engine::CleanupCurses()
{
  endwin(); // Завершение работы с ncurses
}