#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
string sortowanie(string sygnal)
{
    char tmp;
    for(int i=0; i<sygnal.size(); i++)
    {
        for(int j=0; j<sygnal.size()-1; j++)
        {
            if(sygnal[j]>sygnal[j+1])
            {
                tmp=sygnal[j];
                sygnal[j]=sygnal[j+1];
                sygnal[j+1]=tmp;
            }
        }
    }
    return sygnal;
}
int ile(string posortowany)
{
    int licz=1;
    for(int i=0; i<posortowany.size()-1; i++)
    {
        if(posortowany[i]!=posortowany[i+1])
            licz++;
    }
    return licz;
}
bool odleglosc(string sygnal)
{
    bool czy=true;
    for(int i=0; i<sygnal.size(); i++)
    {
        for(int j=i+1; j<sygnal.size(); j++)
        {
            if(abs(sygnal[i]-sygnal[j])>10)
                czy=false;
        }
    }
    return czy;
}
int main()
{
    string sygnal, slowo;
    int licz=1;
    ifstream wczytaj("sygnaly.txt");
    ofstream wypisz("wyniki4.txt");
    wypisz<<"Zadanie 4.1."<<endl;
    cout<<"Zadanie 4.3."<<endl;
    for(int i=1; i<=1000; i++)
    {
        wczytaj>>sygnal;
        if(i%40==0)
            wypisz<<sygnal[9];
        if(licz<ile(sortowanie(sygnal)))
        {
            slowo=sygnal;
            licz=ile(sortowanie(sygnal));
        }
        if(odleglosc(sygnal)==true)
            cout<<sygnal<<endl;
    }
    wypisz<<endl<<"Zadanie 4.2."<<endl<<slowo<<" "<<licz<<endl;
    return 0;
}
