/*
Essas s�o as bibliotecas usadas para poder rodar o programa
*/
# include <stdio.h> // Inclui a biblioteca padr�o de entrada e sa�da
# include <string.h> // Inclui a biblioteca para manipula��o de strings
# include <stdlib.h> // Inclui a biblioteca padr�o para fun��es de aloca��o de mem�ria, convers�es de tipos e outras
# include <locale.h> // Inclui a biblioteca para configura��es de localiza��o

/*
Vetores do tipo char que pode ter 45 colunas e 65 caracteres
*/
char nome [45][65]; // Declara uma matriz para armazenar nomes de at� 45 clientes, cada nome pode ter at� 64 caracteres (65 para o caractere nulo)
char email [45][65]; // Declara uma matriz para armazenar emails de at� 45 clientes, cada email pode ter at� 64 caracteres (65 para o caractere nulo)
char cpf[45][14]; // Declara uma matriz para armazenar CPFs de at� 45 clientes, cada CPF pode ter at� 13 caracteres (14 para o caractere nulo)
/*
Declarando uma funcao para depois poder chamar ela na funcao main
*/
void menu(); // Declara��o da fun��o menu
void cadastro(); // Declara��o da fun��o cadastro
void pesquisa(); // Declara��o da fun��o pesquisa

void pesquisaNome(char nomeP[65]); // Declara��o da fun��o para pesquisar clientes por nome. Recebe um array de caracteres (string) com at� 65 caracteres.
void pesquisaCpf(char cpfP[14]); // Declara��o da fun��o para pesquisar clientes por CPF. Recebe um array de caracteres (string) com at� 14 caracteres.
void pesquisaEmail(char emailP[65]); // Declara��o da fun��o para pesquisar clientes por e-mail. Recebe um array de caracteres (string) com at� 65 caracteres.

void lista(); // Declara��o da fun��o para listar clientes.
void gravarcsv(); // Declara��o da fun��o para gravar os dados dos clientes em um arquivo CSV.
void lercsv(); // Declara��o da fun��o para ler os dados dos clientes a partir de um arquivo CSV.
void cabecalho(char Titulo[50]); // Declara��o da fun��o para imprimir um cabe�alho, recebendo um t�tulo como par�metro, que � um array de caracteres (string) com at� 50 caracteres.

/*
Inicio da funcao main, onde e o ponto de partida para o codigo
*/
int main(void){ //ponto de entrada principal de um programa.
    setlocale(LC_ALL, "Portuguese"); // Define o local para Portugu�s
    menu(); // Chama a fun��o menu para exibir o menu principal
}
/*
Essa fun�ao e o cabecalho, onde so apresenta um modelo mais interativo para o cliente
*/
void cabecalho(char Titulo[50]){
    system("cls"); // Limpa a tela do console
    int t = strlen(Titulo); // Calcula o comprimento da string Titulo

    printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separa��o

    if (strlen(Titulo)==0) // Verifica se a string Titulo est� vazia
    {
        printf("                       CADASTRO DE ALUNO UNIALFA 2024\n"); // Imprime o cabe�alho padr�o
    }else{
        printf(" %s UNIALFA 2024\n",Titulo); // Imprime o cabe�alho personalizado com o conte�do de Titulo
    }
    
    printf("|--------------------------------------------------------------------------------|\n"); // Imprime outra linha de separa��o
}
/*
Funcao menu tem a funcao de apresentar todas a funcoes disponiveis no sistema
*/
void menu(){
    int menu; // Declara��o da vari�vel menu para armazenar a op��o do usu�rio
    char t[50]=""; // Declara��o de uma string vazia t com tamanho m�ximo de 50 caracteres
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string vazia t como par�metro
    printf("Informe sua op��o: \n \t 1 = Cadastro; \n\t 2 = Pesquisa; \n\t 3 = Listar alunos; \n\t 4 = Gravar Dados \n\t 5 = Ler Dados \n"); // Exibe as op��es do menu
    printf("\r|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separa��o

    do{
        scanf("%d",&menu); // L� a op��o escolhida pelo usu�rio
        printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separa��o

        switch (menu){ // Inicia a estrutura de sele��o switch-case com base na op��o escolhida
            case 1:
                cadastro(); // Chama a fun��o cadastro para a op��o 1
                break;
            case 2:
                pesquisa(); // Chama a fun��o pesquisa para a op��o 2
                break;
            case 3:
                lista(); // Chama a fun��o lista para a op��o 3
                break;
            case 4:
                gravarcsv(); // Chama a fun��o gravarcsv para a op��o 4
                break;
            case 5:
                lercsv(); // Chama a fun��o lercsv para a op��o 5
                break;
            case 0:
                exit(0); // Encerra o programa para a op��o 0
                break;
            default:
                exit(0); // Encerra o programa para qualquer outra op��o inv�lida
                break;
        }
    } while(menu<4); // Continua o loop enquanto a op��o do menu for menor que 4
}
/*
Funcao cadastro e onde voce declara o nome, email, cpf da pessoa e guarda em um vetor
*/
void cadastro(){
    static int linha; // Declara��o de uma vari�vel est�tica linha para controlar o �ndice de cadastro
    int opc; // Declara��o da vari�vel opc para armazenar a op��o do usu�rio

	CAD: // Marcador para um ponto de retorno
    
    printf("Informe o nome do aluno: "); // Solicita o nome do aluno ao usu�rio
    scanf("\n%65[^\n]s",nome[linha]); // L� e armazena o nome do aluno na posi��o atual de linha

    printf("Informe o E-mail do aluno: "); // Solicita o e-mail do aluno ao usu�rio
    scanf("\n%65[^\n]s",email[linha]); // L� e armazena o e-mail do aluno na posi��o atual de linha

    printf("Informe o cpf do aluno: "); // Solicita o CPF do aluno ao usu�rio
    scanf("\n%14[^\n]s",cpf[linha]); // L� e armazena o CPF do aluno na posi��o atual de linha

    printf("Para continuar digite 1. \nPara Sair digite qualquer outro n�mero.\n"); // Solicita a op��o do usu�rio
    scanf("\n%d",&opc); // L� a op��o escolhida pelo usu�rio

    linha++; // Incrementa a vari�vel linha para avan�ar para o pr�ximo cadastro

    if(opc==1){ // Verifica se a op��o escolhida � 1
        goto CAD; // Retorna ao marcador CAD para adicionar um novo cadastro
    }else{
        menu(); // Chama a fun��o menu para retornar ao menu principal
    };
}

/*
funcao pesquisa e um modo aonde a pessoa pode pesquisar para encontrar a pessoa cadastrada dentro do sistema
*/
void pesquisa(){
    int i, opc; // Declara��o das vari�veis i e opc para controle e op��o do usu�rio
    char emailP[65], nomeP[65], cpfP[14]; // Declara��o das vari�veis para armazenar dados de pesquisa
    char t[50]="PESQUISA "; // Declara��o de uma string t para o cabe�alho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro

    do{
        printf("\nDigite 1 para pesquisa por CPF; \n 2 para pesquisa por e-mail; \n 3 para pesquisa pelo nome:");
        scanf("%d",&opc); // L� a op��o escolhida pelo usu�rio

        switch (opc){
            case 1:
                printf("\nInforme o CPF: ");
                scanf("%s",cpfP); // Solicita e l� o CPF para pesquisa
                pesquisaCpf(cpfP); // Chama a fun��o pesquisaCpf passando o CPF como par�metro
                break;
            case 2:
                printf("\nInforme o e-mail: ");
                scanf("%s",emailP); // Solicita e l� o e-mail para pesquisa
                pesquisaEmail(emailP); // Chama a fun��o pesquisaEmail passando o e-mail como par�metro
                break;
            case 3:
                printf("\nInforme o nome: ");
                scanf("%s",nomeP); // Solicita e l� o nome para pesquisa
                pesquisaNome(nomeP); // Chama a fun��o pesquisaNome passando o nome como par�metro
                break;
            default: // Caso nenhum das opcoes anteriores seja escolhida
                printf("\nOp��o Inv�lida."); // Exibe uma mensagem de op�ao invalida
                break; // Encerra o bloco de switch
        }

        printf("\nPara continuar digite 1. \nPara Sair digite qualquer outro n�mero.");
        scanf("%d",&opc); // Solicita a op��o do usu�rio para continuar ou sair
    } while (opc == 1); // Continua o loop enquanto o usu�rio desejar
    return;
}
/*
pesquisa Cpf tem o objetivo de pesquisa por cpf 
*/
void pesquisaCpf(char cpfP[14]){
    char t[50]="PESQUISA CPF "; // Declara��o de uma string t para o cabe�alho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro
    printf("Buscando por CPF: [ %s ];\n",cpfP); // Exibe a mensagem de busca pelo CPF fornecido
    int i; // Declara��o da vari�vel i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(cpf[i],cpfP)==0){ // Verifica se o CPF fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da fun��o
}
/*
pesquisa Cpf tem o objetivo de pesquisa por email 
*/
void pesquisaEmail(char emailP[65]){
    char t[50]="PESQUISA EMAIL "; // Declara��o de uma string t para o cabe�alho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro
    int i; // Declara��o da vari�vel i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(email[i],emailP)==0){ // Verifica se o e-mail fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da fun��o
}
/*
pesquisa Cpf tem o objetivo de pesquisa por nome
*/
void pesquisaNome(char nomeP[65]){
    char t[50]="PESQUISA NOME "; // Declara��o de uma string t para o cabe�alho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro
    int i; // Declara��o da vari�vel i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(nome[i],nomeP)==0){ // Verifica se o nome fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da fun��o
}
/*
funcao listar tem que mostrar todos os cadastro de pessoas, completo
*/
void lista(){
    int i; // Declara��o da vari�vel i para controle do loop
    int opc; // Declara��o da vari�vel opc para armazenar a op��o do usu�rio
    char t[50]="LISTA COMPLETA DE ALUNOS "; // Declara��o de uma string t para o cabe�alho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strlen(cpf[i]) > 0){ // Verifica se o CPF do aluno na posi��o i n�o est� vazio
            printf("NOME: %s \nE-MAIL: %s \nCPF: %s \n",nome[i],email[i],cpf[i]); // Exibe os dados do aluno
            printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separa��o
        }
    }

    printf("Pressione qualquer tecla para retornar ao Menu \n"); // Solicita ao usu�rio que pressione qualquer tecla para retornar ao menu
    scanf(" %d",&opc); // L� a op��o do usu�rio

    if(opc == 1){ // Verifica se a op��o escolhida � 1
        menu(); // Chama a fun��o menu para retornar ao menu principal
    }else{
        printf("\nOp��o Inv�lida."); // Exibe uma mensagem de op��o inv�lida
    }
}
/*
funcao gravar tem por objetivo gravar em um arquivo csv todas os cadastro feito pelo sistema
*/
void gravarcsv(){
    int i = 0; // Inicializa��o da vari�vel i
    char str[144]=""; // Declara��o de uma string str para armazenar os dados formatados

    FILE *file; // Declara��o de um ponteiro para arquivo
    file = fopen("aluno.csv","a"); // Abre o arquivo aluno.csv em modo de escrita (append)
    if(file == NULL){ // Verifica se houve erro na abertura do arquivo
        printf("Erro no Arquivo de dados!"); // Exibe uma mensagem de erro
    }

    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        memset(&str, 0, sizeof(str)); // Limpa a string str
        if(strlen(nome[i]) > 0){ // Verifica se o nome do aluno na posi��o i n�o est� vazio
            strcat(str, nome[i]); // Concatena o nome
            strcat(str, ","); // Adiciona uma v�rgula
            strcat(str, email[i]); // Concatena o e-mail
            strcat(str, ","); // Adiciona uma v�rgula
            strcat(str, cpf[i]); // Concatena o CPF
            strcat(str, "\n"); // Adiciona uma quebra de linha
            fputs(str, file); // Escreve a string formatada no arquivo
        }
    }

    fclose(file); // Fecha o arquivo
    menu(); // Retorna ao menu principal
}
/*
funcao ler vai ler todo o arquivo csv e printar na tela cada cadastro lido dentro do arquivo csv
*/
void lercsv(){
    FILE *file; // Declara��o de um ponteiro para arquivo
    char linha[150]; // Declara��o de uma string para armazenar cada linha lida do arquivo
    int l = 0; // Inicializa��o da vari�vel l para controle

    system("cls"); // Limpa a tela do console
    file = fopen("aluno.csv","r"); // Abre o arquivo aluno.csv em modo de leitura

    if(file == NULL){ // Verifica se houve erro na abertura do arquivo
        printf("Erro no Arquivo de dados!"); // Exibe uma mensagem de erro
        return; // Retorna da fun��o
    }

    char t[50] = "ARQUIVO ALUNO.CSV"; // Declara��o de uma string t para o cabe�alho
    cabecalho(t); // Chama a fun��o cabecalho passando a string t como par�metro

    char *result; // Declara��o de um ponteiro para armazenar o resultado da leitura

    while(!feof(file)){ // Loop enquanto n�o chegar ao final do arquivo
        if((result = fgets(linha, 150, file)) != NULL){ // L� uma linha do arquivo
            printf("Linha %s", linha); // Exibe a linha lida
        }
    }

    fclose(file); // Fecha o arquivo

    do{ 
        printf("\nPara voltar ao menu, pressione a tecla 1 "); // Solicita ao usu�rio que pressione 1 para voltar ao menu
        scanf("%d", &l); // L� a op��o do usu�rio
    } while (l != 1); // Continua o loop enquanto a op��o for diferente de 1
    menu(); // Retorna ao menu principal
}
