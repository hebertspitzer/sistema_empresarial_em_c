#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//declarando uma struct
typedef struct {
	char id[5];
	char name[26];
	char cnpj[15];
	int ativo;
}Cliente;

//declarando as funções
void CriaCliente();
void ListaClientes();
int ExcluiCliente();

int CustomersPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------Página de clientes---------------\n");
    printf("1 - Ver todos os clientes\n");
    printf("2 - adicionar novo cliente\n");
    printf("3 - remover um cliente\n");
    printf("4 - editar um cliente\n");
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
        ListaClientes();
        break;
    case 2:
    	system("cls");
        CriaCliente();
        break;
    case 3:
        system("cls");
        ExcluiCliente();
        break;
    case 4:
        system("cls");
        printf("editar um cliente\n");
        break;
    default:
        system("cls");
        break;
    }
    if(select < 0 || select > 4){
    	//teste para se o usuario inserir numero menor ou maior do que o permitido
        printf("O número da função não e válido\n");
    }
    
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da função principal main
}


//criação da função CriaCliente

void CriaCliente() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/clientes.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	Cliente tcliente;
	char tstring[26];
	
	//entrada do id do cliente
	printf("Digite o id do cliente: ");
	scanf( "%4s", tcliente.id);
	fflush(stdin);
	
	//entrada do nome do cliente
	printf("Digite o nome do cliente: ");
	scanf( "%25[^\n]s", tcliente.name);
	fflush(stdin);
	
	//tratamento do nome do cliente alterando o espaço por "_" e salvando em outra string
	for(int i = 0; i < 26; i++) {
        if (tcliente.name[i] == ' '){
        	tstring[i] = '_';
		}else if(tcliente.name[i] == '\n'){
        	tstring[i] = '\0';
        }else{
        	tstring[i] = tcliente.name[i];
		}
    }
    
    //entrada do cnpj do cliente
	printf("Digite o cnpj do cliente: ");
	scanf( "%14s", tcliente.cnpj);
	fflush(stdin);
	system("cls");
	
	//salvando o cliente como ativo
	tcliente.ativo = 1;
	
	
	printf("\t------Cliente adicionado com sucesso------\n");
	printf("id: %s\n",tcliente.id);
	printf("name: %s\n",tcliente.name);
	printf("cnpj: %s\n\n",tcliente.cnpj);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %s %s %d", tcliente.id, tstring, tcliente.cnpj, tcliente.ativo);
	
	//fechando o arquivo
	fclose(farq);
}


//criação da função ListaClientes
void ListaClientes(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/clientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		//declaração das variaveis
		Cliente tcliente;
		char tstring[26];
		
		//lendo as infos do arquivo e salvando na struct tcliente
		fscanf(farq, "%s %s %s %d", tcliente.id, tcliente.name, tcliente.cnpj, &tcliente.ativo);
		
		//tratando o nome do cliente, trocando o "_" por espaço
		for(int i = 0; i < 26; i++) {
        if (tcliente.name[i] == '_'){
        	tstring[i] = ' ';
		}else{
        	tstring[i] = tcliente.name[i];
		}
    	}
    	
    	//imprimindo as infos da struct tcliente
		printf("Id:%s \nNome:%s \nCNPJ:%s\n--------------------------------\n", tcliente.id, tstring, tcliente.cnpj);
	}
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função ExcluiCliente AINDA NAO ESTA FUNCIONANDO
int ExcluiCliente(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/clientes.txt", "r+");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	char id[5];
	
	//entrada do id do cliente
	printf("Qual o id do cliente que voce deseja excluir: ");
	scanf( "%4s", id);
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		//declaração das variaveis
		Cliente tcliente;
		int buscaId;
		
		//lendo as infos do arquivo e salvando na struct tcliente
		fscanf(farq, "%s %s %s %d", tcliente.id, tcliente.name, tcliente.cnpj, &tcliente.ativo);
		
		//comparando o id digitado com os ids do arquivo
		buscaId = strncmp(tcliente.id, id, 4);
		
		
		if(buscaId == 0){
			fclose(farq);
			printf("teste");
			Sleep(500);
			FILE *farq = fopen("arquivos_txt/clientes.txt", "a");
			tcliente.ativo = 10;
			printf("%d",tcliente.ativo);
			Sleep(500);
			fprintf(farq, "\n%d",tcliente.ativo);
			return(0);
		}
		printf("\n%d\n",buscaId);
	}
	//fechando o arquivo
	fclose(farq);
}

