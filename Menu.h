#pragma once
#include "GameLogic.h"

int addHighscore(void)
{
	int a=0;
	for (int i=0;i<10;i++)
		if(scores[i]>Score) a=i;

	for (int i=9;i>a;i--)
	
	{
		scores[i]=scores[i-1];
		strcpy(hiscore_items[i],hiscore_items[i-1]);
	}

	if (a==0)a=-1;
	scores[a+1]=Score;
	strcpy(hiscore_items[a+1],playername);
	
	FILE *F;
	F = fopen("hiscores.txt", "wt");
	for (int i=0;i<10;i++)
		fprintf(F, "%i	%s	", scores[i], hiscore_items[i]);
	fclose(F);

	return true;
}
int DrawOptions(float n, int ID)
{
	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// ( CHANGE )
	box(225.0f+(1-n)*500,120.0f,540.0f+(1-n)*500,415.0f);	
	
	// OPTIONS ITEMS Difficulty/sound/music
	glBindTexture(GL_TEXTURE_2D, texture[1].texID);			// button.tga
	for (int i=0;i<4;i++){
	if (i!=ID) if (options_items_fade[i]>0.5f){options_items_fade[i]-=0.004f;}
	if (ID==i) if (options_items_fade[i]<1.0f){options_items_fade[i]+=0.016f;} 
	}
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu
	for (int i=0;i<4;i++){
		glColor3f(options_items_fade[i],options_items_fade[i],options_items_fade[i]);
		glPrint(240.0f+(1.0f-n)*500.0f,170.0f+i*70.0f,0,options_items[i]);							// Write GRID CRAZY On The Screen
	}
	
		glColor3f(options_items_fade[0],options_items_fade[0],options_items_fade[0]);
		glPrint(300.0f+(1-n)*500,160.0f+50.0f,1,difficulty_items[Difficulty]);							// Write GRID CRAZY On The Screen
	
		glColor3f(options_items_fade[1],options_items_fade[1],options_items_fade[1]);
		glBindTexture(GL_TEXTURE_2D, texture[6].texID);			// leveler.tga
		glPushMatrix();
		glTranslatef(250.0f+(1-n)*500+SoundVolume*250,160.0f+115.0f,0.0f);

	box(0,0,10,25);	

		glPopMatrix();

		glColor3f(options_items_fade[2],options_items_fade[2],options_items_fade[2]);
		glBindTexture(GL_TEXTURE_2D, texture[6].texID);			// leveler.tga
		glPushMatrix();
		glTranslatef(250.0f+(1-n)*500+MusicVolume*250,160.0f+185.0f,0.0f);
		box(0,0,10,25);	
		glPopMatrix();


	if (n>=1){
		glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		if ((GameTime/20) % 2==0) if (MenuInGame) glPrint(300,128,1,"esc to return"); else glPrint(300,128,1,"game options");							// Write GRID CRAZY On The Screen
	}
	return TRUE;											
}
int DrawExit(float n, int ID)
{
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	glColor3f(1.0f,1.0f,1.0f);
	box(180.0f+(1-n)*500,200.0f,500.0f+(1-n)*500,350.0f);	
	
	// EXIT ITEMS YES/NO
	glBindTexture(GL_TEXTURE_2D, texture[1].texID);			// button.tga
	for (int i=0;i<2;i++){
	if (i!=ID) if (exit_items_fade[i]>0.5f){exit_items_fade[i]-=0.004f;}
	if (ID==i) if (exit_items_fade[i]<1.0f){exit_items_fade[i]+=0.016f;} 
	glColor3f(exit_items_fade[i],exit_items_fade[i],exit_items_fade[i]);
	
	box(200.0f+(1-n)*500,240.0f+i*50,480.0f+(1-n)*500,280.0f+i*50);	
	}
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	for (int i=0;i<2;i++){
		glColor3f(exit_items_fade[i],exit_items_fade[i],exit_items_fade[i]);
		glPrint(310.0f+(1-n)*500,240.0f+i*50.0f,0,exit_items[i]);							// Write GRID CRAZY On The Screen
	}
	
	if (n>=1){
		glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		if ((GameTime / 10) % 2==0) glPrint(190,215,1,"Do you want to exit?");							// Write GRID CRAZY On The Screen
	}
	return TRUE;											
}
int DrawExitToMenu(float n, int ID)
{
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	glColor3f(1.0f,1.0f,1.0f);
	box(180.0f+(1-n)*500,200.0f,500.0f+(1-n)*500,350.0f);	

	
	// EXIT ITEMS YES/NO
	glBindTexture(GL_TEXTURE_2D, texture[1].texID);			// button.tga
	for (int i=0;i<2;i++){
	if (i!=ID) if (exit_items_fade[i]>0.5f){exit_items_fade[i]-=0.004f;}
	if (ID==i) if (exit_items_fade[i]<1.0f){exit_items_fade[i]+=0.016f;} 
	glColor3f(exit_items_fade[i],exit_items_fade[i],exit_items_fade[i]);
	
	box(200.0f+(1-n)*500,240.0f+i*50,480.0f+(1-n)*500,280.0f+i*50);	
	}
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	for (int i=0;i<2;i++){
		glColor3f(exit_items_fade[i],exit_items_fade[i],exit_items_fade[i]);
		glPrint(310.0f+(1-n)*500,240.0f+i*50.0f,0,exit_items[i]);							// Write GRID CRAZY On The Screen
	}
	
	if (n>=1){
		glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		if ((GameTime/10) % 2==0) glPrint(190,215,1,"Exit to menu?");							// Write GRID CRAZY On The Screen
	}
	return TRUE;											
}
int DrawMenu(float n,int ID)
{
	// BACKGROUND
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	box(20.0f-400*(1-n),120.0f,330.0f-400*(1-n),360.0f);	

	// MENU ITEMS
	glBindTexture(GL_TEXTURE_2D, texture[1].texID);			// button.tga
	for (int i=0;i<4;i++)
	{
	if (i!=ID) if (menu_items_fade[i]>0.5f){menu_items_fade[i]-=0.002f*spd; }
	if (ID==i) if (menu_items_fade[i]<1.0f){menu_items_fade[i]+=0.008f*spd; } 
	glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
	
	box(40.0f-400*(1-n),150.0f+i*50,300.0f-400*(1-n),195.0f+i*50);	
	}

	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	for (int i=0;i<4;i++)
	{
		glColor3f(menu_items_fade[i],menu_items_fade[i],menu_items_fade[i]);
		glPrint(50.0f-400.0f*(1.0f-n),155.0f+i*50.0f,0,menu_items[i]);							// Write GRID CRAZY On The Screen
	}
	
	return TRUE;											
}
inline void TimeProcessMenu()
{
	GameTimeCounter+=1.0f*(spd*1.5f); // увел.spd дало быструю реакцию при совпадении фигур быстро добавляются линии снизу
	GameTime=(int)GameTimeCounter;
	Pauseval-=2.0*spd;
}
 
// при наведении рамки на две фигуры они должны вращатся
void RotateTwoFigures()
{
	 glRotatef(360.0f,0,1,0);
}

// эффект уменьшения фигур при исчезновении
void ScaleUp()
{
	for(int i=50; i>1; i--)
	glScalef(i,i,0);
}

int ProcessMenu(GLvoid)											// Here's Where We Do All The Drawing
{
  
	 TimeProcessMenu();
	
	if (CurMenu!=GAME) if(CurMenu!=LOGO)
	{


	};
	if(CurMenu==GAME && !GameOver)
	{
		
	};

if(CurMenu==MAIN_MENU)musicselect=0;
if(CurMenu==GAME && pause==false && GameOver==false)musicselect=1;
if(CurMenu==OPTIONS && MenuInGame==true)musicselect=3;
if(PauseMes==2 && Pauseval>0)musicselect=3;


if (musicplaying!=musicselect)
{
	
	
}

switch (CurMenu)
	{
	case MAIN_MENU:
	  if (keys[VK_UP])	{if (CurSelect>0)CurSelect--;};
	  if (keys[VK_DOWN]){if (CurSelect<3)CurSelect++;};
	  if (keys[VK_ESCAPE]){CurSelect=3;keys[VK_SPACE]=true;};
	  if (keys[VK_SPACE] || keys[VK_RETURN])

		  switch (CurSelect)
			{
		        case 0: StartGame(0); goafterfade=GAME;blackfade=true;blackunfade=false;break;
				case 1: CurMenu=OPTIONS;CurOptionsSelect=0;MenuInGame=false;break;
				case 2: CurMenu=HI_SCORES; break;
				case 3: CurMenu=EXIT_GAME;CurExitSelect=0;break;
				
			};
    break;
  case LOGO:
	  if (keys[VK_SPACE]||keys[VK_ESCAPE]||keys[VK_RETURN]){CurMenu=MAIN_MENU;Debug=false;};
    break;
  case HI_SCORES:
	  if (keys[VK_SPACE]||keys[VK_ESCAPE]||keys[VK_RETURN]){CurMenu=MAIN_MENU;keys[VK_ESCAPE]=false;};
    break;
  case OPTIONS:
	  if (keys[VK_UP])	{if (CurOptionsSelect>0)CurOptionsSelect--;};
	  if (keys[VK_DOWN]){if (CurOptionsSelect<3)CurOptionsSelect++;};
	  if (keys[VK_LEFT]){
		  switch (CurOptionsSelect)
			{
				case 0: if (!MenuInGame) if(Difficulty>0)Difficulty--;break;
				case 1: if(SoundVolume>0)SoundVolume-=0.04f; break;
				case 2: if(MusicVolume>0)MusicVolume-=0.04f;break;
				default:
				{};
			};
	  };
	  if (keys[VK_RIGHT]){
		  switch (CurOptionsSelect)
			{
				case 0: if (!MenuInGame) if(Difficulty<2)Difficulty++;break;
				case 1: if(SoundVolume<1)SoundVolume+=0.04f; break;
				case 2: if(MusicVolume<1)MusicVolume+=0.04f;break;
				default:
				{};
			};
	  };
	  if (keys[VK_ESCAPE])if (MenuInGame) {goafterfade=GAME;blackfade=true;blackunfade=false; menufade[GAME]=1;} else CurMenu=MAIN_MENU;
	  if (keys[VK_SPACE]||keys[VK_RETURN])if (CurOptionsSelect==3){CurMenu=MAIN_MENU;};
    break;
  case EXIT_GAME:
	  if (keys[VK_UP])	{if (CurExitSelect>0)CurExitSelect--;};
	  if (keys[VK_DOWN]){if (CurExitSelect<1)CurExitSelect++;};
	  if (keys[VK_SPACE]||keys[VK_RETURN]){if (CurExitSelect==0)done=true;};
	  if (keys[VK_SPACE]||keys[VK_RETURN]){if (CurExitSelect==1)CurMenu=MAIN_MENU;};
    break;
  case GAME:


	  if (keys[VK_ESCAPE])		
		  if (!GameOver) 
		  {
			  goafterfade=OPTIONS;
			  MenuInGame=true;blackfade=true;blackunfade=false;
		  };// else 
	  if (keys[VK_RETURN] && GameOver)
		  {
			  goafterfade=HI_SCORES;
			  MenuInGame=false;
			  GameOver=false;
			  blackfade=true;
			  blackunfade=false;
			  addHighscore();
		  };
		  
		
	  
	  if (anykey>64 && anykey<96 && namelen<11) 
	  {
		  playername[namelen]=char(anykey);
		  namelen++;
		  anykey=-1;
	  }
	  if (anykey==8 && namelen>0) 
	  {
		  namelen--;
		  playername[namelen]=char(32);
		  anykey=-1;
	  }


	  if (keys[68])  { RightBorderStakan; } // D если поставить CurSelectX <8 тогда можем двигатся дальше по горизонтали 
	  if (keys[65])  LeftBorderStakan; // A
	  if (keys[87])  TopBorderStakan; // W /* стакан в 11 пунктов высотой ? */ 
	  if (keys[83])  BottomBorderStakan;    // S

	  if (keys[VK_PAUSE]) if(Pauseval < 0){PauseMes=2; Pauseval=999999;} else {Pauseval=0;}

	  if (keys[VK_SPACE])

		  // если кубик и след. кубик на гориз.линии не одинаковы!!! то обменяем их
		  if( !cube[CurSelectY][CurSelectX].InMove && !cube[CurSelectY][CurSelectX+1].InMove )
	  {
		    FonMusic.pause();
		    sound.play();
			FonMusic.play();

	//while (sound.getStatus() == sf::Sound::Playing)
 //   {
 //       sf::sleep(sf::milliseconds(100));
 //   }

		float ftemp=cube[CurSelectY][CurSelectX].cx;
		 
		cube[CurSelectY][CurSelectX].cx = cube[CurSelectY][CurSelectX+1].cx;
 
		cube[CurSelectY][CurSelectX+1].cx = ftemp;
		int temp=cube[CurSelectY][CurSelectX].Type;
		cube[CurSelectY][CurSelectX].Type=cube[CurSelectY][CurSelectX+1].Type;
		cube[CurSelectY][CurSelectX+1].Type=temp;
	  }
		if (keys[VK_CONTROL]) AddLineNow = true;   break;
 
	};

	 /* если будут скачки курсора по стакану проверить коды клавиш или дописать */
	keys[VK_RETURN]=false;
	keys[68]=false;
	keys[87]=false;
	keys[83]=false;
	keys[65]=false;
	keys[VK_PAUSE]=false;
	keys[VK_SPACE]=false;
	keys[VK_CONTROL]=false;
	keys[VK_PAUSE]=false;
//	keys[VK_F1]=false;
//	keys[VK_F2]=false;

	if (keys[VK_F2]) { Debug=!Debug; }

keys[VK_F2]=false;	
	for(int i=0;i<6;i++)
		if(i!=CurMenu)
			{
				if (menufade[i]>0)
					menufade[i]=menufade[i]-0.01f*spd;
			}
	if (menufade[CurMenu]<1)menufade[CurMenu]=menufade[CurMenu]+0.01f*spd;

	return TRUE;												// Keep Going
}
int DrawLogo(float n)
{
	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[5].texID);			//  menuback.tga
	box(0.0f,0.0f,w,h);	                       // рамка для menuback.tga

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);			// logo.tga
	box(0.0f,0.0f,w,h);	

	if (n>=1){ // если конец игры вывести рекорд таблицу
		glColor3f(1.0f,1.0f,1.0f);								// Set Color To Purple
		if ((GameTime/100) % 2==0) 
			glPrint(300,600,0,"press button to menu");							// Write GRID CRAZY On The Screen
	}
	return TRUE;											
}