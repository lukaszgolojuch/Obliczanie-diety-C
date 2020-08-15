//
//  uzytkownik.cpp
//  kaloryka
//
//  Created by Łukasz Gołojuch on 17/06/2020.
//  Copyright © 2020 Łukasz Gołojuch. All rights reserved.
//
#include <iostream>
#include "uzytkownik.hpp"

using namespace std;

const int bialko_kcal = 4;
const int tluszcze_kcal = 9;
const int weglowodany_kcal = 4;

void User::dieta_redukcja()
{
    //Początek deklaracji zmiennych
    int aktualna_kaloryka = 0;
    int deficyt_kaloryczny = 500;
    int kalorii_w_diecie;
    int kcal_z_tluszczy;
    int kcal_z_wegli;
    //Koniec deklaracji zmiennych
    
    kalorii_w_diecie = zapotrzebowanie - deficyt_kaloryczny;
    
    kcal_z_tluszczy = 0.2 * kalorii_w_diecie;

    bialka = 2.2 * waga;
    tluszcze = kcal_z_tluszczy / tluszcze_kcal;
    aktualna_kaloryka = kcal_z_tluszczy + bialka * bialko_kcal;
    kcal_z_wegli = kalorii_w_diecie - aktualna_kaloryka;
    weglowodany = kcal_z_wegli/weglowodany_kcal;
    
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"|TWOJA DIETA REDUKCYJNA:"<<endl;
    cout<<"|Twoj BMR wynosi: "<<bmr<<" kcal"<<endl;
    cout<<"|Twoje zapotrzebowanie kaloryczne wynosi: "<<zapotrzebowanie<<" kcal"<<endl;
    cout<<"|Aby zredukowac tkanke tluszczowa musisz pzyjmowac: "<<kalorii_w_diecie<<" kcal"<<endl;
    cout<<"|Makroskladniki:"<<endl;
    cout<<"|Bialka: "<<bialka<<"g"<<endl;
    cout<<"|Tluszcze: "<<tluszcze<<"g"<<endl;
    cout<<"|Weglowodany: "<<weglowodany<<"g"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
}

void User::dieta_utrzymanie()
{
    //Początek deklaracji zmiennych
    int kalorii_w_diecie;
    int kcal_z_bialka;
    int kcal_z_wegli;
    int kcal_z_tluszczy;
    //Koniec deklaracji zmiennych

    kalorii_w_diecie = zapotrzebowanie;

    kcal_z_tluszczy = 0.2 * kalorii_w_diecie;
    kcal_z_bialka = 0.3 * kalorii_w_diecie;
    kcal_z_wegli = 0.5 * kalorii_w_diecie;
    
    bialka = kcal_z_bialka / bialko_kcal;
    tluszcze = kcal_z_tluszczy / tluszcze_kcal;
    weglowodany = kcal_z_wegli / weglowodany_kcal;
    
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"|TWOJA DIETA NA UTRZYMANIE:"<<endl;
    cout<<"|Twoj BMR wynosi: "<<bmr<<" kcal"<<endl;
    cout<<"|Twoje zapotrzebowanie kaloryczne wynosi: "<<zapotrzebowanie<<" kcal"<<endl;
    cout<<"|Aby utrzymac aktualna figure musisz pzyjmowac: "<<kalorii_w_diecie<<" kcal"<<endl;
    cout<<"|Makroskladniki:"<<endl;
    cout<<"|Bialka: "<<bialka<<"g"<<endl;
    cout<<"|Tluszcze: "<<tluszcze<<"g"<<endl;
    cout<<"|Weglowodany: "<<weglowodany<<"g"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
}

void User::dieta_masa()
{
    //Początek deklaracji zmiennych
    int aktualna_kaloryka = 0;
    int nadwyzka_kaloryczna = 500;
    int kalorii_w_diecie;
    int kcal_z_tluszczy;
    int kcal_z_wegli;
    //Koniec deklaracji zmiennych

    kalorii_w_diecie = zapotrzebowanie - nadwyzka_kaloryczna;
    
    kcal_z_tluszczy = 0.25 * kalorii_w_diecie;
    
    bialka = 2 * waga;
    tluszcze = kcal_z_tluszczy / tluszcze_kcal;
    aktualna_kaloryka = kcal_z_tluszczy + bialka * bialko_kcal;
    kcal_z_wegli = kalorii_w_diecie - aktualna_kaloryka;
    weglowodany = kcal_z_wegli/weglowodany_kcal;
    
    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"|TWOJA DIETA NA BUDOWE MASY MIESNIOWEJ:"<<endl;
    cout<<"|Twoj BMR wynosi: "<<bmr<<" kcal"<<endl;
    cout<<"|Twoje zapotrzebowanie kaloryczne wynosi: "<<zapotrzebowanie<<" kcal"<<endl;
    cout<<"|Aby zwiekszyc mase miesniowa: "<<kalorii_w_diecie<<" kcal"<<endl;
    cout<<"|Makroskladniki:"<<endl;
    cout<<"|Bialka: "<<bialka<<"g"<<endl;
    cout<<"|Tluszcze: "<<tluszcze<<"g"<<endl;
    cout<<"|Weglowodany: "<<weglowodany<<"g"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    
}
    
void User::wczytaj_dane(int wi,float wa,float wy, float akt, bool kob)
    {
        if(wi>0 && wa>0 && wy>0)
        {
            wiek = wi;
            waga = wa;
            wysokosc = wy;
            kobieta = kob;
        }
        else
        {
            cout<<endl<<"Podane dane są niepoprawne sprobuj ponownie pozniej"<<endl;
            exit(0);
        }
    }
    
void User::wczytaj_aktywnosc(float akt)
    {
        if(akt>0)
        {
            aktywnosc=akt;
        }
        else
        {
            cout<<endl<<"Podane dane są niepoprawne sprobuj ponownie pozniej"<<endl;
            exit(0);
        }
    }
void User::oblicz_bmr()
    {
        //sprawdzamy czy uzytkownik jest mezczyzna czy kobieta w celu obliczenia BMR
        if(kobieta)
        {
            //wzor dla kobiety: 655 + [9,6 x masa ciała (kg)] + [1,8 x wzrost (cm)] - [4,7 x wiek (lata)]
            bmr = 655 + (9.6 * waga) + (1.8 * wysokosc) + (4.7 * wiek);
        } else
        {
            //wzor dla mezczyzny: 66 + [13,7 x masa ciała (kg)] + [5 x wzrost (cm)] - [6,76 x wiek (lata)]
            bmr = 66 + (13.7 * waga) + (5 * wysokosc) + (6.76 * wiek);
        }
    }
void User::oblicz_zapotrzebowanie()
    {
        oblicz_bmr();
        zapotrzebowanie = bmr * aktywnosc;
    }
    
User::User(int wi, float wa, float wy, float akt, bool kob)
    {
        wczytaj_dane(wi, wa, wy, akt, kob);
        wczytaj_aktywnosc(akt);
    }

void User::menu_obliczaniediety()
{
    //Początek deklaracji zmiennych
    int wybor;
    //Koniec deklaracji zmiennych

    cout<<endl<<"-----------------------------------------------------------------"<<endl;
    cout<<"Jaki jest cel Twojej diety?"<<endl;
    cout<<"Opcje:"<<endl;
    cout<<"1. Redukcja tkanki tluszczowej "<<endl;
    cout<<"2. Utrzymanie aktualnej masy ciala"<<endl;
    cout<<"3. Zwiekszenie masy"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    
    //instrukcja warunkowa w celu uruchomienia odpowiedniej funkcji tworzacych okreslona diete
    if(wybor==1)
    {
        dieta_redukcja();
    } else if(wybor==2)
    {
        dieta_utrzymanie();
    } else if (wybor==3)
    {
        dieta_masa();
    } else
    {
        cout<<endl<<"Podane dane są niepoprawne... sprobuj ponownie"<<endl;
        menu_obliczaniediety();
    }
    
}
