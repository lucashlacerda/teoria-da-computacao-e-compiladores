#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Verificando o tamanho de vari�veis
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
//    //Entradas e sa�das padr�o
//
//    printf("Informe um n�mero");
//    //Para o scanf � necess�rio colocar o endere�o de mem�ria da vari�vel.
//    //%d referencia o tipo da vari�vel, nesse caso, Int.
//    scanf("%d", &x);
//    printf("Valor de x: %d \n\n\n", x);


    int num;
    char letra;

    printf ("\nInforme um numero: ");
    scanf ("%d", &num);
    printf("Valor de num: %d \n\n\n", num);
    scanf ("%c", &letra); //Aqui � utilizado a vari�vel lixo para armazenar a tecla enter clicada para seguir, sen�o ela iria pra vari�vel letra
    printf ("\nInforme uma letra: ");
    scanf ("%c", &letra);
    printf("Letra informada: %c \n\n\n", letra);


    return 0;
}
