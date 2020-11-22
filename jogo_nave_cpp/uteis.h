#ifndef UTEIS_H_UNIVALI
#define UTEIS_H_UNIVALI
#include <SDL2/SDL.h>


SDL_Texture* LoadBMP(const char* img, SDL_Renderer* render);


bool colisao(SDL_Rect* a, SDL_Rect* b);


int geraPosicaoAleatoriaMeteoro(SDL_Rect* destinoInimigo1, SDL_Rect* destinoInimigo2, bool twoMeteor = false);


int geraTamanhoAleatoriaMeteoro();


int verificaBordasDoMapa_X(SDL_Rect* destinoAliado, int positionX);


int verificaBordasDoMapa_Y(SDL_Rect* destinoAliado, int positionY);


#endif // UTEIS_H_UNIVALI
