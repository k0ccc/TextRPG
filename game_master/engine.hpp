
#ifdef _WIN32
#include <ncurses/ncurses.h>
#else 
#include <curses.h>
#endif

#include <iostream>
#include "../settings/ui_settings.hpp"
#include <memory>

class Engine
{
private:
  bool isRunning_;
  std::unique_ptr<UserInterfaceSettings> ui_settings_;

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
  ui_settings_ = std::make_unique<UserInterfaceSettings>();
  while (isRunning_)
  {
    Update();
    Render();
    HandleInput();
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
  case KEY_UP:
    // ui_settings_->SetColor(YELLOW);
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
  ui_settings_->SetColor(0, 0, "--- My text game ---", RED);
  ui_settings_->SetColor(2, 5, "Current location: Room 1", GREEN);
  ui_settings_->SetColor(3, 5, "Inv: Empty", YELLOW);
  // ... вывод карты, лога сообщений ...

  mvprintw(LINES - 1, 0, "Press (q - quit): "); // LINES - высота экрана

  refresh(); // Обновляем реальный экран содержимым виртуального
}

void Engine::CleanupCurses()
{
  endwin(); // Завершение работы с ncurses
}