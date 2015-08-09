// ReSoNaNCe 29/06/2006 Artur Birzgals 
// www.resonance.from.lv
// resonance@inbox.lv
// Block destroyer game main file
// Oleg Plotnikov 27.10.2014

#include <vector>								
#include <stdio.h>		
#include "D:\\Движки\freeglut-2.8.1\include\GL\freeglut.h"
#pragma comment(lib,"freeglut.lib")
#pragma comment(lib,"OpenGL32.lib")
#include "StructData.h"
#include "Fonts.h"
#include "Menu.h"
#include "GameObject.h"
#include "TextureSystem.h"

 TCHAR buf2[MAX_PATH];
inline void GetCur2()
{
GetCurrentDirectory(sizeof(buf2),buf2);

}

//Добавим наш лог
	std::ofstream LogSystem("C:\\Log.bin",ios::out);

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if (height==0)
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();			

	glOrtho(0.0f,width,height,0.0f,-1.0f,1.0f);

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
}

TGameObject RenderClass;

int InitGL(GLvoid)												// All Setup For OpenGL Goes Here
{
	if (!LoadRes())										// Jump To Texture Loading Routine ( NEW )
	{
		return FALSE;											// If Texture Didn't Load Return FALSE
	}

	BuildFont();											// Build The Font
	glEnable(GL_TEXTURE_2D);									// Enable Texture Mapping ( NEW )
	glShadeModel(GL_SMOOTH);									// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);						// Black Background
//	glClearDepth(1.0f);											// Depth Buffer Setup
//	glEnable(GL_DEPTH_TEST);									// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);										// The Type Of Depth Testing To Do
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER,0.5f);

	
	LogSystem.open("C:\\Log.bin",ios::out);
  GetCur2();

		std::strcat(buf2,MusicRes[0]);

	if (!buffer.loadFromFile(buf2)) { MessageBoxW(0,L"Cannot media load",L"error load",MB_OK); }
	sound.setBuffer(buffer);

	 GetCur2();
	std::strcat(buf2,MusicRes[1]);

	if (!bufferSwapTwoCubes.loadFromFile(buf2)) { MessageBoxW(0,L"Cannot media load",L"error load",MB_OK); }
	swapTwoCubes.setBuffer(bufferSwapTwoCubes);
	 
	 GetCur2();
	std::strcat(buf2,MusicRes[2]);

	if (!bufferGameOver.loadFromFile(buf2)) { MessageBoxW(0,L"Cannot media load",L"error load",MB_OK); }
	gameOverMusic.setBuffer(bufferGameOver);

	//if (!bufferSwapTwoCubes.loadFromFile("backgroundMusig.ogg")) { MessageBoxW(0,L"Cannot media load",L"error load",MB_OK); }
	 GetCur2();
	std::strcat(buf2,MusicRes[3]);

	if (!FonMusic.openFromFile(buf2)) { MessageBoxW(0,L"Cannot  load music",L"error load",MB_OK);}

	
	FonMusic.setVolume(50);
	FonMusic.setLoop(true);
	
	return TRUE;											
}
int DrawHighScores(float n)
{
	const float x_menu = 245.0f+(1-n)*500; const float y_menu = 120.0f; const float x2_menu = 580.0f+(1-n)*500; const float y2_menu = 415.0f;
	const float x_score = 280.0f+(1-n)*500.0f; 
	const float setPrint = 1; 

	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// menuback.tga
	box( x_menu, y_menu, x2_menu, y2_menu );	
	for (int i=0;i<10;i++)
	{
		if (i<3) glColor3f(1.0f,0.0f,0.0f);
		else     glColor3f(1.0f,1.0f,1.0f);

		glPrint( x_score, 160.0f+i*25, setPrint,hiscore_items[i]);
		glPrint(280.0f+(1-n)*500.0f+180,160.0f+i*25,1,"%i",scores[i]);
	}
	
	
	if (n>=1){
		glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		if ((GameTime/100) % 2==0) glPrint(170,430,1,"press button to menu");							// Write GRID CRAZY On The Screen
	}
	return TRUE;											
}
int DrawDebug(float n)
{
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga

	glEnable(GL_ALPHA_TEST);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
	//glPrint(10,10,2,"GameTime:%2i",GameTime);
	glPrint(10,20,2,"FPS:%2i",FPS);
//	glPrint(10,30,2,"CurFPS:%2i",CurFPS);
	glPrint(20,590,1, "arrows-navigation");
	glPrint(20,570,1, "space -action");
	glPrint(20,550,1, "ctrl  -add blocks");
	glPrint(20,530,1,"F1   -full screen");
	glPrint(20,510,1,"pause-pause");
	glPrint(20,490,1,"F2   -help");
	return TRUE;											
}
void Selection(const int& x_, const int& y_)
{
	float num_x = (x_ / w) - 2.0f;
	float num_y = (y_ / h) - 2.0f;

	//printf(" num_x %d\n",num_x);
	//printf(" num_y %d\n",num_y);

	//glPrint(65,95,0,"hello");

	LogSystem<<"x "<<x_<<endl;
	LogSystem<<"y "<<y_<<endl;
	LogSystem<<"x OpenGL "<<num_x<<endl;
	LogSystem<<"y OpenGL "<<num_y<<endl;
	LogSystem<<"Times "<<spd<<endl;

}
int unpresskeys(GLvoid)
{
	for (int i=0;i<255;i++) 
		keys[i]=false;
	return TRUE;												
}
inline void Times()
{
	//__int64 time;											// time Will Hold A 64 Bit Integer
	//QueryPerformanceCounter((LARGE_INTEGER *) &time);	// Grab The Current Performance Time
	int time;
	time = GetTickCount();
	CurFPS++;

	if( time - oldtime > 1000 )
	{
		oldtime = time;
		FPS = CurFPS;
		CurFPS = 0;
	}

	spd = (float)100 / (float)FPS;
	Pauseval -= 1.0f * spd ;            // 20.0 - 2..4..6
}
inline void MainMenU_()
{
	if (menufade[MAIN_MENU]>0) DrawMenu(menufade[MAIN_MENU],CurSelect);
}
inline void HighMenu_()
{
	if (menufade[HI_SCORES]>0) DrawHighScores(menufade[HI_SCORES]);
}
inline void Options_()
{
if (menufade[OPTIONS]>0)   DrawOptions(menufade[OPTIONS],CurOptionsSelect);
}
inline void ExitMEnu_()
{
 if (menufade[EXIT_GAME]>0) DrawExit(menufade[EXIT_GAME],CurExitSelect);
}
inline void Game_()
{
if (CurMenu == GAME)  DrawGame(menufade[GAME]);
}
inline void blackfades_()
{
if (blackfade) blackfadelevel -= 0.016f*spd;
}
inline void blackunfades_()
{
	if (blackunfade) blackfadelevel += 0.016f*spd;
}
int DrawGLScene(GLvoid)											
{
	
	Times();
	glClear(GL_COLOR_BUFFER_BIT);								
//	glEnable(GL_ALPHA_TEST);
	glColor3f(1.0f,1.0f,1.0f);									
	glLoadIdentity();		//загрузить един.матрицу будет быстрее	//glMatrixMode(GL_MODELVIEW);//glLoadMatrixf(IdenMatrix);
     DrawLogo(menufade[LOGO]);
	 //MainMenU_();
	 HighMenu_();
	 Options_();
	 ExitMEnu_();
	 Game_();
	// if (CurMenu == WIN ) { win = true; GameOver = true; }//CurMenu = GAME; Game_(); } DrawWin();
	
	/* if ((GameTime) % 300==0) AddParticle(rand()%200+740,rand()%400+100,0,4);
	 ProcessParticles();
	if (CurMenu!=GAME) RenderParticles();*/

	blackfades_();
	blackunfades_();
	if (blackfadelevel<0.0f){blackfade=false;blackunfade=true;CurMenu=goafterfade;};
	if (blackfadelevel>=0.5f){blackunfade=false;blackfadelevel=0.5f;};	

	if (blackfade||blackunfade) // показываем СЕРОЕ МЕНЮ ИГРЫ
	{
	glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);	
		glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
		glDisable(GL_ALPHA_TEST);
		glColor4f(blackfadelevel,blackfadelevel,blackfadelevel,blackfadelevel);
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glVertex2f(0,0);
			glVertex2f(640,0);
			glVertex2f(640,480);
			glVertex2f(0,480);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
	};
	

	if (Debug) DrawDebug(1);
	return TRUE;												// Keep Going
}
int LoadSounds(GLvoid)
{
	FILE *F;
	F = fopen("hiscores.txt", "r+");
	for (int i=0;i<10;i++)fscanf(F, "%i	%s	", &scores[i], &hiscore_items[i]);
	fclose(F);

	for(int i=0;i<30;i++) 
		//AddParticle(rand()%640,rand()%400+100,0,4);
	oldtime=GetTickCount();
	srand((int)oldtime);
	

	return TRUE;
}
GLvoid KillGLWindow(GLvoid)										// Properly Kill The Window
{
	if (fullscreen)												// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);							// If So Switch Back To The Desktop
		ShowCursor(TRUE);										// Show Mouse Pointer
	}

	if (hRC)													// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))							// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))								// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;												// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))							// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;												// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))							// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;												// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))					// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;											// Set hInstance To NULL
	}
}
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;									// Holds The Results After Searching For A Match
	WNDCLASS	wc;												// Windows Class Structure
	DWORD		dwExStyle;										// Window Extended Style
	DWORD		dwStyle;										// Window Style
	RECT		WindowRect;										// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;									// Set Left Value To 0
	WindowRect.right=(long)width;								// Set Right Value To Requested Width
	WindowRect.top=(long)0;										// Set Top Value To 0
	WindowRect.bottom=(long)height;								// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;									// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","ReSoNaNCe",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;								// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=							// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),							// Size Of This Pixel Format Descriptor
		1,														// Version Number
		PFD_DRAW_TO_WINDOW |									// Format Must Support Window
		PFD_SUPPORT_OPENGL |									// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,										// Must Support Double Buffering
		PFD_TYPE_RGBA,											// Request An RGBA Format
		bits,													// Select Our Color Depth
		0, 0, 0, 0, 0, 0,										// Color Bits Ignored
		0,														// No Alpha Buffer
		0,														// Shift Bit Ignored
		0,														// No Accumulation Buffer
		0, 0, 0, 0,												// Accumulation Bits Ignored
		16,														// 16Bit Z-Buffer (Depth Buffer)  
		0,														// No Stencil Buffer
		0,														// No Auxiliary Buffer
		PFD_MAIN_PLANE,											// Main Drawing Layer
		0,														// Reserved
		0, 0, 0													// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))										// Did We Get A Device Context?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))				// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))					// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))							// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))								// Try To Activate The Rendering Context
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);									// Show The Window
	SetForegroundWindow(hWnd);									// Slightly Higher Priority
	SetFocus(hWnd);												// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);								// Set Up Our Perspective GL Screen

	if (!InitGL())												// Initialize Our Newly Created GL Window
	{
		KillGLWindow();											// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	return TRUE;												// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,						// Handle For This Window
							UINT	uMsg,						// Message For This Window
							WPARAM	wParam,						// Additional Message Information
							LPARAM	lParam)						// Additional Message Information
{
	switch (uMsg)												// Check For Windows Messages
	{
		case WM_ACTIVATE:										// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))								// Check Minimization State
			{
				active=TRUE;									// Program Is Active
			}
			else
			{
				active=FALSE;									// Program Is No Longer Active
			}

			return 0;											// Return To The Message Loop
		}

		case WM_SYSCOMMAND:										// Intercept System Commands
		{
			switch (wParam)										// Check System Calls
			{
				case SC_SCREENSAVE:								// Screensaver Trying To Start?
				case SC_MONITORPOWER:							// Monitor Trying To Enter Powersave?
				return 0;										// Prevent From Happening
			}
			break;												// Exit
		}

		case WM_CLOSE:											// Did We Receive A Close Message?
		{
			PostQuitMessage(0);									// Send A Quit Message
			LogSystem.close();
			return 0;											// Jump Back
		}

		case WM_KEYDOWN:										// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;								// If So, Mark It As TRUE
			anykey=wParam;
			return 0;											// Jump Back
		}

		case WM_KEYUP:											// Has A Key Been Released?
		{
			keys[wParam] = FALSE;								// If So, Mark It As FALSE
			return 0;											// Jump Back
		}

		case WM_SIZE:											// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));		// LoWord=Width, HiWord=Height
			return 0;											// Jump Back
		}

		case WM_LBUTTONDOWN:
		 {
	            int mouse_x = LOWORD(lParam);          
				int mouse_y = HIWORD(lParam);
			    Selection(LOWORD(lParam),HIWORD(lParam));                   //Получим х и у мыши
				return 0;
			}
		 break;
	
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,						
					HINSTANCE	hPrevInstance,					
					LPSTR		lpCmdLine,						
					int			nCmdShow)					
{
	MSG		msg;											

	
		fullscreen=FALSE;										

	if (!CreateGLWindow("Ice Cube v1.0",w,h,32,fullscreen))
	{
		return 0;												
	}

	while(!done)												
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))				
		{
			if (msg.message==WM_QUIT)							
			{
				done=TRUE;										
			}
			else												
			{
				TranslateMessage(&msg);							
				DispatchMessage(&msg);							
			}
		}
		else													
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			ProcessMenu();
			if ((active && !DrawGLScene()))	// Active?  Was There A Quit Received?
			{
				done=TRUE;										// ESC or DrawGLScene Signalled A Quit
			}
			else												// Not Time To Quit, Update Screen
			{
				SwapBuffers(hDC);								// Swap Buffers (Double Buffering)
			}

			if (keys[VK_F1])									// Is F1 Being Pressed?
			{
				keys[VK_F1]=FALSE;								// If So Make Key FALSE
				KillGLWindow();									// Kill Our Current Window
				fullscreen=!fullscreen;							// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("ReSoNaNCe 'terminate' CTXM game",w,h,32,fullscreen))
				{
					return 0;									// Quit If Window Was Not Created
				}
			}

		}
	}

	KillGLWindow();												
	return (msg.wParam);										
}

