#include <iostream>
#include "uteis.h"
#include <SDL2/SDL.h>
#include <ctime>

using namespace std;

SDL_Texture* LoadBMP(const char* img, SDL_Renderer* render)
{

    SDL_Surface* backGround = SDL_LoadBMP(img);
    if (!backGround)
    {
        cout << SDL_GetError() << endl;;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, backGround);
    SDL_FreeSurface(backGround);

    return texture;
}


bool colisao(SDL_Rect* a, SDL_Rect* b)
{
    if(a->x+14 > b->x + b->w || a->x + a->w < b->x+14 || a->y+10 > b->y + b->h || a->y + a->h < b->y+10)
    {
        return false;
    }
    return true;
}


int geraPosicaoAleatoriaMeteoro(SDL_Rect* destinoInimigo1, SDL_Rect* destinoInimigo2, bool twoMeteor)
{
    int maior = 400;
    bool colisa = true;
    int separador = 0;
    if (twoMeteor)
    {
        while (colisa)
        {
            colisa = colisao(destinoInimigo1, destinoInimigo2);
            separador += 4;
        }
        return separador;
    }
    else
    {
        return rand()%(maior-100) + 100;
    }
}


int geraTamanhoAleatoriaMeteoro()
{
    int maior = 60;
    int menor = 100;
    return rand()%(maior-menor+1) + menor;
}


int verificaBordasDoMapa_X(SDL_Rect* destinoAliado, int positionX)
{
    if (destinoAliado->x < 0)
    {
        return positionX = 0;
    }
    else if (destinoAliado->x > 445)
    {
        return positionX = 445;
    }

    return positionX;
}


int verificaBordasDoMapa_Y(SDL_Rect* destinoAliado, int positionY)
{
    if (destinoAliado->y < 0)
    {
        positionY = 0;
    }
    else if (destinoAliado->y > 425)
    {
        positionY = 425;
    }

    return positionY;
}
