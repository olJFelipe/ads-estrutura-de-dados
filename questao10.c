// 10 - Faça uma rotina recursiva para calcular a somatória de todos os números de 1 a N (N será lido do teclado).
#include <stdio.h>

int fatorial(int n){
	if(n == 1) return 1;
	return n + fatorial(n-1);
}

int main(){
	int num;
	printf("Insira um numero: ");
	scanf("%d", &num);
	printf("%d\n", fatorial(num));
	return 0;
}
