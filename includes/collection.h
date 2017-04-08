#ifndef _COLLECTION_H
#define _COLLECTION_H

#include "helper.h"

typedef struct _Node{
    int data;
    struct _Node* next;
}Node;

/********************************************
 * PUBLIC: Bag interface.
 ********************************************/
typedef struct _Bag{
    Node* head;
    int count;
}Bag;

void Bag_init(Bag* bag);
void Bag_add(Bag* bag, int value);
bool Bag_isEmpty(Bag* bag);
int Bag_count(Bag* bag);
void Bag_show(Bag* bag);
void Bag_destroy(Bag* bag);

/*********************************************
 * PUBLIC: FixSTack interface.
 *********************************************/
typedef struct _FixStack{
    int* arr;
    int top;
    int capacity;
}FixStack;

void FixStack_init(FixStack* st, int capacity);
void FixStack_push(FixStack* st, int value);
int FixStack_pop(FixStack* st);
int FixStack_peek(FixStack* st);
int FixStack_count(FixStack* st);
bool FixStack_isEmpty(FixStack* st);
void FixStack_show(FixStack* st);
void FixStack_destroy(FixStack* st);

/********************************************
* PUBLIC: ResizeStack interface.
********************************************/
typedef struct _ResizeStack{
    int* arr;
    int top;
    int capacity;
} ResizeStack;

void ResizeStack_init(ResizeStack* st);
void ResizeStack_push(ResizeStack* st, int value);
int ResizeStack_pop(ResizeStack* st);
int ResizeStack_peek(ResizeStack* st);                                          
int ResizeStack_count(ResizeStack* st);
bool ResizeStack_isEmpty(ResizeStack* st);
void ResizeStack_show(ResizeStack* st);
void ResizeStack_destroy(ResizeStack* st);

/**********************************************
* PUBLIC: LinkList
**********************************************/
typedef struct _List{
Node* head;
int count;
} List;

void List_init(List* list);
void List_insert_front(List* list, int value);
void List_insert(List* list, Node* insert_after, int value);
int List_delete(List* list, Node* delete_node);
bool List_isEmpty(List* list);
int List_size(List* list);
void List_show(List* list);
Node* List_getNode(List* list, int value);
void List_destroy(List* list);

/*********************************************
* PUBLIC: QUEUE
*********************************************/
typedef struct _Queue{
Node* head;
Node* tail;
int count;
} Queue;

void Queue_init(Queue* q);
void Queue_enqueue(Queue* q, int value);
int Queue_dequeue(Queue* q);
int Queue_size(Queue* q);
bool Queue_isEmpty(Queue* q);
void Queue_show(Queue* q);
void Queue_destroy(Queue* q);

/********************************************
 * PUBLIC: DOUBLY_LINKLIST.
 ********************************************/
typedef struct _TwoWayLinkNode{
    int data;
    struct _TwoWayLinkNode* prev;
    struct _TwoWayLinkNode* next;
} DNode;

typedef struct _DoublyList{
    DNode* head;
    DNode* tail;
    int count;
} DoublyList;

void DoublyList_init(DoublyList* dlist);
void DoublyList_insert(DoublyList* dlist, int value);
void DoublyList_insert_after(DoublyList* dlist, DNode* node, int value);
int DoublyList_delete(DoublyList* dlist, DNode* node);
int DoublyList_size(DoublyList* dlist);
bool DoublyList_isEmpty(DoublyList* dlist);
void DoublyList_show(DoublyList* dlist);
DNode* DoublyList_getNode(DoublyList* dlist, int key);
void DoublyList_destroy(DoublyList* dlist);

/********************************************************************
* PUBLIC : DEQUEUE
********************************************************************/
typedef DoublyList Dequeue;
void Dequeue_init(Dequeue* dq);
void Dequeue_pushBack(Dequeue* dq, int value);
void Dequeue_pushFront(Dequeue* dq, int value);
int Dequeue_popBack(Dequeue* dq);
int Dequeue_popFront(Dequeue* dq);
int Dequeue_size(Dequeue* dq);
bool Dequeue_isEmpty(Dequeue* dq);
void Dequeue_show(Dequeue* dq);
void Dequeue_destroy(Dequeue* dq);

/**************************************************************
* PUBLIC : MAX_PRIORITY_QUEUE.
**************************************************************/
typedef struct _Priority_queue{
    int* array;
    int size;
    int capacity;
}MaxPQ;

void MaxPQ_init(MaxPQ* pq);
void MaxPQ_insert(MaxPQ* pq, int key);
int MaxPQ_deleteMax(MaxPQ* pq);
int MaxPQ_max(MaxPQ* pq);
bool MaxPQ_isEmpty(MaxPQ* pq);
int MaxPQ_size(MaxPQ* pq);
void MaxPQ_show(MaxPQ* pq);
void MaxPQ_destroy(MaxPQ* pq);

#endif
