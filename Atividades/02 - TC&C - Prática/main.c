#include <stdio.h>

void lerSequencia(int sequencia[], int tamanho) {
    printf("Digite os numeros: \n");

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
    }
}

void apresentarSequencia(int sequencia[], int tamanho) {
    printf("Sequencia: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

void armazenarSequencias (int sequencia[], int tamanho, const char *nomeArquivo, int nSequencia, const char *tipo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (tipo == "sequencia"){
        fprintf(arquivo, "Sequencia %d:\n", nSequencia);
    }else if (tipo == "conjunto"){
        if (nSequencia == 1){
            fprintf(arquivo, "Conjunto A:\n", nSequencia);
        }else if (nSequencia == 2){
            fprintf(arquivo, "Conjunto B:\n", nSequencia);
        }
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", sequencia[i]);
    }

    fclose(arquivo);
}

void lerArquivo(const char *nomeArquivo, int vetor1[], int *tamanho1, int vetor2[], int *tamanho2) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int sequenciaAtual = 0;
    int numero;
    while (fscanf(arquivo, "Sequencia %d:", &sequenciaAtual) == 1) {
        int *vetorAtual;
        int *tamanhoAtual;
        if (sequenciaAtual == 1) {
            vetorAtual = vetor1;
            tamanhoAtual = tamanho1;
        } else if (sequenciaAtual == 2) {
            vetorAtual = vetor2;
            tamanhoAtual = tamanho2;
        } else {
            printf("Sequ�ncia inv�lida no arquivo.\n");
            return;
        }

        // Ler os n�meros da sequ�ncia
        *tamanhoAtual = 0;
        while (fscanf(arquivo, "%d", &numero) == 1) {
            vetorAtual[(*tamanhoAtual)++] = numero;
        }
    }

    fclose(arquivo);
}

void gerarConjuntosAB(int sequencia1[], int tamanho1, int sequencia2[], int tamanho2, int conjuntoA[], int *tamanhoA, int conjuntoB[], int *tamanhoB) {

    *tamanhoA = 0;
    *tamanhoB = 0;

    // Conjunto A
    for (int i = 0; i < tamanho1; i++) {
        int elemento = sequencia1[i];
        int elementoRepetido = 0;
        for (int j = 0; j < *tamanhoA; j++) {
            if (conjuntoA[j] == elemento) {
                elementoRepetido = 1;
                break;
            }
        }
        if (!elementoRepetido) {
            conjuntoA[(*tamanhoA)++] = elemento;
        }
    }

    // Conjunto B
    for (int i = 0; i < tamanho2; i++) {
        int elemento = sequencia2[i];
        int elementoRepetido = 0;
        for (int j = 0; j < *tamanhoB; j++) {
            if (conjuntoB[j] == elemento) {
                elementoRepetido = 1;
                break;
            }
        }
        if (!elementoRepetido) {
            conjuntoB[(*tamanhoB)++] = elemento;
        }
    }
}

void conjuntoPotencia(int conjunto[], int tamanho, const char *nomeArquivo, const char *nConjunto) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (nConjunto == "A"){
        fprintf(arquivo, "Conjunto Potencia A:\n");
        printf("Conjunto Potencia A:\n");
    }else if (nConjunto == "B"){
        fprintf(arquivo, "Conjunto Potencia B:\n");
        printf("Conjunto Potencia B:\n");
    }

    int tamanhoPotencia = (int)pow(2, tamanho);
    for (int i = 0; i < tamanhoPotencia; i++) {
        fprintf(arquivo, "{ ");
        printf("{ ");
        int conjuntoVazio = 1;
        for (int j = 0; j < tamanho; j++) {
            if (i & (1 << j)) {
                if (!conjuntoVazio) {
                    fprintf(arquivo, ", ");
                    printf(", ");
                }
                fprintf(arquivo, "%d", conjunto[j]);
                printf("%d", conjunto[j]);
                conjuntoVazio = 0;
            }
        }
        fprintf(arquivo, " }\n");
        printf(" }\n");
    }

    fclose(arquivo);
}

void conjuntoProprio(const char *nomeArquivo, int conjunto[], int tamanho, const char *nConjunto) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (nConjunto == "A"){
        fprintf(arquivo, "Conjuntos Proprios A:\n");
        printf("Conjuntos Proprios A:\n");
    }else if (nConjunto == "B"){
        fprintf(arquivo, "Conjuntos Proprios B:\n");
        printf("Conjuntos Proprios B:\n");
    }

    // Determinar e apresentar na tela os conjuntos pr�prios
    int tamanhoPotencia = (int)pow(2, tamanho);
    for (int i = 1; i < tamanhoPotencia; i++) { // Come�a em 1 para evitar o conjunto original
        fprintf(arquivo, "{ ");
        printf("{ ");
        int conjuntoVazio = 1;
        for (int j = 0; j < tamanho; j++) {
            if (i & (1 << j)) {
                if (!conjuntoVazio) {
                    fprintf(arquivo, ", ");
                    printf(", ");
                }
                fprintf(arquivo, "%d", conjunto[j]);
                printf("%d", conjunto[j]);
                conjuntoVazio = 0;
            }
        }
        fprintf(arquivo, " }\n");
        printf(" }\n");
    }

    fclose(arquivo);
}

void uniao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int conjuntoUniao[200];
    int tamanhoUniao = 0;

    // Uni�o de A e B
    for (int i = 0; i < tamanhoA; i++) {
        conjuntoUniao[tamanhoUniao++] = conjuntoA[i];
    }

    for (int i = 0; i < tamanhoB; i++) {
        int elementoRepetido = 0;
        for (int j = 0; j < tamanhoA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                elementoRepetido = 1;
                break;
            }
        }

        if (!elementoRepetido) {
            conjuntoUniao[tamanhoUniao++] = conjuntoB[i];
        }
    }

    printf("Uniao de A e B: ");
    for (int i = 0; i < tamanhoUniao; i++) {
        printf("%d ", conjuntoUniao[i]);
    }
    printf("\n");

    fprintf(arquivo, "Uniao de A e B:\n");
    for (int i = 0; i < tamanhoUniao; i++) {
        fprintf(arquivo, "%d\n", conjuntoUniao[i]);
    }

    fclose(arquivo);
}

void intersecao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int conjuntoIntersecao[100];
    int tamanhoIntersecao = 0;

    // Interse��o de A e B
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                conjuntoIntersecao[tamanhoIntersecao++] = conjuntoA[i];
                break;
            }
        }
    }


    printf("Intersecao de A e B: ");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        printf("%d ", conjuntoIntersecao[i]);
    }
    printf("\n");

    fprintf(arquivo, "Intersecao de A e B:\n");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        fprintf(arquivo, "%d\n", conjuntoIntersecao[i]);
    }

    fclose(arquivo);
}

void diferencaAB(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int conjuntoDiferenca[100];
    int tamanhoDiferenca = 0;

    // Diferen�a entre A e B
    for (int i = 0; i < tamanhoA; i++) {
        int elementoNaoPertence = 1;
        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                elementoNaoPertence = 0;
                break;
            }
        }
        if (elementoNaoPertence) {
            conjuntoDiferenca[tamanhoDiferenca++] = conjuntoA[i];
        }
    }

    printf("Diferenca de A e B (A - B): ");
    for (int i = 0; i < tamanhoDiferenca; i++) {
        printf("%d ", conjuntoDiferenca[i]);
    }
    printf("\n");

    fprintf(arquivo, "Diferenca de A e B (A - B):\n");
    for (int i = 0; i < tamanhoDiferenca; i++) {
        fprintf(arquivo, "%d\n", conjuntoDiferenca[i]);
    }

    fclose(arquivo);
}

void diferencaBA(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int conjuntoDiferenca[100];
    int tamanhoDiferenca = 0;

    // Diferen�a entre B e A
    for (int i = 0; i < tamanhoB; i++) {
        int elementoNaoPertence = 1;
        for (int j = 0; j < tamanhoA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                elementoNaoPertence = 0;
                break;
            }
        }
        if (elementoNaoPertence) {
            conjuntoDiferenca[tamanhoDiferenca++] = conjuntoB[i];
        }
    }

    printf("Diferenca de B e A (B - A): ");
    for (int i = 0; i < tamanhoDiferenca; i++) {
        printf("%d ", conjuntoDiferenca[i]);
    }
    printf("\n");

    fprintf(arquivo, "Diferenca de B e A (B - A):\n");
    for (int i = 0; i < tamanhoDiferenca; i++) {
        fprintf(arquivo, "%d\n", conjuntoDiferenca[i]);
    }

    fclose(arquivo);
}

void produtoCartesianoAB(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Produto Cartesiano de A e B:\n");
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            fprintf(arquivo, "(%d, %d)\n", conjuntoA[i], conjuntoB[j]);
        }
    }

    printf("Produto Cartesiano de A e B:\n");
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            printf("(%d, %d) ", conjuntoA[i], conjuntoB[j]);
        }
        printf("\n");
    }

    fclose(arquivo);
}

void produtoCartesianoBA(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Produto Cartesiano de B e A:\n");
    for (int i = 0; i < tamanhoB; i++) {
        for (int j = 0; j < tamanhoA; j++) {
            fprintf(arquivo, "(%d, %d)\n", conjuntoB[i], conjuntoA[j]);
        }
    }

    printf("Produto Cartesiano de B e A:\n");
    for (int i = 0; i < tamanhoB; i++) {
        for (int j = 0; j < tamanhoA; j++) {
            printf("(%d, %d) ", conjuntoB[i], conjuntoA[j]);
        }
        printf("\n");
    }

    fclose(arquivo);
}

void linha(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    fprintf(arquivo, "------------------------------------------\n");
    fclose(arquivo);
}

int main() {

    char nomeArquivo[12] = "arquivo.txt";

    // Limpar Arquivo
    FILE *arquivo = fopen(nomeArquivo, "w");

    int tamanho1, tamanho2;

    // a)

    printf("Tamanho da primeira sequencia: ");
    scanf("%d", &tamanho1);
    int sequencia1[tamanho1];
    lerSequencia(sequencia1, tamanho1);
    apresentarSequencia(sequencia1, tamanho1);
    armazenarSequencias(sequencia1, tamanho1, nomeArquivo, 1, "sequencia");

    printf("------------------------------------------\n");

    printf("Tamanho da segunda sequencia: ");
    scanf("%d", &tamanho2);
    int sequencia2[tamanho2];
    lerSequencia(sequencia2, tamanho2);
    apresentarSequencia(sequencia2, tamanho2);
    armazenarSequencias(sequencia2, tamanho2, nomeArquivo, 2, "sequencia");

    printf("------------------------------------------\n");

    // b)

    lerArquivo(nomeArquivo, sequencia1, &tamanho1, sequencia2, &tamanho2);

    printf("Sequencia 1 do arquivo: ");
    apresentarSequencia(sequencia1, tamanho1);
    printf("Sequencia 2 do arquivo: ");
    apresentarSequencia(sequencia2, tamanho2);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // c)

    int conjuntoA[100];
    int tamanhoA;
    int conjuntoB[100];
    int tamanhoB;

    gerarConjuntosAB(sequencia1, tamanho1, sequencia2, tamanho2, conjuntoA, &tamanhoA, conjuntoB, &tamanhoB);

    printf("Conjunto A: ");
    apresentarSequencia(conjuntoA, tamanhoA);
    printf("Conjunto B: ");
    apresentarSequencia(conjuntoB, tamanhoB);

    armazenarSequencias(conjuntoA, tamanhoA, nomeArquivo, 1, "conjunto");
    armazenarSequencias(conjuntoB, tamanhoB, nomeArquivo, 2, "conjunto");

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // d)

    conjuntoPotencia(conjuntoA, tamanhoA, nomeArquivo, "A");
    conjuntoPotencia(conjuntoB, tamanhoB, nomeArquivo, "B");

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // e)

    conjuntoProprio(nomeArquivo, conjuntoA, tamanhoA, "A");
    conjuntoProprio(nomeArquivo, conjuntoB, tamanhoB, "B");

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // f)

    uniao(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // g)

    intersecao(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // h)

    diferencaAB(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // i)

    diferencaBA(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // j)

    produtoCartesianoAB(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    // k)

    produtoCartesianoBA(conjuntoA, tamanhoA, conjuntoB, tamanhoB, nomeArquivo);

    linha(nomeArquivo);
    printf("------------------------------------------\n");

    return 0;
}
