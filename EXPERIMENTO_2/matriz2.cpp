/*
Experimento 2
Organização e Arquitetura de Computadores


Prof. Me. Diego Negretto
Prof. Me. Orlando Saraiva Jr

Fonte: http://codare.aurelio.net/2006/09/21/c-performance-uso-eficiente-da-memoria-cache/
*/
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

int main() {

	auto inicio = std::chrono::system_clock::now();

    #define N 10000
    #define M 15000

    static int m[N][M];


    int i, j, soma = 0;
       for (i = 0; i < N; i++) /* linha a linha */
           for (j = 0; j < M; j++)
               soma += m[i][j];


	auto final = std::chrono::system_clock::now();
    std::chrono::duration<double> tempo = final-inicio;
    cout << "Tempo total: " << tempo.count() << "s" << endl;
}
