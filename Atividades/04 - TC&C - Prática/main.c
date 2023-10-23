#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função recursiva para determinar o tamanho da string
int tamanhoStringRecursivo(const char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + tamanhoStringRecursivo(str + 1);
    }
}

// Função recursiva para inverter a string
void inverterStringRecursivo(char *str, int inicio, int fim) {
    if (inicio < fim) {
        // Trocar os caracteres nas posições inicio e fim
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        // Chamar a função recursivamente para os caracteres restantes
        inverterStringRecursivo(str, inicio + 1, fim - 1);
    }
}

int main() {
    FILE *arquivo;
    char nomeArquivo[50];

    // Pedir ao usuário o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Abrir o arquivo para leitura e escrita
    arquivo = fopen(nomeArquivo, "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler a string do arquivo
    char linha[1000];
    fgets(linha, sizeof(linha), arquivo);

    // Determinar o tamanho da string recursivamente
    int tamanho = tamanhoStringRecursivo(linha);

    // Armazenar o tamanho da string no arquivo
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "Tamanho: %d\n", tamanho);

    // Determinar o reverso da string recursivamente
    inverterStringRecursivo(linha, 0, tamanho - 1);

    // Armazenar o reverso da string no arquivo
    fprintf(arquivo, "Reverso: %s", linha);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Operaçoes concluidas com sucesso.\n");

    return 0;
}
 