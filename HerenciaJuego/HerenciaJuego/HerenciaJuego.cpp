
#include "Personajes.h"
#include "FinalBoss.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

void youLost() {
    system("cls");
    cout << "HAS PERDIDO";
    exit(0);
}
void youWon() {
    system("cls");
    cout << "HAS VENCIDO A HADES Y ESCAPASTE DEL INFRAMUNDO! FELICIDADES";
    exit(0);
}
void statuspelea(Personaje& Zagreo, Personaje& Enemigo) {
    system("cls");
    cout << "PELEA ENTRE " << Zagreo.getName() << " Y " << Enemigo.getName() << "\n";
    cout << "=================================================================\n";
    cout << "Tu Vida: " << Zagreo.getHP() << "            Vida Enemigo: " << Enemigo.getHP() << "\n";
    cout << "Tu ataque " << Zagreo.getAttack() << "            Ataque Enemigo: " << Enemigo.getAttack() << "\n";

}
void peleaFinal(Personaje& Zagreo, FinalBoss& Hades) {
    srand(time(NULL));
    
    cout << "BIENVENIDO A LA PELEA FINAL CONTRA " << Hades.getName() << "\n";
    while (Zagreo.getHP() > 0 && Hades.getHP() > 0)
    {
        system("pause");
        system("cls");
        cout << "=================================================================\n";
        cout << "Tu Vida: " << Zagreo.getHP() << "            Vida Enemigo: " << Hades.getHP() << "\n";
        cout << "Tu ataque " << Zagreo.getAttack() << "            Ataque Enemigo: " << Hades.getAttack() << "\n";

        cout << "Atacaste al enemigo " << Hades.getName() << " con un golpe de " << Zagreo.getAttack() << " puntos de DMG.\n";
        Hades.setHP(Zagreo.getAttack());
        system("pause");
        if (rand() % 2 == 0)
        {
            cout << Hades.getName() << " se esta preparando para hacer un ataque potenciado ";
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << " . ";
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << " . ";
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << " . \n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            if (rand() % 2 == 0)
            {
                Hades.setFrozenShot(rand() % 2);
                if (Hades.getFrozenShot() > 0)
                {
                    Zagreo.setHP(Hades.getFrozenShot());
                }
            }
            else
            {
                Hades.setFireFall(rand() % 2);
                if (Hades.getFireFall() > 0)
                {
                    Zagreo.setHP(Hades.getFireFall());
                }
            }
        }
        else {
            cout << "El enemigo te ha atacado con un golpe de " << Hades.getAttack() << " puntos de DMG.\n";
            Zagreo.setHP(Hades.getAttack());
        }
        if (Hades.getHP() <= 0)
        {
            youWon();
        }

    }
    if (Zagreo.getHP() <= 0)
    {
        youLost();
    }
}
void pelea(Personaje& Zagreo, Personaje& Enemigo) {
    system("pause");
    system("cls");
    int turno = 1;

    while (Zagreo.getHP() > 0 && Enemigo.getHP() > 0)
    {
        
        statuspelea(Zagreo, Enemigo);
      
        cout << "TURNO " << turno;
        cout << "\n================================================================\n";
        cout << "Atacaste al enemigo " << Enemigo.getName() << " con un golpe de " << Zagreo.getAttack() << " puntos de DMG.\n";
        cout << "El enemigo te ha atacado con un golpe de " << Enemigo.getAttack() << " puntos de DMG.\n";
        system("pause");
        system("cls");
      

        Zagreo.setHP(Enemigo.getAttack());
        Enemigo.setHP(Zagreo.getAttack());
        
       
       
            if (Enemigo.getHP() <= 0)
            {
                cout << "Has vencido a " << Enemigo.getName() << " ahora sigue con tu misión\n";
                system("pause");
                system("cls");
               
            }
           
            turno++;
        

        
        
      
    }
    if (Zagreo.getHP() <= 0)
    {
        youLost();
    }







}
void printTablero(int x, int y, int e1x, int e1y, int e2x, int e2y, int e3x, int e3y, int e4x, int e4y, int fbx, int fby, Personaje& Zagreo, Personaje& Enemigo1, Personaje& Enemigo2, Personaje& Enemigo3, Personaje& Enemigo4, FinalBoss& Hades) {

    system("cls");
    const int tx = 10;
    const int ty = 5;
    char tablero[10][5];
    //llena el array de asteriscos
    for (int i = 0; i < tx; i++) {
        for (int j = 0; j < ty; j++) {
            tablero[i][j] = '*';
        }
    }
    

    tablero[y][x] = '+';
    for (int i = 0; i < tx; i++) {
        for (int j = 0; j < ty; j++) {
            cout << tablero[i][j] << "  ";
        }
        cout << "\n";
    }
    /*
    if (Enemigo1.getHP() > 0 )
    {
        
        tablero[e1y][e1x] = '-';
        
      
    }
    if (Enemigo2.getHP() > 0)
    {
        tablero[e2y][e2x] = '-';
    }
    if (Enemigo3.getHP() > 0)
    {
        tablero[e3y][e3x] = '-';
    }
    if (Enemigo4.getHP() > 0)
    {
        tablero[e4y][e4x] = '-';
    }
    


    tablero[fby][fbx] = '#';
    */
    // printeo del array
    
    if (Enemigo1.getHP() > 0)
    {
        if (x == e1x && y == e1y)
        {
            cout << "VAYA TE HAS ENCONTRADO A UN ENEMIGO LLAMADO " << Enemigo1.getName() << "\n";
            pelea(Zagreo, Enemigo1);
        }
    }
    if (Enemigo2.getHP() > 0)
    {
        if (x == e2x && y == e2y)
        {
            cout << "VAYA TE HAS ENCONTRADO A UN ENEMIGO LLAMADO " << Enemigo2.getName() << "\n";
            pelea(Zagreo, Enemigo2);
        }
    }
    if (Enemigo3.getHP() > 0)
    {
        if (x == e3x && y == e3y)
        {
            cout << "VAYA TE HAS ENCONTRADO A UN ENEMIGO LLAMADO " << Enemigo3.getName() << "\n";
            pelea(Zagreo, Enemigo3);
        }
    }
    if (Enemigo4.getHP() > 0)
    {
        if (x == e4x && y == e4y)
        {
            cout << "VAYA TE HAS ENCONTRADO A UN ENEMIGO LLAMADO " << Enemigo4.getName() << "\n";
            pelea(Zagreo, Enemigo4);
        }
    }
    if (x == fbx && y == fby)
    {
        peleaFinal(Zagreo, Hades);
    }

}




int main() 
{
    srand(time(NULL));
    int key;
    Personaje Zagreo = Personaje(410, 35, "Zagreo", 2, 0);
    Personaje Enemigo1 = Personaje(75, 15, "Hydra", rand() % 4, 2);
    Personaje Enemigo2 = Personaje(75, 15, "Minotauro", rand() % 4, 4);
    Personaje Enemigo3 = Personaje(75, 15, "Serpiente", rand() % 4, 6);
    Personaje Enemigo4 = Personaje(75, 15, "Teseo", rand() % 4, 8);
    FinalBoss Hades = FinalBoss(250, 55, "Hades", rand() % 4, 9, 0, 0);


    int xInicial;
    int yInicial;





    printTablero(Zagreo.getPositionX(), Zagreo.getPositionY(), Enemigo1.getPositionX(), Enemigo1.getPositionY(),
            Enemigo2.getPositionX(), Enemigo2.getPositionY(), Enemigo3.getPositionX(), Enemigo3.getPositionY(),
            Enemigo4.getPositionX(), Enemigo4.getPositionY(), Hades.getPositionX(), Hades.getPositionY(), Zagreo, Enemigo1, Enemigo2, Enemigo3, Enemigo4, Hades);

    string input;


    while ((key = _getch()) != 27) {
        if (key == 0 || key == 224) {
            switch (_getch()) {
            case 72://flechaArriba 
                input = "up";
                Zagreo.setPosition(Zagreo.getPositionX(), Zagreo.getPositionY(), input);
                break;
            case 80: //flechaAbajo
                input = "down";
                Zagreo.setPosition(Zagreo.getPositionX(), Zagreo.getPositionY(), input);
                break;
            case 75: //flechaIzquierda
                input = "left";
                Zagreo.setPosition(Zagreo.getPositionX(), Zagreo.getPositionY(), input);
                break;
            case 77: //flechaDerecha
                input = "right";
                Zagreo.setPosition(Zagreo.getPositionX(), Zagreo.getPositionY(), input);
                break;
            }
        }


        printTablero(Zagreo.getPositionX(), Zagreo.getPositionY(), Enemigo1.getPositionX(), Enemigo1.getPositionY(),
            Enemigo2.getPositionX(), Enemigo2.getPositionY(), Enemigo3.getPositionX(), Enemigo3.getPositionY(),
            Enemigo4.getPositionX(), Enemigo4.getPositionY(), Hades.getPositionX(), Hades.getPositionY(), Zagreo, Enemigo1, Enemigo2, Enemigo3, Enemigo4, Hades);
    }



}