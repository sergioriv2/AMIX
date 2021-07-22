#pragma once
#include "entidad.h"
class Dialogo: public Entidad
{
private:
	sf::Text _txt;
	sf::Text _txt2;
	sf::Texture textburbj;
	sf::Texture Txtopers;
	sf::RectangleShape burbuja;
	sf::RectangleShape pers;
	bool desdibujar=true;
public:

	Dialogo(sf::Vector2f(pos), sf::Vector2f(size),int tipo);
	void cambiarQuienHabla(int tipo);
	void updatee_e(float lapso) override;
	void draw_enty(sf::RenderWindow& _w) override;
	sf::RectangleShape& getburbuja();
	sf::RectangleShape& getPers() { return pers; }
	sf::Text& getTxt() { return _txt; }
	sf::Text& getTxt2() { return _txt2; }
	void cambiar_desdibujar();
	~Dialogo();
	
};

