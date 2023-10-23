#include <stdio.h>
int main()
{
    float ceusius, fahr;

    printf("Digite a temperatura em Celsius: \n");
    scanf("%f", &ceusius);

    fahr = (ceusius * 1.8) + 32;

    printf("A tempartura em Fahrenheit é: %.2f°F \n",ceusius, fahr);

    return 0;
}
