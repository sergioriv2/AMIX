#include "Ciudad2.h"
#include "Cementerio.h"
#include "tipos_fondo.h"
#include "Gameplay.h"
#include "Dialogo.h"
#include "EscenaFinal.h"
#include <iostream>
#include "item.h"
extern bool inv[10];
extern bool quest[2];

const std::string W1 = "VOY A ENCONTRARLOS \n ESTOY SEGURO QUE NO FUE UN ROBO \n LO MEJOR ES SERA LA PACIENCIA";

const std::string B1 = "¿QUE HACES ACA?, NO QUIERO HABLAR CON NADIE";
const std::string B1_2 = "Y MENOS SI NO ME DEVUELVEN MIS OBJETOS \n ..........";

float valor_y_c2 = 460;
bool flag_2C = false;
bool flag_C2 = true;
bool colision = true;


int pos_each2 = 0;

bool winnerCheck(bool* quest);

Ciudad2::Ciudad2()
{

	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");
	_obj = new Fondo(TipoFondo::CIUDAD_2);
	personaje = new Personaje({ 1438, valor_y_c2 });
	personaje->quieto(-10, 500);
	_msg = new mensaje;
	personaje->getDrawn().setPosition(1438, 500);
	personaje_izq = new Personaje({ -100, 460 });
	personaje_izq->getDrawn().setColor(sf::Color(99, 122, 254, 255));

	add(_obj);
	int dial = 0;
	iniDec();

	setFondo(TipoFondo::CIUDAD_2);
	//Musica
	Ciudad2::newMusic();
	Ciudad2::FileSelect(Ciudad2::getFondo());
	Ciudad2::getMusic()->play();
	Ciudad2::getMusic()->setVolume(4);
	Ciudad2::getMusic()->setLoop(true);
	//add(_it);
	add(personaje);
	add(personaje_izq);
	add(_msg);
}

void Ciudad2::iniDec()
{
	if (!inv[3]) crear_item(TipoItem::AMULETO, { 100, 295 });
	crear_dec(tipo_dec::ARBOL, { -180, 200 });

	if (!inv[6]) crear_item(TipoItem::LLAVE2, { 1013, 360 });

	crear_dec(tipo_dec::FAROL, { -235, 150 });
	crear_dec(tipo_dec::FAROL, { 165, 150 });
	crear_dec(tipo_dec::FAROL, { 565, 150 });
	crear_dec(tipo_dec::FAROL, { 965, 150 });
	crear_dec(tipo_dec::FAROL, { 1365, 150 });

	crear_dec(tipo_dec::BASURA1, { -15, 420 });
	crear_dec(tipo_dec::BASURA2, { 965, 420 });
	if (!inv[0]) crear_item(TipoItem::LIBRO5, { 1405, 460 });
	crear_dec(tipo_dec::BASURA3, { 1300, 420 });
	if (!inv[5]) crear_item(TipoItem::LLAVE1, { -275, 530 });

}

void Ciudad2::crear_item(TipoItem _t, sf::Vector2f pos)
{
	_pitem = new Item(_t, pos);
	_objIt.push_back(_pitem);
	add(_pitem);
}
void Ciudad2::crear_dec(tipo_dec _t, sf::Vector2f pos)
{
	_pdec = new bg_dec(_t, pos);
	_objDec.push_back(_pdec);
	add(_pdec);
}


void Ciudad2::updatee_es(float lapso)
{
	if (quest[0] && quest[1]) {
		Ciudad2::getMusic()->stop();
		Gameplay::getInstancia().cambiar_Escena(new EscenaFinal);
	}

	personaje->cmd();

	//Sigue al personaje, pero en la posicion y 500
	sf::Vector2f posCamara = personaje->getDrawn().getPosition();

	//	----------------------------------------------------------------
	//	CAMARA
	//

	posCamara.y = 500.0f;
	//Fix para la camara 
	if (posCamara.x <= _obj->getTextura().getSize().x * 0.06) posCamara.x =
		_obj->getTextura().getSize().x * 0.06;

	else if (posCamara.x >= _obj->getTextura().getSize().x * 0.334) posCamara.x =
		_obj->getTextura().getSize().x * 0.334;


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

	// ------------------------------------------------------------
	// PERSONAJE
	//

	_obj->getTextura().getSize().x* _obj->getFondo().getScale().x;

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
		else pos_each2++;
	}

	std::cout << "X: " << personaje->getUb().x;
	std::cout << "\t\tY: " << personaje->getUb().y << std::endl;

	/*****************************************************************************************/
	if (personaje->getDrawn().getPosition().y > 460) {
		personaje->quieto(personaje->getDrawn().getPosition().x, 460);
	}
	if (personaje->getDrawn().getPosition().x < -250) {
		personaje->quieto(-250, 460);
	}
	if (personaje->getDrawn().getPosition().x > 1438) {
		Gameplay::getInstancia().cambiar_Escena(new Cementerio({ 0, 500 }));
		Ciudad2::getMusic()->stop();

	}
	/******************************************************************************************/

	/******************************************************************************************/
	if (personaje->getDrawn().getPosition().x < 40)
	{
		questcheckBlue(inv);
		if (quest[0] && quest[1]) {
			Ciudad2::getMusic()->stop();
			Gameplay::getInstancia().cambiar_Escena(new EscenaFinal);
		}
	}

	flag_C2 = false;

	EscenaBase::updatee_es(lapso);
}

void Ciudad2::draw_es(sf::RenderWindow& _w)
{
	_w.setView(_camara.getView());
	EscenaBase::draw_es(_w);
}



bool Ciudad2::questcheckBlue(bool* items) {
	for (int i = 0; i < 5; i++) {
		if (!items[i]) { return false; }
	}
	quest[0] = true;
	return true;
}

void Ciudad2::crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size), int tipo)
{
	if (flag_C2 == true)
	{
		diag = new Dialogo(sf::Vector2f(pos), sf::Vector2f(size), tipo);
		add(diag);
	}
}
