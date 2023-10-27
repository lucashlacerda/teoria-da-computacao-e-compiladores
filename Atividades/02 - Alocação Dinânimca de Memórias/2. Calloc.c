#include <stdio.h>
#include <stdlib.h>
#define TAM 255
// Definindo a estrutura Pessoa
struct Pessoa
{
    char CPF[12];
    char nome[50];
    float salario;
};


// Função para alocar memória para um vetor de estruturas Pessoa
struct Pessoa *alocarMemoria(int tamanho)
{
    struct Pessoa *vetor = (struct Pessoa *)calloc(tamanho, sizeof(struct Pessoa));
    if (vetor == NULL)
    {
        printf("Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    return vetor;
}

// Função para preencher um vetor de estruturas Pessoa
void preencherVetor(struct Pessoa *vetor, int tamanho)
{
    char lixo;
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o CPF da Pessoa %d: \n", i + 1);
        scanf("%s", vetor[i].CPF);

        printf("Digite o nome da Pessoa %d: \n", i + 1);
        scanf("%s[^\n]", vetor[i].nome);
        printf("Digite o salário da Pessoa %d: \n", i + 1);
        scanf("%f", &vetor[i].salario);
    }
}

// Função para imprimir os elementos de um vetor de estruturas Pessoa
void imprimirVetor(struct Pessoa *vetor, int tamanho)
{
    printf("Vetor de Pessoas:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Pessoa %d:\n", i + 1);
        printf("CPF: %s\n", vetor[i].CPF);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Salário: %.2f\n", vetor[i].salario);
        printf("\n");
    }
}

int main()
{
    struct Pessoa *array;
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Chamar a função para alocar memória
    array = alocarMemoria(n);

    // Chamar a função para preencher o vetor
    preencherVetor(array, n);

    // Chamar a função para imprimir o vetor
    imprimirVetor(array, n);

    // Liberar a memória alocada com calloc
    free(array);

    return 0;
}
