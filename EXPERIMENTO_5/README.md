## EXPERIMENTO 5

##### O Objetivo: Como eu compilo uma aplicação que faz uso de threads com a biblioteca OpenMP?


### Para rodar no ambiente Windows, utilize o compilador DevCPP versão 5.1

##### Clique na opção Tools / Compiler Options

##### Selecione a combobox "Add the following command when call the compiler:"

##### Digite na TextArea o seguinte comando:
<b>-std=c++11  -lgomp -fopenmp</b>


### O que fazer ?

##### 1) Compilar o código no ambiente Windows. Leia o código e compreenda o que ele faz.

##### 2) Altere o parâmetro da função omp_set_num_threads.
