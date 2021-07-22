#include "tipos_fondo.h"
#include "Fondo.h"
#include <iostream>

Fondo::Fondo()
{
	//Mensaje de error por si no carga
	if (!_fondoTextura.loadFromFile("recursos/fondos/b1.jpg")) std::cout << "Error";

	_fondoSprite.setPosition({ -250,0 });
	_fondoSprite.setScale({ 0.55, 0.556 });
	_fondoSprite.setTexture(_fondoTextura);
}

Fondo::Fondo(TipoFondo _tf)
{
	switch (_tf)
	{
	case TipoFondo::CIUDAD_1:
		_fondoTextura.loadFromFile("recursos/fondos/b1.jpg");
		_fondoSprite.setScale({ 0.55, 0.556 });
		_fondoSprite.setPosition({ -250,0 });
		break;
	case TipoFondo::CIUDAD_2:
		_fondoTextura.loadFromFile("recursos/fondos/b2.jpg");
		_fondoSprite.setScale({ 0.55, 0.556 });
		_fondoSprite.setPosition({ -250,0 });
		break;
	case TipoFondo::PLAYA:
		_fondoTextura.loadFromFile("recursos/fondos/background_after.png");
		_fondoSprite.setScale({ 1.55, 1.43 });
		_fondoSprite.setPosition({ 0,0 });
		break;
	case TipoFondo::CASA:
		_fondoTextura.loadFromFile("recursos/fondos/background_house.png");
		_fondoSprite.setScale({ 1.43, 1.3 });
		break;
	case TipoFondo::CEMENTERIO:
		_fondoTextura.loadFromFile("recursos/fondos/cementerio.png");
		_fondoSprite.setScale({ 0.5, 0.56 });
		_fondoSprite.setPosition({ -30,0 });
	default:
		break;
	}

	_fondoSprite.setTexture(_fondoTextura);
}

void Fondo::updatee_e(float _lapso)
{

}

void Fondo::draw_enty(sf::RenderWindow& _w)
{
	_w.clear();
	_w.draw(_fondoSprite);
	
}
void Fondo::setFondo(TipoFondo _tf)
{
	/*switch (_tf)
	{
	case TipoFondo::CIUDAD_1:
		_fondoTextura.loadFromFile("recursos/fondos/b1.jpg");
		break;
	case TipoFondo::CIUDAD_2:
		_fondoTextura.loadFromFile("recursos/fondos/b2.jpg");
		break;
	case TipoFondo::PLAYA: 
		_fondoTextura.loadFromFile("recursos/background_after.png");		
		break;
	case TipoFondo::CASA: 
		_fondoTextura.loadFromFile("recursos/background_house.png");
		break;
	default:
		break;
	}
	_fondoSprite.setTexture(_fondoTextura);*/
}
