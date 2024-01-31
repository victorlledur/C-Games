/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de uma explos�o
//
**********************************************************************************/

#ifndef _INERTIA_EXPLOSION_H_
#define _INERTIA_EXPLOSION_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // objetos do jogo
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Animation * anim;                   // anima��o

public:
    Explosion(TileSet * tiles);         // construtor
    ~Explosion();                       // destrutor

    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Explosion::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif