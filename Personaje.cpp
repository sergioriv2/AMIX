#include "Personaje.h"
#include "SFML/Graphics.hpp"
#include <iostream>


Personaje::Personaje(const sf::Vector2f& pos)
{
	_texturaP.loadFromFile("recursos/personaje.png");

	_spriteP.setTexture(_texturaP);

	_spriteP.setPosition(pos);
	_spriteP.setScale(1, 1);
	_fps_sprite = 0;
	division.x = 4;
	division.y = 4;
	frame.y = 0;
	_estado = ESTADOS::QUIETO_DER;

	soundbuffer.loadFromFile("recursos/audio/paso.ogg");
	paso.setBuffer(soundbuffer);
	paso.setVolume(15);

}

void Personaje::cmd()
{
	if (_estado == ESTADOS::QUIETO || _estado == ESTADOS::QUIETO_DER || _estado == ESTADOS::QUIETO_IZQ)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			paso.play();
			frame.x = 2;
			_estado = ESTADOS::CAMINANDO_DER;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			paso.play();
			frame.x = 3;
			_estado = ESTADOS::CAMINANDO_IZQ;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_estado = ESTADOS::SALTO;
			_vel_salto = 18;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				_estado = ESTADOS::SALTO_DIAG_DER;
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				_estado = ESTADOS::SALTO_DIAG_IZQ;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			_estado = ESTADOS::AGARRAR;
		}
	}
}

void Personaje::updatee_e(float lapso)
{
	switch (_estado)
	{
	case QUIETO:
		break;
	case QUIETO_IZQ:
		frame.x = 3;
		frame.y = 0;
		_fps_sprite = 0;
		set_frame(_spriteP);
		break;
	case QUIETO_DER:
		frame.x = 2;
		frame.y = 0;
		_fps_sprite = 0;
		set_frame(_spriteP);
		break;
	case CAMINANDO_IZQ:
		
		if (_fps_sprite == 3)
		{
			frame.y++;
			//std::cout << frame.y;
			_fps_sprite = 0;
		}
		if (frame.y < 4)
		{
			_fps_sprite += 0.5f;
			_spriteP.move(-_sp_vel, 0);
			
		}
		else
		{
			frame.y = 0;
			_estado = ESTADOS::QUIETO_IZQ;
		}
		set_frame(_spriteP);
		break;

	case CAMINANDO_DER:
		if (_fps_sprite == 3)
		{
			frame.y++;
			_fps_sprite = 0;
		}
		if (frame.y < division.y)
		{
			_fps_sprite += 0.5f;
			_spriteP.move(_sp_vel, 0);
		}
		else
		{
			frame.y = 0;
			_estado = ESTADOS::QUIETO_DER;
		}
		set_frame(_spriteP);
		break;

	case SALTO:
		_vel_salto -= 1;
		_spriteP.move(0, -_vel_salto);

		break;
	case SALTO_DIAG_DER:
		frame.x = 2;
		frame.y = 1;
		set_frame(_spriteP);

		_vel_salto -= 1;
		_spriteP.move(4, -_vel_salto);

		if (_vel_salto <= -16)
		{
			frame.x = 2;
			frame.y = 0;
			set_frame(_spriteP);
		}
		break;
	case SALTO_DIAG_IZQ:
		frame.x = 3;
		frame.y = 1;
		set_frame(_spriteP);
		_vel_salto -= 1;
		_spriteP.move(-4, -_vel_salto);

		if (_vel_salto <= -16)
		{
			frame.x = 3;
			frame.y = 0;
			set_frame(_spriteP);
		}
		break;
	case AGARRAR:
		
		frame.x = 1;
		frame.y = 0;
		set_frame(_spriteP);
		quieto(_spriteP.getPosition().x, _spriteP.getPosition().y);
		break;
	}
	_ub = this->getDrawn().getPosition();
}
//PASO EL PERSONAJE Y MIDO LOS FRAMES
void Personaje::set_frame(sf::Sprite& pers)
{
	sf::IntRect pos(frame.x * (pers.getTexture()->getSize().x / (division.x)), frame.y * (pers.getTexture()->getSize().y / division.y-1), pers.getTexture()->getSize().x / (division.x), pers.getTexture()->getSize().y / (division.y));
	pers.setTextureRect(pos);
}

void Personaje::draw_enty(sf::RenderWindow& _w)
{
	_w.draw(_spriteP);
}
//COLISION CON PANTALLA (La llama escena juego)
void Personaje::quieto(float x, float y)
{
	if (x <= 0)
	{
		_estado = ESTADOS::QUIETO_IZQ;
	}
	else if (x >= 800)
	{
		_estado = ESTADOS::QUIETO_DER;
	}
	else {
		_estado = ESTADOS::QUIETO;
	}
	_vel_salto = 0;
	_spriteP.setPosition(x, y);
}

sf::Sprite& Personaje::getDrawn()
{
	return _spriteP;
}

sf::Vector2f& Personaje::getUb()
{
	return _ub;
}
