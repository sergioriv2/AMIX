#include "EscenaInicial.h"
#include "EscenaInicial2.h"
#include "SFML/graphics.hpp"
#include "Gameplay.h"
#include <iostream>

const std::string W1 = "AL FIN ESTAMOS EN VERANO, PODEMOS DISFRUTAR";
const std::string W1_2 = "DE NUESTRO TIEMPO LIBRE COMO QUERAMOS";

const std::string B1 = "CON TODO ESTO DE LA CUARENTENA Y LAS CLASES";
const std::string B1_2 = "VIRTUALES ME ESTRESE PERO YA ESTAMOS TRANQUI";

const std::string P1 = "BUENO YA QUE ESTAMOS LIBRES ¿QUE LES PARECE SI";
const std::string P1_2 = "VAMOS A LA CASA DE MI TIO EN LA COSTA UNOS DIAS?";

const std::string W2 = "DALE SI QUIEREN ARMAMOS UNA CARPITA EN LA COSTA";
const std::string W2_2 = "ASI NO ESTAMOS DENTRO DE LA CASA";

const std::string B2 = "POR MI SI, YO TENGO UNA CARPA GRANDE PARA LLEVAR";

const std::string P2 = "DESPUES SI QUIEREN EN UN RATO LO CHARLAMOS BIEN";

EscenaInicial::EscenaInicial()
{
	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");

	crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200),1);	

	diag->getTxt().setPosition({ 60, 60 });
	diag->getTxt().setFont(fuente);
	diag->getTxt().setString(W1);

	diag->getTxt2().setPosition({ 60, 100 });
	diag->getTxt2().setFont(fuente);
	diag->getTxt2().setString(W1_2);

	Texto.setFont(fuente);
	Texto.setString("20 DE DICIEMBRE 2020");
	Texto.setPosition(640, 500);
	Texto.setCharacterSize(12);
	Texto.setFillColor(sf::Color::Black);

	//1er escena
	TextFondo.loadFromFile("recursos/cinematic/juntos.png");
	SpriteFondo.setTexture(TextFondo);
	SpriteFondo.setScale(1.58f, 1.54f);

	clock.restart();
	clock2.restart();
	
	setFondo(TipoFondo::CASA);
	//Musica
	EscenaInicial::newMusic();
	EscenaInicial::FileSelect(EscenaInicial::getFondo());
	EscenaInicial::getMusic()->play();
	EscenaInicial::getMusic()->setVolume(5);

}
int dialogo = 0;

void EscenaInicial::updatee_es(float lapso)
{

	if (clock.getElapsedTime().asSeconds() > 6)
	{
		dialogo++;

		diag->cambiar_desdibujar();
		crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200),1);

		diag->getTxt().setPosition({ 60, 60 });	
		diag->getTxt2().setPosition({ 60, 100 });
		diag->getTxt2().setFont(fuente);
		diag->getTxt().setFont(fuente);
		switch (dialogo)
		{
		case 1:
			diag->cambiarQuienHabla(3);
			diag->getTxt().setString(B1);
			diag->getTxt2().setString(B1_2);
			break;
		case 2:
			diag->cambiarQuienHabla(2);
			diag->getTxt().setString(P1);
			diag->getTxt2().setString(P1_2);
			break;
		case 3:
			diag->cambiarQuienHabla(1);
			diag->getTxt().setString(W2);
			diag->getTxt2().setString(W2_2);
			break;
		case 4:
			diag->cambiarQuienHabla(3);
			diag->getTxt().setString(B2);
			break;
		case 5:
			diag->cambiarQuienHabla(2);
			diag->getTxt().setString(P2);
			break;
		default:
			EscenaInicial::getMusic()->stop();
			Gameplay::getInstancia().cambiar_Escena(new EscenaInicial2());
			break;
		}
		std::cout << dialogo << std::endl;
		clock.restart();
	}
}

void EscenaInicial::draw_es(sf::RenderWindow& _w)
{
	_w.clear();
	_w.draw(SpriteFondo);
	_w.draw(Nubetexto);
	_w.draw(Texto);
	EscenaBase::draw_es(_w);
}

void EscenaInicial::crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo)
{
	diag = new Dialogo(sf::Vector2f(pos), sf::Vector2f(size),tipo);
	add(diag);
}