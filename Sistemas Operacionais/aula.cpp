/* A intenção desse trabalho e mostrar como ocorre    */
/* o funcionamento de threads e seus multiprocessos.  */
/* Dependendo da forma que for arquitetado poderá     */
/* gerar alguns erros e problemas durante a execução  */

/* By: Eduardo Amaro Maciel			      */
/* Date: 29/03/2021				      */
/* Email: eduardo.am@protonmail.com		      */
/* Disciplina: Sistemas Operacionais		      */


#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <time.h>
#include <stdlib.h>


using namespace std;
using namespace std::chrono;


std::atomic<int> transacoes = 0;
int saldo = 0;
const int total = 5000;


void Thread1(int n)
{
	/* Cria a thread 1 para fazer a multiprogramação	*/
	/* :param n: determinar um tempo de 'pausa' da thread	*/


	// std::this_thread::sleep_for(std::chrono::seconds(n));
	while (transacoes < total)
	{
		transacoes++;
		saldo += 10;
	}
}


void Thread2(int n)
{
	/* Cria a thread 2 para fazer a multiprogramação		*/
	/* :param n: determinar um tempo de 'pausa'	da thread	*/


	// std::this_thread::sleep_for(std::chrono::seconds(n));
	while (transacoes < total)
	{
		transacoes++;
		saldo += 10;
	}
}


int main()
{
	//while (transacoes < total) {

	std::thread primeira(Thread1, 5);		/* Criar a 1º thread */
	std::thread segunda(Thread2, 10);		/* Criar a 2º thread */

	// std::cout << "threads rodando em paralelo!" << std::endl;
	primeira.join();
	segunda.join();

	// std::cout << "threads finalizaram seus trabalhos!" << std::endl;
	std::cout << "Saldo: " << saldo << std::endl;
	std::cout << "Transações: " << transacoes << std::endl;
}
