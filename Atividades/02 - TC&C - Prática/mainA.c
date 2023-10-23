/*a) Um(a) procedimento/função que leia duas sequências finitas de números naturais (N)
a partir do teclado, apresente-as na tela e, depois, armazene-as em um arquivo no
formato texto.*/

#include <stdio.h>

// Função para ler uma sequência de números naturais a partir do teclado
void lerSequencia(int sequencia[], int tamanho) {
    printf("Digite a sequencia de numeros naturais:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &sequencia[i]);
    }
}

// Função para exibir uma sequência de números na tela
void exibirSequencia(int sequencia[], int tamanho) {
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

// Função para armazenar uma sequência em um arquivo de texto
void armazenarEmArquivo(int sequencia[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", sequencia[i]);
    }
    
    fclose(arquivo);
    printf("Sequencia armazenada no arquivo '%s'.\n", nomeArquivo);
}

int main() {
    int tamanhoSequencia;  // Defina o tamanho desejado para as sequências
    printf("Digite o tamanho da sequencia numerica: \n");
    scanf("%d", &tamanhoSequencia);

    int sequencia1[tamanhoSequencia];
    int sequencia2[tamanhoSequencia];
    
    // Ler e exibir a primeira sequência
    lerSequencia(sequencia1, tamanhoSequencia);
    exibirSequencia(sequencia1, tamanhoSequencia);

    // Ler e exibir a segunda sequência
    lerSequencia(sequencia2, tamanhoSequencia);
    exibirSequencia(sequencia2, tamanhoSequencia);

    // Armazenar as sequências em arquivos
    armazenarEmArquivo(sequencia1, tamanhoSequencia, "sequencia1.txt");
    armazenarEmArquivo(sequencia2, tamanhoSequencia, "sequencia1.txt");

    return 0;
}
