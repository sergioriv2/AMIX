#include <iostream>
#include "Cementerio.h"
#include "Gameplay.h"
#include "tipos_fondo.h"
#include "Ciudad2.h"
#include "Playa.h"
extern bool inv[10];

int pos_each3;

Cementerio::Cementerio(sf::Vector2f(pos))
{
	_obj = new Fondo(TipoFondo::CEMENTERIO);
	personaje = new Personaje({ pos });
	_msg = new mensaje;
	if (pos.x>=800)
	{
		personaje->quieto(-1, 5);
		personaje->getDrawn().setPosition(pos);
	}

	//system("cls");
	//std::cout << "INVENTARIO:" << std::endl;
	//for (int i = 0; i < 22; i++) std::cout << inv[i] << std::endl;

	personaje->getDrawn().setColor(sf::Color(29, 30, 29, 255));

	setFondo(TipoFondo::CEMENTERIO);
	//Musica
	Cementerio::newMusic();
	Cementerio::FileSelect(Cementerio::getFondo());
	Cementerio::getMusic()->play();
	Cementerio::getMusic()->setVolume(5);
	Cementerio::getMusic()->setLoop(true);
	
	add(_obj);

	if(!inv[4])crear_item(TipoItem::KUNAI, { 100, 405 });

	if (!inv[9])crear_item(TipoItem::CUCHILLO, { 500, 490 });

	add(_msg);
	add(personaje);
}

void Cementerio::crear_item(TipoItem _t, sf::Vector2f pos)
{
	_pitem = new Item(_t, pos);
	_objIt.push_back(_pitem);
	add(_pitem);
}

void Cementerio::updatee_es(float lapso)
{
	personaje->cmd();
	if (personaje->getDrawn().getPosition().y > 500) {
		personaje->quieto(personaje->getDrawn().getPosition().x, 500);
	}
	if (personaje->getDrawn().getPosition().x > 800) {
		Cementerio::getMusic()->stop();
		Gameplay::getInstancia().cambiar_Escena(new Playa());
	}
	if (personaje->getDrawn().getPosition().x < 0) {
		Cementerio::getMusic()->stop();
		Gameplay::getInstancia().cambiar_Escena(new Ciudad2());
	}
	
	for (auto e : _objIt)
	{
		if (e->collideWithItem(personaje) && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			e->getitem().setColor(sf::Color::Transparent);
			inv[e->getId()] = true;

			_msg->setPos(personaje->getUb());
			_msg->sel_mensaje(e->getId());

			remove(e);
		}
		else pos_each3++;
	}
	
	EscenaBase::updatee_es(lapso);
}

void Cementerio::draw_es(sf::RenderWindow& _w)
{
	_camara.getView().setCenter(440, 300);

	_w.setView(_camara.getView());

	EscenaBase::draw_es(_w);
}

Cementerio::~Cementerio()
{

}
