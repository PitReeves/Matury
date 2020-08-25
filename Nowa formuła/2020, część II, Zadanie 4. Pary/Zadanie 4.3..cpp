#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int liczba1=3, liczba2;
    string slowo1="asq", slowo2;
    ifstream wczytaj("pary.txt");
    for(int i=1; i<100; i++)
    {
        wczytaj>>liczba2>>slowo2;
        if(liczba2==slowo2.size())
        {
            if(liczba2<liczba1)
            {
                liczba1=liczba2;
                slowo1=slowo2;
            }
            else
            {
                for(int j=0; j<slowo1.size(); j++)
                {
                    if(slowo2[j]<slowo1[j])
                    {
                        liczba1=liczba2;
                        slowo1=slowo2;
                        break;
                    }
                }
            }
        }
    }
    cout<<liczba1<<" "<<slowo1<<endl;
    return 0;
}
