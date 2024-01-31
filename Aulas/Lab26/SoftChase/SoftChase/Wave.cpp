/**********************************************************************************
// Wave (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos
//
**********************************************************************************/

#include "Wave.h"
#include "SoftChase.h"
#include "Blue.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Wave::Wave() : posX(0, window->Width()), posY(0, window->Height()), secs(2.0f, 4.0f)
{
    // posi��o dos inimigos
    pX = posX.Rand();
    pY = posY.Rand();

    // atraso para a pr�xima onda 
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

Wave::~Wave()
{

}

// -------------------------------------------------------------------------------

void Wave::Update()
{
    // contador de inimigos
    static uint counter = 8;

    // se passou o tempo m�nimo entre ondas
    if (timer.Elapsed(delay) && Hud::enemies < 15)
    {
        if (counter > 0)
        {
            // toca som de nova onda
            SoftChase::audio->Play(SPAWN);

            // adiciona nova inimigo
            SoftChase::scene->Add(new Blue(pX, pY, SoftChase::player), MOVING);

            delay = 0.450f;
            timer.Start();
            --counter;
        }
        else
        {
            // nova posi��o do inimigo
            pX = posX.Rand();
            pY = posY.Rand();

            // nova onda
            ++Hud::waves;
            counter = 8;
            delay = secs.Rand();
            timer.Start();
        }
    }
}

// -------------------------------------------------------------------------------

void Wave::Draw()
{
    
}

// -------------------------------------------------------------------------------
