#include <iostream>
#include "nomes.h"
#include "uteis.h"

using namespace std;

int main()
{
    MAPAS campo;
    LACUNAS digito;
    COORDENADAS cord;

    int jogadas = 0;

    bool verificacaoOK;
    bool condicaoDeVitoriaOuDerrota;


    //================== PROGRAMA PRINCIPAL ====================\\.

    nomes();

    for (int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            campo.Jogador[i][j] = '*';
            campo.Computador[i][j] = '*';
        }
    }

    while (true)
    {
        mostraMapa(campo);

        cout << "RESTARAM " << 20 - jogadas << " POSIÇÕES LIVRES" << endl;

        do
        {
            digito.Linha = escolhePosicaoLinha();
            digito.Coluna = escolhePosicaoColuna();
            verificacaoOK = verificaPosicaoLivre(campo, digito);
        } while (verificacaoOK == false);

        system("cls");
        jogadas++;

        if (jogadas == 1)
        {
            const int BOMBA = 5;

            for (int i = 0; i < BOMBA; i++)
            {
                do
                {
                    do
                    {
                        cord.Coordenada_1 = cordenadas();
                        cord.Coordenada_2 = cordenadas();

                    } while (campo.Computador[cord.Coordenada_1][cord.Coordenada_2] == 'x');
                } while ((digito.Linha == cord.Coordenada_1) && (digito.Coluna == cord.Coordenada_2));

                cout << "BOMBA EM [ " << cord.Coordenada_1 << " , " << cord.Coordenada_2 << " ]" << endl;
                campo.Computador[cord.Coordenada_1][cord.Coordenada_2] = 'x';
            }
        }

        campo.Jogador[digito.Linha][digito.Coluna] = verificaBombasAoRedor(campo, digito);

        if (jogadas == 20)
        {
            condicaoDeVitoriaOuDerrota = true;
            fimDeJogo(campo, condicaoDeVitoriaOuDerrota);
        }
    }
    return 0;
}
