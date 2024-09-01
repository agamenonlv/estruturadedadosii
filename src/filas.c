/*
O código abaixo apresenta a implementação de uma fila e suas operações básicas.

1 - comente o código
2 - implemente uma função para contar o número de elementos na fila.
3 - implemente uma função para limpar todos os elementos da fila, liberando memória apropriadamente.
*/

#include <stdio.h>
#include <stdlib.h>

//Define os tipos abstrados de dados
typedef struct Node {	// Um elemento da fila
    int data;
    struct Node* next;
} Node;

typedef struct Queue {	// A fila
    Node* front;
    Node* rear;
} Queue;

//Cria uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

//Coloca um elemento na fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Remove um elemento da fila
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

//Verifica se a fila é vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

//Mostra os elemento da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Conta quantos elementos tem na fila
void countQueue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    int count = 0;
    printf("Quantidade de elementos da fila: ");
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
}

void freeQueue(Queue* q)
{
	if (isEmpty(q))
	{
		printf("A fila está vazia.\n");
		return;
	}
	Node* temp = q->front;
	while (temp != NULL)
	{
		dequeue(q);
		temp = q->front;
	}
	free(q);
}

int main() {
    Queue* q = createQueue();
    countQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    countQueue(q);

    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    countQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    countQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    countQueue(q);
    freeQueue(q);
    printQueue(q);
    countQueue(q);

    return 0;
}
