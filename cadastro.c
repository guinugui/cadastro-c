#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;

void cadastro();


int main(int argc, char *argv[]) {
	cadastro();
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
		
		printf("/n Digite 1 para continuar ou outro valor para sair !");
		scanf("%d", &op);
		linha++;
		
	}while(op == 1);
}


}
