#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char id[5];
	char name[26];
	char cnpj[15];
}Cliente;

void CriaCliente();
void ListaClientes();

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
        printf("remover um cliente\n");
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
        printf("O número da função não e válido\n");
    }

}while (select != 0);

}

void CriaCliente() {
	FILE *farq = fopen("arquivos_txt/clientes.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	Cliente tcliente;
	
	printf("Digite o id do cliente: ");
	scanf( "%4s", tcliente.id);
	fflush(stdin);
	printf("Digite o nome do cliente: ");
	scanf( "%25[^\n]s", tcliente.name);
	fflush(stdin);
	printf("Digite o cnpj do cliente: ");
	scanf( "%14s", tcliente.cnpj);
	fflush(stdin);
	system("cls");
	
	printf("\t------Cliente adicionado com sucesso------\n");
	printf("id: %s\n",tcliente.id);
	printf("name: %s\n",tcliente.name);
	printf("cnpj: %s\n\n",tcliente.cnpj);
	
	fprintf(farq, "\n%s %s %s", tcliente.id, tcliente.name, tcliente.cnpj);
	fclose(farq);
}

void ListaClientes(){
	FILE *farq = fopen("arquivos_txt/clientes.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		Cliente tcliente;
		fscanf(farq, "%s %s %s", tcliente.id, tcliente.name, tcliente.cnpj);
		printf("Id:%s \nNome:%s \nCNPJ:%s\n--------------------------------\n", tcliente.id, tcliente.name, tcliente.cnpj);
	}
	fclose(farq);
	//nao consegue ler nome com espaço
}

