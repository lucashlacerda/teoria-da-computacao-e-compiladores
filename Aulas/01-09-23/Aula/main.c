#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Verificando o tamanho de variáveis
//    int x;
//
//    printf("\nTamanhos: ");
//    printf("\nx: %d bytes", sizeof(x));
//    printf("\n\nshort int: %d bytes", sizeof(short int));
//    printf("\n\nint: %d bytes", sizeof(int));
//    printf("\n\nlong int: %d bytes", sizeof(long int));
//    printf("\n\nfloat: %d bytes", sizeof(float));
//    printf("\n\ndouble: %d bytes\n\n", sizeof(double));
//
//
//    //Entradas e saídas padrão
//
//    printf("Informe um número");
//    //Para o scanf é necessário colocar o endereço de memória da variável.
//    //%d referencia o tipo da variável, nesse caso, Int.
//    scanf("%d", &x);
//    printf("Valor de x: %d \n\n\n", x);


    int num;
    char letra;

    printf ("\nInforme um numero: ");
    scanf ("%d", &num);
    printf("Valor de num: %d \n\n\n", num);
    scanf ("%c", &letra); //Aqui é utilizado a variável lixo para armazenar a tecla enter clicada para seguir, senão ela iria pra variável letra
    printf ("\nInforme uma letra: ");
    scanf ("%c", &letra);
    printf("Letra informada: %c \n\n\n", letra);


    return 0;
}
