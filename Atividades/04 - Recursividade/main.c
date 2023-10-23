#include <stdio.h>

//Calculando potencia de forma recursiva
int potencia(int base, int expoente){
    if (expoente == 0){
        return 1;
    }else{
       return base * potencia(base, expoente - 1 );
    }
}

int main(int argc, char const *argv[])
{

    int base, expoente;

    printf("Vamos calcular a potencia de um numero!\n\n");
    printf("Digite a BASE da operacao: \n");
    scanf("%d", &base);

    printf("Digite o EXPOENTE da operacao: \n");
    scanf("%d", &expoente);

    int resultado = potencia(5, 2);

    printf("O resutado da operacao de %d elevado a %d e igual a: %d \n", base, expoente, resultado);

    return 0;
}

