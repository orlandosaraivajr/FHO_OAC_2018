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
	fstream arquivo2;

	vetor = new int[N];
	for (x=0; x< N; x++){
		vetor[x] = x;
	}

 	auto inicio_1 = std::chrono::system_clock::now();
  	arquivo.open ("numero.txt", std::ofstream::out | std::ofstream::app);
	for (x=0; x< N; x++){
		arquivo << vetor[x] << endl;
	}
  	arquivo.close();
	auto final_1 = std::chrono::system_clock::now();
	std::chrono::duration<double> tempo_disco = final_1-inicio_1;

 	auto inicio_2 = std::chrono::system_clock::now();
    /*
    AJUSTE AQUI A LETRA CORRESPONDENTE A UNIDADE DO PENDRIVE 
    */
  	arquivo2.open ("f:\\numero.txt", std::ofstream::out | std::ofstream::app);
	for (x=0; x< N; x++){
		arquivo2 << vetor[x] << endl;
	}
  	arquivo2.close();
	auto final_2 = std::chrono::system_clock::now();
	std::chrono::duration<double> tempo_pendrive = final_2-inicio_2;

    cout << "Tempo para gravar em disco: " << tempo_disco.count() << "s" << endl;
 	cout << "Tempo para gravar pendrive: " << tempo_pendrive.count() << "s" << endl;

	delete vetor;
}
