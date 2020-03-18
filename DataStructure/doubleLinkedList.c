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
        if(head->prev==NULL){
            return -1;
        }
       
        while (NULL != head->prev )
        {
            
            if(head->data == Value){
                if(head->next == NULL){
                head->prev->next->prev = head->prev;
                head->prev->next->next = NULL;
                return 0;
                }

                head->prev->next = head->next;
                head->next->prev = head->prev;
                return 0;
            }
            head = head->prev;
            
        }
        printf("Don't find this NODE!\n");
        
}

void main(){
    line *head,*temp1;
    int initVal,i;
    initVal = 1997;
    head = initLine(head,initVal);
    for(i=5;i>0;i--){
        head = addLine(head,i);
    }
    eachLine(head);
    i = delLine(head,1);
    eachLine(head);
}