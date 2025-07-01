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
