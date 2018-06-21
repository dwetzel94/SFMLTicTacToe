#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "Board.cpp"

using namespace std;
using namespace sf;

static const float WindowHeight = 800;
void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x/ float(window.getSize().y));
    view.setSize(WindowHeight * aspectRatio, WindowHeight);
}

int main()
{
    RenderWindow window(VideoMode(800, 800), "Tricked Out TicTacToe in SFML", Style::Close | Style::Titlebar | Style::Resize);
    View view(Vector2f(0.0f, 0.0f), Vector2f(WindowHeight, WindowHeight));
    
    Font libertineRBah;
    libertineRBah.loadFromFile("../Font/LinLibertine_RBah.ttf");
    Text text;
    text.setFont(libertineRBah);
    text.setString("Tic Tac Toe");
    text.setCharacterSize(60);
    text.setFillColor(Color::White);
    text.setPosition(250, 10);
   
    Texture gameBoardTexture;
    gameBoardTexture.loadFromFile("../Textures/Board.png");
    Board gameBoard(&gameBoardTexture, 500.0, 500.0, 400, 400);
    
    
    while(window.isOpen())
    {
        Event userEvent;
        while(window.pollEvent(userEvent))
        {
            switch(userEvent.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    ResizeView(window, view);
                    break;
            }
        }
        
        window.clear(Color::Black);
        view.setCenter(gameBoard.getPosition());
        window.setView(view);
        window.draw(text);
        gameBoard.DrawBoard(window);
        window.display();
        
    }
    
}
