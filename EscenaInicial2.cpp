#include "EscenaInicial2.h"
#include "SFML/graphics.hpp"
#include "Gameplay.h"
#include "Playa.h"

EscenaInicial2::EscenaInicial2()
{
	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");

	Texto.setFont(fuente);
	Texto.setPosition(150.0f, 310.0f);
	Texto.setCharacterSize(12);


	//crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200), 0);

	//diag->getTxt().setPosition({ 60, 60 });
	//diag->getTxt2().setPosition({ 60, 100 });
	//diag->getTxt2().setFont(fuente);
	//diag->getTxt().setFont(fuente);
	//diag->cambiarQuienHabla(3);
	//diag->getTxt().setString(P_B1);

	//2da escena
	
	SpriteFondo.setColor(sf::Color::Black);

	Texto.setString("CUANDO LLEGAMOS, LOS PRIMEROS DIAS FUERON TRANQUILOS...");
	clock.restart();

	setFondo(TipoFondo::CASA2);
	//Musica
	EscenaInicial2::newMusic();
	EscenaInicial2::FileSelect(EscenaInicial2::getFondo());
	EscenaInicial2::getMusic()->play();
	EscenaInicial2::getMusic()->setVolume(5);
}

int dialogo2 = 0;

void EscenaInicial2::updatee_es(float lapso)
{
	if (clock.getElapsedTime().asSeconds() > 6)
	{
		dialogo2++;

		switch (dialogo2)
		{
		case 1:
			Texto.setPosition(170.0f, 310.0f);
			Texto.setString("NOS REIAMOS Y HACIAMOS LAS TIPICAS COSAS DE AMIGOS");
			break;
		case 2:
			Texto.setPosition(80.0f, 310.0f);
			Texto.setString("DE PRONTO NOS DIMOS CUENTA DE QUE ALGUNAS COSAS SE EMPEZARON A PERDER");
			break;
		case 3:
			Texto.setPosition(50.0f, 310.0f);
			Texto.setString("ENTRE B. Y P. SE CULPABAN YA QUE TENIAN ANTECEDENTES DE CHOREARSE SUS COSAS");
			break;
		case 4:
			Texto.setPosition(180.0f, 310.0f);
			Texto.setString("MAS COSAS SE PERDIAN Y LAS DICUSIONES ERAN PEORES");
			break;
		case 5:
			Texto.setPosition(110.0f, 310.0f);
			Texto.setString("HASTA QUE UNA NOCHE AGARRARON LAS POCAS COSAS QUE TENIAN"); 
			break;
		case 6:
			Texto.setPosition(240.0f, 310.0f);
			Texto.setString("Y SE ALEJARON POR CAMINOS SEPARADOS");
			break;
		case 7:
			Texto.setString("");	
			SpriteFondo.setColor(sf::Color::White);
			TextFondo.loadFromFile("recursos/cinematic/separados.png");
			SpriteFondo.setTexture(TextFondo);
			SpriteFondo.setScale(1.38f, 1.3f);
			crear_dialogo(sf::Vector2f(0, 0), sf::Vector2f(880, 200),2);
			diag->getTxt().setPosition({ 60, 60 });
			diag->getTxt2().setPosition({ 60, 100 });
			diag->getTxt2().setFont(fuente);
			diag->getTxt().setFont(fuente);

			diag->getTxt().setString("Y SABES QUE? ME VOY A MI CASA");
			diag->cambiarQuienHabla(3);
			break;
		case 8:
			diag->cambiar_desdibujar();
			SpriteFondo.setColor(sf::Color::Black);
			Texto.setPosition(270.0f, 310.0f);
			Texto.setString("NO PUEDO PERDER A MIS AMIGOS");
			break;
		case 9:	
			EscenaInicial2::getMusic()->stop();
			Gameplay::getInstancia().cambiar_Escena(new Playa());
			break;
		default:
			break;
		}

		clock.restart();
	}

	EscenaBase::updatee_es(lapso);
}

void EscenaInicial2::draw_es(sf::RenderWindow& _w)
{
	_w.clear();
	_w.draw(SpriteFondo);
	_w.draw(Nubetexto);
	_w.draw(Texto);
	EscenaBase::draw_es(_w);
}

void EscenaInicial2::crear_dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo)
{
	diag = new Dialogo(sf::Vector2f(pos), sf::Vector2f(size),tipo);
	add(diag);
}

EscenaInicial2::~EscenaInicial2()
{

}
