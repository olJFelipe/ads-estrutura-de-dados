#include <stdio.h>

int main(){
	// valores previamente definidos, para conveniência
	int indices[7][6] = {
		{8, 9, 12, 5, 0, 1},   // cidade 1
		{6, 3, 5, 10, 2, 7},   // cidade 2
		{20, 16, 10, 3, 6, 7}, // cidade 3
		{3, 8, 18, 9, 1, 6},   // cidade 4
		{7, 4, 2, 10, 12, 12}, // cidade 5
		{9, 12, 8, 14, 6, 3},  // cidade 6
		{22, 24, 1, 6, 7, 3}   // cidade 7
	};
	int i, j, soma;
	// para utilizar valores inseridos, libere as linhas comentadas abaixo
	/*
	for(i = 0; i < 7; i++){
		for(j = 0; j < 6; j++){
			printf("Cidade %d mes %d: ", i+1, j+1);
			scanf("%d", &indices[i][j]);
		}
	}
	*/
	printf("\n== Medias de pluviosidade mensal por cidade ==\n");
	for(i = 0; i < 7; i++){
		soma = 0;
		for(j  = 0; j < 6; j++){
			soma += indices[i][j];
		}
		printf("Cidade %d: %d\n", i+1, soma/6);
	}

	printf("\n== Medias de pluviosidade mensal regional ==\n");
	for(j  = 0; j < 6; j++){
		soma = 0;
		for(i = 0; i < 7; i++){
			soma += indices[j][i];
		}
		printf("Mes %d: %d\n", j+1, soma/7);
	}

	return 0;
}
