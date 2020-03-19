#include <stdio.h>
#include <stdlib.h>
 
//定义结构体
typedef struct Test{
	int data;
	struct Test *prev;
	struct Test *next;
}T;
 
/*
 *创建双向链表
*/
T *create_linked(){
	T *head,*node,*end;	//定义头结点，中间节点和尾节点
	int n;	//有多少个节点
	int i;
 
	//为头结点开辟一块内存空间
	head = (T *)malloc(sizeof(T));
	//创建好后立刻为next和prev设置为NULL
	head->next = NULL;
	head->prev = NULL;
	//没有数据的时候，尾节点 = 中间节点 = 头结点
	end = node = head;
 
	printf("N:\n");
	scanf("%d",&n);
	//用循环创建链表
	for(i = 1;i <= n;i++){
		int data;
		printf("data:\n");
		scanf("%d",&data);
		
		//为新节点分配空间
		end = (T *)malloc(sizeof(T));
		//新节点分配完空间立刻为指针赋值
		//next是其下一个节点，但此时新节点是尾节点，所以赋NULL
		end->next = NULL;
		//新节点的上一个节点即为node
		end->prev = node;
		end->data = data;
		//新节点的上一个节点把指针指向新节点
		node->next = end;
		node = end;
	}
	//最后一个节点的指针赋值为NULL
	return head;
}
 
/*
 *获取该链表的长度（不包括头结点）
*/
int linked_len(T *head){
	T *h = head;
	int len = 0;
	while(!(h->next == NULL)){
		h = h->next;
		len++;	
	}
	return len;
}
 
/*
 *获取指定位置的节点
*/
T *linked_value(T *head,int n){
	T *h = head;
	int i;
 
	//如果位置不存在，跳至报错代码
	if(n < 1 || n > linked_len(h))
		goto ERROR;
 
	//循环获取指定的节点（不包括头结点）
	for(i = 1;i <=n;i++){
		h = h->next;
	}
 
	return h;
 
ERROR:
	printf("this Node is NOT FOUND!\n");
}
 
/*
 *新增节点（在尾部新增）
*/
void linked_add(T *head,int value){
	T *node = head;
	T *end;
 
	//获取到尾部节点
	while(!(node->next == NULL)){
		node = node->next;
	}
 
	//为尾节点开辟一块内存空间
	end = (T *)malloc(sizeof(T));
 
	//立刻为新节点的指针赋值为NULL,该节点的上一个节点就是node
	end->next = NULL;
	end->prev = node;
	end->data = value;
	//node的next应该指向新节点
	node->next = end;
}
 
/*
 *插入节点（在中间插入）
*/
 
void linked_insert(T *head,int n,int value){
	T *node;
	T *newNode;
	//获取指定位置的节点
	node = linked_value(head,n);
 
	//为新节点开辟一块内存空间
	newNode = (T *)malloc(sizeof(T));
	//立刻为新节点的next赋值为原先位置的节点，新节点的prev为原先位置的节点的prev
	newNode->next = node;
	newNode->prev = node->prev;
	newNode->data = value;
 
	//原先位置的节点的上一个节点的next要改成新节点
	node->prev->next = newNode;
 
	//最后再改原先位置的节点的next和prev，prev为新节点，next不变
	node->prev = newNode;
}
 
/*
 *修改指定节点的内容
*/
void linked_change(T *head,int n,int value){
	T *node;
	//获取到指定的节点
	node = linked_value(head,n);
	//把值进行改变
	node->data = value;
}
 
/*
 *删除指定节点
*/
void linked_delete(T *head,int n){
	T *node;
	int len;
	//先获取到指定的节点
	node = linked_value(head,n);
	//获取到整个链表的长度
	len = linked_len(head);
 
	//分两种，第一种：删除尾节点，第二种：删除中间节点
	//第一种：
	if(n == len){
		//把尾节点的上一个节点的next设为NULL
		node->prev->next = NULL;
		//把尾节点free掉
		free(node);
	}
	else{
		//把该节点的上一个节点的next设置为该节点的下一个节点
		node->prev->next = node->next;
		//把该节点的下一个节点的prev设置为该节点的上一个节点
		node->next->prev = node->prev;
		//把该节点free掉
		free(node);
	}
}
/*
 *输出链表的内容
*/
void linked_content(T *head){
	T *h =  head;
	while(!(h->next == NULL)){
		h = h->next;
		printf("%d\n",h->data);
	}
}
 
/*
 *主函数
*/
void main(){
	T *head;
	//创建一个双向链表
	head = create_linked();
 
	//新增节点
	linked_add(head,555);
 
	//插入节点
	linked_insert(head,3,666);
 
	//改变值
	linked_change(head,2,888);
 
	//删除节点
	linked_delete(head,4);
 
	//输出链表的内容
	linked_content(head);
 
	//获取该链表的长度
	printf("%d\n",linked_len(head));
 
	//获取该链表的第2个节点
	printf("%d\n",linked_value(head,2)->data);
 
	getchar();
	getchar();
 
}