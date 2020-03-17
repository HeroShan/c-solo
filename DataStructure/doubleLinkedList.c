#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    int data;
    struct line *prev;
    struct line *next;

}line;


line* initLine(line * head,int initVal){    
       head = (line*)malloc(sizeof(line));
       head->prev = NULL;
       head->next = NULL;
       head->data = initVal;
    return head;

}

line* addLine(line * head,int Value){
      line * temp;
      temp = (line*)malloc(sizeof(line)); 
      temp->prev = NULL;
      temp->next = NULL;
      temp->data = Value;

      head->next = temp;
      temp->prev = head;
      head = head->next;
      return head;

}

void eachLine(line * list){
    printf("Fist:%d->",list->data);
    list = list->prev;
    while (list)
    {
        if(list->prev == NULL){
            printf("%d Over!\n",list->data);
            break;
        }
        printf("%d->",list->data);
        list = list->prev;
    }
    
 
}

// line* delLine(){

// }

void main(){
    line *head,*temp1;
    int initVal;
    initVal = 1997;
    head = initLine(head,initVal);
    temp1 = addLine(head,2020);
    temp1 = addLine(temp1,317);
    temp1 = addLine(temp1,5317);
    eachLine(temp1);
}