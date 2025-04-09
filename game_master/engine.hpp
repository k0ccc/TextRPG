
#ifdef _WIN32
#include <conio.h>
#else 
#include <curses.h>
#endif


class Engine
{
private:
  bool isRunning_;
public:
  Engine(bool IsRunning);
  void HandleInput();
  void Update();
  void Render();
};

Engine::Engine(bool IsRunning) : isRunning_(IsRunning)
{
  while (isRunning_)
  {
    HandleInput();
    Update();
    Render();
  }
  
}
// На Linux _kbhit() не было протестировано
void Engine::HandleInput(){
  if (_kbhit())
  {                     // Проверяем, есть ли нажатие клавиши
    char ch = _getch(); // Получаем нажатую клавишу
    if (ch == 'q')
    { // Например, 'q' для выхода
      isRunning_ = false;
    }
    // Обработка других клавиш
  }
}

void Engine::Update()
{
  // Логика обновления состояния игры
}

void Engine::Render()
{
  // Логика отрисовки текста и графики
}
