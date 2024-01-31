/**********************************************************************************
// Fireworks (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "Refinery.h"
#include "Fireworks.h"

// ---------------------------------------------------------------------------------

Fireworks::Fireworks()
{
    // configura gerador de part�culas
    Generator starmaker;
    starmaker.imgFile = "Resources/Star.png";   // arquivo de imagem
    starmaker.angle = RandAngle(mt);            // dire��o das estrelas
    starmaker.spread = 360.0f;                  // espalhamento em graus
    starmaker.lifetime = 2.0f;                  // tempo de vida (em segundos)
    starmaker.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
    starmaker.percentToDim = 0.6f;              // desaparece ap�s 60% da vida
    starmaker.minSpeed = 25.0f;                 // velocidade m�nima das part�culas
    starmaker.maxSpeed = 250.0f;                // velocidade m�xima das part�culas
    starmaker.color.r = RandColor(mt);          // cor aleat�ria para part�cula
    starmaker.color.g = RandColor(mt);          // cor aleat�ria para part�cula
    starmaker.color.b = RandColor(mt);          // cor aleat�ria para part�cula
    starmaker.color.a = 1.0f;                   // transpar�ncia da part�cula

    // cria sistema de part�culas
    starGen = new Particles(starmaker);

    // gera 50 part�culas na posi��o do mouse
    starGen->Generate(window->MouseX(), window->MouseY(), 50);
    type = FIREWORKS;
}

// ---------------------------------------------------------------------------------

Fireworks::~Fireworks()
{
    delete starGen;
}

// -------------------------------------------------------------------------------

void Fireworks::Update()
{
    // atualiza posi��o de cada part�cula
    starGen->Update(gameTime);

    // remove da cena quando todas as part�culas est�o inativas
    if (starGen->Inactive())
        Refinery::scene->Delete();
}

// -------------------------------------------------------------------------------