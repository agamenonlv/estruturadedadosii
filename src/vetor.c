/*
O código abaixo realiza a impressão do vetor na ordem inversa.
1 - comente o código
2 - faça uma modificação para que seja possível inserir um vetor de n elementos.
*/

#include <stdio.h>
#define TAMVET 5

int main() {
    //Declaração e inicialização das variáveis
    int i, temp, tamvetor;
    int vetor[TAMVET];

    for (i = 0; i < TAMVET; i++)
       vetor[i] = i;

    //Inverte o vetor
    tamvetor = TAMVET / 2;
    for (i = 0; i < tamvetor; i++) {
        temp = vetor[i];
        vetor[i] = vetor[TAMVET - 1 - i];
        vetor[TAMVET - 1 - i] = temp;
    }

    //Imprime o vetor em ordem inversa
    printf("Vetor invertido:\n");
    for (i = 0; i < TAMVET; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
