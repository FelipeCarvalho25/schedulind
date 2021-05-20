#include "schedulers.h"
#include "list.h"
#include "task.h"
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>



// representation of a task

void add(char *name, int priority, int burst, int id){
   
    struct task *newTask;
    newTask = (struct task*) malloc(sizeof( struct task));
    newTask->tid = id;
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    
    insert(&head, newTask);

}

// invoke the scheduler
void schedule(int QtdTaks){
    int slice = 30;
    struct node *temp;
    temp = head;
    while (QtdTaks > 0 && temp != NULL){
        if(temp->task == NULL){
            break;
        }
        printf("Executando tarefa [%d] \n" , temp->task->tid);
        printf("Lista de tarefas\n");
        printf("[%s] [%s] [%s] [%s]\n","id","nome", "prioridade", "burst");
        traverse(head);
        sleep(3);
        system("clear");
        if(temp->task->burst <= slice){
            temp->task->burst = 0;
            delete(&head, temp->task);
            QtdTaks--;
        }
        if(temp->task->burst > slice){
            temp->task->burst = temp->task->burst - slice;
            //delete(&head, temp->task);
            //insert(&head, temp->task);
        }
        if(temp->next->task != NULL){
            temp = temp->next;
        }else{
            temp = head;
        }
    }
}
