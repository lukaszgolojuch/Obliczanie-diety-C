//
//  main.cpp
//  kaloryka
//
//  Created by Łukasz Gołojuch on 17/06/2020.
//  Copyright © 2020 Łukasz Gołojuch. All rights reserved.
//

#include <iostream>
#include "uzytkownik.hpp"
#include "main.hpp"

using namespace std;

//Deklaracje zmiennych globalnych
int wi; // zmienna przechowujaca wiek, w celu przekazania do funkcji
float wa; // zmienna przechowujaca wage, w celu przekazania do funkcji
float wy; // zmienna przechowujaca wzrost, w celu przekazania do funkcji
float akt =1; // zmienna przechowujaca aktywnosc, w celu przekazania do funkcji
bool kob; // zmienna boolowska przechowujaca informacje czy badany jes kobieta (1), czy mezczyzna (0)
//Koniec deklaracji zmiennych globalnych

/* Funkcja pobierajaca od klienta dane tj. plec, wiek, wage i wzrost w celu wykonania dalszych obliczen ktorych wynik uzytkownik chcr poznac */

void podaj_dane()
{
    //Deklaracje zmiennych lokalnych
    int wybor; //zmienna przechowujaca wybor w menu (zakres 1 - 3)
    //Koniec deklaracji zmiennych lokalnych
    
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"Plec"<<endl;
    cout<<"1 - jestem kobieta"<<endl;
    cout<<"2 - jestem mezczyzna"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    
    //switch case dla wyboru plci uzytkownika
    switch (wybor)
    {
        case 1:
            kob = true;
            break;
        case 2:
            kob = false;
            break;
        default:
            cout<<"Dane wejsciowe sa bledne... sprobuj ponownie"<<endl;
            podaj_dane();
            break;
    }
    //koniec switch case
    
    //pobieranie wieku wagi i wzrostu użytkownika
    cout<<"Podaj wiek w latach: ";
    cin>>wi;
    
    cout<<"Podaj wage w kg: ";
    cin>>wa;
    
    cout<<"Podaj wzrost w cm: ";
    cin>>wy;
    //koniec pobierania wieku wagi i wzrostu użytkownika
}

/* Funkcja pobierajaca od uzytkownika dane odnosie rodzaju aktywnosci uprawianej przez uzytkownika programu/osoby dla ktorej wylicza diete */

void podaj_aktywnosc()
{
    //Deklaracje zmiennych lokalnych
    int wybor; //zmienna przechowujaca wybor w menu (zakres 1 - 3)
    //Koniec deklaracji zmiennych lokalnych
    
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"Jak wyglada Twoja aktywnosc"<<endl;
    cout<<"1. Znikoma aktywnosc (siedzacy tryb zycia, praca biurowa)"<<endl;
    cout<<"2. Bardzo niska aktywnosc (jeden trening w tygodniu, praca biurowa) "<<endl;
    cout<<"3. Umiarkowana (cwiczenia 2 razy w tygodniu - srednia intensywnosc)"<<endl;
    cout<<"4. Duza (dosc ciezki trening kilka razy w tygodniu)"<<endl;
    cout<<"5. Bardzo duza (przynajmniej 4 ciezkie treningi fizyczne w tygodniu, praca fizyczna)"<<endl;
    cout<<"5. Najwyzsza (codzienny ciezki trening, ciezka praca fizyczna)"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    
    switch (wybor)
    {
        case 1:
            akt = 1.0;
            break;
        case 2:
            akt = 1.2;
            break;
        case 3:
            akt = 1.4;
            break;
        case 4:
            akt = 1.6;
            break;
        case 5:
            akt = 1.8;
            break;
        case 6:
            akt = 2.0;
            break;
        default:
            cout<<"Dane wejsciowe sa bledne... sprobuj ponownie"<<endl;
            podaj_aktywnosc();
            break;
    }
    
}

int main() {
    //Deklaracje zmiennych lokalnych
    int wybor; //zmienna przechowujaca wybor w menu (zakres 1 - 3)
    //Koniec deklaracji zmiennych lokalnych
    
    //Poczatek menu wyboru
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"Witam w programie tworzacym Twoja nowa diete!!!!"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1. Oblicz BMR "<<endl;
    cout<<"2. Oblicz zapotrzebowanie kaloryczne i BMR"<<endl;
    cout<<"3. Oblicz docelowa ilos kalorii i makrosklanikow"<<endl;
    cout<<"4. Wyjście z aplikacji"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    //koniec menu i wczytywania wyboru
    
    if(wybor==1)
    {
        //Obliczamy BMR uzytkownika
        podaj_dane();
        User uzytkownik1(wi, wa, wy, akt, kob);
        uzytkownik1.oblicz_bmr();
        cout<<"Twoje BMR wynosi: "<<uzytkownik1.bmr<<"kcal"<<endl;
        
    } else if(wybor==2)
    {
        //Obliczamy zapotrzebowanie kaloryczne klienta
        podaj_dane();
        podaj_aktywnosc();
        User uzytkownik1(wi, wa, wy, akt, kob);
        uzytkownik1.oblicz_zapotrzebowanie();
        cout<<"Twoje BMR wynosi: "<<uzytkownik1.bmr<<"kcal"<<endl;
        cout<<"Twoje zapotrzebowanie kaloryczne wynosi: "<<uzytkownik1.zapotrzebowanie<<"kcal"<<endl;


    } else if(wybor==3)
    {
        //Obliczamy docelowa ilosc kalorii i makroskladnikow w diecie uzytkownika
        podaj_dane();
        podaj_aktywnosc();
        User uzytkownik1(wi, wa, wy, akt, kob);
        uzytkownik1.oblicz_zapotrzebowanie();
        uzytkownik1.menu_obliczaniediety();
        
    } else if (wybor==4)
    {
        //wyjscie z programu
        exit(0);
        
    } else
    {
        //podana liczba z poza zakresu 1,2,3,4... BLAD
        cout<<" "<<endl;
        main();
    }
    
    
    return 0;
}
