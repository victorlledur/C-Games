/**********************************************************************************
// Inertia (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Mar 2013
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Movimenta��o por aplica��o de um vetor For�a
//
**********************************************************************************/

#ifndef _INERTIA_H_
#define _INERTIA_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Audio.h"
#include "Font.h"
#include "Resources.h"
#include "Ship.h"    
#include "Missile.h" 
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

enum Sounds {JETUP, LOOPUP, JETDOWN, LOOPDOWN, FIRE, EXPLOSION};

// ------------------------------------------------------------------------------

class Inertia : public Game
{
private:
    Sprite * backg = nullptr;        // pano de fundo
    Sprite * keyMap = nullptr;      // caixa para teclas de atalho    
    Ship   * ship = nullptr;        // nave espacial
    Font   * font = nullptr;        // exibi��o de texto
    Font   * bold = nullptr;        // exibi��o de texto
    stringstream text;              // gera��o de texto

public:
    static TileSet * exploSet;      // tileset da explos�o
    static Scene * scene;           // cena do jogo
    static Audio * audio;           // sistema de �udio

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif