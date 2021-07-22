#include "item.h"
#include "tipo_item.h"
#include "Personaje.h"
bool band = true;
int pos = 0;

Item::Item(TipoItem _t, sf::Vector2f pos)
{
	switch (_t)
	{
	case TipoItem::LIBRO5:
		_texitem.loadFromFile("recursos/libro5.png");
		_spritem.setTexture(_texitem);
		_spritem.setRotation(90);
		id = 0;
		break;
	case TipoItem::ANILLO:
		_texitem.loadFromFile("recursos/anillo.png");
		_spritem.setColor(sf::Color(29, 30, 29, 255));
		_spritem.setTexture(_texitem);
		id = 1;
		break;
	case TipoItem::COLLAR4:
		_texitem.loadFromFile("recursos/collar4.png");
		_spritem.setTexture(_texitem);
		id = 2;
		break;
	case TipoItem::AMULETO:
		_texitem.loadFromFile("recursos/amuleto.png");
		_spritem.setTexture(_texitem);
		_spritem.setRotation(-230);
		id = 3;
		break;
	case TipoItem::KUNAI:
		_texitem.loadFromFile("recursos/kunai.png");
		_spritem.setColor(sf::Color(29, 30, 29, 150));
		_spritem.setTexture(_texitem);
		id = 4;
		break;
	case TipoItem::LLAVE1:
		_texitem.loadFromFile("recursos/key.png");
		_spritem.setTexture(_texitem);
		_spritem.setColor(sf::Color(126, 126, 126, 240));
		_spritem.setRotation(-90);
		id = 5;
		break;
	case TipoItem::LLAVE2:
		_texitem.loadFromFile("recursos/llave2.png");
		_spritem.setRotation(-25);
		_spritem.setTexture(_texitem);
		id = 6;
		break;
	case TipoItem::PERGAMINO:
		_texitem.loadFromFile("recursos/pergamino.png");
		_spritem.setTexture(_texitem);
		id = 7;
		break;
	case TipoItem::BINOCULAR:
		_texitem.loadFromFile("recursos/binocular.png");
		_spritem.setRotation(120);
		_spritem.setTexture(_texitem);
		id = 8;
		break;
	case TipoItem::CUCHILLO:
		_texitem.loadFromFile("recursos/cuchillo.png");
		_spritem.setTexture(_texitem);
		_spritem.setColor(sf::Color(29, 30, 29, 150));
		_spritem.setRotation(180);
		id = 9;
		break;
	default:
		break;
	}
	_spritem.setPosition(pos);
}
int Item::getId()
{
	return id;
}
void Item::updatee_e(float lapso)
{

}
void Item::draw_enty(sf::RenderWindow& _w)
{
	_w.draw(_spritem);
}

bool Item::collideWithItem(Personaje* perso)
{

	sf::FloatRect charRect = perso->getDrawn().getGlobalBounds();
	sf::FloatRect camRect = getitem().getGlobalBounds();

	return camRect.intersects(charRect);
}

sf::Sprite& Item::getitem()
{
	return _spritem;
}

Item::~Item()
{

}
