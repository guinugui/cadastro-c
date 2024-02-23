#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;

void cadastro();
void pesquisa();
void lista();


int main(int argc, char *argv[]) {
	cadastro();
	lista();
	//pesquisa();
	
	
}

void lista(){
	int i;
	for(i=0;i<SIZE;i++){
		
		if(cpf[i] > 0){
			printf("\nName: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);	
		}
		
	}
}

void cadastro(){
	static int linha;
	
	do{
		printf("\n Digite o nome: ");
		scanf("%s", &nome[linha]);
		
		printf("\n Digite o email: ");
		scanf("%s", &email[linha]);
		
		printf("\n Digite o cpf: ");
		scanf("%d", &cpf[linha]);
		
		printf("\n Digite 1 para continuar ou outro valor para sair !");
		scanf("%d", &op);
		linha++;
		
	}while(op == 1);
}

void pesquisa(){
	
	int cpfPesquisa;
	int i;
	char nomePesquisa[50];
	do{
		printf("\nDigite 1 para pesquisar por cpf ou 2 para pesquisar por nome: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\n Digite o cpf: ");
				scanf("%d", &cpfPesquisa);
				for( i=0 ;i<SIZE; i++){
					if(cpf[i]==cpfPesquisa){
						printf("\nName: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
					}
				}
				
				break;
			case 2:
					printf("\n Digite o nome: ");
				scanf("%s", nomePesquisa);
				for( i=0 ;i<SIZE; i++){
					if(strcmp(nome[i], nomePesquisa) == 0){
						printf("\nName: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
					}
				}
				break;
			default:
			
				printf("Opção invalida!");
			
				break;	
		}
		
		printf("\n Digite 1 para continuar!");
		scanf("%d", &op);
	}while(op == 1);
}

	
	
	
