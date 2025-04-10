
#ifdef _WIN32
#include <ncurses/ncurses.h>
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
  Engine();
  void Run();
  void InitCurses();
  void HandleInput();
  void Update();
  void Render();
  void CleanupCurses();
};


Engine::Engine(): isRunning_(false){}


void Engine::Run()
{
  isRunning_ = true;
  InitCurses();
  while (isRunning_)
  {
    HandleInput();
    Update();
    Render();
  }
  CleanupCurses();
}

void Engine::InitCurses()
{
  initscr();            // Инициализация ncurses
  cbreak();             // Отключаем буферизацию строк (символы доступны сразу)
  noecho();             // Не выводить нажатые символы автоматически
  keypad(stdscr, TRUE); // Включаем обработку спец. клавиш (стрелки и т.д.)
  curs_set(1);          // Показать курсор (0 - скрыть)
}

void Engine::HandleInput(){
  int ch = getch();
  switch (ch)
  {
  case 'q':
  case 'Q':
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

  // Используем функции ncurses для вывода в нужных координатах (y, x)
  mvprintw(0, 0, "--- My text game ---");
  mvprintw(2, 5, "Current location: Room 1");
  mvprintw(3, 5, "Inv: Empty");
  // ... вывод карты, лога сообщений ...

  mvprintw(LINES - 1, 0, "Press (q - quit): "); // LINES - высота экрана

  refresh(); // Обновляем реальный экран содержимым виртуального
}

void Engine::CleanupCurses()
{
  endwin(); // Завершение работы с ncurses
}