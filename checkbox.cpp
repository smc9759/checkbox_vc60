
#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass="Class";

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(LTGRAY_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		  CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		  NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	
	while(GetMessage(&Message,0,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}
#define ID_R1 101
#define ID_R2 102
#define ID_R3 103
#define ID_R4 104
#define ID_R5 105
#define ID_R6 106
HWND r1,r2,r3,r4,r5,r6;
int GRAPH=0;
int COLOR=0;
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH MyBrush, OldBrush;
	switch(iMessage) {
	case WM_CREATE:
		CreateWindow("button","Graph",WS_CHILD | WS_VISIBLE | 
			BS_GROUPBOX,5,5,120,110,hWnd,(HMENU)0,g_hInst,NULL);
		CreateWindow("button","Color",WS_CHILD | WS_VISIBLE | 
			BS_GROUPBOX,145,5,120,110,hWnd,(HMENU)1,g_hInst,NULL);
		r1=CreateWindow("button","Rectangle",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON | WS_GROUP,
			10,20,100,30,hWnd,(HMENU)ID_R1,g_hInst,NULL);
		r2=CreateWindow("button","Ellipse",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON,
			10,50,100,30,hWnd,(HMENU)ID_R2,g_hInst,NULL);
		r3=CreateWindow("button","Line",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON,
			10,80,100,30,hWnd,(HMENU)ID_R3,g_hInst,NULL);
		r4=CreateWindow("button","Black",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON | WS_GROUP,
			150,20,100,30,hWnd,(HMENU)ID_R4,g_hInst,NULL);
		r5=CreateWindow("button","Red",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON,
			150,50,100,30,hWnd,(HMENU)ID_R5,g_hInst,NULL);
		r6=CreateWindow("button","Blue",WS_CHILD | WS_VISIBLE | 
			BS_AUTORADIOBUTTON,
			150,80,100,30,hWnd,(HMENU)ID_R6,g_hInst,NULL);
		break;
	case WM_PAINT:
		hdc=BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}