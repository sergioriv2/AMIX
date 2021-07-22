#include "Dialogo.h"

Dialogo::Dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo)
{
	textburbj.loadFromFile("recursos/fondos/cuadroTexto.png");
	burbuja.setTexture(&textburbj);
	burbuja.setPosition(pos);
	burbuja.setSize(size);
	burbuja.setFillColor(sf::Color(126, 126, 126, 150));
	
	if (tipo==1)
	{
		Txtopers.loadFromFile("recursos/fondos/whitehead.png");
		pers.setTexture(&Txtopers);
		pers.setPosition(burbuja.getPosition().x + 670 , burbuja.getPosition().y + 32);
		pers.setSize({ 12 , 10 });
		pers.scale(13, 13);

	}
	if (tipo == 2)
	{
		Txtopers.loadFromFile("recursos/fondos/pinkhead.png");
		pers.setTexture(&Txtopers);
		pers.setPosition(burbuja.getPosition().x + 670, burbuja.getPosition().y + 32);
		pers.setSize({ 12 , 10 });
		pers.scale(13, 13);

	}
	if (tipo == 3)
	{
		Txtopers.loadFromFile("recursos/fondos/bluehead.png");
		pers.setTexture(&Txtopers);
		pers.setPosition(burbuja.getPosition().x + 670, burbuja.getPosition().y + 32);
		pers.setSize({ 12 , 10 });
		pers.scale(13, 13);

	}

	_txt.setCharacterSize(15);
	_txt2.setCharacterSize(15);
}

void Dialogo::cambiarQuienHabla(int tipo)
{
	switch (tipo)
	{
	case 1:
		pers.setFillColor(sf::Color(255, 255, 255, 255));
		break;
	case 2:
		pers.setFillColor(sf::Color(255, 106, 255, 255));
		break;
	case 3:
		pers.setFillColor(sf::Color(99, 122, 254, 255));
		break;
	default:
		pers.setFillColor(sf::Color(255, 255, 255, 255));
	break;
	}
}

void Dialogo::updatee_e(float lapso)
{

}

void Dialogo::draw_enty(sf::RenderWindow& _w)
{
	if (desdibujar == true)
	{
		_w.draw(burbuja);
		_w.draw(pers);
		_w.draw(_txt);
		_w.draw(_txt2);
	}
}

sf::RectangleShape& Dialogo::getburbuja()
{
	return burbuja;
}

void Dialogo::cambiar_desdibujar()
{
	desdibujar = false;
}

Dialogo::~Dialogo()
{
	textburbj.~Texture();
}
