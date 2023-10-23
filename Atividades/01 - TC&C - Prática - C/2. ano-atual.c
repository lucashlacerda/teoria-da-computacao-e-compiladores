#include <stdio.h>
int main()
{
    int nasc, atual, idade;

    printf("Digite seu ano de nascimento: \n");
    scanf("%d", &nasc);

    printf("Digite o ano atual: \n");
    scanf("%d", &atual);

    idade = atual - nasc;

    printf("Voce tem %d anos.\n", idade);

    return 0;
}
