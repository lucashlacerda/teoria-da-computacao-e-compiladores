#include <stdio.h>
#include <math.h>

int main()
{
    float catetoOposto, catetoAdjacente, hipotenusa = 0.0;

    printf("Calculando a Hipotenusa! \n");

    printf("Qual o valor do Cateto Oposto? \n");
    scanf("%f", &catetoOposto);

    printf("Qual o valor do Cateto Adjacente? \n");
    scanf("%f", &catetoAdjacente);

    hipotenusa = sqrt(pow(catetoOposto, 2) + pow(catetoAdjacente, 2));

    printf("De acordo com os dados passados o valor da Hipotenusa é igual a: %.2f \n", hipotenusa);

    return 0;
}
