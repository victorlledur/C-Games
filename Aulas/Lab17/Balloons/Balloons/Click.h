/**********************************************************************************
// Click (Arquivo de Cabe�alho)
//
// Cria��o:     29 Jun 2019
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Click do Mouse
//
**********************************************************************************/

#ifndef _BALLOONS_CLICK_H_
#define _BALLOONS_CLICK_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "TileSet.h"                    // folha de sprites para a anima��o
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Click : public Object
{
private:
    Animation * anim;                   // anima��o do click

public:
    Click(TileSet * tiles);             // construtor
    ~Click();                           // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Click::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif