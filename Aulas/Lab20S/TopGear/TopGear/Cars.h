/**********************************************************************************
// Cars (Arquivo de Cabe�alho)
//
// Cria��o:     14 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Carros advers�rios
//
**********************************************************************************/

#ifndef _TOPGEAR_CARS_H_
#define _TOPGEAR_CARS_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // uso de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Types.h"                              // tipos espec�ficos do motor
#include <random>                               // gerador de n�meros aleat�rios

// ---------------------------------------------------------------------------------

using std::uniform_int_distribution;
using std::random_device;
using std::mt19937;
using DistInt = uniform_int_distribution<int>;

// ---------------------------------------------------------------------------------

class Cars : public Object
{
private:
    Image * img;                                // imagem do carro branco
    Sprite * sprite;                            // sprite do carro branco

    float deltaX;                               // valor do deslocamento eixo X
    float deltaY;                               // valor do deslocamento eixo Y
    float& speed;                               // velocidade do carro

    random_device rd;                           // gerador n�o-determin�stico
    mt19937 mt{rd()};                           // gerador mersenne twister
    DistInt randPos{ 0, 2 };                    // distribui aleat�riamente

    float positions[3] = { 447, 480, 511 };     // posi��es iniciais no eixo X
    int lane;                                   // n�mero da faixa da pista em uso

public:
    Cars();                                     // construtor
    ~Cars();                                    // destrutor

    void MoveUp(float val);                     // move o carro em uma colis�o
    void Update();                              // atualiza estado do avi�o
    void Draw();                                // desenha avi�o
};

// ---------------------------------------------------------------------------------

#endif

