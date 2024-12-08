#include <stdio.h>

int main(){
	int x, y, *p;

	y = 0; // "y" recebe o valor 0

	p = &y; // o ponteiro "p" é definido como o endereço de "y"

	x = *p; // "x" recebe o valor referenciado de "p", que é o mesmo de "y", que é 0

	x = 4; // "x" recebe o valor 4

	(*p)++; // o valor referenciado por "p", que é o mesmo de "y", que é 0, é adicionado em 1, tornando-o 1

	--x; // o valor de "x" é subtraído em 1, tornando-o 3

	(*p) += x; // o valor de "x", que é 3, é adicionado ao valor referenciado por "p", que é o mesmo de "y", que era 1, e agora será 4

	// no fim, x será 3, y será 4 e p apontará ao endereço de y
	printf("x = %d\ny = %d\np = %p\n&y = %p\n*p = %d\n", x, y, p, &y, *p);

	return 0;
}
