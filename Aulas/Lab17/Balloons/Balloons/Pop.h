/**********************************************************************************
// Pop (Arquivo de Cabe�alho)
// 
// Cria��o:     29 Jun 2019
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Estouro do Bal�o
//
**********************************************************************************/

#ifndef _BALLOONS_POP_H_
#define _BALLOONS_POP_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "TileSet.h"                    // folha de sprites para a anima��o
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Pop : public Object
{
private:
    Animation * anim;                   // anima��o da explos�o
    Color color;                        // cor do bal�o estourado

public:
    Pop(TileSet * tiles, Color tint);   // construtor
    ~Pop();                             // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Pop::Draw()
{ anim->Draw(x, y, z, color); }

// ---------------------------------------------------------------------------------

#endif