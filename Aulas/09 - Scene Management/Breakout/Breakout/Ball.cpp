/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player * p)
{
	player = p;
	sprite = new Sprite("Resources/Ball.png");
	velX = 0.0f;
	velY = 0.0f;
	MoveTo(player->x , player->y - 30);
}

Ball::~Ball()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
	MoveTo(player->x, player->y-15);
	// Deslocar a bola
	//Translate(velX * gameTime, velY * gameTime);

	// Manter a bola dentro da janela
	if (x < 0)
		velX = -velX;
	if (x + sprite->Width() > window->Width())
		velX = -velX;

	if (y < 0)
		velY = -velY;
	if (y + sprite->Height() > window->Height())
		velY = -velY;
}

void Ball::Draw()
{
	sprite->Draw(x, y, z);
}


