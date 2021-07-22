#pragma once
#include <SFML/Graphics.hpp>

class Camara
{
private:
	sf::View _camara;
public:
	Camara()
	{
		_camara.setCenter({ 0,0 });
		_camara.setSize({ 880, 600 });
	}
	sf::View& getView() { return _camara; }
};