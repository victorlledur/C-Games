#include <windows.h>

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPSTR lpCmdLine,
                     _In_ int nCmdShow)
{
    MessageBox(NULL, (LPCWSTR)L"Oi Windows!", (LPCWSTR)L"Mensagem", 0);

    return 0;
}