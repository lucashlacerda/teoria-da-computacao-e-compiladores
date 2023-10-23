#include <stdio.h>
int main()
{
    float peso, novoPeso = 0.0;

    printf("Qual o seu peso atual? \n");
    scanf("%f", &peso);

    novoPeso = peso + (peso * 0.15);
    printf("Se você engorda 15%% seu novo peso sera de: %.2f \n", novoPeso);

    novoPeso = peso + (peso * 20 / 100);
    printf("Se você engorda 20%% seu novo peso sera de: %.2f \n", novoPeso);

    return 0;
}
