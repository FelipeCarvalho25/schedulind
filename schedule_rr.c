#include "schedulers.h"
#include "list.h"
#include "task.h"
#include "CPU.h"

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
    int tempoTotal = 0;
    struct node *temp;
    int rodando = 0;
    temp = head;
    while (QtdTaks > 0 && temp != NULL){
        
        if(temp->task == NULL){
            break;
        }
        system("clear");
        printf("Lista de tarefas\n");
        printf("[%s] [%s] [%s] [%s]\n","id","nome", "prioridade", "burst");
        traverse(head);
        sleep(3);
        system("clear");
        rodando = 0;
        while(temp->task->burst > 0 && rodando < slice){
            tempoTotal = tempoTotal + 1;
            sleep(1);
            rodando = rodando +1;
            temp->task->burst = temp->task->burst - 1 ;
            run(temp->task, rodando);
        }
        if(temp->task->burst == 0 ){
            delete(&head, temp->task);
            QtdTaks--;
        }
        if(temp->next->task != NULL){
            temp = temp->next;
        }else{
            temp = head;
        }
    }
    system("clear");
    printf("Tarefas executadas em [%d] unidades de tempo;", tempoTotal);
}
