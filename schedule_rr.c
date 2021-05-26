#include "schedulers.h"
#include "list.h"
#include "task.h"
#include "CPU.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



// representation of a task

void add(char *name, int priority, int burst, int id){
    //cria ponteiro de newTask temporario
    struct task *newTask;
    newTask = (struct task*) malloc(sizeof( struct task));
    newTask->tid = id;
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    //insere no fim da lista de aptos
    insereFim(head, newTask);

}
//salva task no log de execução
void salvaExecutados(Task *task){
    struct task *newTask;
    newTask = (struct task*) malloc(sizeof( struct task));
    newTask->tid = task->tid;
    newTask->name = task->name;
    newTask->priority = task->priority;
    newTask->burst = task->burst;
    insereFim(executados, newTask);
}
// invoke the scheduler
void schedule(int QtdTaks){
    //define o slice/quantum do processador
    int slice = 8;
    //cria variavel do tempo total de processamento
    int tempoTotal = 0;
    //cria variáveis de controle durante a execução
    node *raiz = head->prox;
    node *temp = head->prox;
    //variavel de controle de tempo em que a tarefa está rodando
    int rodando = 0;
    //enquanto houver tarefas na lista de aptos executa
    while (QtdTaks > 0 ){
        //printa lista de aptos
        system("clear");
        printf("Lista de aptos:\n");
        exibe(head);
        sleep(3);
        system("clear");
        //zera variavel de controle de tempo da execução da task
        rodando = 0;
        //insere a task a ser executada no fim da lista de log de exeução
        salvaExecutados(temp->task);
        //enquanto o burst da task for maior que zero ou o tempo rodando for menor que o quantum
        while(temp->task->burst > 0 && rodando < slice){
            //adiciona no tempo total de execução
            tempoTotal = tempoTotal + 1;
            //adiciona no tempo que a task está rodando
            rodando = rodando +1;
            //decrementa no burst da task para simular a exeução
            temp->task->burst = temp->task->burst - 1 ;
            //chama função de execução
            run(temp->task, rodando);
            //sleep para melhorar o acompanhamento da execução
            sleep(1);
        }
        //se o burst for zero e a tarefa rodou ele retira da lista de aptos e decrementa a qtd de tasks
        if(temp->task->burst == 0 && rodando > 0){
            retira(head, temp->task);
            QtdTaks--;
        }
        // chama o proximo item da lista, caso esteja no final volta pro inicio
        if(temp->prox != NULL){
            temp = temp->prox;
        }else{
            temp = raiz;
        }
    }
    system("clear");
    printf("Tarefas executadas em [%d] unidades de tempo;", tempoTotal);
}
