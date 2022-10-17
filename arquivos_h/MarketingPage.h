#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char informacao[100];
}Info;

void CriaInformacao();
void ListaInformacoes();

int MarketingPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
     printf("--------------Página de Marketing--------------\n");
    printf("1 - Ver todas as informações de marketing da empresa\n");
    printf("2 - adicionar nova informação\n");
    printf("3 - remover uma informação\n");
    printf("4 - editar uma informação\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o número da Função desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
    	system("cls");
        ListaInformacoes();
        break;
    case 2:
    	system("cls");
        CriaInformacao();
        break;
    case 3:
        system("cls");
        printf("remover uma informacao\n");
        break;
    case 4:
        system("cls");
        printf("editar uma informacao\n");
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

void CriaInformacao() {
	FILE *farq = fopen("arquivos_txt/informacoes.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	Info tinfo;
	
	printf("Digite a informacao de marketing: ");
	scanf( "%99[^\n]s", tinfo.informacao);
	fflush(stdin);
	system("cls");
	
	printf("\t------informação adicionada com sucesso------\n");
	printf("informação: %s\n",tinfo.informacao);
	
	fprintf(farq, "\n%s", tinfo.informacao);
	fclose(farq);
}

void ListaInformacoes(){
	FILE *farq = fopen("arquivos_txt/informacoes.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		Info tinfo;
		fscanf(farq, "%s", tinfo.informacao);
		printf("Informação: %s\n--------------------------------\n", tinfo.informacao);
	}
	fclose(farq);
	//nao consegue ler nome com espaço
}

