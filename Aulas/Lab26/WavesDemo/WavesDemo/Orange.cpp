/**********************************************************************************
// Orange (C�digo Fonte)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil�neo
//
**********************************************************************************/

#include "WavesDemo.h"
#include "Orange.h"
#include "Random.h" 

// ---------------------------------------------------------------------------------

Orange::Orange(float pX, float pY, float ang)
{
    sprite = new Sprite("Resources/Orange.png");
    BBox(new Circle(20.0f));

    // ajusta o vetor velocidade
    speed.RotateTo(ang);
    speed.ScaleTo(400);
    RotateTo(-speed.Angle());
    MoveTo(pX, pY);
    type = ORANGE;

    // configura��o do emissor de part�culas
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png";    // arquivo de imagem
    emitter.angle = speed.Angle() + 180;        // �ngulo base do emissor
    emitter.spread = 10;                        // espalhamento em graus
    emitter.lifetime = 0.4f;                    // tempo de vida em segundos
    emitter.frequency = 0.010f;                 // tempo entre gera��o de novas part�culas
    emitter.percentToDim = 0.8f;                // desaparece ap�s 60% da vida
    emitter.minSpeed = 100.0f;                  // velocidade m�nima das part�culas
    emitter.maxSpeed = 200.0f;                  // velocidade m�xima das part�culas
    emitter.color.r = 1.0f;                     // componente Red da part�cula 
    emitter.color.g = 0.5;                      // componente Green da part�cula 
    emitter.color.b = 0.0f;                     // componente Blue da part�cula 
    emitter.color.a = 1.0f;                     // transpar�ncia da part�cula

    // cria sistema de part�culas
    tail = new Particles(emitter);

    // incrementa contagem
    ++Hud::enemies;
}

// ---------------------------------------------------------------------------------

Orange::~Orange()
{
    delete sprite;
    delete tail;

    // decrementa contagem
    --Hud::enemies;
}

// -------------------------------------------------------------------------------

void Orange::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        WavesDemo::scene->Delete(obj, STATIC);
        WavesDemo::scene->Delete(this, MOVING);
        WavesDemo::audio->Play(EXPLODE);
    }
}

// -------------------------------------------------------------------------------

void Orange::Update()
{
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // ajusta �ngulo do vetor na dire��o oposta
    if (x < 0 || y < 0 || x > game->Width() || y > game->Height())
    {
        Rotate(180);
        speed.Rotate(180);        
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    }

    // atualiza calda da nave
    tail->Config().angle = speed.Angle();
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);
}

// ---------------------------------------------------------------------------------

void Orange::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------