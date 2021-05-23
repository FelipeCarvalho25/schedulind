/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}
void insereFim(struct node *head, Task *newTask)
{
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->task = newTask;

    if(head == NULL){
        head->next = newNode;
    }
    else{
       struct  node *tmp = head->next;
    
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
        tmp->next = newNode;
    }

}
// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}
int menorPrioridade(struct node *head){
    struct node *temp;
    temp = head;
    int menor = 50;
    while (temp->task != NULL) {
        if(temp->task->priority < menor){
            menor = temp->task->priority ;
        }
        temp = temp->next;        
    }
    return menor;
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp->task != NULL) {
        printf("[%d] [%s] [%d] [%d]\n",temp->task->tid,temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;        
    }
}
