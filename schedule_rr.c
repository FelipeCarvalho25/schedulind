#include "schedulers.h"
#include "list.h"
#include "task.h"
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



// representation of a task

void add(char *name, int priority, int burst){
    
    struct task *newTask;
    newTask = (struct task*) malloc(sizeof( struct task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);

}

// invoke the scheduler
void schedule(){
    
    traverse(head);
    printf("voltei");
}
