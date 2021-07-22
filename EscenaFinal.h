#pragma once
#include "EscenaBase.h"
#include "Dialogo.h"
class EscenaFinal :public EscenaBase
{
private:
	sf::RectangleShape Nubetexto;
	Dialogo* diag;
	sf::Font fuente;
	sf::Sprite fondo;
	sf::Texture textfondo;
	sf::Clock clock;
	sf::Text Texto;
	sf::Text Texto2;
	sf::View camara;
	int dialogo2 = 0;
public:
	EscenaFinal();

	void updatee_es(float lapso);
	void draw_es(sf::RenderWindow& _w);
	void crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);
};

