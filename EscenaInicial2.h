#pragma once
#include "EscenaBase.h"
#include "Dialogo.h"

class EscenaInicial2 : public EscenaBase
{
private:

	Dialogo* diag;
	sf::Font fuente; //Donde cargo la fuente en la que se va a mostrar el Texto
	sf::RectangleShape Nubetexto;// Nube donde se coloca el texto
	sf::Texture TextFondo;// textura fondo mapa
	sf::Texture TextNube;// textura nube
	sf::Sprite SpriteFondo; // fondo sprite
	sf::Clock clock;
	sf::Text Texto; //Texto a mostrar


public:

	EscenaInicial2();
	void updatee_es(float lapso);
	void draw_es(sf::RenderWindow& _w);
	void crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);

	~EscenaInicial2();
};

