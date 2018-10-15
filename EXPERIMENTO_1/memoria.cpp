/*
Experimento 1
Organização e Arquitetura de Computadores


Prof. Me. Diego Negretto
Prof. Me. Orlando Saraiva Jr

*/
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

#define N 1000000

int main() {
	int *vetor;
	int x;
	fstream arquivo;
	auto inicio_alocacao = std::chrono::system_clock::now();

	vetor = new int[N];
	for (x=0; x< N; x++){
		vetor[x] = x;
	}

	auto final_alocacao = std::chrono::system_clock::now();
    std::chrono::duration<double> tempo_alocacao = final_alocacao-inicio_alocacao;


	auto inicio_disco = std::chrono::system_clock::now();
  	arquivo.open ("numero.txt", std::ofstream::out | std::ofstream::app);
	for (x=0; x< N; x++){
		arquivo << vetor[x] << endl;
	}
  	arquivo.close();
	auto final_disco = std::chrono::system_clock::now();
	std::chrono::duration<double> tempo_disco = final_disco-inicio_disco;

    cout << "Tempo para alocação: " << tempo_alocacao.count() << "s" << endl;
    cout << "Tempo para gravar em disco: " << tempo_disco.count() << "s" << endl;

    delete vetor;
}
