#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int select;

do{
    printf("-----------------Paginas-----------------\n");
    printf("1 - Clientes\n");
    printf("2 - Marketing\n");
    printf("3 - Financeiro\n");
    printf("4 - Tarefas\n");
    printf("5 - Possiveis clientes\n");
    printf("0 - Finalizar o sistema\n");

    printf("Digite o numero da pagina desejada:");
    scanf("%d",&select);
    switch (select)
    {
    case 1:
        printf("Pagina de Clientes selecionada\n");
        break;
    case 2:
        printf("Pagina de Marketing selecionada\n");
        break;
    case 3:
        printf("Pagina de Financeiro selecionada\n");
        break;
    case 4:
        printf("Pagina de Tarefas selecionada\n");
        break;
    case 5:
        printf("Pagina de Possiveis clientes selecionada\n");
        break;
    default:
        break;
    }
    if(select < 0 || select > 5){
        printf("O numero da pagina nao e valido\n");
    }

}while (select != 0);

}