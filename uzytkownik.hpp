//
//  uzytkownik.hpp
//  kaloryka
//
//  Created by Łukasz Gołojuch on 17/06/2020.
//  Copyright © 2020 Łukasz Gołojuch. All rights reserved.
//

#ifndef uzytkownik_hpp
#define uzytkownik_hpp

#include <stdio.h>

class User{
    
private:
    int wiek; //wiek w latach
    float waga; // waga uzytkownika [kg]
    float wysokosc; // wzrost uzytkownika [cm]
    float aktywnosc; // aktywnosc uzytkownika (1.0-2.0)
    bool kobieta; // TRUE - kobieta False - Mezczyzna
    
public:
    float bmr; // zmienna przechowujaca obliczone BMI uzytkownika
    float zapotrzebowanie; // zmienna przechowujaca obliczone zapotrzebowanie kaloryczne uzytkownika
    float weglowodany; // zmienna przechowujaca ilosc weglowodanow w diecie [g]
    float bialka; // zmienna przechowujaca ilosc bialka w diecie [g]
    float tluszcze; // zmienna przechowujaca ilosc tluszczy w diecie [g]
    
    /* Funkcja wczytujaca dane podane przez uzytkownika i zapisujaca je jako dane tworzonego obiektu w tym wypadku uzytkownika/osoby dla ktorej uzytkownik takowa diete chce wygenerowac */
    void wczytaj_dane(int, float, float, float,bool);
    
    /* Funkcja wczytujaca rodzaj aktywnosci podany przez uzytkownika i zapisujaca je jako dane utworzonego oniektu */
    void wczytaj_aktywnosc(float);
    
    /* Funkcja obliczajaca BMR uzytkownika */
    void oblicz_bmr();
    
    /* Funkcja obliczajaca zapotrzebowanie kaloryczne obiektu */
    void oblicz_zapotrzebowanie();
    
    /* Funkcja void obliczajaca ile kcal obiekt musi skonsumowac w celu redukcji tkanki tluszczowej. Dodatkowo oblicza ona takze zapotrzebowanie w makro skladniki w ww. diecie */
    void dieta_redukcja();
    
    /* Funkcja void obliczajaca ile kcal obiekt musi skonsumowac w celu utrzymania aktualnej masy ciala. Dodatkowo oblicza ona takze zapotrzebowanie w makro skladniki w ww. diecie */
    void dieta_utrzymanie();
    
    /* Funkcja void obliczajaca ile kcal obiekt musi skonsumowac w celu budowy masy miesniowej. Dodatkowo oblicza ona takze zapotrzebowanie w makro skladniki w ww. diecie */
    void dieta_masa();
    
    /* Menu pozwalajace uzytkownikowi programu wybrac rodzaj diety jaka ma zostac obliczona dla niego podczas dzialania programu */
    void menu_obliczaniediety();
    
    //Konstruktor obiektu
    User(int,float,float,float,bool);
    
};

#endif /* uzytkownik_hpp */
