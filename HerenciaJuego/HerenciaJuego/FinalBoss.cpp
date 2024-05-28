#include "FinalBoss.h"	
using namespace std;


FinalBoss::FinalBoss(int pVida,
	int pAtaque,
	string pNombre,
	int px, 
	int py,
	int pFrozenShot,
	int pFireFall) : Personaje(pVida,
		pAtaque,
		pNombre,
		px,
		py
		) {
	FrozenShot = pFrozenShot;
	FireFall = pFireFall;
	
}


int FinalBoss::getFireFall() {
	return FireFall;
}
int FinalBoss::getFrozenShot() {
	return FrozenShot;
}
void FinalBoss::setFrozenShot(int pFrozenShot) {
	if (pFrozenShot == 0)
	{
		cout << "El Final Boss ha lanzado un ataque gelido y ha hecho 70 puntos de daño \n";
		FrozenShot = 70;
	}
	else {
		cout << "El Final Boss ha intentado lanzar un ataque gelido pero ha fallado \n";
		FrozenShot = 0;
	}

}

void FinalBoss::setFireFall(int pFireFall) {
	if (pFireFall == 0)
	{
		cout << "El Final Boss ha lanzado una cascada de lava y ha hecho 70 puntos de daño \n";
		FireFall = 70;
	}
	else {
		cout << "El Final Boss ha intentado lanzar una cascada de lava pero ha fallado \n";
		FireFall = 0;
	}
	
	
		
}