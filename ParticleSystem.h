#pragma once

#include "TextureSystem.h"
#include "StructData.h"
#include "GameLogic.h"

const int PARTICLE_COUNT = 256;

struct	Tparticle												// Create A Structure For Our Player
{
	float		mx, my;											// Fine Movement Position
	float		x, y;											// Current Position
	float	Speed;
	float	Gravity;
	float	mAngle;
	float	Angle;
	float	size;
	int		Type;
	int		tx;
	float		Live;
} particle[PARTICLE_COUNT];



int AddParticle(int px, int py, int pType, int TextureID)
{
	particle[CurParticle].x=(float)px;
	particle[CurParticle].y=(float)py;
	particle[CurParticle].tx=TextureID;	
	switch (pType)
	{
		case 0:
			particle[CurParticle].Live=100;
			particle[CurParticle].Speed=rand()%10*0.02f;
			particle[CurParticle].mx=-1.0f;
			particle[CurParticle].my=0;
			particle[CurParticle].Angle=0;
			particle[CurParticle].mAngle=(rand()%10*0.01f-0.05f)*2.0f;
			particle[CurParticle].Gravity=0;
			particle[CurParticle].Type=0;
			particle[CurParticle].size=(float)(rand()%10)/3;
		break;
		case 1:
			particle[CurParticle].Live=50;
			particle[CurParticle].Speed=0.4f;
			particle[CurParticle].mx=-0.5f;
			particle[CurParticle].my=0.5f;
			particle[CurParticle].Angle=0;
			particle[CurParticle].mAngle=(rand()%10*0.01f-0.05f)*8.0f;
			particle[CurParticle].Gravity=0.01f;
			particle[CurParticle].Type=1;
			particle[CurParticle].size=16;
		break;
		case 2:
			particle[CurParticle].Live=60;
			particle[CurParticle].Speed=0.6f;
			particle[CurParticle].mx=0.5f;
			particle[CurParticle].my=-0.5f;
			particle[CurParticle].Angle=0;
			particle[CurParticle].mAngle=0;
			particle[CurParticle].Gravity=0.01f;
			particle[CurParticle].Type=2;
			particle[CurParticle].size=128;
			particle[CurParticle].tx=15;
		break;
		default:
	  {};
	};

	CurParticle=(CurParticle+1)%PARTICLE_COUNT;
	return TRUE;											
}

int RenderParticles(GLvoid)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	for (int i=0;i<PARTICLE_COUNT;i++)
	{
	glBindTexture(GL_TEXTURE_2D, texture[particle[i].tx].texID);			// ( CHANGE )
	float drawsize=50*particle[i].size;
		switch (particle[i].Type)
		{
			case 0:
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glColor3f(0.8f,1.0f,1.0f);
				glPushMatrix();
				glLoadIdentity();
				glTranslatef(particle[i].x,particle[i].y,0);
				glRotatef(particle[i].Angle,0,0,1);
				box(-drawsize,drawsize,drawsize,-drawsize);
				glPopMatrix();
			break;
			case 1:
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				if (CurMenu==GAME){
				glColor3f(0.3f,0.3f,0.3f);
				glPushMatrix();
				glLoadIdentity();
				glTranslatef(particle[i].x,particle[i].y,0);
				glRotatef(particle[i].Angle,0,0,1);
				box(-particle[i].size,particle[i].size,particle[i].size,-particle[i].size);
				glPopMatrix();}
			break;
			case 2:
				if (CurMenu==GAME && particle[i].Live>0){
				glBlendFunc(GL_SRC_ALPHA,GL_ONE);
				float constant=60.0f/float(particle[i].Live);
				glPushMatrix();
				glLoadIdentity();
				glTranslatef(particle[i].x,particle[i].y,0);
				glColor4f(constant,constant,constant,constant);
				box(-particle[i].size*2*constant,-particle[i].size/constant,particle[i].size*2*constant,particle[i].size/constant);
				glPopMatrix();}
			break;
			default:
		  {};
		};
	};

	glEnable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);

	return TRUE;											
}

int ProcessParticles(GLvoid)
{
	for (int i=0;i<PARTICLE_COUNT;i++)
	{
		particle[i].x+=(particle[i].mx*particle[i].Speed*spd);
		particle[i].y+=(particle[i].my*particle[i].Speed*spd);
		particle[i].my+=particle[i].Gravity*spd;
		particle[i].Angle+=particle[i].mAngle*spd;
		particle[i].Live-=1*spd;		
		switch (particle[i].Type)
		{
			case 0:
			break;
			case 1:
			break;
			default:
		  {};
		};
	};

	return TRUE;											
}





