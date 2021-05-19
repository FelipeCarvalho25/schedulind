#include "schedulers.h"
#include "list.h"

typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
} Task;
struct node *head = malloc(sizeof(struct node));

void add(char *name, int priority, int burst){

    struct Task *newTask = malloc(sizeof(struct Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(head, newTask);

}

// invoke the scheduler
void schedule(){
    traverse(head);
}