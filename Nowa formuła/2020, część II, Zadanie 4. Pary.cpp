#include <iostream>
#include <fstream>
using namespace std;
int czy_pierwsza(int liczba)
{
    bool czy=true;
    for(int i=2; i<liczba; i++)
    {
        if(liczba%i==0)
            czy=false;
    }
    return czy;
}
int main()
{
    int liczba, a, b;
    string slowo;
    ifstream wczytaj("pary.txt");
    ofstream wypisz("wyniki4.txt");
    for(int i=0; i<100; i++)
    {
        wczytaj>>liczba>>slowo;
        if(liczba%2==0)
        {
            a=0;
            b=0;
            for(int j=3; j<=liczba-3; j++)
            {
                if(czy_pierwsza(j)==1&&czy_pierwsza(liczba-j)==1&&(liczba-j-j>a-b||liczba-j-j==a-b))
                {
                    a=liczba-j;
                    b=j;
                }
            }
            wypisz<<liczba<<" ";
            if(a<b)
                wypisz<<a<<" "<<b<<endl;
            else
                wypisz<<b<<" "<<a<<endl;
        }
    }
    return 0;
}
