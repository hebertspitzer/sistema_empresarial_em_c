#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
        printf("ver todas as tarefas\n");
        break;
    case 2:
        system("cls");
        printf("adicionar uma nova tarefa\n");
        break;
    case 3:
        system("cls");
        printf("remover uma tarefa\n");
        break;
    case 4:
        system("cls");
        printf("editar uma tarefa\n");
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
