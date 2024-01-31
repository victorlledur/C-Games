/**********************************************************************************
// Cannon (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Out 2012
// Atualiza��o: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o canh�o do jogo
//
**********************************************************************************/

#ifndef _PROJECTILE_CANNON_H_
#define _PROJECTILE_CANNON_H_

// ---------------------------------------------------------------------------------

#include "Vector.h"                             // representa��o de vetor
#include "Object.h"                             // representa��o de objetos 
#include "Sprite.h"                             // desenho de sprites
#include "Controller.h"                         // leitura do controle
#include "Types.h"                              // tipos espec�ficos da engine
#include "Timer.h"                              // medi��o de tempo

// ---------------------------------------------------------------------------------

enum ButtonMapping { SHOOT = 0, NONSTOP = 1, AIR = 6 };

// ---------------------------------------------------------------------------------

class Cannon : public Object
{
private:
    Sprite * sprite;                            // sprite do canh�o
    Controller * gamepad;                       // entrada por controle
    bool gamepadOn;                             // controle conectado

    Timer timer;                                // medidor de tempo
    llong start;                                // marca��o de in�cio do tempo
    bool keyCtrl;                               // estado de libera��o da tecla
    bool buttonCtrl;                            // estado de libera��o do bot�o
    
public:
    Vector direction;                           // dire��o do canh�o

    Cannon();                                   // construtor
    ~Cannon();                                  // destrutor

    bool KeyTimed(int vkcode, float time);      // controle de pressionamento por tempo 
    bool ButtonTimed(int button, float time);   // controle de pressionamento por tempo 
    
    void Rotate(float angle);                   // sobrescreve rota��o
    void Update();                              // atualiza��o
    void Draw();                                // desenho
}; 

// ---------------------------------------------------------------------------------

#endif