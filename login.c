#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include "arquivos_h/PageMenu.h"

typedef struct {
	char email[30];
	char nome[26];
	char senha[20];
}Conta;

void FazerLogin();
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
    	fflush(stdin);
    	FazerLogin();
        break;
    case 2:
    	system("cls");
    	fflush(stdin);
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
        printf("O número da opcao não e valido\n");
    }

}while (select != 0);
}


void CriaConta(){
	FILE *farq = fopen("arquivos_txt/conta.txt", "a");
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

void FazerLogin(){
	char email[30], senha[30];
	int verificacao=0, testeSenha, testeEmail;
	char temail[30];
	
	printf("Insira o seu email: ");
	scanf( "%29s", email);
	fflush(stdin);
	printf("Insira a sua senha: ");
	scanf( "%19s", senha);
	fflush(stdin);
	
	FILE *farq = fopen("arquivos_txt/conta.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		Conta tconta;
		fscanf(farq, "%s %s %s", tconta.email, tconta.nome, tconta.senha);
		testeEmail = strncmp(tconta.email, email, 29);
		testeSenha = strncmp(tconta.senha, senha, 19);
	}
	fclose(farq);
	
	if(testeEmail>0 || testeEmail<0 || testeSenha>0 || testeSenha<0){
		system("cls");
		printf("*********Os dados inseridos são invalidos*********");
		Sleep(1000);
		system("cls");
	}else{
		system("cls");
		printf("Acesso liberado\n");
		Sleep(500);
		system("cls");
		Menu();
	}
	}
