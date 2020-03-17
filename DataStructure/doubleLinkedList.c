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
    printf("list:%p\n",list->prev);
    if(list->prev == NULL){
        printf("this list is NULL!\n");
        return;
    }
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

line*  delLine(line * head,int Value){
    int i=1;
    if(head->prev==NULL){
        printf("this is empty!\n");
        return head;
    }
    line *temp,*body;
    while (head)
    {   
        i++;
        printf("head:    %d prev:%p next:%p\n",head->data,head->prev,head->next);
        printf("%d prev:%p next:%p\n",temp->data,temp->prev,temp->next);
        if(head->data == Value){
            head = head->prev;
            temp = head;
            printf("head->data:%d\n",i);
            break;
        }else{
            temp = body;
        }
        printf("%d\n",i);
        body = head->next;
        body->prev = NULL;
        if(head->prev==NULL){
            printf("head->prev:%d\n",i);
            break;
        }
        head = head->prev;

    }
    return temp;
}

void main(){
    line *head,*temp1;
    int initVal,i;
    initVal = 1997;
    head = initLine(head,initVal);
    for(i=8;i>0;i--){
        head = addLine(head,i);
    }
    eachLine(head);
    head = delLine(head,6);
    printf("headheadhead%d prev:%p next:%p\n",head->data,head->prev,head->next);
    eachLine(head);
}