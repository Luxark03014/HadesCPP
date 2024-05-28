#pragma once
#include <iostream>
using namespace std;

class Personaje
{
	private:
		int vida;
		int ataque;
		string nombre;
		int x;
		int y;

	public:
		Personaje(int pVida, int pAtaque, string pNombre, int px, int py);
		void setPosition(int px, int py, string input);
		int getPositionX();
		int getPositionY();
		string getName();
		int getHP();
		int getAttack();
		void setHP(int ataque);
};