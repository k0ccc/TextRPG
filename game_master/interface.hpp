#include "../settings/ui_settings.hpp"

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
  void RenderText(int y, int x, std::string text, Color color);
  void MutliText(std::vector<std::string> lines, int y, Color color, bool isCount);
  void RenderLine(int y, int x, char symbol, int len);
  std::unique_ptr<UserInterfaceSettings> ui_settings_;

  public:
  Interface();
  void ChooseMove();
  void SystemButtons();
  void StartRoom();
  void Room();
  void FightEnemy();
  void OpenChest();
  void OpenInventory();

  Offset offset_;
};
