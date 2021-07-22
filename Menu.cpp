#include "Menu.h"
#include "Gameplay.h"
#include "EscenaInicial.h"
 

Menu::Menu() {

	fuente.loadFromFile("recursos/fuentes/Pixeled.ttf");
	
	texto.setFont(fuente);
	texto2.setFont(fuente);
	texto3.setFont(fuente);
	texto.setString("AMIX");
	texto2.setString("Presione ENTER para continuar..");
	texto3.setString("CONTROLES: A-IZQUIERDA / D-DERECHA / E-AGARRAR ITEM / W-SALTO / Q-INTERACCION");
	texto.setPosition(300.0f, 50.0f);
	texto2.setPosition(160.0f, 400);
	texto3.setPosition(50.0f, 570.0f);
	texto.setCharacterSize(70);
	texto2.setCharacterSize(20);
	texto3.setCharacterSize(12);
	texto.setFillColor(sf::Color::Red);
	texto2.setFillColor(sf::Color::Black);
	texto3.setFillColor(sf::Color::Black);
	
	texto4.setFont(fuente);
	texto4.setCharacterSize(15);
	texto4.setFillColor(sf::Color::Blue);
	texto4.setString("Creado por Facundo Rivas, Enzo Bogado y Sergio Rivera");
	texto4.setPosition(80.0f, 150.0f);
	//1er escena
	textfondo.loadFromFile("recursos/fondos/main-menu.png");
	fondo.setTexture(textfondo);
	fondo.setScale(1.0f, 1.0f);

	Menu::setFondo(TipoFondo::MAIN_MENU);
	//Musica
	Menu::newMusic();
	Menu::FileSelect(Menu::getFondo());
	Menu::getMusic()->play();
	Menu::getMusic()->setVolume(10);
	Menu::getMusic()->setLoop(true);
}
void Menu::cmd_m() {
	sf::Event ev;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		Menu::getMusic()->stop();
		Gameplay::getInstancia().cambiar_Escena(new EscenaInicial);
	}
}
void Menu::updatee_es(float lapso){
	cmd_m();
}
void Menu::draw_es(sf::RenderWindow& _w){
	_w.clear();
	_w.draw(fondo);
	_w.draw(texto);
	_w.draw(texto2);
	_w.draw(texto3);
	_w.draw(texto4);
	

	EscenaBase::draw_es(_w);
}
 