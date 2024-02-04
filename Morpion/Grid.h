#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
class Grid
{
private:
	int m_rows;
	int m_cols;
	std::vector<std::vector<int>> m_grid;

	bool checkWin(int player);

public:
	Grid();
	void Show(sf::RenderWindow& window);
	int play(int player, sf::RenderWindow& window);
};

