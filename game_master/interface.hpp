#include "../settings/ui_settings.hpp"
#include <string>
#include <memory>
#include <iostream>
// Перенести в save
struct CurrentState
{
  bool isStartingRoom;
  int room;
  bool isFighting;
  bool isChestOpen;
  bool isInventoryOpen;
};

struct Offset{
  int previousPositionX;
  int previousPositionY;
};

class Interface
{
private:
  void RenderLine(int y, int x, std::string text, Color color);

  std::unique_ptr<UserInterfaceSettings> ui_settings_;
  
public:
  Interface();
  void ChooseMove();
  void StartRoom();
  void Room();
  void FightEnemy();
  void OpenChest();
  void OpenInventory();

  Offset offset_;
};

Interface::Interface()
{
  ui_settings_ = std::make_unique<UserInterfaceSettings>();
  ui_settings_->InitCurses();
  offset_.previousPositionX = 0;
  offset_.previousPositionY = -1;
}

void Interface::RenderLine(int y, int x, std::string text, Color color = Color::WHITE)
{
  if (offset_.previousPositionY != y){
    offset_.previousPositionX = 0;
    offset_.previousPositionY = y;
  }
  attron(COLOR_PAIR(color));
  mvprintw(y, offset_.previousPositionX, text.c_str());
  attroff(COLOR_PAIR(color));
  if (x == -1)
  {
    offset_.previousPositionX = text.length() + offset_.previousPositionX + 1;
  }
  else
  {
    offset_.previousPositionX = x + text.length() + 1;
  }
  
}

void Interface::ChooseMove()
{
  RenderLine(LINES - 5, -1, "Attack1", Color::RED);
  RenderLine(LINES - 5, -1, "Attack1", Color::RED);
  RenderLine(LINES - 5, -1, "Attack1", Color::RED);
  RenderLine(LINES - 4, -1, "Attack", Color::RED);
  RenderLine(LINES - 4, 10, "Talk", Color::GREEN);
  RenderLine(LINES - 4, 15, "Inventory", Color::YELLOW);
  RenderLine(LINES - 4, 28, "Run", Color::WHITE);
}

void Interface::StartRoom() 
{
  
}

void Interface::Room()
{
}

void Interface::FightEnemy()
{
}

void Interface::OpenChest()
{
}

void Interface::OpenInventory()
{
}
