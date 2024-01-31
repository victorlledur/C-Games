/**********************************************************************************
// Ball (C�digo Fonte)
//
// Cria��o:     28 Jun 2019
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto Bal�o
//
**********************************************************************************/

#include "Balloons.h"
#include "Ball.h"
#include "Pop.h"    

// ---------------------------------------------------------------------------------

Ball::Ball(Image * img, TileSet * pop, Color tint) 
    : sprite(new Sprite(img)), 
      tiles(pop), 
      color(tint)
{
    BBox(new Circle(30.0f));
    vel = 100;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object* obj)
{
    // adiciona estouro do bal�o na cena
    Pop * pop = new Pop(tiles, color);
    pop->MoveTo(x, y);
    Balloons::scene->Add(pop, STATIC);

    // bal�o estourado
    Balloons::scene->Delete(this, STATIC);    
    Balloons::audio->Play(POP);    
    Balloons::popped++;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    // bal�o sobe com velocidade constante
    Translate(0, -vel * gameTime);

    // bal�o tem tamanho 64x128
    if (y < -64)
    {
        // bal�o perdido
        Balloons::scene->Delete();
        Balloons::lost++;
    }
}

// ---------------------------------------------------------------------------------