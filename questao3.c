// Notas da turma - Fazer um programa para ler as notas de 4 provas para 5 alunos de uma turma e calcular a média do aluno e média da turma

#include <stdio.h>

int main(){
	int notas[4][5] = { 0 };
	int i, j, nota, soma;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 4; j++){
			printf("Aluno %d prova %d: ", i+1, j+1);
			scanf("%d", &nota);
			notas[j][i] = nota;
		}
	}
	printf("============\n");
	for(i = 0; i < 5; i++){
		soma = 0;
		printf("Media do aluno %d: ", i+1);
		for(j = 0; j < 4; j++){
			soma += notas[j][i];
		}
		printf("%d\n", soma/4);
	}

	return 0;
}
