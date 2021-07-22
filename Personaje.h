#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entidad.h"

enum ESTADOS {
	QUIETO,
	QUIETO_IZQ,
	QUIETO_DER,
	CAMINANDO_IZQ,
	CAMINANDO_DER,
	SALTO,
	SALTO_DIAG_DER,
	SALTO_DIAG_IZQ,
	AGARRAR
};

class Personaje : public Entidad {
private:
	sf::Texture _texturaP;
	sf::Sprite _spriteP;
	ESTADOS _estado;
	const float _sp_vel = 4;
	float _vel_salto = 0;
	sf::Vector2i division;
	sf::Vector2i frame;
	float _fps_sprite;
	sf::SoundBuffer soundbuffer;
	sf::Sound paso;
	
	//Coordenadas del pj
	sf::Vector2f _ub;
public:
	//CONSTRUCTOR
	Personaje(const sf::Vector2f& pos);

	void cmd();

	ESTADOS getEstado() { return _estado; }
	void updatee_e(float lapso) override;
	void draw_enty(sf::RenderWindow& _w) override;
	void quieto(float x, float y);
	void set_frame(sf::Sprite& pers);

	sf::Sprite& getDrawn();
	sf::Vector2f& getUb();
};

