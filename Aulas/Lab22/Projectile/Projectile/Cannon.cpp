/**********************************************************************************
// Cannon (C�digo Fonte)
// 
// Cria��o:     01 Out 2012
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o canh�o do jogo
//
**********************************************************************************/

#include "Cannon.h"
#include "Ball.h"
#include "Projectile.h"

// ---------------------------------------------------------------------------------

Cannon::Cannon()
{
    // controlador de jogo
    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    // inicializa sprite 
    sprite = new Sprite("Resources/Cannon.png");

    // posi��o inicial do canh�o
    MoveTo(45.0f, window->Height() - 120.0f);

    // define dire��o inicial do canh�o
    direction.RotateTo(45.0f);
    direction.ScaleTo(400.0f);

    // inicia controle do KeyTimed
    start = 0;
    keyCtrl = true;
    buttonCtrl = true;
    timer.Start();
}

// ---------------------------------------------------------------------------------

Cannon::~Cannon()
{
    delete sprite;
    delete gamepad;
}

// -------------------------------------------------------------------------------

bool Cannon::KeyTimed(int vkcode, float time)
{
    if (keyCtrl)
    {
        if (window->KeyDown(vkcode))
        {
            keyCtrl = false;
            start = timer.Stamp();
            return true;
        }
    }
    else if (timer.Elapsed(start, time))
    {
        keyCtrl = true;
    }

    return false;
}

// -------------------------------------------------------------------------------

bool Cannon::ButtonTimed(int button, float time)
{
    if (buttonCtrl)
    {
        if (gamepad->ButtonDown(button))
        {
            buttonCtrl = false;
            start = timer.Stamp();
            return true;
        }
    }
    else if (timer.Elapsed(start, time))
    {
        buttonCtrl = true;
    }

    return false;
}

// ---------------------------------------------------------------------------------

void Cannon::Rotate(float angle)
{ 
    float newAngle = direction.Angle() - angle;
    
    // rotaciona apenas dentro da faixa indicada
    if (newAngle >= 5 && newAngle < 86)
        direction.RotateTo(newAngle);
} 

// -------------------------------------------------------------------------------

void Cannon::Update()
{
    float delta = 30 * gameTime;

    // ---------------------------
    // Teclado
    // ---------------------------
    
    // rotaciona canh�o
    if (window->KeyDown(VK_RIGHT) || window->KeyDown(VK_DOWN))
        Rotate(delta);
    if (window->KeyDown(VK_LEFT) || window->KeyDown(VK_UP))
        Rotate(-delta);

    // dispara bola
    if (window->KeyPress(VK_SPACE))
    {        
        Projectile::scene->Add(new Ball(this), STATIC);
        Projectile::audio->Play(CANNON);
    }
    if (KeyTimed('T', 0.200f))
    {
        Projectile::scene->Add(new Ball(this), STATIC);
        Projectile::audio->Play(CANNON);
    }

    // ativa ou desativa resist�ncia do ar
    if (window->KeyPress('R'))
        Ball::airResistance = !Ball::airResistance;

    // ---------------------------
    // Controle
    // ---------------------------

    if (gamepadOn)
    {
        // atualiza estado do controle
        gamepad->UpdateState();

        // rotaciona canh�o
        Rotate(delta * gamepad->Axis(AxisX) * 0.001f);
        Rotate(delta * gamepad->Axis(AxisY) * 0.001f);

        // dispara bola
        if (gamepad->ButtonPress(SHOOT))
        {
            Projectile::scene->Add(new Ball(this), STATIC);
            Projectile::audio->Play(CANNON);            
        }
        if (ButtonTimed(NONSTOP, 0.200f))
        {
            Projectile::scene->Add(new Ball(this), STATIC);
            Projectile::audio->Play(CANNON);
        }

        // ativa ou desativa resist�ncia do ar
        if (gamepad->ButtonPress(AIR))
            Ball::airResistance = !Ball::airResistance;
    }
}

// -------------------------------------------------------------------------------

void Cannon::Draw()
{
    // desenha canh�o
    sprite->Draw(x, y, z, scale, -direction.Angle());

    // desenha texto 
    if (gamepadOn)
    {
        string msg { "A        Disparo       L Stick     Inclina��o           Resis. Ar      Back      Cont�nuo        B" };
        Projectile::font->Draw(window->CenterX() - 218.0f, window->Height() - 6.0f, msg, Color(0.65f, 0.65f, 0.65f, 1.0f));
    }
    else
    {
        string msg { "Espa�o     Disparo       Setas     Inclina��o           Resis. Ar         R        Cont�nuo        T" };
        Projectile::font->Draw(window->CenterX() - 232.0f, window->Height() - 6.0f, msg, Color(0.65f, 0.65f, 0.65f, 1.0f));
    }
}

// -------------------------------------------------------------------------------