#include <iostream>
#include <ctime>
#include <clocale>
#include <ctype.h>
#include "uteis.h"
#include <windows.h>

using namespace std;


void mostraMapa(MAPAS campo, bool definicaoMapa)
{
    for (int i=0; i<5; i++)
    {
        if (i == 0)
        {
            cout << "L/C 0---1---2---3---4-- " << endl;
        }
        cout << i << " ";
        if (definicaoMapa == true)
        {
            for (int j=0; j<5; j++)
            {
                cout << "| "<< campo.Jogador[i][j] << " ";
            }
        }
        else
        {
            for (int j=0; j<5; j++)
            {
                cout << "| "<< campo.Computador[i][j] << " ";
            }
        }
        cout << "|" << endl;
        cout << "  --------------------- " << endl;
    }
}


bool verificaPosicaoLivre(MAPAS campo, LACUNAS digito)
{
    if (campo.Computador[digito.Linha][digito.Coluna] == 'x')
    {
        fimDeJogo(campo);

    }
    else if (
             (campo.Jogador[digito.Linha][digito.Coluna] == '0') ||
             (campo.Jogador[digito.Linha][digito.Coluna] == '1') ||
             (campo.Jogador[digito.Linha][digito.Coluna] == '2') ||
             (campo.Jogador[digito.Linha][digito.Coluna] == '3') ||
             (campo.Jogador[digito.Linha][digito.Coluna] == '4'))
    {
        cout << "A COORDENADA " << "[ " << digito.Linha << " , " << digito.Coluna << " ] JA FOI ESCOLIDA ANTERIORMENTE, POR FAVOR RE-DIGITE" << endl;
        return false;
    }
    else
    {
        return true;
    }
}


int escolhePosicaoLinha()
{
    LACUNAS digito;

    cout << "ESCOLHA A LINHA DE 0 ATE 4" << endl;
    cin >> digito.Linha;
    while (
            (digito.Linha != 0) &&
            (digito.Linha != 1) &&
            (digito.Linha != 2) &&
            (digito.Linha != 3) &&
            (digito.Linha != 4))
        {
            cout << "DIGITO INVALIDO! ESCOLHA A LINHA DE 0 ATE 4" << endl;
            cin >> digito.Linha;
        }
    return digito.Linha;
}


int escolhePosicaoColuna()
{
    LACUNAS digito;

    cout << "ESCOLHA A COLUNA DE 0 ATE 4" << endl;
    cin >> digito.Coluna;
    while (
            (digito.Coluna != 0) &&
            (digito.Coluna != 1) &&
            (digito.Coluna != 2) &&
            (digito.Coluna != 3) &&
            (digito.Coluna != 4))
        {
            cout << "DIGITO INVALIDO! ESCOLHA A COLUNA DE 0 ATE 4" << endl;
            cin >> digito.Coluna;
        }
        return digito.Coluna;
}


int cordenadas()
{
    const int BOMBA = 5;
    int cord = rand() % BOMBA;
    return cord;
}


void fazBOOM()
{
    cout << ".---.   .--.   .--.  .-..-. .-. .-. .-. " << endl;
    cout << ": .; : : ,. : : ,. : : `' : : : : : : : " << endl;
    cout << ":   .' : :: : : :: : : .. : : : : : : : " << endl;
    cout << ": .; : : :; : : :; : : :; : :_; :_; :_; " << endl;
    cout << ":___.' `.__.' `.__.' :_;:_; :_; :_; :_; " << endl;
    Sleep(3500);
    system("cls");
}


void fimDeJogo(MAPAS campo, bool explode)
{
    setlocale(LC_ALL,"Portuguese");

    if (explode)
    {
        cout << "VOCÊ GANHOU!!!" << endl;
    }
    else
    {
        fazBOOM();
    }

    cout << "AS BOMBAS (X) ESTAVAM EM:" << endl << endl;
    mostraMapa(campo, false);
    system("pause");
    _Exit(EXIT_SUCCESS);
}


char verificaBombasAoRedor(MAPAS campo, LACUNAS digito)
{
    int n = 0; // acumulo de bombas ao redor
    char bombasAoRedor;

    if ((digito.Linha == 0) && (digito.Coluna == 0))
    {
        if (campo.Computador[digito.Linha + 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 0) && (digito.Coluna == 4))
    {
        if (campo.Computador[digito.Linha + 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 4) && (digito.Coluna == 0))
    {
        if (campo.Computador[digito.Linha - 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    else if((digito.Linha == 4) && (digito.Coluna == 4))
    {
        if (campo.Computador[digito.Linha - 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    else if(( digito.Linha == 0) && (digito.Coluna == 1 || digito.Coluna == 2 || digito.Coluna == 3))
    {
        if (campo.Computador[digito.Linha + 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 1 || digito.Linha == 2 || digito.Linha == 3) && (digito.Coluna == 0))
    {
        if (campo.Computador[digito.Linha + 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 1 || digito.Linha == 2 || digito.Linha == 3) &&
                (digito.Coluna == 1 || digito.Coluna == 2 || digito.Coluna == 3))
    {
        if (campo.Computador[digito.Linha - 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 1 || digito.Linha == 2 || digito.Linha == 3) && (digito.Coluna == 4))
    {
        if (campo.Computador[digito.Linha - 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha + 1][digito.Coluna] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    else if ((digito.Linha == 4) && (digito.Coluna == 1 || digito.Coluna == 2 || digito.Coluna == 3))
    {
        if (campo.Computador[digito.Linha - 1][digito.Coluna - 1] == 'x')   n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna + 1] == 'x')   n++;
        if (campo.Computador[digito.Linha][digito.Coluna + 1] == 'x')       n++;
        if (campo.Computador[digito.Linha][digito.Coluna - 1] == 'x')       n++;
        if (campo.Computador[digito.Linha - 1][digito.Coluna] == 'x')       n++;
    }
    bombasAoRedor = n + '0';
    return bombasAoRedor;
}
