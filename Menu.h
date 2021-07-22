#pragma once
#include <SFML/Graphics.hpp>
#include "EscenaBase.h"
 
class Menu :
    public EscenaBase
{
private:
    sf::RectangleShape botones;
    sf::Text texto;
    sf::Text texto2;
    sf::Text texto3;
    sf::Text texto4;
    sf::Font fuente;
    sf::Sprite fondo;
    sf::Texture textfondo;
 
public:
    Menu();
    void updatee_es(float lapso);
    void draw_es(sf::RenderWindow& _w);
    void cmd_m();
};

