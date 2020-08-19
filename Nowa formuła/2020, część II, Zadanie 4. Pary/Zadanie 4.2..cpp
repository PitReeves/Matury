#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int liczba, licz, tmp;
    string slowo, znak;
    ifstream wczytaj("pary.txt");
    for(int i=0; i<100; i++)
    {
        wczytaj>>liczba>>slowo;
        licz=1;
        tmp=1;
        znak=slowo[0];
        for(int j=0; j<slowo.size()-1; j++)
        {
            if(slowo[j]==slowo[j+1])
            {
                tmp++;
                if(licz<tmp)
                {
                    licz=tmp;
                    znak=slowo[j];
                }
            }
            else
                tmp=1;
        }
        for(int j=0; j<licz; j++)
            cout<<znak;
        cout<<" "<<licz<<endl;
        licz=1;
    }
    return 0;
}
