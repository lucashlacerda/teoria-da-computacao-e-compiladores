#include <stdio.h>
int main()
{
    float salMinimo, salario, quantidade;

    printf("Qual o valor atual do salário mínimo? \n");
    scanf("%f", &salMinimo);

    printf("Qual o valor atual do seu salário? \n");
    scanf("%f", &salario);

    quantidade =  salario / salMinimo;

    printf("O seu salario equivale a %.0f salarios míminos.",quantidade);

    return 0;
}
