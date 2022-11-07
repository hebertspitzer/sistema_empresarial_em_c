#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declarando uma struct
typedef struct {
	char id[5];
	float valorEnt;
	float valorSaido;
}Financas;

//declarando as funções
void CriaFinancas();
void ListaFinancas();
void ExcluiFinanca();

int FinancierPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");
    
    //configurando para aceitar virgula no float
    setlocale(LC_NUMERIC, "pt_BR");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------Página de finanças---------------\n");
    printf("1 - ver todas as informações de finanças\n");
    printf("2 - adicionar uma nova informação\n");
    printf("3 - remover uma informação\n");
    printf("4 - editar uma informação\n");
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
        ListaFinancas();
        break;
    case 2:
    	system("cls");
        CriaFinancas();
        break;
    case 3:
        system("cls");
        ExcluiFinanca();
        break;
    case 4:
        system("cls");
        printf("editar uma finança\n");
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
void CriaFinancas() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/financas.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	Financas tfinancas;
	
	//entrada do id da finança
	printf("Digite o id da finança: ");
	scanf( "%4s", tfinancas.id);
	fflush(stdin);
	
	//entrada do valor entrado
	printf("Digite o valor entrado: ");
	scanf( "%f", &tfinancas.valorEnt);
	fflush(stdin);
	
	//entrada do valor saido
	printf("Digite o valor saido: ");
	scanf( "%f", &tfinancas.valorSaido);
	fflush(stdin);
	
	system("cls");
	printf("\t------Finança adicionada com sucesso------\n");
	printf("id: %s\n",tfinancas.id);
	printf("valor entrado: %.2f\n",tfinancas.valorEnt);
	printf("valor saido: %.2f\n",tfinancas.valorSaido);
	
	//salvando as informações no arquivo txt
	fprintf(farq, "\n%s %f %f", tfinancas.id, tfinancas.valorEnt, tfinancas.valorSaido);
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função ListaFinancas
void ListaFinancas(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/financas.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		
		//declaração das variaveis
		Financas tfinancas;
		
		//lendo as infos do arquivo e salvando na struct tfinancas
		fscanf(farq, "%s %f %f", tfinancas.id, &tfinancas.valorEnt, &tfinancas.valorSaido);
		
		//imprimindo as infos da struct tfinancas
		printf("Id: %s \nValor entrado: %.2f \nValor saido: %.2f\n--------------------------------\n",tfinancas.id, tfinancas.valorEnt, tfinancas.valorSaido);
	}
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função ExcluiFinanca
void ExcluiFinanca(){
	//declaração das variaveis
	Financas tfinancas[50];
	int cont=0, excFinanca=-1;
	char id[5];
	
	//entrada do id da financa
	printf("Qual o id da finança que voce deseja excluir: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/financas.txt", "r+b");
	
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
		
		//lendo as infos do arquivo e salvando nas struct tfinancas
		fscanf(original, "%s %f %f", tfinancas[cont].id, &tfinancas[cont].valorEnt, &tfinancas[cont].valorSaido);
		
		//buscando o id do financa digitado
    	buscaId = strncmp(tfinancas[cont].id, id, 4);
    	
    	//salvando a posição que esta a financa que deseja remover 
    	if(buscaId == 0){
    		excFinanca = cont;
		}
		
		//aumentando o contador para criar uma nova financa
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(excFinanca == -1){
		system("cls");
		printf("\nO id da finança não existe\n");
	} else {
	
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo, menos a financa removido
		for(int i=0;i<cont;i++){
		
			if(i == excFinanca) {
				printf("-");
			} else {
				fprintf(alterado, "\n%s %f %f", tfinancas[i].id, tfinancas[i].valorEnt, tfinancas[i].valorSaido);
			}
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/financas.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/financas.txt");
	
		//limpando a tela e falando que a financa foi excluido
		system("cls");
		printf("a finança foi excluida com sucesso\n");
	}
}


