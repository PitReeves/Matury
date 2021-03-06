#include <iostream>
#include <fstream>
using namespace std;
string deszyfrowanie(string szyfrogram, int klucz)
{
    int ascii;
    klucz=klucz%26;
    for(int i=0; i<szyfrogram.size(); i++)
    {
        ascii=szyfrogram[i]+klucz;
        if(ascii>90)
            ascii=65+(ascii-91);
        szyfrogram[i]=ascii;
    }
    return szyfrogram;
}
int main()
{
    string szyfrogram[700];
    int klucz[700];
    ifstream wczytaj("dane_6_2.txt");
    ofstream wypisz("wyniki_6_2.txt");
    wypisz<<"Zadanie 6.2."<<endl;
    for(int i=0; i<700; i++)
    {
        wczytaj>>szyfrogram[i];
        wczytaj>>klucz[i];
        wypisz<<deszyfrowanie(szyfrogram[i], klucz[i])<<endl;
    }
    return 0;
}
