#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int MarketingPage(){
    //setlocale permite usar acentos para isso precisa inportar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------Página de Marketing--------------\n");
    printf("1 - Ver todas as informações de marketing da empresa\n");
    printf("2 - adicionar nova informação\n");
    printf("3 - remover uma informação\n");
    printf("4 - editar uma informação\n");
    printf("0 - Voltar para o menu\n");
    printf("-----------------------------------------------\n");


    printf("Digite o número da Função desejada:");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        printf("Ver todas as informações de marketing da empresa\n");
        break;
    case 2:
        system("cls");
        printf("adicionar nova informação\n");
        break;
    case 3:
        system("cls");
        printf("remover uma informação\n");
        break;
    case 4:
        system("cls");
        printf("editar uma informação\n");
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
