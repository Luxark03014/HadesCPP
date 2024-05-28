#pragma once
#include "Personajes.h"
#include <iostream>
using namespace std;

class FinalBoss : public Personaje
{
	private:
		int FrozenShot;
		int FireFall;

	public:
		FinalBoss(int pVida, int pAtaque, string pNombre, int px, int py, int pFrozenShot, int pFireFall);

		int getFrozenShot();
		int getFireFall();

		void setFireFall(int pFireFall);
		void setFrozenShot(int pFrozenShot);


	

};