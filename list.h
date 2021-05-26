/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

//estrutura do nodo
struct Node{
 Task *task;
 struct Node *prox;
}; 
//declarado o typedef para facilitar a declaração
typedef struct Node node;
//declarado o head da lista de aptos
node *head;
//declarado nodo para controle de log de executados
node *executados;
//tamanho da lista
int tam;
//método que inicial a lista apontando o head para null
void iniciaLista(node *LISTA);
//insere task no fim da lista
void insereFim(node *LISTA, Task *newTask );
//insere task no inicio da lista
void insereInicio(node *LISTA, Task *newTask);
//exibe a lista
void exibe(node *LISTA);
//libera a lista
void libera(node *LISTA);
//insere em alguma posição escolhida
void insere (node *LISTA, Task *newTask);
//retira do inicio
node *retiraInicio(node *LISTA);
//retira do fim
node *retiraFim(node *LISTA);
//retira task especifica
node *retira(node *LISTA, Task *newTask );
//retorna a menor prioridade da lista
int menorPrioridade(node *LISTA);
