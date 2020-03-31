int score=0;
int tab[4][4];

nadanie_wartosci(tab,0);

losowanie(tab);
losowanie(tab);

SDL_Init(SDL_INIT_EVERYTHING);
SDL_Window* window = NULL;
SDL_Event event;
SDL_Surface* tlo=NULL;
SDL_Surface* windowsurfurence=NULL;
SDL_Surface* bloki[15];
SDL_Rect grafika[4][4];

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
grafika[j][i].x=(20+(i*120));
grafika[j][i].y=(20+(j*120));
grafika[j][i].w=100;
grafika[j][i].h=100;

    }
}

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 600;

srand(time(NULL));

bloki[0]=SDL_LoadBMP("a/0.bmp");
bloki[1]=SDL_LoadBMP("a/2.bmp");
bloki[2]=SDL_LoadBMP("a/4.bmp");
bloki[3]=SDL_LoadBMP("a/8.bmp");
bloki[4]=SDL_LoadBMP("a/16.bmp");
bloki[5]=SDL_LoadBMP("a/32.bmp");
bloki[6]=SDL_LoadBMP("a/64.bmp");
bloki[7]=SDL_LoadBMP("a/128.bmp");
bloki[8]=SDL_LoadBMP("a/256.bmp");
bloki[9]=SDL_LoadBMP("a/512.bmp");
bloki[10]=SDL_LoadBMP("a/1024.bmp");
bloki[11]=SDL_LoadBMP("a/2048.bmp");
bloki[12]=SDL_LoadBMP("a/4096.bmp");
bloki[13]=SDL_LoadBMP("a/8192.bmp");
bloki[14]=SDL_LoadBMP("a/16384.bmp");
tlo=SDL_LoadBMP("a/1.bmp");

for(int i=0;i<14;i++){
    if(bloki[i]==NULL){
        cout<<i<<" Jestes deklem!!!"<<endl;
    }
}

window = SDL_CreateWindow( "Projekt 2048 Autor: Pawel Blaszczak", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
windowsurfurence = SDL_GetWindowSurface( window );
SDL_BlitSurface( tlo, NULL, windowsurfurence, NULL );
SDL_UpdateWindowSurface(window);

int licznik=0;
while((czy_mozna(tab,1)==1)or(czy_mozna(tab,4)==1)or(czy_mozna(tab,3)==1)or(czy_mozna(tab,2)==1)){
 int kierunek=NULL;
licznik++;

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        switch(tab[j][i]){
        case 0: SDL_BlitSurface( bloki[0], NULL, tlo, &grafika[j][i] );break;
        case 2:  SDL_BlitSurface( bloki[1], NULL, tlo, &grafika[j][i] );break;
        case 4: SDL_BlitSurface( bloki[2], NULL, tlo, &grafika[j][i] );break;
        case 8: SDL_BlitSurface( bloki[3], NULL, tlo, &grafika[j][i] );break;
        case 16: SDL_BlitSurface( bloki[4], NULL, tlo, &grafika[j][i] );break;
        case 32: SDL_BlitSurface( bloki[5], NULL, tlo, &grafika[j][i] );break;
        case 64: SDL_BlitSurface( bloki[6], NULL, tlo, &grafika[j][i] );break;
        case 128: SDL_BlitSurface( bloki[7], NULL, tlo, &grafika[j][i] );break;
        case 256: SDL_BlitSurface( bloki[8], NULL, tlo, &grafika[j][i] );break;
        case 512: SDL_BlitSurface( bloki[9], NULL, tlo, &grafika[j][i] );break;
        case 1024: SDL_BlitSurface( bloki[10], NULL, tlo, &grafika[j][i] );break;
        case 2048: SDL_BlitSurface( bloki[11], NULL, tlo, &grafika[j][i] );break;
        case 4096: SDL_BlitSurface( bloki[12], NULL, tlo, &grafika[j][i] );break;
        case 8192: SDL_BlitSurface( bloki[13], NULL, tlo, &grafika[j][i] );break;
        case 16384: SDL_BlitSurface( bloki[14], NULL, tlo, &grafika[j][i] );break;
        }

    }
}
 SDL_BlitSurface( tlo, NULL, windowsurfurence, NULL );
        SDL_UpdateWindowSurface(window);

bool aa=0;

while(aa==0){
    while(SDL_PollEvent( &event ) != 0)
                {

                    switch( event.key.keysym.sym )
                        {
                            case SDLK_UP:
                            kierunek=1;
                            aa=1;
                            break;

                            case SDLK_DOWN:
                            kierunek=3;
                            aa=1;
                            break;

                            case SDLK_LEFT:
                            kierunek=4;
                            aa=1;
                            break;

                            case SDLK_RIGHT:
                            kierunek=2;
                            aa=1;
                            break;

                        }

}
}
if((licznik%2==1)and(czy_mozna(tab,kierunek)==1)){
tas(tab,kierunek,score);
losowanie(tab);
}

}

SDL_FreeSurface(tlo);
tlo=NULL;
SDL_FreeSurface(windowsurfurence);
windowsurfurence=NULL;
SDL_DestroyWindow(window);
window=NULL;
