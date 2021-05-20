/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100


int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];
    head = malloc(sizeof(struct node));
    char *name;
    int priority;
    int burst;
    int QtdTaks = 0;
    in = fopen(argv[1],"r");

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        
        add(name,priority,burst,QtdTaks+1 );
        QtdTaks ++;
        free(temp);
    }
    printf("Todas as tarefas executadas com sucesso!");
    fclose(in);

    // invoke the scheduler
    schedule(QtdTaks);

    return 0;
}
