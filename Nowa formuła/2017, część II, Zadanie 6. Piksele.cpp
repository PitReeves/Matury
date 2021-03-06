#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    int piksele[200][320];
    int najjasniejszy=0, najciemniejszy=225, kontrast=0, licz=0, linia=1, linia_max=1;
    ifstream wczytaj("dane.txt");
    ofstream wypisz("wyniki6.txt");
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<320; j++)
        {
            wczytaj>>piksele[i][j];
            if(piksele[i][j]>najjasniejszy)
                najjasniejszy=piksele[i][j];
            if(piksele[i][j]<najciemniejszy)
                najciemniejszy=piksele[i][j];
        }
        for(int j=0; j<160; j++)
        {
            if(piksele[i][j]!=piksele[i][319-j])
            {
                licz++;
                break;
            }
        }
    }
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<320; j++)
        {
            if(i==0&&j==0)
            {
                if(abs(piksele[i][j]-piksele[i][j+1])>128||abs(piksele[i][j]-piksele[i+1][j])>128)
                    kontrast++;
            }
            else if(i==0&&j==319)
            {
                if(abs(piksele[i][j]-piksele[i][j-1])>128||abs(piksele[i][j]-piksele[i+1][j])>128)
                    kontrast++;
            }
            else if(i==199&&j==0)
            {
                if(abs(piksele[i][j]-piksele[i][j+1])>128||abs(piksele[i][j]-piksele[i-1][j])>128)
                    kontrast++;
            }
            else if(i==199&&j==319)
            {
                if(abs(piksele[i][j]-piksele[i][j-1])>128||abs(piksele[i][j]-piksele[i-1][j])>128)
                    kontrast++;
            }
            else if(i==0&&j!=0&&j!=319)
            {
                if(abs(piksele[i][j]-piksele[i][j+1])>128||abs(piksele[i][j]-piksele[i+1][j])>128||abs(piksele[i][j]-piksele[i][j-1])>128)
                    kontrast++;
            }
            else if(i==199&&j!=0&&j!=319)
            {
                if(abs(piksele[i][j]-piksele[i][j+1])>128||abs(piksele[i][j]-piksele[i-1][j])>128||abs(piksele[i][j]-piksele[i][j-1])>128)
                    kontrast++;
            }
            else if(i!=0&&i!=199&&j==0)
            {
                if(abs(piksele[i][j]-piksele[i][j+1])>128||abs(piksele[i][j]-piksele[i+1][j])>128||abs(piksele[i][j]-piksele[i-1][j])>128)
                    kontrast++;
            }
            else if(i!=0&&i!=199&&j==319)
            {
                if(abs(piksele[i][j]-piksele[i-1][j])>128||abs(piksele[i][j]-piksele[i+1][j])>128||abs(piksele[i][j]-piksele[i][j-1])>128)
                    kontrast++;
            }
            else
            {
                if(abs(piksele[i][j]-piksele[i-1][j])>128||abs(piksele[i][j]-piksele[i+1][j])>128||abs(piksele[i][j]-piksele[i][j-1])>128||abs(piksele[i][j]-piksele[i][j+1])>128)
                    kontrast++;
            }
        }
    }
    for(int i=0; i<320; i++)
    {
        for(int j=1; j<200; j++)
        {
            if(piksele[j][i]==piksele[j-1][i])
                linia++;
            else
            {
                if(linia>linia_max)
                    linia_max=linia;
                linia=1;
            }
        }
    }
    wypisz<<"Zadanie 6.1."<<endl<<najjasniejszy<<" (najjasniejszy) i "<<najciemniejszy<<" (najciemniejszy)"<<endl<<"Zadanie 6.2."<<endl<<licz<<endl<<"Zadanie 6.3."<<endl<<kontrast<<endl<<"Zadanie 6.4."<<endl<<linia_max<<endl;
    return 0;
}
