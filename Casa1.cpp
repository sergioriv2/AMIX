#include "Casa1.h"
#include "tipos_fondo.h"
Casa1::Casa1()
{
	_obj = new Fondo(TipoFondo::CASA);
	personaje = new Personaje({ 50, 400 });
	add(_obj);
	add(personaje);
}

void Casa1::updatee_es(float lapso)
{
	personaje->cmd();
	EscenaBase::updatee_es(lapso);

}

void Casa1::draw_es(sf::RenderWindow& _w)
{
	EscenaBase::draw_es(_w);
}
