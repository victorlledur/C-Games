/**********************************************************************************
// BackScroll (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Out 2012
// Atualiza��o: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Desenhando e movimentando um background maior que a janela
//
**********************************************************************************/

#ifndef _BACKSCROLL_H_
#define _BACKSCROLL_H_

// ------------------------------------------------------------------------------

#include "Resources.h"              // recursos utilizados no jogo (cursor, �cone, etc.) 
#include "Game.h"                   // defini��o da classe jogo
#include "Font.h"                   // fonte para exibi��o de texto
#include "Sprite.h"                 // defini��o dos sprites
#include "Background.h"             // pano de fundo
#include <sstream>                  // sa�da para strings
using std::stringstream;    

// ------------------------------------------------------------------------------

class BackScroll : public Game
{
private:
    Sprite * infoBox;               // caixa de informa��es
    Sprite * keyMap;                // teclas de atalho
    Font   * font;                  // fonte normal
    Font   * bold;                  // fonte negrito
    stringstream text;              // texto tempor�rio

    ViewPort viewport;              // �rea de visualiza��o
    Background * backg;             // pano de fundo
    float scrollSpeed;              // velocidade de scrolling

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif