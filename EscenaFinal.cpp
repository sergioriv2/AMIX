#include "EscenaFinal.h"
#include "EscenaInicial2.h"
#include "Gameplay.h"
#include "Menu.h"

#include <iostream>

const std::string W1 = "ME ALEGRA VOLVER A JUNTARME CON USTEDES";

const std::string B1 = "PERDON POR HABER SOSPECHADO..";

const std::string P1 = "LO MISMO DIGO..";

EscenaFinal::EscenaFinal() {

	
	camara.reset(sf::FloatRect(0, 0, 880, 600));

	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");

	crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200),2);

	diag->cambiarQuienHabla(3);
	diag->getTxt().setPosition({ 60,60 });
	diag->getTxt().setFont(fuente);
	diag->getTxt().setString(B1);

	Texto.setFont(fuente);
	Texto.setString("21 DE DICIEMBRE 2020");
	Texto.setPosition(640, 500);
	Texto.setCharacterSize(12);
	Texto.setFillColor(sf::Color::Black);

	textfondo.loadFromFile("recursos/cinematic/good-ending.png");
	
	
	fondo.setTexture(textfondo);
	fondo.setScale(1.58f, 1.54f);

	clock.restart();
	setFondo(TipoFondo::CASA_FINAL);

	//Musica
	EscenaFinal::newMusic();
	EscenaFinal::FileSelect(EscenaFinal::getFondo());
	EscenaFinal::getMusic()->play();
	EscenaFinal::getMusic()->setVolume(5);
	EscenaFinal::getMusic()->setLoop(true);
}
void EscenaFinal::updatee_es(float lapso)
{
	if(clock.getElapsedTime().asSeconds()>5){
	dialogo2++;
	diag->cambiar_desdibujar();
	crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200),1);

	switch (dialogo2) {
	case 1:
		diag->cambiarQuienHabla(2);
		diag->getTxt().setPosition({ 60,60 });
		diag->getTxt().setFont(fuente);
		diag->getTxt().setString(P1);
		break;
	case 2:
		diag->cambiarQuienHabla(1);
		diag->getTxt().setPosition({ 60,60 });
		diag->getTxt().setFont(fuente);
		diag->getTxt().setString(W1);
		break;
	case 3:
		diag->cambiar_desdibujar();
		fondo.setColor(sf::Color::Black);
		Texto.setCharacterSize(30);
		Texto.setFillColor(sf::Color::White);
		Texto.setPosition(50, 50);
		Texto.setString("Gracias por jugar!");
		break;
	case 4:
		diag->cambiar_desdibujar();
		Texto.setCharacterSize(10);
		Texto.setString("Creado por: Facundo Rivas & Enzo Bogado & Sergio Rivera");
		break;
	default:
		diag->cambiar_desdibujar();
		EscenaFinal::getMusic()->stop();
		Gameplay::getInstancia().cambiar_Escena(new Menu());

		break;
		}
	clock.restart();
	}
}

void EscenaFinal::crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo)
{
	diag = new Dialogo(sf::Vector2f(pos), sf::Vector2f(size),tipo);
	add(diag);
}

void EscenaFinal::draw_es(sf::RenderWindow& _w) {
	_w.setView(camara);
	_w.clear();
	_w.draw(fondo);
	_w.draw(Texto);

	EscenaBase::draw_es(_w);
}