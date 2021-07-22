#pragma once
#include "EscenaBase.h"
#include "Fondo.h"
#include "Personaje.h"
#include "Camara.h"
#include "tipo_item.h"
#include "item.h"
#include "mensaje.h"

class Cementerio : public EscenaBase
{
private:
	Fondo* _obj;
	Personaje* personaje;

	Item* _pitem;
	std::vector<Item*> _objIt;
	Camara _camara;

	mensaje* _msg;
public:
	Cementerio(sf::Vector2f (pos));

	void updatee_es(float lapso)override;
	void draw_es(sf::RenderWindow& _w)override;
	void crear_item(TipoItem _t, sf::Vector2f pos);
	~Cementerio();
};

