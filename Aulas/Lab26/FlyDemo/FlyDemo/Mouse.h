/**********************************************************************************
// Mouse (Arquivo de Cabe�alho)
// 
// Cria��o:     06 Ago 2019
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Gerencia mouse na tela
//
**********************************************************************************/

#ifndef _FLYDEMO_MOUSE_H_
#define _FLYDEMO_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h"        

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();                // construtor
    ~Mouse();               // destrutor

    void Update();          // atualiza��o
    void Draw();            // desenho
}; 

// ---------------------------------------------------------------------------------

#endif