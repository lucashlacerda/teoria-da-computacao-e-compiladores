/*3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
Imprima este valor em reais.*/
#include <stdio.h>
int main()
{
    float cotacao, quantidade, valor;

    printf("Qual a cotação do dolar atual em reais? \n");
    scanf("%f", &cotacao);

    printf("Quantos dolares você possui? \n");
    scanf("%f", &quantidade);

    valor = quantidade * cotacao;

     printf("De acordo com o valor atual do Dolar você tem R$%.2f.\n", valor);

    return 0;
}
