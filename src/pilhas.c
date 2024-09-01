/*
O código abaixo apresenta a implementação de uma pilha e suas operações básicas.

1 - comente o código
2 - implemente uma função para verificar se a pilha está vazia.
3 - proponha uma função que possa fazer expansão dinâmica quando a capacidade máxima é atingida, em vez
    de simplesmente negar novas inserções na pilha.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Tamanho inicial da pilha
#define MAX_SIZE 3

//Define e inicializa as variáveis globais

int* pilha;
int topo = -1;

//Função que cria uma pilha vazia
void new()
{
	pilha = malloc(MAX_SIZE*sizeof(int));
}

//Função que expande a pilha
void expand()
{
	pilha = realloc(pilha,sizeof(pilha) + 1);
}

//Função que coloca um valor no topo da pilha
void push(int elemento) {
    if (topo >= MAX_SIZE - 1) {
    	pilha = realloc(pilha,sizeof(pilha) + 1);
    }
	pilha[++topo] = elemento;
}

//Função que remove um elemento topo da fila e retorna esse valor
int pop() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];
    }
}

//Função que retorna o valor do elemento do topo da fila, sem o remover
int top() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];
    }
}

//Função que mostra o conteúdo da fila
void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

bool isempty()
{
	if (topo == -1)
		return true;
	else
		return false;
}

int main() {
	new();
	if (isempty())
		printf("A lista está vazia\n");
    push(10);
    push(20);
    push(30);
    imprimir();
    push(40);
    imprimir();
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    imprimir();
    if (!isempty())
    	printf("A lista não está vazia\n");
    return 0;
}
