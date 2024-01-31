/**********************************************************************************
// AnimaMax (Arquivo de Cabe�alho)
//
// Cria��o:     10 Abr 2012
// Atualiza��o: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#ifndef _ANIMAMAX_H_
#define _ANIMAMAX_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

// ------------------------------------------------------------------------------

class AnimaMax : public Game
{
private:
    Sprite * text = nullptr;        // instru��es
    Sprite * backg = nullptr;       // sprite de fundo
    TileSet * tileset = nullptr;    // folha de sprites da explos�o
    bool keyCtrl = false;           // controla pressionamento de teclas 

    random_device rd;               // gerador n�o determin�stico
    mt19937 mt{ rd() };             // gerador mersenne twister

    // distribui��es uniformes nas faixas da largura e altura da janela
    uniform_real_distribution<float> randWidth { 0.0f, window->Width() - 1.0f };
    uniform_real_distribution<float> randHeight{ 0.0f, window->Height() - 1.0f };

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif