#include"include.h"
#include"class.h"

using namespace std;

    Plansza::Plansza(int xx,int yy){
        x=xx;
        y=yy;
        tablica = new int * [x];
            for(int i=0;i<x;i++){
                tablica[i] = new int [y];
            }
        }
    Plansza:: ~Plansza(){
        for(int i=0;i<x;i++){
            delete []  tablica[i];
        }
        delete [] tablica;
        }
   void Plansza::nadaj(int xx,int yy){
        tablica[xx][yy]=1;
   }
    void Plansza::wypisz_tekstowo(){
       //system("cls");
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                cout<<tablica[j][i]<<"  ";
            }
            cout<<endl<<endl;
        }
    }
    void Plansza::zerowanie(){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                tablica[i][j]=0;
            }
        }
    }
int Plansza::ile_pustych(){
    int licznik=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(tablica[i][j]==0){
                licznik++;
            }
        }
    }
    return licznik;
}
bool Plansza::losowanie(int razy){
    int k;
    for(k=1;k<=razy;k++){
    int liczba,randa=rand()%100;
    if(randa<4){
        liczba=2;
    }
    else{
        liczba=1;
    }

    randa=((rand()%ile_pustych())+1);

    int licznik=0;

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(tablica[i][j]==0){
                licznik++;
            }
            if(licznik==randa){
                tablica[i][j]=liczba;
            }
        }
    }
    }
    if(k==razy){
        return 1;
    }
    else{
        return 0;
    }
}

void Plansza::tas(int kierunek){
switch(kierunek){
    case 0: break;
case 1:
   for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(tablica[i][j]!=0){
                int jj=j,baza=tablica[i][j];
                tablica[i][j]=0;
                while(((jj-1)>=0)and(tablica[i][jj-1]==0)){
                    jj--;
                }
                while(((j+1)<y)and((tablica[i][j+1]==0)xor(tablica[i][j+1]==baza))){
                    j++;
                    if(tablica[i][j]==baza){
                        tablica[i][j]=0;
                        baza++;
                        break;
                    }
                }
                tablica[i][jj]=baza;
            }
        }
   }

    break;

case 2:
    for(int j=0;j<(y);j++){

        for(int i=(x-1);i>0;i--){
            if(tablica[i][j]!=0){
                int ii=i,jj=j;
                while((i>0)and((tablica[i-1][j]==0)or(tablica[i-1][j]==tablica[ii][jj]))){
                    if(tablica[i-1][j]==tablica[ii][jj]){
                        tablica[ii][jj]++;
                        tablica[i-1][j]=0;
                        i--;
                        break;
                    }
                    else{
                        i--;
                    }
                }
            }
        }
    }
    for(int j=0;j<(y);j++){
            for (int i=(x-1);i>0;i--){
                    int ii=i,jj=j;
                while((tablica[ii][jj]==0)and(i>0)){
                    if(tablica[i-1][j]!=0){
                        tablica[ii][jj]=tablica[i-1][j];
                        tablica[i-1][j]=0;
                        i=ii;
                        break;
                    }
                    else{
                        i--;
                    }
                }
            }
        }
    break;

case 3:
    for(int i=0;i<(x);i++){
        for(int j=(y-1);j>0;j--){
            if(tablica[i][j]!=0){
                int ii=i,jj=j;
                while((j>0)and((tablica[i][j-1]==0)or(tablica[i][j-1]==tablica[ii][jj]))){
                    if(tablica[i][j-1]==tablica[ii][jj]){
                        tablica[ii][jj]++;
                        tablica[i][j-1]=0;

                        j--;
                        break;
                    }
                    else{
                        j--;
                    }
                }
            }
        }
    }
    for(int i=0;i<(x);i++){
            for (int j=(y-1);j>0;j--){
                    int ii=i,jj=j;
                while((tablica[ii][jj]==0)and(j>0)){
                    if(tablica[i][j-1]!=0){
                        tablica[ii][jj]=tablica[i][j-1];
                        tablica[i][j-1]=0;
                        j=jj;
                        break;
                    }
                    else{
                        j--;
                    }
                }
            }
        }
    break;

case 4:
     for(int i=0;i<(y);i++){
        for(int j=0;j<(x-1);j++){
            if(tablica[j][i]!=0){
                int ii=i,jj=j;
                while((j<(x-1))and((tablica[j+1][i]==0)or(tablica[j+1][i]==tablica[jj][ii]))){
                    if(tablica[j+1][i]==tablica[jj][ii]){
                        tablica[jj][ii]++;
                        tablica[j+1][i]=0;

                        j++;
                        break;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
    }
    for(int i=0;i<(y);i++){
            for (int j=(0);j<(x-1);j++){
                    int ii=i,jj=j;
                while((tablica[jj][ii]==0)and(j<(x-1))){
                    if(tablica[j+1][i]!=0){
                        tablica[jj][ii]=tablica[j+1][i];
                        tablica[j+1][i]=0;
                        j=jj;
                        break;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
    break;
}
}
