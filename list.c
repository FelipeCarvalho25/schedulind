/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"
#include "schedulers.h"

void iniciaLista(node *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}
// add a new task to the list of tasks
int vazia(node *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  //printf("Novo elemento: "); 
  return novo;
 }
}


void insereFim(node *LISTA, Task *newTask)
{
 node *novo=aloca();
 novo->prox = NULL;
 novo->task = newTask;
 
 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)
   tmp = tmp->prox;
  
  tmp->prox = novo;
 }
 tam++;
}

void insereInicio(node *LISTA, Task *newTask)
{
 node *novo=aloca(); 
 node *oldHead = LISTA->prox;
 
 LISTA->prox = novo;
 novo->prox = oldHead;
 novo->task = newTask;
 
 tam++;
}
// traverse the list
/*void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp->task != NULL) {
        printf("[%d] [%s] [%d] [%d]\n",temp->task->tid,temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;        
    }
}*/
void exibe(node *LISTA)
{
 //system("clear");
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp;
 tmp = LISTA->prox;

 printf("[%s] [%s] [%s] [%s]\n","id","nome", "prioridade", "burst");
 while( tmp != NULL){
  printf(" [%d]  [%s]      [%d]       [%d]\n",tmp->task->tid,tmp->task->name, tmp->task->priority, tmp->task->burst);
  tmp = tmp->prox;
 }

}

void libera(node *LISTA)
{
 if(!vazia(LISTA)){
  node *proxNode,
     *atual;
  
  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void insere(node *LISTA, Task *newTask)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA, newTask);
  else{
   node *atual = LISTA->prox,
     *anterior=LISTA; 
   node *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   novo->task = newTask;
   tam++;
  }
   
 }else
  printf("Elemento invalido\n\n");  
}

node *retiraInicio(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }
    
}

node *retiraFim(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox,
    *penultimo = LISTA;
    
  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }
    
  penultimo->prox = NULL;
  tam--;
  return ultimo;  
 }
}

node *retira(node *LISTA, Task *newTask  )
{
    node *atual = LISTA->prox,
    *anterior=LISTA; 
     
    if(atual->task->tid == newTask->tid){
        return retiraInicio(LISTA);        
    }else{
        while (atual->task->tid != newTask->tid) {
            anterior=atual;
            atual=atual->prox;
        }
        anterior->prox=atual->prox;
        tam--;
    } 
    
    return atual;
   
}
int menorPrioridade(node *LISTA){
    int menor = MAX_PRIORITY;
    node *atual = LISTA;
    while(atual  != NULL){
        if(atual->task->priority < menor && atual->task->burst > 0){
            menor = atual->task->priority;
        }
        atual = atual->prox;
    }
    return menor;
}


