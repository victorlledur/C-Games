/**********************************************************************************
// Balloons (Arquivo de Cabe�alho)
// 
// Cria��o:     28 Out 2011
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de uso do mouse e teclado
//
**********************************************************************************/

#ifndef _BALLOONS_H_
#define _BALLOONS_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Scene.h"
#include "Audio.h"
#include "Font.h"
#include "Sprite.h"
#include "Timer.h"
#include "Resources.h"
#include <sstream>
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
using std::stringstream;

// ------------------------------------------------------------------------------

using Real = uniform_real_distribution<float>;

// ------------------------------------------------------------------------------

enum SoundIds {MUSIC, POP};

// ------------------------------------------------------------------------------

class Balloons : public Game
{
private:
    Sprite * backg = nullptr;               // plano de fundo
    Sprite * popBox = nullptr;              // fundo do placar
    Sprite * lostBox = nullptr;             // fundo do placar
    Sprite * infoBar = nullptr;             // barra de informa��es

    Image * ball = nullptr;                 // imagem do bal�o
    TileSet * tilesClick = nullptr;         // folha de sprite do click
    TileSet * tilesPop = nullptr;           // folha de sprite do estouro    
    
    Font * sysFont = nullptr;               // fonte do sistema
    Font * gameFont = nullptr;              // fonte do jogo

    Real randColor{ 0.0f, 1.0f };           // distribui��o para cor
    Real randWidth{ 32.0f, 1247.0f };       // distribui��o para largura (1280x800)
    Real randHeight{ 856.0f, 956.0f };      // distribui��o para altura (1280x800)

    random_device rd;                       // gerador aleat�rio n�o-determin�stico
    mt19937 mt{rd()};                       // gerador aleat�rio Mersenne Twister
    Timer timer;                            // controle do tempo
    stringstream text;                      // texto para exibi��o

    bool viewBBox = false;                  // visualiza bounding box

    float posX = 0.0f;                      // posi��o x do �ltimo bal�o
    float posY = 0.0f;                      // posi��o y do �ltimo bal�o

public:
    static Scene * scene;                   // cena do jogo
    static Audio * audio;                   // sistema de �udio

    static uint popped;                     // n�mero de bal�es estourados
    static uint lost;                       // n�mero de bal�es perdidos
    
    void Init();                            // inicializa��o
    void Update();                          // atualiza��o
    void Draw();                            // desenho
    void Finalize();                        // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif