#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define _WIN#@_WINT 0x0A00

#define masSize 200
RECT mas[masSize];
RECT rct;

void FillMas(){
    srand(5);
    for (int i = 0; i < masSize; ++i) {
        mas[i].left = rand() % 800 - 100;
        mas[i].top = rand() % 400;
        mas[i].right = mas[i].left + 100;
        mas[i].bottom = mas[i].top + 100;
    }
}

void WinMove(){
    for (int i = 0; i < masSize; ++i) {
        mas[i].left += 3;
        if (mas[i].left > 700)
            mas[i].left = -100;
        mas[i].right = mas[i].left + 100;
        mas[i].bottom = mas[i].top + 100;
    }
}

void Show (HDC dc){
    HDC memDC = CreateCompatibleDC(dc);
    HBITMAP memBM = CreateCompatibleBitmap(dc, rct.right - rct.left, rct.bottom - rct.top);
    SelectObject(memDC, memBM);

    SelectObject(memDC, GetStockObject(DC_BRUSH));
    SetDCBrushColor(memDC,RGB(255, 255, 255));
    Rectangle(memDC, 0, 0, 1000, 800);

    SelectObject(memDC, GetStockObject(DC_BRUSH));
    SetDCBrushColor(memDC,RGB(255, 10, 100));
    SelectObject(memDC, GetStockObject(DC_PEN));
    SetDCPenColor(memDC,RGB(0, 0, 0));

    for (int i = 0; i < masSize; ++i) {
        Rectangle(memDC, mas[i].left, mas[i].top, mas[i].right, mas[i].bottom);
    }

    BitBlt(dc, 0, 0, rct.right - rct.left, rct.bottom - rct.top, memDC, 0, 0, SRCCOPY);

    DeleteDC(memDC);
    DeleteObject(memBM);
}

void Main_OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    RECT rect;
    INT iTabHeight = 22;

    GetClientRect(hwnd, &rect);
    MoveWindow(hwnd, 0, 0, rect.right + 1, iTabHeight, FALSE);
}

LRESULT WINAPI WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam){
    if (message == WM_DESTROY)
        PostQuitMessage(0);

    else if (message == WM_KEYDOWN)
        printf("code = %d\n", wparam);

    else if (message == WM_CHAR)
        printf("%c\n", wparam);

    else if (message == WM_SIZE)
        GetClientRect(hwnd, &rct);

    else if (message == WM_MOUSEMOVE){
        int xPos = LOWORD(lparam);
        int yPos = HIWORD(lparam);
        printf("mouse [%d,%d]\n", xPos, yPos);
    }

    else if (message == WM_LBUTTONDOWN)
        printf("mouse left button down\n");

    else if (message == WM_SIZE)
        Main_OnSize;
    else
        return DefWindowProcA(hwnd, message, wparam, lparam);
}

int main() {
    WNDCLASSW wc1;
        memset(&wc1, 0, sizeof(WNDCLASSW));
        wc1.lpszClassName = "Window";
        wc1.lpfnWndProc = WndProc;
    RegisterClassA(&wc1);

    HWND hwnd;
    hwnd = CreateWindowEx (0, "Window", "Graphics", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 10, 10, 800, 600, 0, 0, NULL, NULL);
    HDC dc = GetDC(hwnd);

    ShowWindow(hwnd, SW_SHOWNORMAL);

    FillMas();

    MSG msg;
    while (1){
        if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)){
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            WinMove();
            Show(dc);
            //Sleep(3);
        }
    }

    return 0;
}