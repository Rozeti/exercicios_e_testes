#include<stdio.h>

main(){

    int produto, quantidade, simNao = 1;
    float valorPedido, valorConta;

    while (simNao == 1)
    {
        printf("\n---------------> Menu <---------------\n");

        printf("\n100 - Cachorro quente ------> R$ 10,10 ");
        printf("\n101 - Bauru simples --------> R$ 8,30 ");
        printf("\n102 - Bauru c/ ovo ---------> R$ 8,50 ");
        printf("\n103 - Hamburger ------------> R$ 12,50 ");
        printf("\n104 - Cheeseburger ---------> R$ 13,25 \n");
        printf("<-------------------------------------->\n");

        printf("O que vai querer: ");
        scanf("%d", &produto);

        while (produto < 100 || produto > 104){
            printf("\n# Produto nao encontrado! Por favor digite o numero do pedido de acordo com o menu: ");
            scanf("%d", &produto);
        }

        printf("\nQual a quantidade que voce vai querer: ");
        scanf("%d", &quantidade);

        printf("\nDeseja continuar escolhendo (1 - para sim ou 0 - para nao): ");
        scanf("%d", &simNao);

        while (simNao != 1 && simNao != 0){
            printf("\n# Erro. Por favor selecione 1 - para continuar ou 0 - para encerrar o pedido: ");
            scanf("%d", &simNao);
        }

        switch (produto){
        case 100:
            valorPedido = 10.10 * quantidade;
            break;
        case 101:
            valorPedido = 8.30 * quantidade;
            break;
        case 102:
            valorPedido = 8.50 * quantidade;
            break;
        case 103:
            valorPedido = 12.50 * quantidade;
            break;
        case 104:
            valorPedido = 13.25 * quantidade;
            break;  
        }
        valorConta += valorPedido; 
    }  
    printf("\n<--------------Conta------------------>\n");
    printf("\n-> O total a pagar eh de: R$ %.2f", valorConta);
}