// Faça um jogo da velha

#include <stdio.h>

char jogador = 'X';
char matriz[3][3];

void iniciar_jogo();

void desenhar_jogo();

int verificar_vitoria();

int col, ln, turno;

int main(){
	iniciar_jogo();
	
	while(1){
		desenhar_jogo();
		
		if(turno == 9){
			printf("> velha!");
			return 0;
		}
		
		printf("> jogador %c, insira a linha desejada (1 - 3): ", jogador);
		scanf("%d", &ln);
		printf("> jogador %c, insira a coluna desejada (1 - 3): ", jogador);
		scanf("%d", &col);
		
		if(col > 0 && col < 4 && ln > 0 && ln < 4){
			if(matriz[ln-1][col-1] == ' '){
				matriz[ln-1][col-1] = jogador;
				if(verificar_vitoria()){
					desenhar_jogo();
					printf("> jogador %c venceu!\n", jogador);
					return 0;
				}
				jogador = (jogador == 'X' ? 'O' : 'X');
				turno++;
			}
			else{
				printf("> ocupado!");
			}
		}
		else{
			printf("> movimento invalido!");
		}
	}
}

void iniciar_jogo(){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matriz[i][j] = ' ';
		}
	}
}

void desenhar_jogo(){
	printf("\n=======================================\n");
	printf(" %c | %c | %c \n---+---+---\n %c | %c | %c \n---+---+---\n %c | %c | %c \n\n", matriz[0][0], matriz[0][1], matriz[0][2], matriz[1][0], matriz[1][1], matriz[1][2], matriz[2][0], matriz[2][1], matriz[2][2]);
}

int verificar_vitoria(){
	if(
		//horizontais
		matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] == jogador ||
		matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] == jogador ||
		matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] == jogador ||
		//verticais
		matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] == jogador ||
		matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] == jogador ||
		matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2] && matriz[0][2] == jogador ||
		//diagonais
		matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] == jogador ||
		matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] == jogador
	){
		return 1;
	}
	return 0;
}
