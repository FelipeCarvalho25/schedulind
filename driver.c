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
    //instancia o ponteiro da lista de aptos
    head = (node *) malloc(sizeof(node));
    //instancia o ponteiro da lista de log de executados
    executados = (node *) malloc(sizeof(node));
    char *name;
    //inicia lista do aptos
    iniciaLista(head);
    //inicia lista de executados
    iniciaLista(executados);
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
        //incrementa quantidade de tasks
        QtdTaks ++;
        free(temp);
    }
    
    fclose(in);

    // invoke the scheduler
    schedule(QtdTaks);
    //printa mensagem de sucesso e log de exeução
    printf("Todas as tarefas executadas com sucesso!\n");
    printf("Log de execução:\n");
    exibe(executados);    
    return 0;
}
