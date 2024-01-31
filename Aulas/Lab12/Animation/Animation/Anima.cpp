/**********************************************************************************
// Animation
// 
// Cria��o:     10 Abr 2012
// Atualiza��o: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "TileSet.h"
#include "Animation.h"
#include "Resources.h"

#include "Sprite.h"

// ------------------------------------------------------------------------------

class Anima : public Game
{
private:
    Sprite * sprite = nullptr;          // sprite de fundo
    TileSet * explosion = nullptr;      // folha de sprites da explos�o
    Animation * anim = nullptr;         // anima��o da explos�o
    

public:
    void Init();                        // inicializa jogo
    void Update();                      // atualiza l�gica do jogo
    void Draw();                        // desenha jogo
    void Finalize();                    // finaliza jogo
};

// -----------------------------------------------------------------------------

void Anima::Init() 
{
    sprite = new Sprite("Resources/Background.jpg");
    explosion = new TileSet("Resources/Explosion.png", 192, 192, 5, 10);
    anim = new Animation(explosion, 0.120f, true);    
}

// ------------------------------------------------------------------------------

void Anima::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza anima��o
    anim->NextFrame();
} 

// ------------------------------------------------------------------------------

void Anima::Draw()
{
    sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    anim->Draw(window->CenterX(), window->CenterY() - 140.0f);    
} 

// ------------------------------------------------------------------------------

void Anima::Finalize()
{
    delete sprite;
    delete explosion;
    delete anim;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Animation");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gr�fico
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Anima());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

