#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declarando uma struct
typedef struct {
	char id[5];
	char nome[26];
	char email[31];
	char telefone[12];
}PossivelCliente;

//declarando as funções
void CriaPossivelCliente();
void ListaPossiveisclientes();
void ExcluiPossiveisclientes();

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
        ExcluiPossiveisclientes();
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

//criação da função CriaPossivelCliente
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
	
	//entrada do id do finança
	printf("Digite o id do possivel cliente: ");
	scanf( "%4s", tpossivelCliente.id);
	fflush(stdin);
	
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
	printf("Id: %s\n",tpossivelCliente.id);
	printf("Nome: %s\n",tpossivelCliente.nome);
	printf("Email: %s\n",tpossivelCliente.email);
	printf("Telefone: %s\n\n",tpossivelCliente.telefone);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %s %s %s",tpossivelCliente.id, tstring, tpossivelCliente.email, tpossivelCliente.telefone);
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função ListaPossiveisclientes
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
		fscanf(farq, "%s %s %s %s",tpossivelCliente.id ,tpossivelCliente.nome, tpossivelCliente.email, tpossivelCliente.telefone);
		
		//tratando o nome do cliente, trocando o "_" por espaço
		for(int i = 0; i < 25; i++) {
        	if (tpossivelCliente.nome[i] == '_'){
        		tstring[i] = ' ';
			}else{
        		tstring[i] = tpossivelCliente.nome[i];
			}
    	}
		
		//imprimindo as infos da struct tpossivelCliente
		printf("Id:%s \nNome:%s \nEmail:%s \nTelefone:%s\n--------------------------------\n", tpossivelCliente.id ,tstring, tpossivelCliente.email, tpossivelCliente.telefone);
	}
	//fechando o arquivo
	fclose(farq);
}

//criação da função ExcluiPossiveisTarefas
void ExcluiPossiveisclientes(){
	//declaração das variaveis
	PossivelCliente tpossivelCliente[50];
	int cont=0, excPossivelCliente=-1;
	char id[5];
	
	//entrada do id do possivel cliente
	printf("Qual o id do possivel cliente que voce deseja excluir: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/possiveisClientes.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(original == NULL){
		exit(0);
	}
	
	//posicionando no inicio do arquivo
	fseek(original, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(original)){
		//declarando a variavel
		int buscaId;
		
		//lendo as infos do arquivo e salvando nas struct ttarefas
		fscanf(original, "%s %s %s %s",tpossivelCliente[cont].id ,tpossivelCliente[cont].nome, tpossivelCliente[cont].email, tpossivelCliente[cont].telefone);
		
		//buscando o id do possivel cliente digitado
    	buscaId = strncmp(tpossivelCliente[cont].id, id, 4);
    	
    	//salvando a posição que esta o possivel cliente que deseja remover 
    	if(buscaId == 0){
    		excPossivelCliente = cont;
		}
		
		//aumentando o contador para criar um novo possivel cliente
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(excPossivelCliente == -1){
		system("cls");
		printf("\nO id do possivel cliente não existe\n");
	} else {
	
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo, menos o possivel cliente removido
		for(int i=0;i<cont;i++){
		
			if(i == excPossivelCliente) {
				printf("-");
			} else {
				fprintf(alterado, "\n%s %s %s %s",tpossivelCliente[i].id, tpossivelCliente[i].nome, tpossivelCliente[i].email, tpossivelCliente[i].telefone);
			}
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/possiveisClientes.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/possiveisClientes.txt");
	
		//limpando a tela e falando que o possivel cliente foi excluido
		system("cls");
		printf("o possivel cliente foi excluido com sucesso\n");
	}
}

