/*
O código apresenta uma lista duplamente ligada com operações básicas para inserir, deletar e imprimir.

1 - comente o código.
2 - Modifique a operação de inserção de dados, para que o usuário seja capaz de inserir valores para a lista.
3 - Faça uma operação de buscar por um valor específico, informado pelo usuário, onde o programa deve apresentar se o valor
    foi encontrado e, em caso afirmativo, exibir detalhes(vizinhos) do nó correspondente.
*/

#include <stdio.h>
#include <stdlib.h>

//Define o tipo abstrado de dados
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

//Insere um valor no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

//Remove um item da lista
void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}

//Buscar por um elemento da lista
void busca(int valor)
{
	Node* temp = head;

	if (head == NULL)
		printf("Lista vazia!\n");
	else
	{
		while (temp != NULL)
			if (valor == temp->data)
			{
				printf("O valor %d foi encontrado na lista!\n", valor);
				printf("Valor anterior: ");
				if (temp->prev == NULL)
					printf("NULO\n");
				else
					printf("%d\n", temp->prev->data);
				printf("Valor posterior: ");
				if (temp->next == NULL)
					printf("NULO\n");
				else
					printf("%d\n", temp->next->data);
				break;
			}

			else
				temp = temp->next;
	}

	if (temp == NULL)
		printf("O valor %d não está na lista\n", valor);
}

//Imprime a lista
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int valor = 0;

    //Usuário insere valores na lista
    while (valor != -1)
    {
       printf("Entre com um valor (-1 -> termina): ");
       scanf("%d", &valor);

       if (valor == -1)
          continue;

       insertFront(valor);
    }

    //Procura por um valor dentro da lista
    printf("Entre com um valor para buscar: ");
    scanf("%d", &valor);

    busca(valor);

    printList();
    return 0;
}
