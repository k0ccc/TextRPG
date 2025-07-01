
#include <iostream>
#include <memory>
#include "interface.cpp"

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