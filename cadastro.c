/*
Essas são as bibliotecas usadas para poder rodar o programa
*/
# include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
# include <string.h> // Inclui a biblioteca para manipulação de strings
# include <stdlib.h> // Inclui a biblioteca padrão para funções de alocação de memória, conversões de tipos e outras
# include <locale.h> // Inclui a biblioteca para configurações de localização

/*
Vetores do tipo char que pode ter 45 colunas e 65 caracteres
*/
char nome [45][65]; // Declara uma matriz para armazenar nomes de até 45 clientes, cada nome pode ter até 64 caracteres (65 para o caractere nulo)
char email [45][65]; // Declara uma matriz para armazenar emails de até 45 clientes, cada email pode ter até 64 caracteres (65 para o caractere nulo)
char cpf[45][14]; // Declara uma matriz para armazenar CPFs de até 45 clientes, cada CPF pode ter até 13 caracteres (14 para o caractere nulo)
/*
Declarando uma funcao para depois poder chamar ela na funcao main
*/
void menu(); // Declaração da função menu
void cadastro(); // Declaração da função cadastro
void pesquisa(); // Declaração da função pesquisa

void pesquisaNome(char nomeP[65]); // Declaração da função para pesquisar clientes por nome. Recebe um array de caracteres (string) com até 65 caracteres.
void pesquisaCpf(char cpfP[14]); // Declaração da função para pesquisar clientes por CPF. Recebe um array de caracteres (string) com até 14 caracteres.
void pesquisaEmail(char emailP[65]); // Declaração da função para pesquisar clientes por e-mail. Recebe um array de caracteres (string) com até 65 caracteres.

void lista(); // Declaração da função para listar clientes.
void gravarcsv(); // Declaração da função para gravar os dados dos clientes em um arquivo CSV.
void lercsv(); // Declaração da função para ler os dados dos clientes a partir de um arquivo CSV.
void cabecalho(char Titulo[50]); // Declaração da função para imprimir um cabeçalho, recebendo um título como parâmetro, que é um array de caracteres (string) com até 50 caracteres.

/*
Inicio da funcao main, onde e o ponto de partida para o codigo
*/
int main(void){ //ponto de entrada principal de um programa.
    setlocale(LC_ALL, "Portuguese"); // Define o local para Português
    menu(); // Chama a função menu para exibir o menu principal
}
/*
Essa funçao e o cabecalho, onde so apresenta um modelo mais interativo para o cliente
*/
void cabecalho(char Titulo[50]){
    system("cls"); // Limpa a tela do console
    int t = strlen(Titulo); // Calcula o comprimento da string Titulo

    printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separação

    if (strlen(Titulo)==0) // Verifica se a string Titulo está vazia
    {
        printf("                       CADASTRO DE ALUNO UNIALFA 2024\n"); // Imprime o cabeçalho padrão
    }else{
        printf(" %s UNIALFA 2024\n",Titulo); // Imprime o cabeçalho personalizado com o conteúdo de Titulo
    }
    
    printf("|--------------------------------------------------------------------------------|\n"); // Imprime outra linha de separação
}
/*
Funcao menu tem a funcao de apresentar todas a funcoes disponiveis no sistema
*/
void menu(){
    int menu; // Declaração da variável menu para armazenar a opção do usuário
    char t[50]=""; // Declaração de uma string vazia t com tamanho máximo de 50 caracteres
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string vazia t como parâmetro
    printf("Informe sua opção: \n \t 1 = Cadastro; \n\t 2 = Pesquisa; \n\t 3 = Listar alunos; \n\t 4 = Gravar Dados \n\t 5 = Ler Dados \n"); // Exibe as opções do menu
    printf("\r|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separação

    do{
        scanf("%d",&menu); // Lê a opção escolhida pelo usuário
        printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separação

        switch (menu){ // Inicia a estrutura de seleção switch-case com base na opção escolhida
            case 1:
                cadastro(); // Chama a função cadastro para a opção 1
                break;
            case 2:
                pesquisa(); // Chama a função pesquisa para a opção 2
                break;
            case 3:
                lista(); // Chama a função lista para a opção 3
                break;
            case 4:
                gravarcsv(); // Chama a função gravarcsv para a opção 4
                break;
            case 5:
                lercsv(); // Chama a função lercsv para a opção 5
                break;
            case 0:
                exit(0); // Encerra o programa para a opção 0
                break;
            default:
                exit(0); // Encerra o programa para qualquer outra opção inválida
                break;
        }
    } while(menu<4); // Continua o loop enquanto a opção do menu for menor que 4
}
/*
Funcao cadastro e onde voce declara o nome, email, cpf da pessoa e guarda em um vetor
*/
void cadastro(){
    static int linha; // Declaração de uma variável estática linha para controlar o índice de cadastro
    int opc; // Declaração da variável opc para armazenar a opção do usuário

	CAD: // Marcador para um ponto de retorno
    
    printf("Informe o nome do aluno: "); // Solicita o nome do aluno ao usuário
    scanf("\n%65[^\n]s",nome[linha]); // Lê e armazena o nome do aluno na posição atual de linha

    printf("Informe o E-mail do aluno: "); // Solicita o e-mail do aluno ao usuário
    scanf("\n%65[^\n]s",email[linha]); // Lê e armazena o e-mail do aluno na posição atual de linha

    printf("Informe o cpf do aluno: "); // Solicita o CPF do aluno ao usuário
    scanf("\n%14[^\n]s",cpf[linha]); // Lê e armazena o CPF do aluno na posição atual de linha

    printf("Para continuar digite 1. \nPara Sair digite qualquer outro número.\n"); // Solicita a opção do usuário
    scanf("\n%d",&opc); // Lê a opção escolhida pelo usuário

    linha++; // Incrementa a variável linha para avançar para o próximo cadastro

    if(opc==1){ // Verifica se a opção escolhida é 1
        goto CAD; // Retorna ao marcador CAD para adicionar um novo cadastro
    }else{
        menu(); // Chama a função menu para retornar ao menu principal
    };
}

/*
funcao pesquisa e um modo aonde a pessoa pode pesquisar para encontrar a pessoa cadastrada dentro do sistema
*/
void pesquisa(){
    int i, opc; // Declaração das variáveis i e opc para controle e opção do usuário
    char emailP[65], nomeP[65], cpfP[14]; // Declaração das variáveis para armazenar dados de pesquisa
    char t[50]="PESQUISA "; // Declaração de uma string t para o cabeçalho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro

    do{
        printf("\nDigite 1 para pesquisa por CPF; \n 2 para pesquisa por e-mail; \n 3 para pesquisa pelo nome:");
        scanf("%d",&opc); // Lê a opção escolhida pelo usuário

        switch (opc){
            case 1:
                printf("\nInforme o CPF: ");
                scanf("%s",cpfP); // Solicita e lê o CPF para pesquisa
                pesquisaCpf(cpfP); // Chama a função pesquisaCpf passando o CPF como parâmetro
                break;
            case 2:
                printf("\nInforme o e-mail: ");
                scanf("%s",emailP); // Solicita e lê o e-mail para pesquisa
                pesquisaEmail(emailP); // Chama a função pesquisaEmail passando o e-mail como parâmetro
                break;
            case 3:
                printf("\nInforme o nome: ");
                scanf("%s",nomeP); // Solicita e lê o nome para pesquisa
                pesquisaNome(nomeP); // Chama a função pesquisaNome passando o nome como parâmetro
                break;
            default: // Caso nenhum das opcoes anteriores seja escolhida
                printf("\nOpção Inválida."); // Exibe uma mensagem de opçao invalida
                break; // Encerra o bloco de switch
        }

        printf("\nPara continuar digite 1. \nPara Sair digite qualquer outro número.");
        scanf("%d",&opc); // Solicita a opção do usuário para continuar ou sair
    } while (opc == 1); // Continua o loop enquanto o usuário desejar
    return;
}
/*
pesquisa Cpf tem o objetivo de pesquisa por cpf 
*/
void pesquisaCpf(char cpfP[14]){
    char t[50]="PESQUISA CPF "; // Declaração de uma string t para o cabeçalho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro
    printf("Buscando por CPF: [ %s ];\n",cpfP); // Exibe a mensagem de busca pelo CPF fornecido
    int i; // Declaração da variável i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(cpf[i],cpfP)==0){ // Verifica se o CPF fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da função
}
/*
pesquisa Cpf tem o objetivo de pesquisa por email 
*/
void pesquisaEmail(char emailP[65]){
    char t[50]="PESQUISA EMAIL "; // Declaração de uma string t para o cabeçalho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro
    int i; // Declaração da variável i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(email[i],emailP)==0){ // Verifica se o e-mail fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da função
}
/*
pesquisa Cpf tem o objetivo de pesquisa por nome
*/
void pesquisaNome(char nomeP[65]){
    char t[50]="PESQUISA NOME "; // Declaração de uma string t para o cabeçalho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro
    int i; // Declaração da variável i para controle do loop
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strcmp(nome[i],nomeP)==0){ // Verifica se o nome fornecido corresponde a um registro
            printf("\nNOME: %s \nE-MAIL: %s \nCPF: %s",nome[i],email[i],cpf[i]); // Exibe os dados do aluno correspondente
        }
    }
    return; // Retorna ao final da função
}
/*
funcao listar tem que mostrar todos os cadastro de pessoas, completo
*/
void lista(){
    int i; // Declaração da variável i para controle do loop
    int opc; // Declaração da variável opc para armazenar a opção do usuário
    char t[50]="LISTA COMPLETA DE ALUNOS "; // Declaração de uma string t para o cabeçalho
    system("cls"); // Limpa a tela do console
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro
    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        if(strlen(cpf[i]) > 0){ // Verifica se o CPF do aluno na posição i não está vazio
            printf("NOME: %s \nE-MAIL: %s \nCPF: %s \n",nome[i],email[i],cpf[i]); // Exibe os dados do aluno
            printf("|--------------------------------------------------------------------------------|\n"); // Imprime uma linha de separação
        }
    }

    printf("Pressione qualquer tecla para retornar ao Menu \n"); // Solicita ao usuário que pressione qualquer tecla para retornar ao menu
    scanf(" %d",&opc); // Lê a opção do usuário

    if(opc == 1){ // Verifica se a opção escolhida é 1
        menu(); // Chama a função menu para retornar ao menu principal
    }else{
        printf("\nOpção Inválida."); // Exibe uma mensagem de opção inválida
    }
}
/*
funcao gravar tem por objetivo gravar em um arquivo csv todas os cadastro feito pelo sistema
*/
void gravarcsv(){
    int i = 0; // Inicialização da variável i
    char str[144]=""; // Declaração de uma string str para armazenar os dados formatados

    FILE *file; // Declaração de um ponteiro para arquivo
    file = fopen("aluno.csv","a"); // Abre o arquivo aluno.csv em modo de escrita (append)
    if(file == NULL){ // Verifica se houve erro na abertura do arquivo
        printf("Erro no Arquivo de dados!"); // Exibe uma mensagem de erro
    }

    for(i=0; i<45; i++){ // Loop para percorrer os registros de alunos
        memset(&str, 0, sizeof(str)); // Limpa a string str
        if(strlen(nome[i]) > 0){ // Verifica se o nome do aluno na posição i não está vazio
            strcat(str, nome[i]); // Concatena o nome
            strcat(str, ","); // Adiciona uma vírgula
            strcat(str, email[i]); // Concatena o e-mail
            strcat(str, ","); // Adiciona uma vírgula
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
    FILE *file; // Declaração de um ponteiro para arquivo
    char linha[150]; // Declaração de uma string para armazenar cada linha lida do arquivo
    int l = 0; // Inicialização da variável l para controle

    system("cls"); // Limpa a tela do console
    file = fopen("aluno.csv","r"); // Abre o arquivo aluno.csv em modo de leitura

    if(file == NULL){ // Verifica se houve erro na abertura do arquivo
        printf("Erro no Arquivo de dados!"); // Exibe uma mensagem de erro
        return; // Retorna da função
    }

    char t[50] = "ARQUIVO ALUNO.CSV"; // Declaração de uma string t para o cabeçalho
    cabecalho(t); // Chama a função cabecalho passando a string t como parâmetro

    char *result; // Declaração de um ponteiro para armazenar o resultado da leitura

    while(!feof(file)){ // Loop enquanto não chegar ao final do arquivo
        if((result = fgets(linha, 150, file)) != NULL){ // Lê uma linha do arquivo
            printf("Linha %s", linha); // Exibe a linha lida
        }
    }

    fclose(file); // Fecha o arquivo

    do{ 
        printf("\nPara voltar ao menu, pressione a tecla 1 "); // Solicita ao usuário que pressione 1 para voltar ao menu
        scanf("%d", &l); // Lê a opção do usuário
    } while (l != 1); // Continua o loop enquanto a opção for diferente de 1
    menu(); // Retorna ao menu principal
}
