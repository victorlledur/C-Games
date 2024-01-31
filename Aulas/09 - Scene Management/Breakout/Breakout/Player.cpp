/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------


Player::Player()
{
	sprite = new Sprite("Resources\\Player.png");
	vel = 300.0f;
	MoveTo(window->CenterX() - sprite->Width() / 2, window->Height() - 40);
}

Player::~Player()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// Deslocando player
	if (window->KeyDown(VK_LEFT))
		Translate(-vel * gameTime, 0);
	if (window->KeyDown(VK_RIGHT))
		Translate(vel * gameTime, 0);

	// Manter player dentro da janela
	if (x < 0)
		MoveTo(0, y);
	if (x + sprite->Width() > window->Width())
		MoveTo(window->Width() - sprite->Width(), y);
}

void Player::Draw()
{
	sprite->Draw(x, y, z);
}
