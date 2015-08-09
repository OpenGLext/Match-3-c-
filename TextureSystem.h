#pragma once
#include <iostream>
#include <fstream>
#include "texture.h"

TCHAR buf[MAX_PATH];

bool LoadTGA(Texture *, char *);

Texture texture[17];

int LoadTexture(Texture *TEXTURE, char *filename)
{
LoadTGA(TEXTURE, filename);
glGenTextures(1, &TEXTURE->texID);
glBindTexture(GL_TEXTURE_2D, TEXTURE->texID);
//glTexImage2D(GL_TEXTURE_2D, 0, TEXTURE->bpp / 8, TEXTURE->width, TEXTURE->height, 0, TEXTURE->type, GL_UNSIGNED_BYTE, TEXTURE->imageData);

gluBuild2DMipmaps(GL_TEXTURE_2D, TEXTURE->bpp / 8, TEXTURE->width, TEXTURE->height, TEXTURE->type, 
                      GL_UNSIGNED_BYTE, TEXTURE->imageData);		
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
if (TEXTURE->imageData) free(TEXTURE->imageData);
return true;
}

inline void GetCur()
{
GetCurrentDirectory(sizeof(buffer),buf);
}


bool LoadRes()
{
	const int maxRes=17;

	char *b[17]={"\\Data\\logo.tga","\\Data\\button.tga","\\Data\\font.tga",
		         "\\Data\\backmenu.tga","\\Data\\combo.tga","\\Data\\menuback.tga",
				 "\\Data\\leveler.tga", "\\Data\\background-2.tga","\\Data\\square.tga",
				 "\\Data\\cursor_64_.tga","\\Data\\box_0.tga","\\Data\\box_1.tga",
				 "\\Data\\box_2.tga","\\Data\\box_3.tga", "\\Data\\figura.tga",
				 "\\Data\\ngon.tga","\\Data\\gameback.tga"};

	for(int i=0;i<maxRes; i++)
	{
      GetCur();
	  std::strcat(buf,b[i]);
	  LoadTexture(&texture[i],buf);
	}

	return true;
}


//int LoadGLTextures()
//{
//	
//
//std::strcat(buffer,"\\Data\\logo.tga");
//LoadTexture(&texture[0],buffer);
//
//std::strcat(buffer,"\\Data\\button.tga");
//LoadTexture(&texture[1],buffer);
//
//
//std::strcat(buffer,"\\Data\\font.TGA");
//LoadTexture(&texture[2],buffer);
//
//
//std::strcat(buffer,"\\Data\\backmenu.tga");
//LoadTexture(&texture[3],buffer);
//
//std::strcat(buffer,"\\Data\\combo.tga");
//LoadTexture(&texture[4],buffer);
//
//std::strcat(buffer,"\\Data\\menuback.tga");
//LoadTexture(&texture[5],buffer);
//
//std::strcat(buffer,"\\Data\\leveler.tga");
//LoadTexture(&texture[6],buffer);
//
//std::strcat(buffer,"\\Data\\background-2.tga");
//LoadTexture(&texture[7],buffer);
//
//std::strcat(buffer,"\\Data\\square.tga");
//LoadTexture(&texture[8],buffer);
//
//std::strcat(buffer,"\\Data\\cursor_64_.tga");
//LoadTexture(&texture[9],buffer);
//
//std::strcat(buffer,"\\Data\\box_0.tga");
//LoadTexture(&texture[10],buffer);
//
//std::strcat(buffer,"\\Data\\box_1.tga");
//LoadTexture(&texture[11],buffer);
//
//std::strcat(buffer,"\\Data\\box_2.tga");
//LoadTexture(&texture[12],buffer);
//
//std::strcat(buffer,"\\Data\\box_3.tga");
//LoadTexture(&texture[13],buffer);
//
//std::strcat(buffer,"\\Data\\figura.tga");
//LoadTexture(&texture[14],buffer);
//
//std::strcat(buffer,"\\Data\\ngon.tga");
//LoadTexture(&texture[15],buffer); 
//
//std::strcat(buffer,"\\Data\\gameback.tga");
//LoadTexture(&texture[16],buffer);  // не получится загрузить т.к цикл везде до 12х6
//
//	
//
//return true;
//}