#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Gameplay.h"
#include "Ciudad1.h"
#include "Personaje.h"
#include "bg_dec.h"
#include "playa.h"
#include "EscenaFinal.h"

extern bool inv[10];
extern bool quest[2];

int pos_each1 = 0;

bool winnerCheck(bool* quest);

bool flag_Cu2 = true;
bool flag2 = false;
int dial2 = 0;

const std::string W2 = "YA SABES QUE ES CLEPTOMANIACO";
const std::string B2 = "¡ ES UN LADRON !";
const std::string B2_2 = "LO SE, PERO QUE ME DEVUELVA MIS COSAS";

Ciudad1::Ciudad1()
{
	_obj = new Fondo();
	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");
	personaje = new Personaje({ -274, 460 });
	_msg = new mensaje;
	personaje_der = new Personaje({ 880, 460 });

	personaje_der->getDrawn().setColor(sf::Color::Magenta);
	personaje_der->quieto(-10, 500);
	personaje_der->getDrawn().setPosition(1250, 500);

	srand(time(static_cast<time_t*>(0)));
	float num, numy;

	add(_obj);

	iniDec();

	//Musica
	Ciudad1::newMusic();
	Ciudad1::FileSelect(Ciudad1::getFondo());
	Ciudad1::getMusic()->play();
	Ciudad1::getMusic()->setVolume(4);
	Ciudad1::getMusic()->setLoop(true);
	add(personaje);
	add(personaje_der);
	add(_msg);
}


void Ciudad1::iniDec()
{
	if (!inv[7]) crear_item(TipoItem::PERGAMINO, { 1083, 450 });
	crear_dec(tipo_dec::PIEDRA, { 703, 465 });
	crear_dec(tipo_dec::PIEDRA, { 1097, 433 });
	//ARBUSTOS
	if (!inv[8]) crear_item(TipoItem::BINOCULAR, { 482, 350 });
	crear_dec(tipo_dec::ARBUSTO, { -235, 460 });
	crear_dec(tipo_dec::ARBUSTO, { 453, 450 });
	crear_dec(tipo_dec::ARBUSTO, { 850, 430 });
	crear_dec(tipo_dec::ARBUSTO, { 1043, 450 });
	crear_dec(tipo_dec::ARBUSTO, { -50, 410 });
	//PIEDRAS
	if (!inv[2]) crear_item(TipoItem::COLLAR4, { -270, 436 });
	if (!inv[7]) crear_item(TipoItem::ANILLO, { 285, 436 });


	crear_dec(tipo_dec::PIEDRA, { -107,436 });
	crear_dec(tipo_dec::PIEDRA, { 301, 437 });
	crear_dec(tipo_dec::PIEDRA, { 60, 439 });

	//ARBOLES
	crear_dec(tipo_dec::ARBOL, { 200, 230 });
	crear_dec(tipo_dec::ARBOL, { 1100, 200 });
}



void Ciudad1::crear_dec(tipo_dec _t, sf::Vector2f pos)
{
	_pdec = new bg_dec(_t, pos);
	_objDec.push_back(_pdec);
	add(_pdec);
}
void Ciudad1::crear_item(TipoItem _t, sf::Vector2f pos)
{
	_pitem = new Item(_t, pos);
	_objIt.push_back(_pitem);
	add(_pitem);
}

void Ciudad1::updatee_es(float lapso)
{
	
	personaje->cmd();

	//Sigue al personaje, pero en la posicion y 500
	sf::Vector2f posCamara = personaje->getDrawn().getPosition();

	posCamara.y = 500.0f;
	//Fix para la camara 
	if (posCamara.x <= _obj->getTextura().getSize().x * 0.06) posCamara.x = _obj->getTextura().getSize().x * 0.06;
	else if (posCamara.x >= _obj->getTextura().getSize().x * 0.334) posCamara.x = _obj->getTextura().getSize().x * 0.334;


	if (personaje->getEstado() == SALTO || personaje->getEstado() == SALTO_DIAG_IZQ || personaje->getEstado() == SALTO_DIAG_DER)
	{
		posCamara.y = 300;
		_camara.getView().setCenter(posCamara);
	}
	else
	{
		posCamara.y -= 200.0f;
		_camara.getView().setCenter(posCamara);
	}

	_obj->getTextura().getSize().x* _obj->getFondo().getScale().x;


	//std::cout << "X: " << personaje->getUb().x;
	//std::cout << "\t\tY: " << personaje->getUb().y << std::endl;

	//Restricciones para el personaje


	if (personaje->getDrawn().getPosition().x < 1100) {
		if (questcheckPink(inv)) std::cout << "PRIMERA QUEST DONE";
	}

	else if (personaje->getDrawn().getPosition().x < 1100 && flag2 == false) {
		diag->cambiar_desdibujar();
		flag2 = true;
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
		else pos_each1++;
	}

	// colision con ventana del personaje
	if (personaje->getDrawn().getPosition().y > 460) {
		personaje->quieto(personaje->getDrawn().getPosition().x, 460);
	}
	if (personaje->getDrawn().getPosition().x > 1438) {
		personaje->quieto(1438, 500);
	}
	if (personaje->getDrawn().getPosition().x < -275) {
		Gameplay::getInstancia().cambiar_Escena(new Playa(800, 430));
		Ciudad1::getMusic()->stop();
	}
	/******************************************************************************/
	if (personaje->getDrawn().getPosition().x > 1100 && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) flag2 = true;
	else if (personaje->getDrawn().getPosition().x >= 1100)
	{
		questcheckPink(inv);
		if (quest[0] && quest[1]) {
			Ciudad1::getMusic()->stop();
			Gameplay::getInstancia().cambiar_Escena(new EscenaFinal);
		}
	}
	
	if (personaje->getDrawn().getPosition().x > 1100 && flag2 == true) {
		if (clock.getElapsedTime().asSeconds() > 4)
		{
			dial2++;
			if (dial2 > 1) diag->cambiar_desdibujar();

			crear_dialogo(sf::Vector2f(630, 0), sf::Vector2f(880, 200), 1);
			diag->getTxt().setPosition({ 700, 80 });
			diag->getTxt().setFont(fuente);
			switch (dial2)
			{
			case 1:
				diag->cambiarQuienHabla(2);
				diag->getTxt().setString(B2);
				break;
			case 2:
				diag->cambiarQuienHabla(1);
				diag->getTxt().setString(W2);
				break;

			case 3:
				diag->cambiarQuienHabla(2);
				diag->getTxt().setString(B2_2);
				break;

			}
			clock.restart();
		}
		if (dial2 > 3)
		{
			diag->cambiar_desdibujar();
			dial2 = 0;
			flag2 = false;
		}
		flag_Cu2 = false;
	}

	else if (personaje->getDrawn().getPosition().x < 1100 && flag_Cu2 == false) {
		diag->cambiar_desdibujar();
		flag_Cu2 = true;
		flag2 = false;
	}


	EscenaBase::updatee_es(lapso);
}

bool Ciudad1::questcheckPink(bool* items) {
	for (int i = 5; i < 10; i++) {
		if (!items[i]) { return false; }
	}
	quest[1] = true;
	return true;
}

void Ciudad1::draw_es(sf::RenderWindow& _w)
{
	_w.setView(_camara.getView());
	EscenaBase::draw_es(_w);
}

void Ciudad1::crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size), int tipo)
{
	if (flag2 == true)
	{
		diag = new Dialogo(sf::Vector2f(pos), sf::Vector2f(size), tipo);
		add(diag);
	}

}

Ciudad1::~Ciudad1()
{
	_objDec.clear();
	//_objDec.~vector();
	delMusic();
}


