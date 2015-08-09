#include "GameObject.h"

TGameObject::TGameObject()
{
	this->sz_min = 32;
	this->sz_midle = 64;
	this->sz_big = 128;

	
}

TGameObject::~TGameObject()
{
	// free memory for structures pointers and etc

}

void TGameObject::SetCoordCubes(int x_, int y_, int x2_, int y2_)
{

	this->x = x_;
	this->y = y_;
	this->x2 = x2_;
	this->y2 = y2_;

}

void TGameObject::SetDestroyCube(bool destroy)
{
	this->DestroyCube = destroy;
}

void TGameObject::Box2d()
{
	glColor3f(0.0f, 0.0f,0.0f);
	glBegin(GL_QUADS);

			glTexCoord2f(0.0f, 1.0f); glVertex2f( this->x,  this->y );
			glTexCoord2f(1.0f, 1.0f); glVertex2f( this->x2, this->y );
			glTexCoord2f(1.0f, 0.0f); glVertex2f( this->x2, this->y2 );
			glTexCoord2f(0.0f, 0.0f); glVertex2f( this->x,  this->y2 );

	glEnd();
	
}

void TGameObject::CheckCollision()
{
	int N_,M_ ;

	for ( int i = 0; i < N_; i++)
	{
		for ( int j = 0; j < M_; j++)
		{
			// проверка массива кубиков

		}

	}

}

bool TGameObject::isCollision(TGameObject * TGameObject)
{
	 this->CheckCollision();
	 return true;
}

void TGameObject::DrawGameCube()
{
	this->Box2d();
}

void TGameObject::SelectSizeCube(SizeCube * sz)
{
	if ( sz->minCube )
	{
		this->sz_cube = this->sz_min;
	}

	if ( sz->midleCube )
	{
		this->sz_cube = this->sz_midle;
	}

	if ( sz->bigCube )
	{
		this->sz_cube = this->sz_big;
	}
}

//void TGameObject::SelectTexture(char pathToTexture)
//{
//	this->nameTexture = pathToTexture;
//}
//
//void TGameObject::SetTexture()
//{
//	LoadTexture( this->(point)oneTexture, &this->nameTexture);
//}