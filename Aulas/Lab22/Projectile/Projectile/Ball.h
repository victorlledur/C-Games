/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para uma bala de canh�o
//
**********************************************************************************/

#ifndef _PROJECTILE_BALL_H_
#define _PROJECTILE_BALL_H_

// --------------------------------------------------------------------------------

#include "Vector.h"                             // representa��o de vetor
#include "Object.h"                             // objetos do jogo
#include "Sprite.h"                             // desenho de sprites
#include "Cannon.h"                             // objeto canh�o

// --------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite * sprite;                            // sprite da bala
    Vector   speed;                             // velocidade da bala
    
public:
    static bool airResistance;                  // resist�ncia do ar

    Ball(Cannon * cannon);                      // construtor
    ~Ball();                                    // destrutor

    void Update();                              // atualiza��o 
    void Draw();                                // desenho
}; 

// ------------------------------------------------------------------------------

#endif