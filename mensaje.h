#pragma once
#include "entidad.h"
class mensaje : public Entidad
{
private:
	sf::Text _texto;
	sf::Text _colorPersonaje;
	sf::Font _fuente;
	sf::Clock rel;
public:
	mensaje();

	void setPos(sf::Vector2f pos);
	void sel_mensaje(int posItem);
	void updatee_e(float a);

	void draw_enty(sf::RenderWindow& w);
	sf::Text& getText() { return _texto; }
};


