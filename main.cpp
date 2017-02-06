/***************************
Program that generates mazes
Made by Matthew Barnett
***************************/
#include <iostream>
#include "Maze.hpp"

int main()
{
    int s;
    std::cout << "Size of maze: ";
    std::cin >> s;
    
    sf::RenderWindow window(sf::VideoMode(700, 700), "Maze Utility");
    sf::View view(sf::FloatRect(0, 0, 700, 700));
    window.setView(view);
    
	Maze maze(s);
	while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
		    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
        window.clear();
		    maze.draw(window);
        window.display();
    }
	return 0;
}	
