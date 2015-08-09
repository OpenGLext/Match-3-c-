#pragma once
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

 bool IsLevelComplete()
{
	if (( Score >= 300)) return true;
	else return false;
}

inline GLvoid box(float x1, float y1, float x2, float y2)
{
	glBegin(GL_QUADS);	
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x1,y1);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x2,y1);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x2,y2);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(x1,y2);
	glEnd();
}
int StartGame(int Level)
{
	// if (isOnMusic) {
	FonMusic.play(); 


#define coord_cube cube[i][t]

	/* в зависимости от уровня сложности увеличиваем скорость игры */
	if (Difficulty==0) AddTime=700; // old 700
	if (Difficulty==1) AddTime=400;
	if (Difficulty==2) AddTime=200;

	Level+=Difficulty*2;

	for ( int i=0; i < HorizonteLine; i++ ) 
		
		for ( int t=0; t < VertLine; t++  )
	{
		coord_cube.Type = -1;
		coord_cube.cx = (float)t * sz_texture; // запишем текст.коорд
		coord_cube.cy = (float)i * sz_texture;
		coord_cube.x = (float)t  * sz_texture;
		coord_cube.y = (float)i  * sz_texture;
		coord_cube.CanDestr = false;
	}
	for ( int i=0; i<Level; i++ ) 
		for ( int t=0; t<VertLine; t++ ) 
		{
			coord_cube.Type=rand() % 6; 
			/* заполняем случайными фигурами массив - 4 различных цвета добавили еще 2 -> 4+2 = 6 ;) */
		};

	CurSelectX=2; // курсоры выделения их положение
	CurSelectY=1;	
	//Score=0;
	Pauseval=350; //время на уровень чуточку побольше сделаем ))) было 700
	PauseMes=0;    // пауза не нажата
	GameOver=false;  
	gameoveranim = 11.0f;
	Gamelevel = 0;
//	musicplaying=1;
	if (musicplaying==0)
	{
		musicplaying=1;
		//FMUSIC_StopSong(MenuSong);
		//FMUSIC_PlaySong(GameSong);
	} 
	return TRUE;											
}

void DrawWin()
{
	//GameOver = true;
	//gameoveranim = 0;
	win = true;
	GameOver = true;
	gameoveranim = 0.0f;

	//active = false;
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0.0f,0.0f,0.0f,0.0f);
	glPrint(300,300,1,"You Win!!! Level is complete");
	//SwapBuffers(hDC);
	
	//Sleep(4000);
	 // DrawLogo(menufade[LOGO]);
	  
	//Sleep(300);
	//glLoadIdentity();
	//CurMenu == GAME;


	//Begin New Level изменить уровень на Next

}

int ProcessGame()
{
	 
	//if (IsLevelComplete()) { CurMenu = WIN; }
	if (IsLevelComplete()) { win = true; /*GameOver = true;*/ }
	Gamelevel = Score / 1000;
	if (!GameOver)
	for ( int t=0; t < HorizonteLine; t++)
	 for( int a=0; a < VertLine; a++)
	 {
		 // скорость обмена фигур                                 в релизной версии установить 0.1f !!! in debug 0.9f
		 cur_cube.cx = cur_cube.cx + ( cur_cube.x - cur_cube.cx ) * 0.1f * spd;
		 cur_cube.cy = cur_cube.cy + ( cur_cube.y - cur_cube.cy ) * 0.1f * spd;

	cur_cube.InMove = ( cur_cube.cx - cur_cube.x > 0.5f) || ( cur_cube.cx - cur_cube.x <- 0.5f );

	cur_cube.InMove = cur_cube.InMove || (( cur_cube.cy - cur_cube.y > 0.5f) || ( cur_cube.cy - cur_cube.y <- 0.5f ));

	 };

	float ftemp;
	int temp;

	//Checking for falling cubes and combinations
	if (!GameOver)
	for (int t=0; t < HorizonteLine; t++)
	{
	 for(int a=0; a < VertLine; a++)
	 {
		if( a < 4 )  // вот оно сравнение на 4 кубике происходит сравнение по вертикали как мы видим
			
			if( cur_cube.Type > -1 )	/* 3 cubes horisontal combinatior -1 это вертикальная линия???    */

			if ( cur_cube.InMove == false && next_cube.InMove == false )

				if (( ( pred_cube.Type > -1 && cube[t-1][a+1].Type >-1 )) || ( t==0 ))
					if (
					
						cur_cube.Type == next_cube.Type && // если цвета совпали то
						cur_cube.Type == cube[t][a+2].Type)
						cur_cube.CanDestr = next_cube.CanDestr = cube[t][a+2].CanDestr = true; // ставим что можно уничтожить
		                

		if( t < HorizonteLine -2 ) // если стакан не заполнен 11х6

			if(cur_cube.Type > -1 )	/* 3 cubes vertical combinatior*/

			if (cur_cube.InMove == false && cube[t+1][a].InMove == false )

				if (cur_cube.Type == cube[t+1][a].Type && // если два кубика совпадают
					cur_cube.Type == cube[t+2][a].Type) 
					cur_cube.CanDestr = cube[t+1][a].CanDestr = cube[t+2][a].CanDestr = true; // ставим что можно уничтожить

		            // св-во CanDestr указывает на то что 3и и более кубиков совпали ( CanDestroy ) типа можно разрушать )))

		if( t > 0) 
			if(cur_cube.Type > -1) 
				if(cube[t-1][a].Type == -1)
					if (cur_cube.InMove == false && cube[t-1][a].InMove == false)

		{ //обмен кубиков падение кубика и/или уничтожение целой линии

			FonMusic.pause();
			swapTwoCubes.play();
			FonMusic.play();

			ftemp=cur_cube.cy;
			cur_cube.cy = cube[t-1][a].cy;
			cube[t-1][a].cy = ftemp;
			temp=cur_cube.Type;
			cur_cube.Type=cube[t-1][a].Type;
			cube[t-1][a].Type=temp;
		};
	 };
	};
	
	// Add new line bottom
	/* Проверка на 11 в высоту линий не порядок сделаем 18 end_top = 18 ))) */
	int end_top = 9;

	if (!GameOver)
	if ( GameTime - AddLineTime > AddTime || AddLineNow) // если вышло время то конец игры проверим
	{                                                   //
	 for(int a=0; a < VertLine; a++)
	 {
		 if( cube[end_top][a].Type > -1 ) { GameOver = true; gameOverMusic.play(); }
		
		 // если закрыть эту строку то God Mode )))
	 };

	 for ( int t = HorizonteLine - 2;  t >= 0; t-- )
	 for( int a=0; a < VertLine; a++ )
	 {
			ftemp=cur_cube.cy;
			cur_cube.cy = cube[t+1][a].cy;
			cube[t+1][a].cy = ftemp;
			temp=cur_cube.Type;
			cur_cube.Type=cube[t+1][a].Type;
			cube[t+1][a].Type=temp;		
			AddLineTime=GameTime - 60.0f;			
	 };

	 for(int a=0; a < VertLine; a++)
	 {
		cube[0][a].Type=rand() % 4; 
		// попытка добавить еще две фигуры проверяются цвета а нам нужна форма т.е геометрия было %4 :)))
		// но какая разница если мы загрузим модельку или сгенерим не суть важно и загрузим как текстуру
		cube[0][a].cx = a * sz_texture + sz_texture * (a-3)+17;
		cube[0][a].cy = - sz_texture;
		cube[0][a].x = a * sz_texture;
		cube[0][a].y=0;
		cube[0][a].CanDestr = false;
	 };
	 if ( CurSelectY < 11 ) CurSelectY++; // оригинал если у < 11 то у++ иначе уперлись в потолок стакана
	 AddLineNow = false;
	};
	 


	// Make cubes fall down if game is over
	if (GameOver)
	{
		 Score =0;
	 for (int t = HorizonteLine - 1; t >= gameoveranim; t--)
		for( int a=0; a < VertLine; a++)
			if( cur_cube.Type >-1) cur_cube.CanDestr = false; 
	             //true; при проигрыше скорее делает весь массив одинакового цвета и все падают что очень логично
	            // но это не так, это ошибка падают все фигуры и разного цвета
	}

	if (GameOver)
		if ( gameoveranim > 0 ) gameoveranim -= 0.05f * spd;

	
	// Destroy all what we can
	int newvalue = 0;
	int bonuscount = 0;
	for ( int t=0; t < HorizonteLine; t++ )
		for( int a=0; a < VertLine; a++)

			if(cur_cube.CanDestr) // если кубик нужно удалить
			{
				//AddParticle( (int) cur_cube.cx + 225 + 16, 412 - (int)cur_cube.cy + 16, 1, 10 + cur_cube.Type );
				// то строим систему частиц спец эффект мазе факе )))

				cur_cube.Type = -1;
				cur_cube.CanDestr = false;
				newvalue += 5+5 * Difficulty;      //сколько очков добавим к текущим при уничтожении линии кубиков
				                                  // 10 на 1 уровне сложности 20 на 2 уровне
				if(!GameOver) Score += newvalue;
				if(!GameOver) Pauseval = 50;
				PauseMes=1;
				fall = true;
				bonuscount++;

				
			}
             if(!GameOver)
               if (bonuscount > 4)
	           {
			        //AddParticle(320, 240, 2, 15);Score+=bonuscount*20;Pauseval=150;
	           }

	return TRUE;											
}
int DrawGame(float n)
{
	

	if ( Pauseval < 0 ) ProcessGame();

	glColor3f(1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[7].texID);			// background.tga
	box(0.0f,0.0f,w,h);	
	//RenderParticles();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_ALPHA_TEST);
	glColor4f(1,1,1,1);

	glBindTexture(GL_TEXTURE_2D, texture[3].texID);			// backmenu.tga
	//glPrint(720,80,2,"Scores");                            // Выводим очки
	RenderScore += (Score-RenderScore) * 0.001f * spd;
	//glPrint(720,70,0,"%2.0f",Score); //это не очки RenderScore

	//glPrint(720,40,2,"HI score");

	/*if (Score<scores[0]) 
		glPrint(460,95,0,"%2.0i",scores[0]); // если не набрали мак.число очков(2000) то выводим макс рекорд кого то т.е рекорд таблица
	else */
		//glPrint(720,80,0,"%2.0f",Score);
	glDisable(GL_BLEND);
	glPrint(720,60,2,"Score:%2i",Score);//Gamelevel);
	//glPrint(720,20,2,difficulty_items[Difficulty]);
	glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, texture[16].texID);			// gameback.tga	

	//box(190.0f, 235.0f * n + 240, 460.0f, -235.0f * n + 240);	
	
	box( stakan_pos_x, stakan_pos_y, stakan_pos_x2, stakan_pos_y2 );
	
	glColor4f(1.0f,1.0f,1.0f,0.6f);

	/* Здесь строятся кубики !!! */
	for ( int t = 0; t < HorizonteLine; t++ )
	{
	for( int a = 0; a < VertLine; a++ )
	{
	    if(cur_cube.Type > -1) // скорее всего если не пустой кубик
	 {
		 if (cur_cube.InMove)  // если это новая линия тогда

		    glColor4f(1.0f,1.0f,1.0f,1.0f); // сделаем поярче 

		  else glColor4f(1.0f,1.0f,1.0f,1.6f); //иначе потемнее  // эти две строки получаем рамки и все фигуры становятся одинаковыми!!!

			glBindTexture(GL_TEXTURE_2D, texture[10+cur_cube.Type].texID);
			//10 + похоже захватывает и курсор доб как фигуру в поле исправить см. условия вверху цикла
		
			if (Pauseval > 0) // если время еще не кончилось
				if (PauseMes == 2) // если включили паузу
				{
					glBindTexture(GL_TEXTURE_2D, texture[16].texID); // загрузим рамку дабы показать во время паузы все фигуры как рамки!!!
					glColor4f(1,1,1,0.5);
				}
			glPushMatrix(); // сохраним буфер цвета -> запомним положение объектов на экране сохранялка такая в стеке матриц )))

			glTranslatef( left_border_stakan + cur_cube.cx, bottom_stakan - cur_cube.cy * n - 235.0f * (1-n), 0); 
			// перенос кубика на нужную позицию в строке стакана

			box(0.0f, 0.0f, sz_cube, sz_cube);	 // выводимый кубик с текстурой конечно

			glPopMatrix(); // загрузим сохранялку т.к кубик мы нарисовали будем следующий делать 
	 };
	};
	};
	


	// Draw cursor changer 
	// курсор 64х64 а появляется 32х32 да и вырезается коричневая середина т.е альфа канал прозрачность скорее вкл
	if (!GameOver)
	{

	glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, texture[9].texID); // покажем курсор	
	
	glColor4f(0.0f,0.0f,1.0f,1.0f);
	
	glPushMatrix();

	glTranslatef( left_border_stakan + sz_texture * CurSelectX, bottom_stakan - CurSelectY * sz_texture, 0.0f);
	box( 0.0f, 0.0f, sz_cube, sz_cube ); 	
	// создаем еще один кубик рядом

	glPopMatrix();

	glPushMatrix();

	glTranslatef( left_border_stakan + sz_texture * ( CurSelectX + 1.0f),bottom_stakan - CurSelectY * sz_texture, 0.0f);
	box( 0.0f, 0.0f, sz_cube, sz_cube );	

	glPopMatrix();

	}

	glDisable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glColor3f(0,0,1);
	if (Pauseval>0)	if (PauseMes==0) glPrint(240,225,0,"READY!%2.0f",Pauseval/200+1);
	if ((GameTime/100) % 2==0) if (Pauseval>0)	if (PauseMes==2) glPrint(240,225,0,"Paused");


	if(GameOver && gameoveranim <= 0) //если конец игры и анимация <= 0
	{
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);	// backmenu.tga
	glColor3f(1.0f,1.0f,1.0f);
	box(180.0f+(1-n)*500, 200.0f,500.0f+(1-n)*500,400.0f);	
	glPrint(220,225,0,"SCORE:%2.0i",Score);
	glPrint(240,255,0,"GAME OVER");
	glPrint(210,285,0,"write name:");
	glColor3f(1.0f,0.0f,0.0f);
	glPrint(210,315,0,playername);
	//glPrint(410,315,0,"%2.0i",anykey);
	glColor3f(1.0f,1.0f,1.0f);
	glPrint(220,355,0,"press Enter");
	};

	if ( win && GameOver )
	{
	
	glBindTexture(GL_TEXTURE_2D, texture[3].texID);	// backmenu.tga
	glColor3f(1.0f,1.0f,1.0f);
	box(180.0f+(1-n)*500, 200.0f,500.0f+(1-n)*500,400.0f);	
	glPrint(220,225,0,"SCORE:%2.0i",Score);
	glPrint(240,255,0,"");
	glPrint(210,285,0,"YOU WINNER!!!");
	glColor3f(1.0f,0.0f,0.0f);
	//glPrint(210,315,0,playername);
	//glPrint(410,315,0,"%2.0i",anykey);
	glColor3f(1.0f,1.0f,1.0f);
	glPrint(220,355,0,"press Enter");

	win = false;
	GameOver = false;

	}

	

	return TRUE;											
}