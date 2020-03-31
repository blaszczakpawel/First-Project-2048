#include"include.h"
#include"class.h"

using namespace std;

int main(int argc, char* args[] ){
    srand(time(NULL));
int a,b;
cin>>a>>b;
Plansza p(a,b);
p.zerowanie();
p.losowanie(2);
p.wypisz_tekstowo();
while(1>0){

    cin>>a;
    p.tas(a);
    p.losowanie();
    p.wypisz_tekstowo();
}
return 0;
}
