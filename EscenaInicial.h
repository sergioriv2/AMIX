#pragma once
#include "EscenaBase.h"
#include "Dialogo.h"
class EscenaInicial : public EscenaBase
{
private:
	Dialogo* diag;
	
	sf::Font fuente;
	sf::RectangleShape Nubetexto;
	sf::Texture TextFondo;// textura fondo mapa
	sf::Texture TextNube;
	sf::Sprite SpriteFondo; // fondo sprite
	sf::Clock clock;
	sf::Clock clock2;
	sf::Text Texto;

public:

	EscenaInicial();
	void updatee_es(float lapso);
	void draw_es(sf::RenderWindow& _w);
	void crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);
	~EscenaInicial() {
		EscenaBase::delMusic();
	}
};

