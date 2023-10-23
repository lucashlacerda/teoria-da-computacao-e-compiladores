#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Veiculo
struct Veiculo {
    int numeroChassi;
    char marca[50];
    char modelo[50];
    float preco;
};

// Função para alocar memória para o vetor de Veiculos
struct Veiculo *alocarMemoria(int tamanho) {
    struct Veiculo *array = (struct Veiculo *)malloc(tamanho * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o vetor de Veiculos com valores inseridos pelo usuário
void preencherVeiculos(struct Veiculo *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite os dados do veiculo %d:\n", i + 1);
        printf("Numero do Chassi: ");
        scanf("%d", &array[i].numeroChassi);

        printf("Marca: ");
        scanf("%s", array[i].marca);

        printf("Modelo: ");
        scanf("%s", array[i].modelo);

        printf("Preco: ");
        scanf("%f", &array[i].preco);

        printf("\n");
    }
}

// Função para imprimir o vetor de Veiculos
void imprimirVeiculos(struct Veiculo *array, int tamanho) {
    printf("Veiculos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Chassi: %d, Marca: %s, Modelo: %s, Preco: %.2f\n",
               array[i].numeroChassi, array[i].marca, array[i].modelo, array[i].preco);
    }
}

// Função para realocar memória para o vetor de Veiculos
struct Veiculo *realocarMemoria(struct Veiculo *array, int tamanhoAntigo, int novoTamanho) {
    array = (struct Veiculo *)realloc(array, novoTamanho * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    return array;
}

int main() {
    int tamanhoInicial, novoTamanho;

    // Pedir ao usuário o tamanho inicial do vetor de Veiculos
    printf("Digite o tamanho inicial do vetor de veiculos: ");
    scanf("%d", &tamanhoInicial);

    // Alocar memória para o vetor de Veiculos
    struct Veiculo *veiculos = alocarMemoria(tamanhoInicial);

    // Preencher o vetor de Veiculos com valores inseridos pelo usuário
    preencherVeiculos(veiculos, tamanhoInicial);

    // Imprimir o vetor de Veiculos antes da realocação
    imprimirVeiculos(veiculos, tamanhoInicial);

    // Pedir ao usuário o novo tamanho do vetor de Veiculos
    printf("Digite o novo tamanho do vetor de veiculos: ");
    scanf("%d", &novoTamanho);

    // Realocar memória para o vetor de Veiculos
    veiculos = realocarMemoria(veiculos, tamanhoInicial, novoTamanho);

    // Preencher os elementos adicionais do vetor de Veiculos com valores inseridos pelo usuário
    preencherVeiculos(veiculos + tamanhoInicial, novoTamanho - tamanhoInicial);

    // Imprimir o vetor de Veiculos após a realocação
    imprimirVeiculos(veiculos, novoTamanho);

    // Liberar a memória alocada
    free(veiculos);

    return 0;
}
