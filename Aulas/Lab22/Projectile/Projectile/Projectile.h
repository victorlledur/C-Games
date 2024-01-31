/**********************************************************************************
// Projectile (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Out 2012
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Movimento de proj�til
//
**********************************************************************************/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Audio.h"
#include "Font.h"
#include "Resources.h"
#include "Cannon.h"     
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

enum Sounds {CANNON, SPLASH};

// ------------------------------------------------------------------------------

class Projectile : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    Sprite * base = nullptr;        // base do canh�o
    Sprite * infoBox = nullptr;     // caixa de informa��es
    Sprite * keyMap = nullptr;      // caixa para teclas de atalho    
    Cannon * cannon = nullptr;      // canh�o

    stringstream text;              // texto tempor�rio

public:
    static Scene * scene;           // cena do jogo
    static Audio * audio;           // sistema de �udio
    static Font  * font;            // fonte para texto

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif