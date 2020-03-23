#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct SequenceQueue
{
    DataType        SequenceQueue[10];
    int             fornt;
    int             rear;

}Sq;


void InitQueue(Sq *queue){
    queue->fornt = 0;
    queue->rear  = 0;
}

int IsEmpty(Sq *queue){
    if(queue->fornt==queue->rear){
        return 1;
    }
    return 0;
}

int IsFull(Sq *queue){
    if(queue->rear == 0){
        return 1;
    }
    return 0;

}

void AddQueue(Sq *queue,DataType q){
    if(IsFull(queue)){
        return 0;
    }
    


}


void main(){
    Sq  queue;
    int size;
    InitQueue(&queue);
    IsEmpty(&queue);


}