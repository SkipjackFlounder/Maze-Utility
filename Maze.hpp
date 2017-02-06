#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>

class Maze
{
	private:
		int size;
		float step;
		std::vector<std::vector<bool>> vWall;
		std::vector<std::vector<bool>> hWall;
		std::vector<std::vector<bool>> visited;
		enum direction
		{
			NONE,
			UP,
			RIGHT,
			DOWN,
			LEFT
		};
		sf::Vector2i cardinal[5] = 
		{
			sf::Vector2i(0, 0),
			sf::Vector2i(0, -1),
			sf::Vector2i(1, 0),
			sf::Vector2i(0, 1),
			sf::Vector2i(-1, 0)
		};
		std::vector<std::vector<direction>> origin;
	public:
		Maze(int);
		void draw(sf::RenderWindow&);
};
