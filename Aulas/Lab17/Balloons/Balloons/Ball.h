/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     28 Jun 2019
// Atualiza��o: 22 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto Bal�o
//
**********************************************************************************/

#ifndef _BALLOONS_BALL_H_
#define _BALLOONS_BALL_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de um objeto
#include "Sprite.h"                                     // desenho de sprites
#include "TileSet.h"                                    // folha de sprites para a anima��o
#include "Animation.h"                                  // anima��o de sprites


// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite * sprite;                                    // sprite do bal�o
    TileSet * tiles;                                    // quadros do estouro do bal�o
    Color color;                                        // cor do bal�o
    float vel;                                          // velocidade para subir

public:
    Ball(Image * img, TileSet * pop, Color tint);       // construtor
    ~Ball();                                            // destrutor

    void OnCollision(Object* obj);                      // resolu��o da colis�o
    void Update();                                      // atualiza��o do objeto
    void Draw();                                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Ball::Draw()
{ sprite->Draw(x, y, z, 1.0f, 0.0f, color); }

// ---------------------------------------------------------------------------------

#endif
