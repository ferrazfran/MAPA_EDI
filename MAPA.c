#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Tamanho da fila
#define tamanho 5

// Estrutura da atividade a ser entregue
struct atividade_pratica {
	char RA[9];
	char nome_arquivo[30];
	char extensao[4];
	char matricula_professor[10];
};

// Estrutura da fila
struct tfila {
	struct atividade_pratica dados[tamanho];
	int ini;
	int fim;
};

struct tfila fila;
struct tfila filaEmpty;


// Função para colocar as atividades na fila
void fila_entrar(){
	if(fila.fim == tamanho){
		printf ("\nO limite de atividades para envio se esgotou, tente novamente em outro momento.\n\n");
		system ("Pause");
	}
	else {
		printf("\nInsira seu RA:");
		scanf("%s", fila.dados[fila.fim].RA);
		printf("\nInsira o nome do arquivo:");
		scanf("%s", fila.dados[fila.fim].nome_arquivo);
		printf("\nInsira a extensão do arquivo:");
		scanf("%s", fila.dados[fila.fim].extensao);
		printf("\nInsira matrícula do professor:");
		scanf("%s", fila.dados[fila.fim].matricula_professor);
		fila.fim++;
	}
}

// Função para retirar a primeira atividade corrigida
void fila_sair(){
	if (fila.ini == fila.fim){
		printf("\nNenhuma atividade foi inserida para correção.");
		system ("Pause");
	}
	else {
		int i;
		for (i = 0; i < tamanho; i++){
			strcpy (fila.dados[i].RA, fila.dados[i+1].RA);
			strcpy (fila.dados[i].nome_arquivo, fila.dados[i+1].nome_arquivo);
			strcpy (fila.dados[i].extensao, fila.dados[i+1].extensao);
			strcpy (fila.dados[i].matricula_professor, fila.dados[i+1].matricula_professor);
		}
		strcpy(fila.dados[fila.fim].RA, "");
		strcpy(fila.dados[fila.fim].nome_arquivo, "");
		strcpy(fila.dados[fila.fim].extensao, "");
		strcpy(fila.dados[fila.fim].matricula_professor, "");
		fila.fim--;
	}
}

// Função para esvaziar a fila

void fila_esvaziar(){
	fila = filaEmpty;
	}

// Função para mostrar as atividades da fila
void fila_mostrar(){
	int i;
	for (i = 0; i < tamanho; i++){
		printf("\nRA do aluno: %s", fila.dados[i].RA);
		printf("\nNome do arquivo: %s", fila.dados[i].nome_arquivo);
		printf("\nExtensão do arquivo: %s", fila.dados[i].extensao);
		printf("\nMatrícula do professor: %s\n\n", fila.dados[i].matricula_professor);
	}
	
}

//Função para mostrar o menu
void menu_mostrar(){
	printf("\nEscolha uma opção:\n");
	printf("1 - Incluir uma atividade:\n");
	printf("2 - Corrigir uma atividade:\n");
	printf("3 - Esvaziar a fila de atividades:\n");
	printf("0 - Sair\n\n");
}

//Função principal
int main(){
	setlocale (LC_ALL, "Portuguese");
	int op;
	op = 1;
	fila.ini = 0;
	fila.fim = 0;
	while (op != 0){
		system ("cls");
		fila_mostrar();
		menu_mostrar();
		scanf("%d", &op);
		switch (op){
			case 1:
				fila_entrar();
			break;
			case 2:
				fila_sair();
			break;
			case 3:
				fila_esvaziar();
			break;
		}
	}
	return (0);
}


