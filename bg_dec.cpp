#include "bg_dec.h"

bg_dec::bg_dec(tipo_dec t, sf::Vector2f pos)
{
	_bgsprite.setScale(0.4, 0.4);
	switch (t)
	{
	case tipo_dec::ARBOL:
		_bgtex.loadFromFile("recursos/fondos/decorativos/arbol.png");
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::ARBUSTO:
		_bgtex.loadFromFile("recursos/fondos/decorativos/arbusto.png");
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::PIEDRA:
		_bgtex.loadFromFile("recursos/fondos/decorativos/piedra.png");
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::FAROL:
		_bgtex.loadFromFile("recursos/fondos/decorativos/luces.png");
		_bgsprite.setScale(0.6, 0.6);
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::BASURA1:
		_bgtex.loadFromFile("recursos/fondos/decorativos/basura1.png");
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::BASURA2:
		_bgtex.loadFromFile("recursos/fondos/decorativos/basura2.png");
		_bgsprite.setPosition(pos);
		break;
	case tipo_dec::BASURA3:
		_bgtex.loadFromFile("recursos/fondos/decorativos/basura3.png");
		_bgsprite.setPosition(pos);
		break;
	default:
		_bgtex.loadFromFile("recursos/fondos/decorativos/piedra.png");
		_bgsprite.setPosition(pos);
		break;
	}
	_bgsprite.setTexture(_bgtex);
}

void bg_dec::updatee_e(float lapso)
{

}

void bg_dec::draw_enty(sf::RenderWindow& _w)
{
	_w.draw(_bgsprite);
}
