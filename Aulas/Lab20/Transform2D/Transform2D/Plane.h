/**********************************************************************************
// Plane (Arquivo de Cabe�alho)
// 
// Cria��o:     24 Set 2012
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um avi�o
//
**********************************************************************************/

#ifndef _TRANSFORM2D_PLANE_H_
#define _TRANSFORM2D_PLANE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"         // um avi�o � um objeto do jogo 
#include "Sprite.h"         // uma avi�o usa um sprite
#include "Types.h"          // tipos espec�ficos do motor

// ---------------------------------------------------------------------------------

class Plane : public Object
{
private:
    Sprite * sprite;        // sprites do avi�o

public:
    Plane();                // construtor
    ~Plane();               // destrutor

    int Width();            // retorna largura do avi�o
    int Height();           // retorna altura do avi�o

    void Update();          // atualiza estado do avi�o
    void Draw();            // desenha avi�o
}; 

// ---------------------------------------------------------------------------------
// fun��es membro inline

inline int Plane::Width()
{ return sprite->Width(); }

// ---------------------------------------------------------------------------------

inline int Plane::Height()
{ return sprite->Height(); }

// ---------------------------------------------------------------------------------

#endif