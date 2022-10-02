#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int select;

do{
    printf("1 - Fazer login\n");
    printf("2 - Criar uma conta\n");
    printf("3 - Recuperar senha\n");
    printf("0 - Finalizar o sistema\n");

    printf("Digite o numero da opcao desejada:");
    scanf("%d",&select);
    switch (select)
    {
    case 1:
        printf("Pagina de login selecionada\n");
        break;
    case 2:
        printf("Pagina de criar uma conta selecionada\n");
        break;
    case 3:
        printf("Pagina de recuperar selecionada\n");
        break;
    default:
        break;
    }
    if(select < 0 || select > 3){
        printf("O numero da opcao nao e valido\n");
    }

}while (select != 0);

}