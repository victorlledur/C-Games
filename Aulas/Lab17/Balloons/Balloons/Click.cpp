/**********************************************************************************
// Click (C�digo Fonte)
//
// Cria��o:     29 Jun 2019
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Click do Mouse
//
**********************************************************************************/

#include "Click.h"
#include "Balloons.h"

// ---------------------------------------------------------------------------------

Click::Click(TileSet * tiles)
{
    anim = new Animation(tiles, 0.030f, false);
    BBox(new Point());
}

// ---------------------------------------------------------------------------------

Click::~Click()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Click::Update()
{
    // segue a posi��o do mouse
    MoveTo(window->MouseX(), window->MouseY());
    
    // atualiza a anima��o
    anim->NextFrame();
    if (anim->Inactive())
        Balloons::scene->Delete();
}

// ---------------------------------------------------------------------------------