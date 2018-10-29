## EXPERIMENTO 6

##### O Objetivo: Toda aplicação que faz uso de paralelismo ou pseudo-paralelismo fica mais rápido ?


### Para rodar no ambiente Windows, utilize o compilador DevCPP versão 5.1

##### Clique na opção Tools / Compiler Options

##### Selecione a combobox "Add the following command when call the compiler:"

##### Digite na TextArea o seguinte comando:
<b>-std=c++11  -lgomp -fopenmp</b>


### O que fazer ?

##### 1) Compilar o código no ambiente Windows. Leia o código e compreenda o que ele faz.

##### 2) Altere o parâmetro da função omp_set_num_threads e o N.

##### 3) Elabore um relatório, descrevendo seu experimento, apresentando os valores adquiridos ( via gráfico, tabela, etc, da forma que achar mais conveniente) Neste relatório, responda a pergunta proposta neste experimento.
