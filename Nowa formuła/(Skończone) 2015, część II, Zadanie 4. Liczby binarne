#include <iostream>
#include <fstream>
using namespace std;
bool wiecej(string liczba)
{
    int zera=0, jedynki=0;
    for(int i=0; i<liczba.size(); i++)
    {
        if(liczba[i]=='0')
            zera++;
        else
            jedynki++;
    }
    if(zera>jedynki)
        return true;
    else
        return false;
}
bool dwa(string liczba)
{
    bool czy=false;
    if(liczba[liczba.size()-1]=='0')
        czy=true;
    return czy;
}
bool osiem(string liczba)
{
    bool czy=true;
    for(int i=liczba.size()-3; i<liczba.size(); i++)
    {
        if(liczba[i]!='0')
        {
            czy=false;
            break;
        }
    }
    return czy;
}
int main()
{
    string liczba, liczba_min="11010100111", liczba_max="11010100111";
    int ile=0, licz_1=0, licz_2=0, pozycja_min, jedynki, maksymalna=0, pozycja_max;
    ifstream wczytaj("liczby.txt");
    ofstream wypisz("wynik4.txt");
    for(int i=1; i<=1000; i++)
    {
        wczytaj>>liczba;
        if(wiecej(liczba)==true)
            ile++;
        if(dwa(liczba)==true)
            licz_1++;
        if(osiem(liczba)==true)
            licz_2++;
        if(liczba.size()<liczba_min.size())
        {
            liczba_min=liczba;
            pozycja_min=i;
        }
        if(liczba.size()==liczba_min.size())
        {
            for(int j=1; j<liczba.size(); j++)
            {
                if(liczba[j]<liczba_min[j])
                {
                    liczba_min=liczba;
                    pozycja_min=i;
                    break;
                }
            }
        }
        if(liczba.size()>liczba_max.size())
        {
            liczba_max=liczba;
            pozycja_max=i;
        }
        jedynki=0;
        if(liczba.size()==liczba_max.size())
        {
            while(liczba[jedynki]=='1'&&jedynki<liczba.size())
                jedynki++;
        }
        if(jedynki>maksymalna)
        {
            maksymalna=jedynki;
            pozycja_max=i;
        }
    }
    wypisz<<"Zadanie 4.1."<<endl<<ile<<endl<<"Zadanie 4.2."<<endl<<licz_1<<" - liczba liczb podzielnych przez 2."<<endl<<licz_2<<" - liczba liczb podzielnych przez 8."<<endl<<"Zadanie 4.3"<<endl<<pozycja_min<<" - numer wiersza zawierajacego minimalna liczbe."<<endl<<pozycja_max<<" - numer wiersza zawierajacego maksymalna liczbe."<<endl;
    return 0;
}
