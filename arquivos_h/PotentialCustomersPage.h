#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declarando uma struct
typedef struct {
	char nome[26];
	char email[31];
	char telefone[12];
}PossivelCliente;

//declarando as funções
void CriaPossivelCliente();
void ListaPossiveisclientes();

int PotentialCustomersPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("---------Página de possiveis clientes----------\n");
    printf("1 - ver todos os possiveis clientes\n");
    printf("2 - adicionar um novo possivel cliente\n");
    printf("3 - remover um possivel cliente\n");
    printf("4 - editar um possivel cliente\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");

	//entrada do numero da função
    printf("Digite o número da Função desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
    	system("cls");
    	fflush(stdin);
        ListaPossiveisclientes();
        break;
    case 2:
    	system("cls");
    	fflush(stdin);
        CriaPossivelCliente();
        break;
    case 3:
        system("cls");
        printf("remover um possivel cliente\n");
        break;
    case 4:
        system("cls");
        printf("editar um possivel cliente\n");
        break;
    default:
        system("cls");
        break;
    }
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 4){
        printf("O número da função não e válido\n");
    }
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da função principal main
}

//criação da função CriaFinancas
void CriaPossivelCliente() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/possiveisClientes.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	PossivelCliente tpossivelCliente;
	char tstring[25];
	
	//entrada do nome do possivel cliente
	printf("Digite o nome do possivel cliente: ");
	scanf( "%25[^\n]s", tpossivelCliente.nome);
	fflush(stdin);
	
	//tratamento do nome do possivel cliente alterando o espaço por "_" e salvando em outra string
	for(int i = 0; i < 25; i++) {
        if (tpossivelCliente.nome[i] == ' '){
        	tstring[i] = '_';
		}else if(tpossivelCliente.nome[i] == '\n'){
        	tstring[i] = '\0';
        }else{
        	tstring[i] = tpossivelCliente.nome[i];
		}
    }
    
    //entrada do email do possivel cliente
	printf("Digite o email do possivel cliente: ");
	scanf( "%30s", tpossivelCliente.email);
	fflush(stdin);
	
	//entrada do telefone do possivel cliente
	printf("Digite o telefone do possivel cliente: ");
	scanf( "%11s", tpossivelCliente.telefone);
	fflush(stdin);
	system("cls");
	
	printf("\t------possivel cliente adicionado com sucesso------\n");
	printf("Nome: %s\n",tpossivelCliente.nome);
	printf("Email: %s\n",tpossivelCliente.email);
	printf("Telefone: %s\n\n",tpossivelCliente.telefone);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %s %s", tstring, tpossivelCliente.email, tpossivelCliente.telefone);
	
	//fechando o arquivo
	fclose(farq);
}

void ListaPossiveisclientes(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/possiveisClientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		
		//declaração das variaveis
		char tstring[25];
		PossivelCliente tpossivelCliente;
		
		//lendo as infos do arquivo e salvando na struct tpossivelCliente
		fscanf(farq, "%s %s %s", tpossivelCliente.nome, tpossivelCliente.email, tpossivelCliente.telefone);
		
		//tratando o nome do cliente, trocando o "_" por espaço
		for(int i = 0; i < 25; i++) {
        	if (tpossivelCliente.nome[i] == '_'){
        		tstring[i] = ' ';
			}else{
        		tstring[i] = tpossivelCliente.nome[i];
			}
    	}
		
		//imprimindo as infos da struct tpossivelCliente
		printf("Nome:%s \nEmail:%s \nTelefone:%s\n--------------------------------\n", tstring, tpossivelCliente.email, tpossivelCliente.telefone);
	}
	//fechando o arquivo
	fclose(farq);
}

