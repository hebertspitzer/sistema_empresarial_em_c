#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include "arquivos_h/PageMenu.h"

//declarando uma struct
typedef struct {
	char email[30];
	char nome[26];
	char senha[20];
}Conta;

//declarando as funções
void FazerLogin();
void CriaConta();


int main(){
	//ajustando para aceitar acentos
    setlocale(LC_ALL, "Portuguese");
    
    //declaração da variavel de seleção de função
    int select;

do{
    printf("1 - Fazer login\n");
    printf("2 - Criar uma conta\n");
    printf("3 - Recuperar senha\n");
    printf("0 - Finalizar o sistema\n");

	//entrada do numero da função
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
    
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 3){
    	system("cls");
        printf("O número da opcao não e valido\n");
    }
    
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da função principal main
}


//criação da função CriaConta
void CriaConta()
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/conta.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	Conta tconta;
	
	//entrada do email
	printf("Digite o seu email: ");
	scanf( "%29s", tconta.email);
	fflush(stdin);
	
	//entrada do nome
	printf("Digite o seu nome: ");
	scanf( "%25[^\n]s", tconta.nome);
	fflush(stdin);
	
	//entrada da senha
	printf("Digite a senha: ");
	scanf( "%19s", tconta.senha);
	fflush(stdin);
	system("cls");
	
	printf("\t------Conta adicionada com sucesso------\n");
	printf("email: %s\n",tconta.email);
	printf("nome: %s\n",tconta.nome);
	printf("\t------------------------------------------\n");
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %s %s", tconta.email, tconta.nome, tconta.senha);
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função FazerLogin
void FazerLogin(){
	
	//declaração das variaveis que serão utilizadas
	char email[30], senha[30];
	int testeSenha, testeEmail;
	
	//entrada de dados do login
	printf("Insira o seu email: ");
	scanf( "%29s", email);
	fflush(stdin);
	
	printf("Insira a sua senha: ");
	scanf( "%19s", senha);
	fflush(stdin);
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/conta.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		
		Conta tconta;
		
		fscanf(farq, "%s %s %s", tconta.email, tconta.nome, tconta.senha);
		
		//testando se o email e senha digitado pelo usuario é o mesmo que esta salvo na linha
		testeEmail = strncmp(tconta.email, email, 29);
		testeSenha = strncmp(tconta.senha, senha, 19);
	}
	
	//fechando o arquivo
	fclose(farq);
	
	//teste para verificar se o email e senha estão corretos
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
