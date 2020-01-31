#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string slowo;
    ifstream wczytaj("dane_6_1.txt");
    ofstream wypisz("wyniki_6_1.txt");
    wypisz<<"Zadanie 6.1."<<endl;
    for(int i=0; i<100; i++)
    {
        wczytaj>>slowo;
        for(int j=0; j<slowo.size(); j++)
        {
            if(slowo[j]<88)
                slowo[j]=slowo[j]+3;
            else if(slowo[j]==88)
                slowo[j]=65;
            else if(slowo[j]==89)
                slowo[j]=66;
            else if(slowo[j]==90)
                slowo[j]=67;
        }
        wypisz<<slowo<<endl;
    }
    return 0;
}
