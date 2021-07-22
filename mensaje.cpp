#include "mensaje.h"

mensaje::mensaje()
{
	_texto.setCharacterSize(12);
	_colorPersonaje.setCharacterSize(12);	
	_fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");
	_colorPersonaje.setCharacterSize(11);

	_colorPersonaje.setFont(_fuente);
	_texto.setFont(_fuente);
}

void mensaje::setPos(sf::Vector2f pos)
{
	_texto.setPosition(pos.x - 30.0f, pos.y - 35.0f);
	_colorPersonaje.setPosition(pos.x - 30.0f, pos.y - 10.0f);
	if (pos.x <= -250)
	{
		_texto.setPosition(-210.0f, pos.y - 35.0f);
		_colorPersonaje.setPosition(-210.0f, pos.y - 10.0f);
	}
}

void mensaje::sel_mensaje(int posItem)
{
	_texto.setFillColor(sf::Color::White);
	std::string mensaje;
	std::string m2;
	switch (posItem)
	{
	case 0:
		mensaje = "AGARRASTE LIBRO!!";
		m2 = "LE PERTENECE A B.";
		_colorPersonaje.setFillColor(sf::Color::Blue);
		break;
	case 1:
		mensaje = "AGARRASTE UN ANILLO!!";
		m2 = "LE PERTENECE A B.";
		_colorPersonaje.setFillColor(sf::Color::Blue);
		break;
	case 2:
		mensaje = "AGARRASTE UN COLLAR!!";
		m2 = "LE PERTENECE A B.";
		_colorPersonaje.setFillColor(sf::Color::Blue);
		break;
	case 3:
		mensaje = "AGARRASTE UN AMULETO!!";
		m2 = "LE PERTENECE A B.";
		_colorPersonaje.setFillColor(sf::Color::Blue);
		break;
	case 4:
		mensaje = "AGARRASTE UN KUNAI!!";
		m2 = "LE PERTENECE A B.";
		_colorPersonaje.setFillColor(sf::Color::Blue);
		break;
	case 5:
		mensaje = "AGARRASTE UNA LLAVE!!";	
		m2 = "LE PERTENECE A P.";
		_colorPersonaje.setFillColor(sf::Color::Magenta);
		break;
	
	case 6:
		mensaje = "AGARRASTE UNA LLAVE!!";
		m2 = "LE PERTENECE A P.";
		_colorPersonaje.setFillColor(sf::Color::Magenta);
		break;
	case 7:
		mensaje = "AGARRASTE UN PERGAMINO!!";
		m2 = "LE PERTENECE A P.";
		_colorPersonaje.setFillColor(sf::Color::Magenta);
		break;
	case 8:
		mensaje = "AGARRASTE UN BINOCULAR!!";
		m2 = "LE PERTENECE A P.";
		_colorPersonaje.setFillColor(sf::Color::Magenta);
		break;
	case 9:
		mensaje = "AGARRASTE UN CUCHILLO!!";
		m2 = "LE PERTENECE A P.";
		_colorPersonaje.setFillColor(sf::Color::Magenta);
		break;
	default:
		mensaje = "";
		m2 = "";
		break;
	}

	_colorPersonaje.setOutlineColor(sf::Color(126, 126, 126, 255));
	_colorPersonaje.setOutlineThickness(1.0f);
	_colorPersonaje.setString(m2);
	_texto.setString(mensaje);
}

void mensaje::updatee_e(float a)
{
	_texto.move(0.5f, 0.0f);
	_colorPersonaje.move(0.5f, 0.0f);

	if (rel.getElapsedTime().asSeconds() > 3)
	{
		_colorPersonaje.setFillColor(sf::Color::Transparent);
		_colorPersonaje.setOutlineColor(sf::Color::Transparent);
		_texto.setFillColor(sf::Color::Transparent);
		rel.restart();
	}
}

void mensaje::draw_enty(sf::RenderWindow& w)
{
	w.draw(_texto);
	w.draw(_colorPersonaje);
}
