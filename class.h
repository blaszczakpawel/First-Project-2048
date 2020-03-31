#include"include.h"
#include"struct.cpp"

using namespace std;

class Plansza{
private:
    int x,y;
    int **tablica;
public:
    Plansza(int=4,int=4);
    ~Plansza();
    void wypisz_tekstowo();
    void zerowanie();
    int ile_pustych();
    bool losowanie(int=1);
    void tas(int);
    void nadaj(int,int);

};
