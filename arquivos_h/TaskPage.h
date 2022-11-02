#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//declarando uma struct
typedef struct {
	int prazo;
	char tarefa[101];
}Tarefas;

//declarando as funções
void CriaTarefa();
void ListaTarefas();

int TaskPage(){
	
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------Página de tarefas---------------\n");
    printf("1 - ver todas as tarefas\n");
    printf("2 - adicionar uma nova tarefa\n");
    printf("3 - remover uma tarefa\n");
    printf("4 - editar uma tarefa\n");
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
        ListaTarefas();
        break;
    case 2:
    	system("cls");
        CriaTarefa();
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
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 4){
        printf("O número da função não e válido\n");
    }
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da função principal main
}

//criação da função CriaTarefa
void CriaTarefa() {
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/tarefas.txt", "a");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis
	Tarefas ttarefas;
	char tstring[101];
	
	//entrada do prazo da tarefa
	printf("Digite o prazo da tarefa em horas: ");
	scanf( "%d", &ttarefas.prazo);
	fflush(stdin);
	
	//entrada da tarefa
	printf("Digite a tarefa: ");
	fgets(ttarefas.tarefa, sizeof(ttarefas.tarefa), stdin);
	fflush(stdin);
	
	//tratamento da tarefa alterando o espaço por "_" e salvando em outra string
	for(int i = 0; i < 101; i++) {
        if (ttarefas.tarefa[i] == ' '){
        	tstring[i] = '_';
		}else if(ttarefas.tarefa[i] == '\n'){
        	tstring[i] = '\0';
        }else{
        	tstring[i] = ttarefas.tarefa[i];
		}
    }
    
    printf("\t------Tarefa adicionada com sucesso------\n");
	printf("Prazo: %d horas\n",ttarefas.prazo);
	printf("Tarefa: %s\n",ttarefas.tarefa);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%d %s", ttarefas.prazo, tstring);
	
	//fechando o arquivo
	fclose(farq);
}

//criação da função ListaTarefas
void ListaTarefas(){
	
	//abrindo o arquivo
	FILE *farq = fopen("arquivos_txt/tarefas.txt", "r+b");
	
	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}
	
	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);
	
	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){
		
		//declaração das variaveis
		char tstring[101];
		Tarefas ttarefas;
		
		//lendo as infos do arquivo e salvando na struct ttarefas
		fscanf(farq, "%d %s", &ttarefas.prazo, ttarefas.tarefa);
		
		//tratando o nome do cliente, trocando o "_" por espaço
		for(int i = 0; i < 101; i++) {
        if (ttarefas.tarefa[i] == '_'){
        	tstring[i] = ' ';
		}else{
        	tstring[i] = ttarefas.tarefa[i];
		}
    	}
    	//imprimindo as infos da struct ttarefas
		printf("Prazo:%d horas\nTarefa:%s\n--------------------------------\n", ttarefas.prazo, tstring);
	}
	fclose(farq);
	//fechando o arquivo
}

