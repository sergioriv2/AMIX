#pragma once

#include <SFML/Graphics.hpp>
#include "entidad.h"
#include "tipos_fondo.h"

class Fondo: public  Entidad
{
private:
	sf::Sprite _fondoSprite;
	sf::Texture _fondoTextura;
public:	

	Fondo();
	Fondo(TipoFondo);

	void setFondo(TipoFondo);

	void updatee_e(float lapso);
	void draw_enty(sf::RenderWindow& w);

	sf::Sprite getFondo() { return _fondoSprite; }
	sf::Texture& getTextura() { return _fondoTextura; }

	~Fondo()
	{
		_fondoTextura.~Texture();
	}

};

