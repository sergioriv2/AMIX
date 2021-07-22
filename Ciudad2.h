#pragma once
#include "EscenaBase.h"
#include "Fondo.h"
#include "Personaje.h"
#include "Camara.h"
#include "bg_dec.h"
#include "Dialogo.h"
#include "item.h"
#include "mensaje.h"
#include <vector>

class Ciudad2 : public EscenaBase
{
private:
	Item* _it;
	Fondo* _obj;
	Personaje* personaje;
	Personaje* personaje_izq;
	Camara _camara;
	Dialogo* diag;
	//Decoracion del background
	bg_dec* _pdec;
	std::vector<bg_dec*> _objDec;

	//Decoracion del background
	Item* _pitem;
	std::vector<Item*> _objIt;
	mensaje* _msg;
	sf::Font fuente;
	sf::Clock clock;
	int dial;

public:
	Ciudad2();
	void iniDec();
	bool questcheckBlue(bool* items);
	void crear_item(TipoItem _t, sf::Vector2f pos);
	void crear_dec(tipo_dec _t, sf::Vector2f pos);
	void updatee_es(float lapso)override;
	void draw_es(sf::RenderWindow& _w)override;
	void crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);
	~Ciudad2() {
		delMusic();
	}
};

