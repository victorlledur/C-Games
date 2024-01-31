/**********************************************************************************
// Fly (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Simula o v�o aleat�rio de uma mosca
//
**********************************************************************************/

#ifndef _FLYDEMO_FLY_H_
#define _FLYDEMO_FLY_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Timer.h"
#include "Random.h"

// ---------------------------------------------------------------------------------

class Fly : public Object
{
private:
    Sprite * sprite;                // sprite da mosca
    Vector speed;                   // velocidade e dire��o
    Timer timer;                    // medidor do tempo de v�o
    RandF magnitude;                // valor de magnitude aleat�ria
    RandF angle;                    // valor de �ngulo aleat�rio    
    RandF secs;                     // valor de segundos aleat�rio
    float delay;                    // tempo para mudan�a de dire��o
    
public:
    Fly(Image * img);               // construtor    
    ~Fly();                         // destrutor
    
    void NewDirection();            // muda dire��o da mosca
    void Update();                  // atualiza��o
    void Draw();                    // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Fly::Draw()
{ sprite->Draw(x, y, Layer::UPPER, scale); }

// ---------------------------------------------------------------------------------


#endif