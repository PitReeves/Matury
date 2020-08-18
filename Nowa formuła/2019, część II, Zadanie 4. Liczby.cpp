#include <iostream>
#include <fstream>
using namespace std;
bool potega(int liczba)
{
    int ile=0;
    if(liczba==1)
        return true;
    else if(liczba%3==0)
    {
        while(liczba>3&&liczba%3==0)
        {
            liczba=liczba/3;
        }
        if(liczba==3)
            return true;
        else
            return false;
    }
    else
        return false;
}
int silnia(int liczba)
{
    int silnia=1;
    for(int i=2; i<=liczba; i++)
        silnia=silnia*i;
    return silnia;
}
int suma_silni(int liczba)
{
    int cyfra, suma=0;
    while(liczba!=0)
    {
        cyfra=liczba%10;
        suma=suma+silnia(cyfra);
        liczba=liczba/10;
    }
    return suma;
}
int NWD(int liczba1, int liczba2)
{
    while(liczba1!=liczba2)
    {
        if(liczba1>liczba2)
            liczba1=liczba1-liczba2;
        else
            liczba2=liczba2-liczba1;
    }
    return liczba1;
}
int main()
{
    long int tablica[500];
    int ile=0, N=500;
    long int pierwsza_max=0, dlugosc_max=0, nwd_max=0;
    ifstream wczytaj("liczby.txt");
    ofstream wypisz("wyniki4.txt");
    wypisz<<"Zadanie 4.2."<<endl;
    for(int i=0; i<500; i++)
    {
        wczytaj>>tablica[i];
        if(potega(tablica[i])==true)
            ile++;
        if(suma_silni(tablica[i])==tablica[i])
            wypisz<<tablica[i]<<endl;
    }
    for(int i=0; i<N-1; i++)
    {
        int pierwsza=tablica[i];
        int dlugosc=1;
        long int nwd=tablica[i];
        for(int j=i+1; j<N; j++)
        {
            long int n=NWD(nwd,tablica[j]);
            if(n>1)
            {
                nwd=n;
                dlugosc+=1;
            }
            if(n==1||j==N-1)
            {
                if(dlugosc_max<dlugosc)
                {
                    pierwsza_max=pierwsza;
                    dlugosc_max=dlugosc;
                    nwd_max=nwd;
                }
                break;
            }
        }
    }
    wypisz<<"Zadanie 4.1."<<endl<<ile<<endl<<"Zadanie 4.3."<<endl<<pierwsza_max<<" (pierwsza liczba ciagu), "<<dlugosc_max<<" (dlugosc ciagu), "<<nwd_max<<" (najwiekszy wspolny dzielnik)"<<endl;
    return 0;
}
