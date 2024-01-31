/**********************************************************************************
// Debris (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // objetos do jogo
#include "Animation.h"                      // anima��o de sprites

// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
    Animation * anim;                       // anima��o

public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualiza��o
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Debris::Draw()
{ anim->Draw(x, y, Layer::MIDDLE); }

// ---------------------------------------------------------------------------------

#endif