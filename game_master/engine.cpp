#include "engine.hpp"

Engine::Engine() : isRunning_(false) {}

void Engine::Run()
{
    isRunning_ = true;
    InitInterface();
    while (isRunning_)
    {
        Update();
        Render();
        HandleInput();
    }
    CleanupCurses();
}

void Engine::InitInterface()
{
    Interface_ = std::make_unique<Interface>();
}

void Engine::HandleInput()
{
    int ch = getch();
    switch (ch)
    {
    case 'q':
    case 'Q':
    case '0':
        isRunning_ = false;
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

    Interface_->ChooseMove();
    Interface_->SystemButtons();

    refresh(); // Обновляем реальный экран содержимым виртуального
}

inline void Engine::CleanupCurses()
{
    endwin(); // Завершение работы с ncurses
}