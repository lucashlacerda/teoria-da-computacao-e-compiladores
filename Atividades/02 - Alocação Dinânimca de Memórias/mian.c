/*Altere o programa para que os trechos de código para alocação de memória, preenchimento
do vetor e impressão do vetor seja realizado por funções.*/

#include <stdio.h>
#include <stdlib.h>

void *alocarMemoria(int n)
{
    int *array = (int *)malloc(n * sizeof(int));

    if (array == NULL)
    {
        printf("Falha na alocação de memória.\n");
        return 1;
    }
}

void preencheArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = i * 10;
    }
}

void imprimiArray(int *array, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    // Alocação dinâmica de memória usando malloc
    array = alocarMemoria(n);

    // Preencher o array
    preencheArray(array, n);

    // Imprimir o array
    imprimiArray(array, n);

    // Liberar a memória alocada com malloc
    free(array);

    return 0;
}