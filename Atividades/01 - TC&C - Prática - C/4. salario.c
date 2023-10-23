#include <stdio.h>
int main()
{
    float salarioAtual, novoSalario = 0.0;

    printf("Qual seu salário atual? \n");
    scanf("%f", &salarioAtual);

    novoSalario = salarioAtual + (salarioAtual * 0,25);

     printf("Você recebeu um aumento de 25%. Seu novo salário é: R$%.2f \n", novoSalario);

    return 0;
}
