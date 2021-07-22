#pragma once
#include "entidad.h"
#include "tipo_item.h"
#include "Personaje.h"
class Item :public Entidad
{
private:
	Personaje* PItem;
	sf::Sprite _spritem;
	sf::Texture _texitem;
	sf::Vector2f cordsItem;
	int id;
public:
	Item(TipoItem _t, sf::Vector2f pos);
	int getId();
	bool getDrawable();
	void updatee_e(float lapso)override;
	void draw_enty(sf::RenderWindow& _w)override;
	bool collideWithItem(Personaje* perso);
	sf::Sprite& getitem();

	~Item();
};

