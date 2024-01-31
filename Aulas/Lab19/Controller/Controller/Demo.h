/**********************************************************************************
// Demo (Arquivo de Cabe�alho)
// 
// Cria��o:     09 Nov 2011
// Atualiza��o: 30 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de uso da classe Controller
//
**********************************************************************************/

#ifndef _CONTROLLER_DEMO_H_
#define _CONTROLLER_DEMO_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Controller.h"
#include "Resources.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class Demo : public Game
{
private:
    Controller * gamepad = nullptr;     // controle de jogo

    Sprite * backg = nullptr;           // pano de fundo
    Sprite * overlay = nullptr;         // pano de fundo sobreposto
    Sprite * xboxOver = nullptr;        // pano de fundo sobreposto
    Sprite * xbox360 = nullptr;         // desenho do controle do 360
    Sprite * box = nullptr;             // pequena caixa

    Sprite * A = nullptr;               // desenho do bot�o A
    Sprite * B = nullptr;               // desenho do bot�o B
    Sprite * X = nullptr;               // desenho do bot�o X
    Sprite * Y = nullptr;               // desenho do bot�o Y

    Sprite * RB = nullptr;              // desenho do bot�o RB
    Sprite * LB = nullptr;              // desenho do bot�o LB
    Sprite * RT = nullptr;              // desenho do bot�o RT
    Sprite * LT = nullptr;              // desenho do bot�o LT

    Sprite * Start = nullptr;           // desenho do bot�o Start
    Sprite * Back = nullptr;            // desenho do bot�o Back
    Sprite * LThumb = nullptr;          // desenho do bot�o Left Thumb
    Sprite * RThumb = nullptr;          // desenho do bot�o Right Thumb

    Sprite * LStick = nullptr;          // desenho do anal�gico esquerdo
    Sprite * RStick = nullptr;          // desenho do anal�gico direito
    Sprite * DpadR = nullptr;           // desenho do Dpad Direita
    Sprite * DpadL = nullptr;           // desenho do Dpad Esquerda
    Sprite * DpadU = nullptr;           // desenho do Dpad Cima
    Sprite * DpadD = nullptr;           // desenho do Dpad Baixo
    
    Sprite * P1 = nullptr;              // indicativo de Player 1 
    Sprite * P2 = nullptr;              // indicativo de Player 2 
    Sprite * P3 = nullptr;              // indicativo de Player 3 
    Sprite * P4 = nullptr;              // indicativo de Player 4

    Font * gameFont = nullptr;          // fonte do jogo
    Font * sysFont = nullptr;           // fonte do sistema

    bool controllerOn = false;          // controle directinput ativado
    bool xboxOn = false;                // controle xinput ativado
    
    uint xboxPlayer = PLAYER1;          // controle Xbox ativo            

    float boxX = 0.0f;                  // posi��o X da caixa
    float boxY = 0.0f;                  // posi��o Y da caixa

    stringstream text;                  // texto tempor�rio

public:
    void Init();                        // inicializa jogo
    void Update();                      // atualiza l�gica do jogo
    void Draw();                        // desenha jogo
    void Finalize();                    // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif