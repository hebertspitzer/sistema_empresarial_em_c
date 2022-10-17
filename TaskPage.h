#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int prazo;
	char tarefa[101];
}Tarefas;

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
    if(select < 0 || select > 4){
        printf("O número da função não e válido\n");
    }

}while (select != 0);

}

void CriaTarefa() {
	FILE *farq = fopen("tarefas.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	Tarefas ttarefas;
	
	printf("Digite o prazo da tarefa em horas: ");
	scanf( "%d", &ttarefas.prazo);
	fflush(stdin);
	printf("Digite a tarefa: ");
	scanf( "%100s", ttarefas.tarefa);
	fflush(stdin);
	
	printf("\t------Tarefa adicionada com sucesso------\n");
	printf("Prazo: %d horas\n",ttarefas.prazo);
	printf("Tarefa: %s\n",ttarefas.tarefa);
	
	fprintf(farq, "\n%d %s", ttarefas.prazo, ttarefas.tarefa);
	fclose(farq);
}

void ListaTarefas(){
	FILE *farq = fopen("tarefas.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	fseek(farq, 0, SEEK_SET);
	while(!feof(farq)){
		Tarefas ttarefas;
		fscanf(farq, "%d %s", &ttarefas.prazo, ttarefas.tarefa);
		printf("Prazo:%d horas\nTarefa:%s\n--------------------------------\n", ttarefas.prazo, ttarefas.tarefa);
	}
	fclose(farq);
	//nao consegue ler nome com espaço
}

