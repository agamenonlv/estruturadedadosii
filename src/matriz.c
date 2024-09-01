/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
//    int matriz[3][3];
    int i, j, soma = 0, dim;
    int *matriz;

    //Entra com o tamanho da matriz
    printf("Entre com a quantidade de linhas(colunas) da matriz quadrada: ");
    scanf("%d", &dim);

    //Aloca memória para a matriz (em forma de vetor)
    matriz = malloc(dim*dim*sizeof(int));

    printf("Insira os elementos da matriz 3x3:\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%d", &matriz[(i*dim) + j]);
            if (i == j) {
                soma += matriz[(i*dim) + j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
