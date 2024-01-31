/**********************************************************************************
// WinGame 
// 
// Cria��o:     19 Mai 2007
// Atualiza��o: 04 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Um jogo para Windows � uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os m�todos Init, 
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	HDC hdc;
	int xi, xf, yi, yf;
	int velxi, velyi;
	int velxf, velyf;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{
	hdc = GetDC(window->Id());
	xi = 10;
	yi = 10;
	xf = 100; xf = 100;
	yf = 100;
	velxi = 5;
	velyi = 5;
	velxf = 5;
	velyf = 5;
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();	

	xi += velxi;
	yi += velyi;
	xf += velxf;
	yf += velyf;

	if (xi > window->Width())
		velxi = -velxi;

	if (yi > window->Height())
		velyi = -velyi;

	if (xi < 0)
		velxi = -velxi;

	if (yi < 0)
		velyi = -velyi;

	if (xf > window->Width())
		velxf = -velxf;

	if (yf > window->Height())
		velyf = -velyf;

	if (xf < 0)
		velxf = -velxf;

	if (yf < 0)
		velyf = -velyf;

	MoveToEx(hdc, xi, yi, NULL);	
} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{	
	LineTo(hdc, xf, yf);
} 

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}	


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------

