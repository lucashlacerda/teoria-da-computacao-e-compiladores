/AREA = (DIAGONAL MAIOR * DIAGONAL
MENOR) / 2.*/

#include <stdio.h>
int main()
{
    float diagMaior, diagMenor, area;

    printf("Digite o tamanho da Diagonal Maior: \n");
    scanf("%f", &diagMaior);

    printf("Digite o tamanho da Diagonal Menor: \n");
    scanf("%f", &diagMenor);

    area = (diagMaior * diagMenor) / 2;

     printf("A area total deste losango é: %.2f \n", area);

    return 0;
}
