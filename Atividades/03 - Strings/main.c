#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{

    char numero = '3';
    char letra = 'B';

    int func = isalpha(letra);
    int fun = isdigit(numero);


    // verificando se é uma letra ou não
    if (func == 1)
    {
        printf("E uma letra MAIUSCULA \n");
    }
    else if (func == 2)
    {
        printf("E uma letra MINUSCULA \n");
    }
    else
    {
        printf("ERRO DESCONHECIDO");
    }

    // verificando se é um número ou não
    if (fun == 1)
    {
        printf("E UM DIGITO \n");
    }
    else if (fun == 0)
    {
        printf("NAO E UM DIGITO \n");
    }
    else
    {
        printf("ERRO DESCONHECIDO");
    }

    // verificando se um caracter é maiusculo ou minusculo
    if (isupper(letra) == 0)
    {
        printf("NAO E MAIUSUCULO\n");
    }else
    {
        printf("E MAISUCULO \n");
    }


    //VERIFICANDO SE A LETRA E MINUSCULA
    if (islower(letra) == 0)
    {
        printf("NAO E MINUSCULO\n");
    }
    else 
    {
        printf("E MINUSCULO \n");
    }


    //VERIFICA SE É UM LETRA
    if (isalnum(letra) == 0)
    {
        printf("NAO E UMA LETRA\n");
    }else 
        printf("E UMA LETRA OU NUMERO\n");
    
    // getchar();

    return 0;
}