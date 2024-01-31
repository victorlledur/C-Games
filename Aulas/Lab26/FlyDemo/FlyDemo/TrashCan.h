/**********************************************************************************
// TrashCan (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Lixeira
//
**********************************************************************************/

#ifndef _FLYDEMO_TRASHCAN_H_
#define _FLYDEMO_TRASHCAN_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Image.h"
#include "Sprite.h"
#include "Types.h"        

// ---------------------------------------------------------------------------------

class TrashCan : public Object
{
private:
    const int maxFlies = 50;            // n�mero m�ximo de moscas
    Image * flyImg;                     // imagem da mosca
    Sprite * cover;                     // tampa da lata de lixo
    Sprite * message;                   // mensagem de conscientiza��o
    Sprite * warning;                   // indicativo de aten��o
    float rFactor;                      // fator de rota��o
    bool openCover;                     // estado da lixeira
    

public:
    TrashCan();                         // construtor
    ~TrashCan();                        // destrutor

    void OnCollision(Object* obj);      // resolu��o de colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------

#endif
