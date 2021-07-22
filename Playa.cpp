#include "Playa.h"
#include "tipos_fondo.h"
#include "Gameplay.h"
#include "Ciudad1.h"
#include "Cementerio.h"

Playa::Playa(float x = 0, float y = 430)
{
	_obj = new Fondo(TipoFondo::PLAYA);
	personaje = new Personaje({ x, y });

	add(_obj);
	add(personaje);

	setFondo(TipoFondo::PLAYA);

}

Playa::Playa()
{
	_obj = new Fondo(TipoFondo::PLAYA);
	personaje = new Personaje({ 0, 430 });

	add(_obj);
	add(personaje);

}

void Playa::updatee_es(float lapso)
{
	personaje->cmd();

	//sf::Vector2f vc = personaje->getDrawn().getPosition();

	
	if (personaje->getDrawn().getPosition().y > 430) {
	
		personaje->quieto(personaje->getDrawn().getPosition().x, 430);
	}
	if (personaje->getDrawn().getPosition().x > 800) {

		Gameplay::getInstancia().cambiar_Escena(new Ciudad1());
	}
	if (personaje->getDrawn().getPosition().x < 0)
	{
		Gameplay::getInstancia().cambiar_Escena(new Cementerio({ 800,500 }));
	}
	EscenaBase::updatee_es(lapso);
}

void Playa::draw_es(sf::RenderWindow& _w)
{	
	_camara.getView().setCenter(440, 300);
	_w.setView(_camara.getView());

	EscenaBase::draw_es(_w);
}