/*
Experimento 6
Organização e Arquitetura de Computadores


Prof. Me. Diego Negretto
Prof. Me. Orlando Saraiva Jr

*/
#include <omp.h>
#include <chrono>
#include <iostream>


#define CHUNK 100
#define N 100000

int main (){
	int i, n, chunk;
	float a[N], b[N], c[N], d[N];
	/* Some initializations */
	omp_set_num_threads(16);
	for (i=0; i < N; i++)
	 	a[i] = b[i] = i * 1.0;
	n = N;
	chunk = CHUNK;
	auto inicio_paralelo = std::chrono::system_clock::now();

	#pragma omp parallel shared(a,b,c,n,chunk) private(i) 
	{
	 	#pragma omp for schedule(dynamic,chunk) nowait
	 	for (i=0; i < n; i++)
	 		c[i] = a[i] + b[i];
	} /* end of parallel section */
	
	auto final_paralelo = std::chrono::system_clock::now();
	
	auto inicio_serial = std::chrono::system_clock::now();

	for (i=0; i< N; i++){
		d[i] = a[i] + b[i];
	}
	auto final_serial = std::chrono::system_clock::now();
    
    for (i=0; i< N; i++){
		if (d[i] != c[i]){
			std::cout << "Deu ruim em "<< i << std::endl;
		}
	}
	std::chrono::duration<double> paralelo = final_paralelo-inicio_paralelo;
    std::chrono::duration<double> serial = final_serial-inicio_serial;
	std::cout << "Serial : " << serial.count() << "s"  << std::endl;
	std::cout << "Paralelo : " << paralelo.count() << "s" << std::endl;
}

