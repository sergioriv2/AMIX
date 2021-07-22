#include <SFML/Graphics.hpp>
#include "Gameplay.h"
#include "Ciudad1.h"
#include "Playa.h"
#include "EscenaInicial.h"
#include "EscenaFinal.h"
#include "Ciudad2.h"
#include "Casa1.h"
#include "item.h"
#include "Menu.h"
#include <time.h>
#include <iostream>

bool inv[10] = {};
bool quest[2] = {};

sf::Texture textura[5];

bool winnerCheck(bool* quest);

int main()
{
    //semilla random
    srand(time(static_cast<time_t*>(0)));
    //primer escena
    EscenaBase* escena = new Menu;
    //pantalla y escena
    Gameplay& g = Gameplay::create(sf::VideoMode(880, 600), escena, "AMIX");
    //empieza la cola de eventos
    g.run();

    return 0;
}

bool winnerCheck(bool* quest) {
    if (quest[0] && quest[1]) {
        Gameplay::getInstancia().cambiar_Escena(new EscenaFinal);

    }
    return false;
}