#pragma once	

//#include "TextureSystem.h"
#pragma comment(lib, "Opengl32.lib")					//Link to OpenGL32.lib so we can use OpenGL stuff

#include <windows.h>									// Standard windows header
#include <stdio.h>										// Standard I/O header 
#include <gl\gl.h>										// Header for OpenGL32 library


struct SizeCube
{
	bool minCube;
	bool midleCube;
	bool bigCube;
};

class TGameObject
{

public:

	TGameObject();
	~TGameObject();

	void DrawGameCube();
	void SelectSizeCube(SizeCube * sz);
	//void SelectTexture(char  pathToTexture);
	void SetCoordCubes(int x_, int y_, int x2_, int y2_);

	void SetDestroyCube(bool destroy);
	/* ������������ ������ ����� �� ������� ����� */


	bool isCollision(TGameObject * TGameObject_);
	/* ���� �� ����� ����������� ������ �� ����������� � �� ��������� ? */

	void SetSizeField(int N, int M);
	/* ������ ������� N x M */

private:

 int sz_min; /* 32x32 pixels*/
 int sz_midle;
 int sz_big;

 int x,x2,y,y2;
 //Texture oneTexture;
 char nameTexture;


 /* ������ ������� */
 int sz_cube;

 bool DestroyCube; 
 /* ����� �� ��������� - ������� ����� � ������ ?*/

	void Box2d();

	void SetSizeCube();

	void CheckCollision();

	//void SetTexture();

};