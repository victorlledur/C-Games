/**********************************************************************************
// FlyDemo (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra��o da intelig�ncia artificial de uma mosca
//
**********************************************************************************/

#ifndef _FLYDEMO_H_
#define _FLYDEMO_H_

// ------------------------------------------------------------------------------

#include "Game.h"                       // defini��o da classe jogo
#include "Sprite.h"                     // desenho de sprites
#include "Scene.h"                      // gerenciamento da cena
#include "Resources.h"                  // recursos utilizados no jogo

// ------------------------------------------------------------------------------

enum { TRASHCAN, FLY, MOUSE };          // identificadores dos objetos

// ------------------------------------------------------------------------------

class FlyDemo : public Game
{
private:
    Sprite * backg = nullptr;           // pano de fundo    
    bool viewBBox = false;              // visualiza��o da bounding box

public:
    static Scene * scene;               // gerenciador de cena

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif