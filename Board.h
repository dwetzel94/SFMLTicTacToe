#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Board
{
public:
    
    Board(Texture* texture, float width, float height, float xPos, float yPos);
    
    Vector2f getPosition();
    
    void DrawBoard(RenderWindow& window);
    
private:
    RectangleShape gameBoard;
};

#endif // BOARD_H
