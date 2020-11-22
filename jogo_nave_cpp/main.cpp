#include <iostream>
#include <SDL2/SDL.h>
#include "uteis.h"
#include <ctime>

#undef main
using namespace std;


int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        cout << SDL_GetError() << endl;



    srand((unsigned)time(0));



    bool collisionBetweenSprite;
    bool gameOver = false;


    int dificuldade = 400;
    int positionX = 250;
    int positionY = 400;
    int meteoroPosition_X[2] = {0, 420};
    int meteoroPosition_Y[2] = {-100, -100};
    int meteoroTamanho[2] = {120, 120};



    SDL_Window* window = SDL_CreateWindow("GAME",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          525, 510,
                                          0);



    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    SDL_Texture* backGround = LoadBMP("imagens/fundo_espaco_bmp.bmp", render);
    SDL_Texture* spaceShip = LoadBMP("imagens/nave_bmp.bmp", render);
    SDL_Texture* enemy = LoadBMP("imagens/asteroide_bmp.bmp", render);



    SDL_AudioSpec wavPropriedades;
    Uint8* wavBuffer;
    Uint32 wavComprimento;

    SDL_LoadWAV("imagens/test.wav", &wavPropriedades, &wavBuffer, &wavComprimento);
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(nullptr, 0, &wavPropriedades, nullptr, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavComprimento);
    SDL_PauseAudioDevice(deviceId, 0);



    SDL_Rect origemInimigo[2];
    SDL_Rect destinoInimigo[2];


    while (!gameOver)
    {
        const int velocidade = 10;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: gameOver = true;
                break;

                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_a:
                    positionX -= velocidade;
                    break;


                    case SDLK_d:
                    positionX += velocidade;
                    break;


                    case SDLK_w:
                    positionY -= velocidade;
                    break;


                    case SDLK_s:
                    positionY += velocidade;
                    break;
                }
                break;
            }
        }



        SDL_RenderClear(render);


        SDL_Rect origemAliado = {0, 0, 370, 510};
        SDL_Rect destinoAliado = {positionX, positionY, 80, 80};


        // bord verification
        positionX = verificaBordasDoMapa_X(&destinoAliado, positionX);
        positionY = verificaBordasDoMapa_Y(&destinoAliado, positionY);


        origemInimigo[0] =  {0, 0, 587, 420};
        destinoInimigo[0] = {meteoroPosition_X[0], meteoroPosition_Y[0], meteoroTamanho[0], meteoroTamanho[0]};
        origemInimigo[1] =  {0, 0, 587, 420};
        destinoInimigo[1] = {meteoroPosition_X[1], meteoroPosition_Y[1], meteoroTamanho[1], meteoroTamanho[1]};


        if (meteoroPosition_Y[0] && meteoroPosition_Y[1] > 530)
        {
            meteoroPosition_Y[0] = -100;
            meteoroPosition_Y[1] = -100;

            meteoroPosition_X[0] = geraPosicaoAleatoriaMeteoro(&destinoInimigo[0], &destinoInimigo[1]);
            meteoroPosition_X[1] = geraPosicaoAleatoriaMeteoro(&destinoInimigo[0], &destinoInimigo[1], true);

            meteoroTamanho[0] = geraTamanhoAleatoriaMeteoro();
            meteoroTamanho[1] = geraTamanhoAleatoriaMeteoro();
            dificuldade++;


            // verification music
            if (dificuldade % 15 == 0)
            {
                if (SDL_AudioStatus(deviceId) == SDL_AUDIO_PAUSED)
                {
                    SDL_QueueAudio(deviceId, wavBuffer, wavComprimento);
                }
            }
        }
        else
        {
            meteoroPosition_Y[0]++;
            meteoroPosition_Y[1]++;
        }

        SDL_RenderCopy(render, backGround, NULL, NULL);
        SDL_RenderCopy(render, spaceShip, &origemAliado, &destinoAliado);
        SDL_RenderCopy(render, enemy, &origemInimigo[0], &destinoInimigo[0]);
        SDL_RenderCopy(render, enemy, &origemInimigo[1], &destinoInimigo[1]);
        SDL_RenderPresent(render);
        SDL_Delay(1000/dificuldade);



        collisionBetweenSprite = colisao(&destinoAliado, &destinoInimigo[0]) || colisao(&destinoAliado, &destinoInimigo[1]);

        if (collisionBetweenSprite)
        {
            gameOver = true;
        }
    }

    cout << "VOCÊ DESVIOU DE: " << (dificuldade - 400) * 2 << " ROCHAS ESPACIAS" << endl;


    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_DestroyTexture(spaceShip);
    SDL_DestroyTexture(enemy);
    SDL_DestroyTexture(backGround);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();

    return 0;
}
