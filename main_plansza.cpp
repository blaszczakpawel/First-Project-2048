#include"plansza.h"
#include"include.h"

using namespace std;

void nadanie_wartosci(int tab[4][4],int liczba){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        tab[i][j]=liczba;
    }
}
}

void wyswietl (int tab[4][4],int score){
system("cls");
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        cout<<tab[i][j]<<"   ";
    }
    cout<<endl<<endl;
}
cout<<"Oto wynik: "<<score<<endl;
}
void wyswietl2 (int tab[4][4],int score){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        cout<<tab[i][j]<<"   ";
    }
    cout<<endl<<endl;
}
cout<<"Oto wynik: "<<score<<endl;
}

int ile_pustych(int tab[4][4]){
int licznik=0;
for(int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        if(tab[i][j]==0){
            licznik++;
        }
    }
}
return licznik;
}

int losowanie1(int tab[4][4]){
int random=rand()%ile_pustych(tab);
return random+1;
}

int losowanie2(){
int random=rand()%100+1;
if(random>5){
    return 2;
}
return 4;
}

int ktore_miejsce(int tab[4][4],int liczba){
int licznik=0;
for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        if(tab[i][j]==0){
            licznik++;
        }
        if(licznik==liczba){
            return ((i*10)+(j));
        }
    }
}
}

void losowanie (int tab[4][4]){
int miejsce=ktore_miejsce(tab,losowanie1(tab)),i,j;
j=miejsce%10;
miejsce/=10;
i=miejsce;
tab[i][j]=losowanie2();

}
