#pragma once
#include "EscenaBase.h"
#include "Fondo.h"
#include "Personaje.h"
#include "Camara.h"

class Playa : public EscenaBase
{
private:
	Fondo* _obj;
	Personaje* personaje;
	Camara _camara;
public:
	Playa(float, float);
	Playa();

	void updatee_es(float lapso)override;
	void draw_es(sf::RenderWindow& _w)override;

	~Playa() {
		delMusic();
	}
};

