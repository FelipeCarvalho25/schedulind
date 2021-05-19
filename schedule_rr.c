#include "schedulers.h"
#include "list.h"
#include "task.h"
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node *head ;
// representation of a task

void add(char *name, int priority, int burst){
    printf("TESTE");
    head = malloc(sizeof(struct node));
    
    struct task *newTask;
    printf("TESTE");
    newTask = (struct task*) malloc(sizeof( struct task));
    printf("TESTE");
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);

}

// invoke the scheduler
void schedule(){
    
    traverse(head);
}
