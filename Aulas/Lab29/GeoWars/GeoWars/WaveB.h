/**********************************************************************************
// WaveB (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Blue
//
**********************************************************************************/

#ifndef _GEOWARS_WAVEB_H_
#define _GEOWARS_WAVEB_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class WaveB : public Object
{
private:
    float pX, pY;           // posi��o dos inimigos 
    RandF posX;             // valor aleat�rio para posi��o X
    RandF posY;             // valor aleat�rio para posi��o Y
    RandF secs;             // valor aleat�rio de segundos
    Timer timer;            // medidor de tempo
    float delay;            // atraso para a pr�xima onda

public:
    WaveB();                // construtor
    ~WaveB();               // destrutor

    void Update();          // atualiza��o
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
