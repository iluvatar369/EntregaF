#ifndef GAME_H //se establece para la clase
#define GAME_H
#include "CHARACTER.h" //se establece para composición
#include "TLOZELDA.h"
#include<iostream> //para imprimir.
//#include <string>
//#include <sstream>
using namespace std;

//const int MAX = 1000;

class GAME{//CLASE JUEGO
    private://atributos
        string nameG;
        string version;
        //CHARACTER *character[MAX];
    public://metodos
        //SOBRECARGA
        GAME(string _nameG, string _version, string, int, int, int);
        GAME(string nameG_, string version_);
        //void agregar();
        //void mostrar();
        string getname();
        string getversion();
        void welcome();
};

//Constructor 1
GAME::GAME(string _nameG, string _version, string Game, int DamagePer, int TiltAttack, int Turn){
    nameG=_nameG;
    version=_version;

}

//Constructor 2 (SOBRECARGA)
GAME::GAME(string nameG_, string version_){
    nameG= nameG_;
    version= version_;
}

//obtener nombre
string GAME::getname(){
    return nameG;
}

//obtener version
string GAME::getversion(){
    return version;
}

//bienvenida
void GAME::welcome(){
    cout<<"¡WELCOME! \nAND THIS IS!!"<<endl;
}
/*
void GAME::agregar(){
    int jugadores=0;
    character[jugadores] = new TLOZELDA ("THE LEGEND OF ZELDA", "Best Game in the world", "The hero of time");
    jugadores++;
    cout<<character[jugadores];
}


void GAME::mostrar(){
  //Ciclo que recorre el arreglo e imprime cada objeto.
    stringstream aux;
	for(int i=0; i<1 ;i++)
        aux << character[i];
}
*/

#endif // GAME_H
