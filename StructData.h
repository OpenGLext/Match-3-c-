#pragma once
#include <SFML/Audio.hpp>
//#pragma comment(lib,"sfml-audio.lib")

 sf::SoundBuffer buffer,bufferSwapTwoCubes,bufferGameOver,bufferFonMusic;
 sf::Sound       sound,swapTwoCubes,gameOverMusic;
 sf::Music	     FonMusic;
 char *MusicRes[4]={"\\Data\\DownCube.wav","\\Data\\SwapCubes.wav","\\Data\\DestroyLine.wav","\\Data\\backgroundMusic.ogg"};

HDC			hDC=NULL;
HGLRC		hRC=NULL;
HWND		hWnd=NULL;
HINSTANCE	hInstance;
GLuint	    fontbase;

const int MAIN_MENU=1;
const int OPTIONS=2;
const int HI_SCORES=3;
const int EXIT_GAME=4;
const int EXIT_MENU=6;
const int GAME_OVER=7;
const int GAME=5;
const int LOGO=0;
const int WIN = 25;
const int HorizonteLine = 12; // 12 изначальные значения
const int VertLine= 6;  // 6  изначальные значения

int   menu;
int   CurSelect=0;
int   CurExitSelect=0;
int   CurOptionsSelect=0;
int   GameTime=0;
int   goafterfade=0;
int   Difficulty=1;
int	  FPS=100;
int   CurFPS=100;
int   Score=0;
int   AddLineTime=0;
int   AddTime=0;
int   PauseMes;
int   musicplaying=-1;
int   musicselect=-1;
int   Gamelevel=0;
int   LastBinded;
int   scores[10]={2000,1700,1600,1500,1000,800,500,300,200,100};
int   namelen=6;
int   w = 1024;
int   h = 768;
int   CurSelectX;
int   CurSelectY;
//const int PARTICLE_COUNT=256;
int   CurParticle=0;
int   CurMenu=0;

__int64 oldtime;

float   menu_items_fade[4]={0.5f,0.5f,0.5f,0.5f};
float   menufade[5];
float   options_items_fade[4]={0.5f,0.5f,0.5f,0.5f};
float   exit_items_fade[2]={0.5f,0.5f};
float	spd=2.0f;
float   spin;			
float   GameTimeCounter=0;
float  	SoundVolume=50.0f;  //громкость музыки
float	MusicVolume=100.0f; // и звуков используется для смещения в игре охренеть ))))
float	blackfadelevel=0.0f;
float   RenderScore=0;
float   Pauseval=20;
float   gameoveranim=0;
float   IdenMatrix[16]={1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0};

// размер кубика
float sz_cube  = 64.0f;

float bottom_stakan = 600.0f;
float left_border_stakan = 225.0f; 
float sz_texture = 64.0f;

float sz_stakan_w = 512;
float sz_stakan_h = 512;
/* размер фото стакана */

float stakan_pos_x = (w / 8) + 10.0f ; /* разница между х и х2 дает ширину */ // 10.0f
float stakan_pos_y = (h / 20)  - 25.0f ; //-25.0f
float stakan_pos_x2 = sz_stakan_h + 150.0f;//384.0f; //225.0f  ; /* отступ сверху экрана */
float stakan_pos_y2 = sz_stakan_h + 200.0f ;  /* отступ снизу экрана  */
/* позиция стакана на экране */

bool	blackfade=false;
bool	blackunfade=true;
bool    GameOver=false;
bool	pause;
bool    fall=false;
bool    AddLineNow=false;
bool    MenuInGame=false;
bool    Debug=true;
bool	keys[256];
bool	active = true;
bool	fullscreen = true;
bool	canexit = false;
bool	done=FALSE;	
bool    win = false;
										
char	anykey;	
char    menu_items[4][15]={"New Game","Options","High scores","Exit"};
char    difficulty_items[3][12]={"< easy >","< normal >","< hard >"};
char    options_items[5][16]={"difficulty","sound volume","music volume","Main menu","Return to game"};
char    exit_items[2][5]={"yes","no"};
char    playername[12]={"Player"};
char    hiscore_items[10][20]={"Katja","petrovi4","Sanjok","Sanjok","Vasja","Edgar","Andrej","Stas","Vika","Vasja"};
//char hiscore_items[10][20]={"Vasja        10000","petrovi4     80000","Sanjok       70500","Sanjok       6523","Katja        6423","Edgar        6128","Andrej       5280","Stas         5188","Vika         4800","Vasja        3600"};

struct	Tcube												// Create A Structure For Our Player
{
	float	x, y;											// Current Position
	float	cx, cy;
	float	Speed;
	int		Type;      // цвет? 0-красный 1-зеленый
	bool	InMove;    // в движении?
	bool	CanDestr;  // разрушен ли? 
} cube[HorizonteLine][VertLine];


#define cur_cube cube[t][a]
#define pred_cube cube[t-1][a]
#define next_cube cube[t][a+1]

#define RightBorderStakan if ( CurSelectX < 4 ) CurSelectX++
#define LeftBorderStakan  if (CurSelectX > 0) CurSelectX--
#define TopBorderStakan   if (CurSelectY < 11) CurSelectY++
#define BottomBorderStakan if (CurSelectY > 0) CurSelectY--

