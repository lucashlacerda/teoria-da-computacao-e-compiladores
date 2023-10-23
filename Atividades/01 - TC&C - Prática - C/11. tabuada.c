
#include <stdio.h>

int main()
{
    int numero;
    printf("Digite um número e vamos calcular a sua tabuada: \n");
    scanf("%d", &numero);

    for (int i = 0; i <= 10; i++){
        printf("%d X %d = %d \n",numero, i, numero * i );
    }

    return 0;
}
