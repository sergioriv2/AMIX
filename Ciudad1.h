#pragma once

#include "tipos_fondo.h"
#include "tipo_item.h"
#include "Fondo.h"
#include "EscenaBase.h"
#include "Personaje.h"
#include "Dialogo.h"
#include "Camara.h"
#include "bg_dec.h"
#include "item.h"
#include "mensaje.h"
#include <vector>

class Ciudad1 : public EscenaBase
{
private:
	Fondo* _obj;

	Personaje* personaje;
	Personaje* personaje_izq;
	Personaje* personaje_der;

	Dialogo* diag;
	sf::Font fuente;


	//Decoracion del background
	bg_dec* _pdec;
	std::vector<bg_dec*> _objDec;
	mensaje* _msg;

	Item* _pitem;
	std::vector<Item*> _objIt;
	sf::Clock clock;
	Camara _camara;
public:
	Ciudad1();

	void iniDec();
	bool questcheckPink(bool* items);
	void crear_dec(tipo_dec _t, sf::Vector2f pos);
	void crear_item(TipoItem _t, sf::Vector2f pos);
	void updatee_es(float lapso)override;
	void draw_es(sf::RenderWindow& _w)override;
	void crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);

	~Ciudad1();
};

