#include <stdio.h>

//Somando uma sequencia de número de forma recursiva
int somaSequencia (int numero){
    if (numero == 1){
     return 1;
    }else {
        return numero + somaSequencia(numero - 1);
    }
}
int main()
{
    int numero;

    printf("Somando numeros da sequencia ate zero: \n\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);

    int resultado = somaSequencia(numero);

    printf("Se somarmos o numero %d com seus antecesores ate 1 o resultado sera: %d \n", numero, resultado);
    return 0;
}

