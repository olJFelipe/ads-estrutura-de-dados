// Suponha uma matriz de 3 linhas por 3 colunas do tipo inteiro.
// Leia os valores dessa matriz, depois informe qual é o maior e o menor elemento.

#include <stdio.h>

int main(){
	int mat[3][3] = {
		{8, 3, 2},
		{14, 9, 5},
		{4, 7, 11}
	};
	int i, j, menor = mat[0][0], maior = mat[0][0];
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		if(mat[i][j] > maior) maior = mat[i][j];
		if(mat[i][j] < menor) menor = mat[i][j];
		}
	}
	printf("Menor elemento: %d\nMaior elemento: %d\n", menor, maior);
	return 0;
}
