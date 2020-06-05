#ifndef FINALFANTASY_H
#define FINALFANTASY_H
#include"SEPHIROTH.h"//llamada de clase SEPHIROTH
#include"CHARACTER.h"//Llamada de clase jugador
#include<iostream> //para imprimir.

using namespace std;

class FINALFANTASY:public CHARACTER{//CLASE FINALFANTASY (hija), con herencia a PERSONAJE
    private://Atributos
        string NameF;
        bool LimitBreakF;
        int SmashF;
        string info;
        string infoPlayer;
    public://Metodos
        //SOBRECARGA
        FINALFANTASY(string, int, int, int, string, bool, int);
        FINALFANTASY(string, int, int, int, string, bool, int, string);//SOBRECARGA PARA UNA SOBREESCRITURA
        FINALFANTASY(string,string,string);
        FINALFANTASY(): NameF(""), info(""), infoPlayer(""){};
        void ShowInfoGame();///metodo polimorfismo y sobrescritura de clase abstracta
        string ShowNameF();
        int Mako(SEPHIROTH &s);
        bool GetLimitBreakF();
};

//Constructor 1
FINALFANTASY::FINALFANTASY(string _Game, int _DamagePer, int _TiltAttack, int _Turn, string _NameF, bool _LimitBreakF, int _SmashF):CHARACTER(_Game, _DamagePer, _TiltAttack, _Turn){
    NameF=_NameF;
    LimitBreakF=_LimitBreakF;
    SmashF=_SmashF;
}

//Constructor 2 (SOBRECARGA)
FINALFANTASY::FINALFANTASY(string _Game, int _DamagePer, int _TiltAttack, int _Turn, string _NameF, bool _LimitBreakF, int _SmashF, string inf)
:CHARACTER(_Game, _DamagePer, _TiltAttack, _Turn){
    info=inf;
}

FINALFANTASY::FINALFANTASY(string _Game, string information, string infPlayer):CHARACTER(_Game){
    info=information;
    infoPlayer=infPlayer;
}

//Mostrar la información del juego(SUBREESCRITURA)
void FINALFANTASY::ShowInfoGame(){///metodo de polimorfismo para esta clase y sobrescritura de clase ABSTRACTA
    cout<<"You chose ";
    cout<<Game;
    cout<<"\nExtra game info: ";
    cout<<info<<"\n";
    cout<<"\nYou will be Cloud and your enemy Sephiroth"<<endl;
    cout<<"Extra -Cloud- info: ";
    cout<<infoPlayer;
}

//Mostrar el nombre del personaje
string FINALFANTASY::ShowNameF(){
    cout<<NameF;
    return NameF;
}

//Obtener el ataque especial dependiendo del metodo (GetLimitBreakF)
int FINALFANTASY::Mako(SEPHIROTH &s){//apuntando directamente a la clase SEPHIROTH
    if(LimitBreakF==true){//Si la barra de magia esta llena(TRUE)
        int SA;//variable para selección
        cout<<"Do yo want to do your Smash Attack? 1)YES...any other number)NO"<<endl;
        cin>>SA;
        if (SA==1){//Si la selección es 1 vale 43
            SmashF=40;
            s.DamageRecive(40);
            cout<<"You used MAKO of 40!!!"<<endl;
        }
    }
    else{//SINO vale 0
        SmashF=0;
        s.DamageRecive(0);
    }
    return SmashF;
}

//Obtener la barra de magia
bool FINALFANTASY::GetLimitBreakF(){
    if(Turn%3==0){//Si el turno del jugador es div entre 3
        LimitBreakF=true;//la barra estará llena
    }
    else{
        LimitBreakF=false;//sino estará vacía
    }
    return LimitBreakF;
}

#endif // FINALFANTASY_H
