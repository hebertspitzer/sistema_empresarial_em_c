#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//declarando uma struct
typedef struct {
	char id[5];
	int prazo;
	char tarefa[101];
}Tarefas;

//declarando as funções
void CriaTarefa();
void ListaTarefas();
void ExcluiTarefas();
void EditarTarefas();

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
        ExcluiTarefas();
        break;
    case 4:
        system("cls");
        EditarTarefas();
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
	
	//entrada do id da tarefa
	printf("Digite o id da tarefa: ");
	scanf( "%4s", ttarefas.id);
	fflush(stdin);
	
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
    
    system("cls");
    printf("\t------Tarefa adicionada com sucesso------\n");
    printf("Id: %s\n",ttarefas.id);
	printf("Prazo: %d horas\n",ttarefas.prazo);
	printf("Tarefa: %s\n",ttarefas.tarefa);
	
	//salvando as infos do cliente no arquivo txt
	fprintf(farq, "\n%s %d %s", ttarefas.id, ttarefas.prazo, tstring);
	
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
		fscanf(farq, "%s %d %s", ttarefas.id, &ttarefas.prazo, ttarefas.tarefa);
		
		//tratando o nome do cliente, trocando o "_" por espaço
		for(int i = 0; i < 101; i++) {
        if (ttarefas.tarefa[i] == '_'){
        	tstring[i] = ' ';
		}else{
        	tstring[i] = ttarefas.tarefa[i];
		}
    	}
    	//imprimindo as infos da struct ttarefas
		printf("Id:%s \nPrazo:%d horas\nTarefa:%s\n--------------------------------\n",ttarefas.id, ttarefas.prazo, tstring);
	}
	fclose(farq);
	//fechando o arquivo
}

//criação da função ExcluiTarefas
void ExcluiTarefas(){
	//declaração das variaveis
	Tarefas ttarefas[50];
	int cont=0, excTarefa=-1;
	char id[5];
	
	//entrada do id da tarefa
	printf("Qual o id da tarefa que voce deseja excluir: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/tarefas.txt", "r+b");
	
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
		fscanf(original, "%s %d %s", ttarefas[cont].id, &ttarefas[cont].prazo, ttarefas[cont].tarefa);
		
		//buscando o id da tarefa digitado
    	buscaId = strncmp(ttarefas[cont].id, id, 4);
    	
    	//salvando a posição que esta a tarefa que deseja remover 
    	if(buscaId == 0){
    		excTarefa = cont;
		}
		
		//aumentando o contador para criar uma nova tarefa
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(excTarefa == -1){
		system("cls");
		printf("\nO id da tarefa não existe\n");
	} else {
	
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo, menos a tarefa removida
		for(int i=0;i<cont;i++){
		
			if(i == excTarefa) {
				printf("-");
			} else {
				fprintf(alterado, "\n%s %d %s", ttarefas[i].id, ttarefas[i].prazo, ttarefas[i].tarefa);
			}
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/tarefas.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/tarefas.txt");
	
		//limpando a tela e falando que a tarefa foi excluido
		system("cls");
		printf("a tarefa foi excluida com sucesso\n");
	}
}

//criação da função EditarTarefas
void EditarTarefas(){
	//declaração das variaveis
	Tarefas ttarefas[50];
	int cont=0, tarefaSel=-1;
	char id[5];
	
	//entrada do id da tarefa
	printf("Qual o id da tarefa que voce deseja editar: ");
	scanf( "%4s", id);
	
	//Abrindo o arquivo
	FILE *original = fopen("arquivos_txt/tarefas.txt", "r+b");
	
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
		fscanf(original, "%s %d %s", ttarefas[cont].id, &ttarefas[cont].prazo, ttarefas[cont].tarefa);
		
		//buscando o id da tarefa digitado
    	buscaId = strncmp(ttarefas[cont].id, id, 4);
    	
    	//salvando a posição que esta a tarefa que deseja editar
    	if(buscaId == 0){
    		tarefaSel = cont;
		}
		
		//aumentando o contador para criar uma nova tarefa
		cont++;
	}
	//fechando o arquivo
	fclose(original);
	
	//verificando se existe o id digitado
	if(tarefaSel == -1){
		system("cls");
		printf("\nO id da tarefa não existe\n");
	} else {
		//var usada para selecionar o item do menu
    	int select;
		do{
    		printf("------------O que vc deseja editar?------------\n");
    		printf("1 - Id\n");
    		printf("2 - Prazo\n");
    		printf("3 - Tarefa\n");
    		printf("-----------------------------------------------\n");
	
			//entrada do numero da função
    		printf("Digite o número da Função desejada:");
    		scanf("%d",&select);

    		//switch case usado para selecionar o item do menu
    		switch (select)
    		{
    		case 1:
    			system("cls");
        		printf("Digite o novo Id:");
        		scanf( "%4s", ttarefas[tarefaSel].id);
				fflush(stdin);
       		 	break;
    		case 2:
    			system("cls");
				printf("Digite o novo prazo da tarefa em horas: ");
				scanf( "%d", &ttarefas[tarefaSel].prazo);
				fflush(stdin);
        		break;
    		case 3:
        		system("cls");
        		fflush(stdin);
        		char tstring[101];
        		
				//entrada da tarefa
				printf("Digite a nova tarefa: ");
				fgets(tstring, sizeof(tstring), stdin);
				fflush(stdin);
	
				//tratamento da tarefa alterando o espaço por "_" e salvando em outra string
				for(int i = 0; i < 101; i++) {
        			if (tstring[i] == ' '){
        				ttarefas[tarefaSel].tarefa[i] = '_';
					}else if(tstring[i] == '\n'){
        				ttarefas[tarefaSel].tarefa[i] = '\0';
        			}else{
        				ttarefas[tarefaSel].tarefa[i] = tstring[i];
					}
    			}
    			
        		break;
    		default:
        		system("cls");
        		break;
    		}
    		//teste para se o usuario inserir numero menor ou maior do que o permitido
    		if(select < 0 || select > 3){
        		printf("O número da função não e válido\n");
    		}
			//so sai do loop se o valor tiver uma funcao
		}while (select < 0 || select > 3);
		
		//criando um novo arquivo
		FILE *alterado = fopen("arquivos_txt/alterado.txt", "a");
	
		//passando tudo do antigo arquivo para este novo e a tarefa editada
		for(int i=0;i<cont;i++){
			fprintf(alterado, "\n%s %d %s", ttarefas[i].id, ttarefas[i].prazo, ttarefas[i].tarefa);
		}
	
		//fechando o arquivo
		fclose(alterado);
	
		//removendo o antigo arquivo
		remove("arquivos_txt/tarefas.txt");
	
		//renomeando o novo arquivo
		rename("arquivos_txt/alterado.txt", "arquivos_txt/tarefas.txt");
	
		//limpando a tela e falando que a tarefa foi editado
		system("cls");
		printf("a tarefa foi editada com sucesso\n");
	}
}
