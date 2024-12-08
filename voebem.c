#include <stdio.h>
#include <stdlib.h>

char* dias[8] = {"seg", "ter", "qua", "qui", "sex", "sab", "dom", "diario"};

typedef struct voo{
	int codigo, data, hora, minuto, aeroporto_saida, aeroporto_chegada, rota, numero_passageiros;
	float tempo_estimado;
	struct voo *prox;
} Voo;

// lista para conter os vôos
typedef struct {
	Voo* primeiro;
	int contagem;
} ListaVoos;

void cadastrar_voo(ListaVoos* _lista){
	Voo* ret = (Voo*)malloc(sizeof(Voo));
	if (ret == NULL){ // retorna se houver erro na alocação e exibe mensagem
		printf("[cadastrar_voo] ERRO: falha ao alocar memoria\n");
		return;
	}
	printf("== Cadastrar voo ==\n");
	// recebe os dados do voo
	// codigo definido automaticamente de acordo com posição na lista
	printf("Data do voo (1-7 dias da semana, 8 diario): ");
	scanf("%d", &ret->data);
	printf("Hora: ");
	scanf("%d", &ret->hora);
	printf("Minuto: ");
	scanf("%d", &ret->minuto);
	printf("Codigo do aeroporto de saida: ");
	scanf("%d", &ret->aeroporto_saida);
	printf("Codigo do aeroporto de chegada: ");
	scanf("%d", &ret->aeroporto_chegada);
	printf("Codigo da rota: ");
	scanf("%d", &ret->aeroporto_chegada);
	printf("Tempo estimado (em horas, decimais separados por ponto): ");
	scanf("%f", &ret->tempo_estimado);
	printf("Numero de passageiros: ");
	scanf("%d", &ret->numero_passageiros);
	ret->codigo = _lista->contagem + 1;
	// define o novo voo como último item da lista
	if(_lista->primeiro == NULL){
		_lista->primeiro = ret;
	}
	else{
		// "it" sendo variável de iteração
		Voo* it = _lista->primeiro;
		while(it->prox != NULL){
			it = it->prox;
		}
		it->prox = ret;
	}
	_lista->contagem++;
	printf("Voo cadastrado com sucesso.\n");
	return;
}

// imprime os dados do vôo na posição "_codigo" da lista
void consultar_voo(ListaVoos* _lista){
	printf("== Consultar voo ==\n");
	if (_lista->contagem == 0) {
		printf("Nao ha voos cadastrados.");
		return;
	}
	int indice = -1;
	while(indice <= 0){
		printf("Insira o codigo do voo (%d voos cadastrados): ", _lista->contagem);
		scanf("%d", &indice);
		if(indice < 1 || indice > _lista->contagem){
			printf("Codigo invalido!\n");
			return;
		}
	}
	Voo* it = _lista->primeiro;
	int i = 1;
	while(i != indice && it != NULL){
		it = it->prox;
		i++;
	}
	printf("\n>> Dados do voo %d\n", it->codigo);
	printf("Saida: %s, %02d:%02d, no Aeroporto %d.\n", (it->data < 8 ? dias[it->data-1] : "N/A"), it->hora, it->minuto, it->aeroporto_saida);
	printf("Destino: Aeroporto %d, em aproximadamente %.1fh.\n", it->aeroporto_chegada, it->tempo_estimado);
	printf("Rota %d, %d passageiros.\n", it->rota, it->numero_passageiros);
	return;
}

// remove o vôo na posição "_codigo" da lista
void remover_voo(ListaVoos* _lista){
	printf("== Remover voo ==\n");
	if (_lista->contagem == 0) {
		printf("Nao ha voos cadastrados.");
		return;
	}
	int indice = -1;
	while(indice <= 0){
		printf("Insira o codigo do voo (%d voos cadastrados): ", _lista->contagem);
		scanf("%d", &indice);
		if(indice < 1 || indice > _lista->contagem){
			printf("Codigo invalido!\n");
			return;
		}
	}
	Voo *it = _lista->primeiro, *it_anter = NULL;
	int i = 1;
	while(i != indice && it != NULL){
		it_anter = it;
		it = it->prox;
		i++;
	}
	if(i == 1){
		_lista->primeiro = it->prox;
		free(it);
		it = _lista->primeiro;
	}
	else{
		// conecta voos faltantes
		it_anter->prox = it->prox;
		free(it);
		it = it_anter->prox;
	}
	// normaliza numeros de indice dos voos
	while(it != NULL){
		it->codigo--;
		it = it->prox;
	}
	printf("Voo removido com sucesso.");
	_lista->contagem--;
	return;
}

int main(){
	int entrada;
	ListaVoos* lista = (ListaVoos*)malloc(sizeof(ListaVoos));
	lista->primeiro = NULL;
	lista->contagem = 0;
	for(;;){
		printf("\n======================\n");
		printf("1. Cadastrar voo\n2. Consultar voo\n3. Remover voo\n0. Sair\n\nInsira a operacao desejada: ");
		scanf("%d", &entrada);
		switch(entrada){
			case 1: cadastrar_voo(lista); break;
			case 2: consultar_voo(lista); break;
			case 3: remover_voo(lista); break;
			case 0: return 0; break;
			default: break;
		}
	}

	return 0;
}
