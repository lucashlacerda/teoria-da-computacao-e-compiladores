#include <stdio.h>
#include <stdlib.h>

// Função para ler um arquivo e armazenar os dados em um vetor
void lerArquivoExibirVetor(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para leitura.\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    int tamanho;
    fscanf(arquivo, "%d", &tamanho);

    // Alocar memória para o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Ler a sequência do arquivo
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &vetor[i]);
    }

    fclose(arquivo);

    // Exibir o vetor na tela
    printf("Vetor lido do arquivo %s:\n", nomeArquivo);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberar a memória alocada para o vetor
    free(vetor);
}

int main() {
    const char *nomeArquivo = "sequencia1.txt"; // Nome do arquivo

    // Chamar a função para ler o arquivo e exibir o vetor
    lerArquivoExibirVetor(nomeArquivo);

    return 0;
}
