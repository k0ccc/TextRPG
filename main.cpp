
#include "entitys/entity.hpp"
#include "game_master/ui.hpp"

int main()
{
  Entity test_;
  UserInterface ui;
  test_.Print();
  ui.SetColor(GREEN);
  test_.Print();
  return 0;
}

