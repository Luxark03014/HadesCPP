#include "Personajes.h"
#include "FinalBoss.h"	
using namespace std;
Personaje::Personaje(int pVida, int pAtaque, string pNombre, int px, int py) {
	vida = pVida;
	ataque = pAtaque;
	nombre = pNombre;
	x = px;
	y = py;
}

void Personaje::setPosition(int px, int py, string input) {
	if (input == "up")
	{
		y--;
	}
	else if (input == "down")
	{
		y++;
	}
	else if (input == "left")
	{
		x--;
	}
	else if (input == "right")
	{
		x++;
	
	}
	

}


int Personaje::getPositionX(){
	return x;

}
int Personaje::getPositionY() {
	return y;

}
string Personaje::getName() {
	return nombre;
}
int Personaje::getAttack() {
	return ataque;
}
int Personaje::getHP() {
	return vida;
}
void Personaje::setHP(int ataque) {
	vida = vida - ataque;
	if (vida <= 0)
	{
		vida = 0;
	}
}