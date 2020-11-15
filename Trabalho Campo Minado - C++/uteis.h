#ifndef UTEIS_H
#define UTEIS_H

    struct MAPAS
    {
        char Jogador[5][5];
        char Computador[5][5];
    };

    struct LACUNAS
    {
        int Linha;
        int Coluna;
    };

    struct COORDENADAS
    {
        int Coordenada_1;
        int Coordenada_2;
    };

    void mostraMapa(MAPAS campo, bool definicaoMapa = true);

    bool verificaPosicaoLivre(MAPAS campo, LACUNAS digito);

    int escolhePosicaoLinha();

    int escolhePosicaoColuna();

    int cordenadas();

    void fazBOOM();

    void fimDeJogo(MAPAS campo, bool explode = false);

    char verificaBombasAoRedor(MAPAS campo, LACUNAS digito);

#endif // UTEIS_H
