
#include "entitys/entity.hpp"
#include "game_master/ui.hpp"

#include <windows.h>
int main()
{
  Entity test_;
  UserInterface ui_;
  test_.Print();
  ui_.SetColor(GREEN);
  test_.Print();
  return 0;
}

