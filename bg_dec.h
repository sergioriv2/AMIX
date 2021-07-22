#pragma once
#include "entidad.h"

enum class tipo_dec
{
	ARBOL,
	ARBUSTO,
	FAROL,
	BASURA1,
	BASURA2,
	BASURA3,
	PIEDRA
};

class bg_dec : public Entidad
{
private:
	sf::Sprite _bgsprite;
	sf::Texture _bgtex;
public:
	bg_dec() {};
	bg_dec(tipo_dec t, sf::Vector2f pos);


	void updatee_e(float lapso);

	void draw_enty(sf::RenderWindow& _w);
};

