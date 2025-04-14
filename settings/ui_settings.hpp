
#include "../wrapper/libs.hpp"

enum Color
{
  RED = 1,    // ATTACK
  GREEN = 2,  // TALK - ACTION
  YELLOW = 3, // INVETORY
  WHITE = 4   // TEXT
};
class UserInterfaceSettings
{
private:

public:
  UserInterfaceSettings();
  void SetColor(int y, int x, std::string text, Color color = WHITE) const;
};

UserInterfaceSettings::UserInterfaceSettings()
{
  initscr();            // Инициализация ncurses
  cbreak();             // Отключаем буферизацию строк (символы доступны сразу)
  noecho();             // Не выводить нажатые символы автоматически
  keypad(stdscr, TRUE); // Включаем обработку спец. клавиш (стрелки и т.д.)
  curs_set(1);          // Показать курсор (0 - скрыть)
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);   // Пара 1: красный текст на черном фоне
  init_pair(2, COLOR_GREEN, COLOR_BLACK); // Пара 2: зеленый текст на черном фоне
  init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Пара 3: синий текст на черном фоне
  init_pair(4, COLOR_WHITE, COLOR_BLACK); // Пара 4: белый текст на черном фоне
}

// Функцию вынести в UI,нужно для изоляции цвета
void UserInterfaceSettings::SetColor(int y, int x, std::string text, Color color) const
{
  attron(COLOR_PAIR(color));
  mvprintw(y, x, text.c_str());
  attroff(COLOR_PAIR(color));
}
