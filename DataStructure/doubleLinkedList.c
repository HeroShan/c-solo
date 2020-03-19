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

int  delLine(line * head,int Value){
        line *temp = head;
        line **pprev;
        if(head->prev==NULL){
            return -1;
        }
       
        while (head->prev != NULL)
        {
            //printf("while : ---data: %d ,%p\n",head->data,head->prev);
            if(head->data == Value){
                if(NULL == head->next){     //链尾删除
                head->prev->next = NULL;
                free(head);
                return head->data;
                }else{
                head->prev->next = head->next;      //普通删除
                head->next->prev = head->prev;
                return head->data;
                }
            }
            head = head->prev;
        }
        if(head->data == Value){
                head->next->prev = NULL;        //链头删除
                return head->data;
            }
        printf("Don't find this %d NODE!\n",Value);
        return -1;
        
}

void main(){
    line *head,*temp1;
    int initVal,i;
    initVal = 99;
    head = initLine(head,initVal);
    for(i=15;i>0;i--){
        head = addLine(head,i);
    }
    eachLine(head);
    i = delLine(head,1);
    i = delLine(head,3);
    eachLine(head);
}