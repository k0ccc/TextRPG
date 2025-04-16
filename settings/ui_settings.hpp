
#include "../wrapper/libs.hpp"

enum Color
{
  WHITE,  // TEXT
  GREEN,  // PLAYER CHOICE
  YELLOW, // INVETORY
  RED,    // ATTACK

  AMOUNT
};
class UserInterfaceSettings
{
private:

public:
  UserInterfaceSettings();
  void InitCurses();
};

UserInterfaceSettings::UserInterfaceSettings()
{
}

void UserInterfaceSettings::InitCurses()
{
  initscr();            // Инициализация ncurses
  cbreak();             // Отключаем буферизацию строк (символы доступны сразу)
  noecho();             // Не выводить нажатые символы автоматически
  keypad(stdscr, TRUE); // Включаем обработку спец. клавиш (стрелки и т.д.)
  curs_set(1);          // Показать курсор (0 - скрыть)
  start_color();
  init_pair(0, COLOR_WHITE, COLOR_BLACK); // Пара 1: белый текст на черном фоне 
  init_pair(1, COLOR_GREEN, COLOR_BLACK); // Пара 2: зеленый текст на черном фоне
  init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Пара 3: желтый текст на черном фоне
  init_pair(3, COLOR_RED, COLOR_BLACK);    // Пара 4: красный текст на черном фоне
}
