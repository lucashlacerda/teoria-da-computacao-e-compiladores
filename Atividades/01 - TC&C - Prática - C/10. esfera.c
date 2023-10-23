
#include <stdio.h>
#include <math.h>

int main()
{
    float raio, comprimento, area, volume;

    printf("Digite o valor do Raio: \n");
    scanf("%f", &raio);

    //O comprimento de uma esfera:
    comprimento = 2 * 3.14 * raio;
    printf("O comprimento de uma esfera que tem o raio com esse valor é igual a: %.2f \n\n", comprimento);

    //A área de uma esfera:
    area =  3.14 * pow(raio, 2);
    printf("A area de uma esfera que tem o raio com esse valor é igual a: %.2f \n\n", area);

    //O volume de uma esfera:
    volume = (4* 3.14 * pow(raio, 3)) / 3;
    printf("O volume de uma esfera que tem o raio com esse valor é igual a: %.2f \n\n", volume);


    return 0;
}
