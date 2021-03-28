#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;
//using namespace std::chrono;

int transacoes = 0;
int saldo = 0;
const int total = 5000;


void Thread1(int n)
{
	//std::this_thread::sleep_for(std::chrono::seconds(n));

	while (transacoes < total) 
	{
		transacoes++;
		saldo += 10;
	}
}

void Thread2(int n)
{
	//std::this_thread::sleep_for(std::chrono::seconds(n));

	while (transacoes < total)
	{
		transacoes++;
		saldo += 10;
	}
}


int main() 
{

	/* Criar as threads*/
	while (transacoes < total) {


		std::thread primeira(Thread1, 5);
		std::thread segunda(Thread2, 10);

		//std::cout << "threads rodando em paralelo!" << std::endl;
		primeira.join();
		segunda.join();
	}
	//std::cout << "threads finalizaram seus trabalhos!" << std::endl;
	std::cout << "As threads obtiveram!" << saldo << std::endl;
}