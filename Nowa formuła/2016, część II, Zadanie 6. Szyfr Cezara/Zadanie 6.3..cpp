#include <iostream>
#include <fstream>
using namespace std;
bool blad(string slowo, string szyfrogram)
{
    int ascii, klucz;
    bool czy=false;
    if(slowo[0]>szyfrogram[0])
        klucz=szyfrogram[0]-64+90-slowo[0];
    else
        klucz=szyfrogram[0]-slowo[0];
    for(int i=1; i<slowo.size(); i++)
    {
        ascii=slowo[i]+klucz;
        if(ascii>90)
        {
            ascii=64+(ascii-90);
            if(ascii!=szyfrogram[i])
            {
                czy=true;
                break;
            }
        }
        else
        {
            if(ascii!=szyfrogram[i])
            {
                czy=true;
                break;
            }
        }
    }
    return czy;
}
int main()
{
    string slowo, szyfrogram;
    ifstream wczytaj("dane_6_3.txt");
    ofstream wypisz("wyniki_6_3.txt");
    wypisz<<"Zadanie 6.3."<<endl;
    for(int i=0; i<3000; i++)
    {
        wczytaj>>slowo;
        wczytaj>>szyfrogram;
        if(blad(slowo, szyfrogram)==true)
            wypisz<<slowo<<endl;
    }
    return 0;
}
