/* A intenção desse trabalho e mostrar como ocorre    */
/* o funcionamento de threads e seus multiprocessos.  */
/* Dependendo da forma que for arquitetado poderá     */
/* gerar alguns erros e problemas durante a execução  */

/* By: Eduardo Amaro Maciel							  */
/* Date: 29/03/2021									  */
/* Email: eduardo.am@protonmail.com				      */
/* Disciplina: Sistemas Operacionais			      */


#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>


using namespace std;

std::atomic <int> transacoes = 0;
int saldo = 0;
const int total = 5000;
std::mutex m1;


void Thread1() 
{
	m1.lock()
	while (transacoes < total)
	{
		transacoes++;
		saldo += 10;
	}
	m1.unlock()
}


int main()
{
	std::thread primeira(Thread1);		/* Criar a 1º thread */
	std::thread segunda(Thread1);		/* Criar a 2º thread */

	primeira.join();
	segunda.join();

	std::cout << "Saldo: " << saldo << std::endl;
	std::cout << "Transacoes: " << transacoes << std::endl;
}
