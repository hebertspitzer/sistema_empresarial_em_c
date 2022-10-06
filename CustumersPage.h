#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char id[4];
	char name[25];
	char cnpj[14];
}Cliente;


int CustomersPage(){
	FILE *farq;
	Cliente tempCliente[30], cliente[30];
	int cont;
	
	farq = fopen("contcliente.txt", "rb");
	fread(&cont, sizeof(int), 1, farq);
	printf("%d",cont);
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------P�gina de clientes---------------\n");
    printf("1 - Ver todos os clientes\n");
    printf("2 - adicionar novo cliente\n");
    printf("3 - remover um cliente\n");
    printf("4 - editar um cliente\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o n�mero da Fun��o desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        printf("Ver todos os clientes\n");
        break;
    case 2:
        system("cls");
        printf("adicionar novo cliente\n");
        printf("Digite o id do %d� cliente (at� 4 caracteres): ",cont+1);
		scanf("%s", &cliente[cont].id);
		printf("Digite o nome do %d� cliente",cont+1);
		scanf("%s", &cliente[cont].name);
		printf("Digite o cnpj do %d cliente (o cnpj tem 14 numeros): ",cont+1);
		scanf("%s", &cliente[cont].cnpj);
		cont++;
		
		farq = fopen("arqclientes.txt", "wb");
		fwrite(cliente, sizeof(Cliente), cont+1, farq); // grava o array de registros alunos
		fclose(farq);
		
		farq = fopen("contcliente.txt", "wb");
		fwrite(&cont, sizeof(int), 1, farq);
		fclose(farq);
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
        printf("O n�mero da fun��o n�o e v�lido\n");
    }

}while (select != 0);

}
