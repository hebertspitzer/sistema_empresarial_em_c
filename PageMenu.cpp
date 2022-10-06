#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "CustumersPage.h"
#include "MarketingPage.h"
#include "FinancierPage.h"
#include "TaskPage.h"

int main(){
    //setlocale permite usar acentos para isso precisa inportar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------------Páginas--------------------\n");
    printf("\t\t1 - Clientes\n");
    printf("\t\t2 - Marketing\n");
    printf("\t\t3 - Financeiro\n");
    printf("\t\t4 - Tarefas\n");
    printf("\t\t5 - Possíveis clientes\n");
    printf("\t\t0 - Voltar para login\n");
    printf("-----------------------------------------------\n");

    printf("Digite o número da página desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        CustomersPage();
        break;
    case 2:
        system("cls");
        MarketingPage();
        break;
    case 3:
        system("cls");
        FinancierPage();
        break;
    case 4:
        system("cls");
        TaskPage();
        break;
    case 5:
        system("cls");
        printf("\t\tPágina de Possíveis clientes selecionada\n");
        break;
    default:
        system("cls");
        break;
    }
    if(select < 0 || select > 5){
        printf("\t\tO número da página não e válido\n");
    }

}while (select != 0);

}
