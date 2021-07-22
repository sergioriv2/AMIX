#pragma once
#include "EscenaBase.h"
#include "Personaje.h"
#include "Camara.h"
#include "Fondo.h"

class Casa1 :public EscenaBase
{

private:
	Fondo* _obj;
	Personaje* personaje;
	Camara _camara;
public:
	Casa1();

	void updatee_es(float lapso)override;
	void draw_es(sf::RenderWindow& _w)override;

	~Casa1();
};

