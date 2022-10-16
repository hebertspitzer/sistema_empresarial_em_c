#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char email[30];
	char nome[26];
	char senha[20];
}Conta;


void CriaConta();

int main(){
    setlocale(LC_ALL, "Portuguese");
    int select;

do{
    printf("1 - Fazer login\n");
    printf("2 - Criar uma conta\n");
    printf("3 - Recuperar senha\n");
    printf("0 - Finalizar o sistema\n");

    printf("Digite o numero da opcao desejada:");
    scanf("%d",&select);
    switch (select)
    {
    case 1:
    	system("cls");
        printf("Pagina de login selecionada\n");
        break;
    case 2:
    	system("cls");
        CriaConta();
        break;
    case 3:
    	system("cls");
        printf("Pagina de recuperar selecionada\n");
        break;
    default:
        break;
    }
    if(select < 0 || select > 3){
    	system("cls");
        printf("O numero da opcao nao e valido\n");
    }

}while (select != 0);
}


void CriaConta(){
	FILE *farq = fopen("conta.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	Conta tconta;
	
	printf("Digite o seu email: ");
	scanf( "%29s", tconta.email);
	fflush(stdin);
	printf("Digite o seu nome: ");
	scanf( "%25[^\n]s", tconta.nome);
	fflush(stdin);
	printf("Digite a senha: ");
	scanf( "%19s", tconta.senha);
	fflush(stdin);
	system("cls");
	
	printf("\t------Conta adicionada com sucesso------\n");
	printf("email: %s\n",tconta.email);
	printf("nome: %s\n",tconta.nome);
	printf("\t------------------------------------------\n");
	
	fprintf(farq, "\n%s %s %s", tconta.email, tconta.nome, tconta.senha);
	fclose(farq);
}
