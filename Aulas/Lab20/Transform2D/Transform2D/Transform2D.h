/**********************************************************************************
// Transform2D (Arquivo de Cabe�alho)
//
// Cria��o:     11 Nov 2011
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Teste de transforma��es - Transla��o, Rota��o e Escala
//
**********************************************************************************/

#ifndef _TRANSFORM2D_H_
#define _TRANSFORM2D_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Controller.h"
#include "Resources.h"
#include "Plane.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

enum ButtonMapping { DPAD = 0, START = 7};

// ------------------------------------------------------------------------------

class Transform2D : public Game
{
private:
    Controller * gamepad = nullptr;     // suporte a controle
    bool controllerOn = false;          // controle conectado

    Sprite * backg = nullptr;           // pano de fundo
    Sprite * infoBox = nullptr;         // caixa de informa��es
    Sprite * keyMap = nullptr;          // caixa para teclas de atalho
    Font * sysFont = nullptr;           // fonte do sistema

    Plane * plane = nullptr;            // objeto avi�o

    float backgScale = 0.0f;            // escala do pano de fundo
    stringstream text;                  // texto tempor�rio

public:
    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif