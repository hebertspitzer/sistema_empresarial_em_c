#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char nome[26];
	char email[31];
	char telefone[12];
}PossivelCliente;

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


    printf("Digite o número da Função desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
    	system("cls");
        ListaPossiveisclientes();
        break;
    case 2:
    	system("cls");
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
    if(select < 0 || select > 4){
        printf("O número da função não e válido\n");
    }

}while (select != 0);

}

void CriaPossivelCliente() {
	FILE *farq = fopen("arquivos_txt/possiveisClientes.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	PossivelCliente tpossivelCliente;
	
	printf("Digite o nome do possivel cliente: ");
	scanf( "%25s", tpossivelCliente.nome);
	fflush(stdin);
	printf("Digite o email do possivel cliente: ");
	scanf( "%30s", tpossivelCliente.email);
	fflush(stdin);
	printf("Digite o telefone do possivel cliente: ");
	scanf( "%11s", tpossivelCliente.telefone);
	fflush(stdin);
	system("cls");
	
	printf("\t------possivel cliente adicionado com sucesso------\n");
	printf("Nome: %s\n",tpossivelCliente.nome);
	printf("Email: %s\n",tpossivelCliente.email);
	printf("Telefone: %s\n\n",tpossivelCliente.telefone);
	
	fprintf(farq, "\n%s %s %s", tpossivelCliente.nome, tpossivelCliente.email, tpossivelCliente.telefone);
	fclose(farq);
}

void ListaPossiveisclientes(){
	FILE *farq = fopen("arquivos_txt/possiveisClientes.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		PossivelCliente tpossivelCliente;
		fscanf(farq, "%s %s %s", tpossivelCliente.nome, tpossivelCliente.email, tpossivelCliente.telefone);
		printf("Nome:%s \nEmail:%s \nTelefone:%s\n--------------------------------\n", tpossivelCliente.nome, tpossivelCliente.email, tpossivelCliente.telefone);
	}
	fclose(farq);
	//nao consegue ler nome com espaço
}

