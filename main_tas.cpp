#include"tas.h"
#include"include.h"

using namespace std;

void tas(int tab[4][4],int kierunek,int &score){
switch(kierunek){
    case 0: break;
case 1:
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(tab[j][i]!=0){
                int liczba=tab[j][i],ii=i,jj=j;
                while((tab[j+1][i]==0)or(tab[j+1][i]==liczba)and(j<3)){
                    if(tab[j+1][i]==liczba){
                        tab[jj][ii]=(2*liczba);
                        tab[j+1][i]=0;
                        score+=(2*liczba);
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
    sumowanie(tab,kierunek);

    break;
case 2:
    for(int j=0;j<4;j++){
        for(int i=3;i>0;i--){
            if(tab[j][i]!=0){
                int liczba=tab[j][i],ii=i,jj=j;
                while(((tab[j][i-1]==0)or(tab[j][i-1]==liczba))and(i>0)){
                    if(tab[j][i-1]==liczba){
                        tab[jj][ii]=(2*liczba);
                        tab[j][i-1]=0;
                         score+=(2*liczba);
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
sumowanie(tab,kierunek);
    break;
case 3:
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(tab[j][i]!=0){
                int liczba=tab[j][i],ii=i,jj=j;
                while((tab[j-1][i]==0)or(tab[j-1][i]==liczba)and(j>0)){
                    if(tab[j-1][i]==liczba){
                        tab[jj][ii]=(2*liczba);
                        tab[j-1][i]=0;
                         score+=(2*liczba);
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
    sumowanie(tab,kierunek);
    break;
case 4:
     for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            if(tab[j][i]!=0){
                int liczba=tab[j][i],ii=i,jj=j;
                while((tab[j][i+1]==0)or(tab[j][i+1]==liczba)and(i<3)){
                    if(tab[j][i+1]==liczba){
                        tab[jj][ii]=(2*liczba);
                        tab[j][i+1]=0;
                         score+=(2*liczba);
                        i++;
                        break;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
    }
    sumowanie(tab,kierunek);
    break;
}
}

void sumowanie(int tab[4][4],int kierunek){
    switch(kierunek){
    case 1:
        for(int i=0;i<4;i++){
            for (int j=0;j<3;j++){
                    int ii=i,jj=j;
                while((tab[jj][ii]==0)and(j<3)){
                    if(tab[j+1][i]!=0){
                        tab[jj][ii]=tab[j+1][i];
                        tab[j+1][i]=0;
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
    case 2:
        for(int j=0;j<4;j++){
            for (int i=3;i>0;i--){
                    int ii=i,jj=j;
                while((tab[jj][ii]==0)and(i>0)){
                    if(tab[j][i-1]!=0){
                        tab[jj][ii]=tab[j][i-1];
                        tab[j][i-1]=0;
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
        for(int i=0;i<4;i++){
            for (int j=3;j>0;j--){
                    int ii=i,jj=j;
                while((tab[jj][ii]==0)and(j>0)){
                    if(tab[j-1][i]!=0){
                        tab[jj][ii]=tab[j-1][i];
                        tab[j-1][i]=0;
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
         for(int j=0;j<4;j++){
            for (int i=0;i<3;i++){
                    int ii=i,jj=j;
                while((tab[jj][ii]==0)and(i<3)){
                    if(tab[j][i+1]!=0){
                        tab[jj][ii]=tab[j][i+1];
                        tab[j][i+1]=0;
                        i=ii;
                        break;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        break;
    }
}

bool czy_mozna(int tab[4][4],int kierunek){
    if((kierunek==1)or(kierunek==2)or(kierunek==3)or(kierunek==4)){
switch(kierunek){
    case 1:
        for(int i=0;i<4;i++){
            for (int j=0;j<3;j++){
                    int ii=i,jj=j;
                    if(((tab[j+1][i]!=0)and(tab[jj][ii]==0))or((tab[jj][ii]==tab[j+1][i])and(tab[jj][ii]!=0))){
                        return 1;
                    }
            }
        }
        break;
    case 2:
        for(int j=0;j<4;j++){
            for (int i=3;i>0;i--){
                    int ii=i,jj=j;
                    if(((tab[j][i-1]!=0)and(tab[jj][ii]==0))or((tab[jj][ii]==tab[j][i-1])and(tab[jj][ii]!=0))){
                        return 1;
                    }
            }
        }
        break;
    case 3:
        for(int i=0;i<4;i++){
            for (int j=3;j>0;j--){
                    int ii=i,jj=j;
                    if(((tab[j-1][i]!=0)and(tab[jj][ii]==0))or((tab[jj][ii]==tab[j-1][i])and(tab[jj][ii]!=0))){
                        return 1;
                    }
            }
        }
        break;
    case 4:
         for(int j=0;j<4;j++){
            for (int i=0;i<3;i++){
                    int ii=i,jj=j;
                    if(((tab[j][i+1]!=0)and(tab[jj][ii]==0))or((tab[jj][ii]==tab[j][i+1])and(tab[jj][ii]!=0))){
                        return 1;
                    }
            }
        }
        break;
    }
return 0;
}
return 0;
}
