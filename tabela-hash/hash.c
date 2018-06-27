
//Talles Bezerra
//Tabela hash com enderecamento fechado utilizando listas
// gcc hash.c -o hash

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <time.h>
#include <math.h>

#define TAM 11
//#define LIM_VAL 1000
//#define LIM_VAL 50000
#define LIM_VAL 100000


int main(){
	double inicio, fim, tempo_medio=0, tempo[5];
	int vetor[LIM_VAL];
	lista *hash[TAM];
	srand( (unsigned)time(NULL) );
	int i, end;

	printf("Teste com %d de numeros \n\n", LIM_VAL);
	for (int j = 0; j < 5; ++j){

		for (i = 0; i < TAM; ++i){
			hash[i] = criarlista();
		}

		for (i = 0; i < LIM_VAL; ++i){
			vetor[i] = rand()%(LIM_VAL+1);
		}

		inicio = clock();
		for (i = 0; i < LIM_VAL; ++i){
			end = vetor[i]%TAM;
			hash[end] = inserir(hash[end],vetor[i]);
		}
		fim = clock();
		tempo[j] = (fim-inicio)/(double)CLOCKS_PER_SEC;
		printf("Tempo %d: %lf\n",j+1, tempo[j]);
		tempo_medio += tempo[j];

		for (i = 0; i < TAM; i++){
			liberarlista(hash[i]);
		}
	}
	tempo_medio /= 5;
	
	printf("\nTempo medio de 5 execucoes: %lf\n\n", tempo_medio);

	return 0;
}