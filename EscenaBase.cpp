#include "EscenaBase.h"
#include "Entidad.h"
#include <iostream>
#include "tipos_fondo.h"
#include "SFML/audio.hpp"
using namespace std;
EscenaBase::EscenaBase()
{
}

void EscenaBase::updatee_es(float lapso)
{
	for (auto e : entidades) {
		e->updatee_e(lapso);
	}
	
	//eliminar
	for (auto b : borrar) {
		auto it = find(entidades.begin(), entidades.end(), b);
		if (it != entidades.end()) {
			entidades.erase(it);
		}
	}
}

void EscenaBase::draw_es(sf::RenderWindow& _w)
{
	for (auto e : entidades)
	{
		e->draw_enty(_w);
	}
	
}

void EscenaBase::add(Entidad* e)
{
	entidades.push_back(e);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << entidades.size();
	std::cout << std::endl << std::endl << std::endl;
}

void EscenaBase::remove(Entidad* e)
{
	borrar.push_back(e);
}

void EscenaBase::process_event(const sf::Event& e)
{

}

void EscenaBase::setFondo(TipoFondo fondo) {
	tipo = fondo;
}

void EscenaBase::newMusic() {
	musica = new sf::Music;
}
void EscenaBase::delMusic() {
	delete musica;
}
void EscenaBase::FileSelect(TipoFondo fondo) {
	switch (fondo) {
	case TipoFondo::CASA:
		getMusic()->openFromFile("recursos/audio/bensound-sadday-primercinematica.ogg");
		break;
	case TipoFondo::CIUDAD_1:
		getMusic()->openFromFile("recursos/audio/bensound-retrosoul-mapaciudad.ogg");
		break;
	case TipoFondo::CIUDAD_2:
		getMusic()->openFromFile("recursos/audio/bensound-allthat-campo.ogg");
		break;
	case TipoFondo::PLAYA:
		getMusic()->openFromFile("recursos/audio/bensound-onceagain-escenacarpa.ogg");
		break;
	case TipoFondo::CEMENTERIO:
		getMusic()->openFromFile("recursos/audio/demons-souls-cc-theme.wav");
		break;
	case TipoFondo::CASA2:
		getMusic()->openFromFile("recursos/audio/bensound-sadday-segundacinematica.wav");
		break;
	case TipoFondo::MAIN_MENU:
		getMusic()->openFromFile("recursos/audio/main-menu-ost.ogg");
		break;
	case TipoFondo::CASA_FINAL:
		getMusic()->openFromFile("recursos/audio/bensound-slowmotion-final.ogg");
		break;
		
	}
}