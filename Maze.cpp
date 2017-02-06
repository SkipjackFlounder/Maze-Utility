#include "Maze.hpp"

Maze::Maze(int size)
{
	srand(time(NULL));
	this->size = size;
	this->step = 700.0/((float)size);
	for(auto y = 0; y < size + 1; y++)
	{
		vWall.push_back(std::vector<bool>());
		hWall.push_back(std::vector<bool>());
		visited.push_back(std::vector<bool>());
		origin.push_back(std::vector<direction>());
		for(auto x = 0; x < size + 1; x++)
		{
			vWall[y].push_back(true);
			hWall[y].push_back(true);
			visited[y].push_back(false);
			origin[y].push_back(NONE);
		}
	}
	sf::Vector2i cursor = sf::Vector2i(size/2, 0);
	do
	{
		bool free = false;
		for(auto i = 1; i < 5; i++)
		{
			sf::Vector2i possible = cursor + cardinal[i];
			if(possible.x >= 0 and possible.x < size and possible.y >= 0 and possible.y < size)
			{
				if(visited[possible.x][possible.y] == false)
				{
					free = true;
				}
			}
		}
		
		if(free == false)
		{
			visited[cursor.x][cursor.y] = true;
			cursor += cardinal[origin[cursor.x][cursor.y]];
		}else{
			direction pDirection;
			do
			{
				do
				{
					pDirection = (direction)(rand()%4 + 1);
				}while(!(cursor.x + cardinal[pDirection].x >= 0 and cursor.x + cardinal[pDirection].x < size
					 and cursor.y + cardinal[pDirection].y >= 0 and cursor.y + cardinal[pDirection].y < size)); 
			}while(visited[cursor.x + cardinal[pDirection].x][cursor.y + cardinal[pDirection].y] == true);
			visited[cursor.x][cursor.y] = true;
			cursor += cardinal[pDirection];
			switch(pDirection)
			{
				case UP:
					hWall[cursor.x][cursor.y + 1] = false;
					origin[cursor.x][cursor.y] = DOWN;
					break;
				case RIGHT:
					vWall[cursor.x][cursor.y] = false;
					origin[cursor.x][cursor.y] = LEFT;
					break;
				case DOWN:
					hWall[cursor.x][cursor.y] = false;
					origin[cursor.x][cursor.y] = UP;
					break;
				case LEFT:
					vWall[cursor.x + 1][cursor.y] = false;
					origin[cursor.x][cursor.y] = RIGHT;
					break;
			}
		}
	}while(cursor != sf::Vector2i(size/2, 0));
	
}

void Maze::draw(sf::RenderWindow &window)
{
	for(auto y = 0; y < size; y++)
	{
		for(auto x = 0; x < size; x++)
		{
			if(hWall[x][y] == true)
			{
				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(x * step, y * step)),
					sf::Vertex(sf::Vector2f((x + 1) * step, y * step))
				};
				window.draw(line, 2, sf::Lines);
			}
			if(vWall[x][y] == true)
			{
				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(x * step, y * step)),
					sf::Vertex(sf::Vector2f(x * step, (y + 1) * step))
				};
				window.draw(line, 2, sf::Lines);
			}
		}
	}
}
