#include "Board.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

Board::Board(Texture* texture, float width, float height, float xPos, float yPos)
{
    gameBoard.setSize(Vector2f(width, height));
    gameBoard.setOrigin(gameBoard.getSize()/2.0f);
    gameBoard.setPosition(xPos, yPos);
    gameBoard.setTexture(texture);
}

Vector2f Board::getPosition()
{
    return gameBoard.getPosition();
}


void Board::DrawBoard(sf::RenderWindow& window)
{
    window.draw(gameBoard);
}

