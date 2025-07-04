#include "interface.hpp"

Interface::Interface()
{
  ui_settings_ = std::make_unique<UserInterfaceSettings>();
  ui_settings_->InitCurses();
  offset_.previousPositionX = 0;
  offset_.previousPositionY = -1;
}

/**
 * The RenderText function in C++ renders text at a specified position with a specified color.
 *
 * @param y The `y` parameter in the `RenderText` function represents the vertical position where the
 * text will be rendered on the screen. It specifies the row number where the text will be displayed.
 * @param x The `x` parameter in the `RenderText` function represents the horizontal position where the
 * text will be rendered on the screen. If the value of `x` is set to -1, the function will
 * automatically calculate the next position based on the length of the text and the previous position.
 * If
 * @param text The `text` parameter in the `RenderText` function is a string that represents the text
 * that you want to render on the screen at the specified coordinates (y, x). It is the actual content
 * that will be displayed on the screen at the specified position.
 * @param color The `color` parameter in the `RenderText` function is of type `Color` and has a default
 * value of `Color::WHITE`. This parameter is used to specify the color in which the text will be
 * rendered on the screen.
 */
void Interface::RenderText(int y, int x, std::string text, Color color = Color::WHITE)
{
  int yCoord; 
  if( y < 0 ){yCoord = LINES + y;}
  else{yCoord = y;}

  if (offset_.previousPositionY != yCoord){
    offset_.previousPositionX = 0;
    offset_.previousPositionY = yCoord;
  }
  attron(COLOR_PAIR(color));
  mvprintw(yCoord, offset_.previousPositionX, text.c_str());
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
/**
 * The function MutliText renders multiple lines with optional line numbering and color at a
 * specified y-coordinate.
 *
 * @param lines The `lines` parameter is a vector of strings that contains multiple lines of text to be
 * rendered. Each element in the vector represents a single line of text.
 * @param y The `y` parameter in the `MutliText` function seems to represent the vertical position
 * where the lines will be rendered on the interface. It likely specifies the y-coordinate or row
 * number where the lines will be displayed.
 * @param color The `color` parameter in the `MutliText` function is of type `Color`. It is used to
 * specify the color in which the lines will be rendered on the interface. The `Color` type likely
 * represents a color value or object that determines the visual appearance of the text or lines
 * @param isCount The `isCount` parameter in the `MutliText` function is a boolean flag that
 * determines whether line numbers should be displayed along with the text lines. If `isCount` is
 * `true`, then line numbers will be prepended to each line of text before rendering.
 */

void Interface::MutliText(std::vector<std::string> lines, int y, Color color, bool isCount)
{
  for (int i = 0; i < lines.size(); i++)
  {
  if (!isCount) RenderText(y, -1, lines[i], color);
  else RenderText(y, -1, std::to_string(i+1)+ " - " + lines[i], color);
  }
}

void Interface::RenderLine(int y, int x, char symbol, int len)
{
  mvhline(y, x, symbol, len);
}


void Interface::ChooseMove()
{
  RenderLine(0, 0, '-', 100);
  MutliText({"Attack1", "Attack2"}, -5, Color::RED, true);
  RenderText(-4, -1, "1 - Attack", Color::RED);
  RenderText(-4, -1, "2 - Talk", Color::GREEN);
  RenderText(-4, -1, "3 - Inventory", Color::YELLOW);
  RenderText(-4, -1, "4 - Run", Color::WHITE);
 }

 void Interface::SystemButtons()
 {
  RenderText(-1, 0, "Press (q or '0' - quit)"); // LINES - высота экрана
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
