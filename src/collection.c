#include "collection.h"
#include "helper.h"

/***************************************************
 * Private - BAG: Implementation.
 ***************************************************/

void Bag_init(Bag* bag){
    bag->head = NULL;
    bag->count = 0;
}

void Bag_add(Bag* bag, int value){
    Node* node = (Node*)Malloc(sizeof(Node));
    node->data = value;
    node->next = bag->head;

    bag->head = node;
    bag->count += 1;
}

bool Bag_isEmpty(Bag* bag){
    return (bag->head == NULL);
}

int Bag_count(Bag* bag){
    return bag->count;
}

void Bag_show(Bag* bag){
    Node* temp = bag->head;
    printf("Bag: {");
    while (temp){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("}\n");
}

void Bag_destroy(Bag* bag){
    Node* temp = NULL;
    while (bag->head){
        temp = bag->head;
        bag->head = bag->head->next;
        Free(temp);
    }
    bag->count = 0;
}

/********************************************
 * Private - FIXSTACK implementation
 ********************************************/

void FixStack_init(FixStack* st, int capacity){
    st->arr = (int* )Malloc(sizeof(int)*capacity);
    st->top = 0;
    st->capacity = capacity;
}

void FixStack_push(FixStack* st, int value){
    if (st->top == st->capacity){
        printf("FixStack: ERROR, stack overflow\n");
        return;
    }
    st->arr[st->top] = value;
    st->top += 1;
}

int FixStack_pop(FixStack* st){
    if (st->top == 0){
        printf("FixStack: ERROR, stack underflow\n");
        return -1;
    }
    int temp = st->arr[st->top - 1];
    st->top -= 1;
    return temp;
}

int FixStack_peek(FixStack* st){
    if (st->top == 0){
        printf("FixStack: Error, stack underflow\n");
        return -1;
    }
    return st->arr[st->top - 1];
}

int FixStack_count(FixStack* st){
    return st->top;
}

void FixStack_show(FixStack* st){
    printf("FixStack: {");
    for (int i = 0; i < st->top; i++){
        printf(" %d, ", st->arr[i]);
    }
    printf("}\n");
}

bool FixStack_isEmpty(FixStack* st){
    return (st->top == 0);
}
void FixStack_destroy(FixStack* st){
    Free(st->arr);
    st->top = 0;
    st->capacity = 0;
}


/**************************************************
* RESIZESTACK - private implementation.
**************************************************/

void _resizeStack(ResizeStack* st, int size){
    int* temp = Malloc(sizeof(int) * size);
    for (int i = 0; i < st->top; i++){
        temp[i] = st->arr[i];
    }
    Free(st->arr);
    st->arr = temp;
    st->capacity = size;
}

void ResizeStack_init(ResizeStack* st){
    st->arr = (int* )Malloc(sizeof(int));
    st->top = 0;
    st->capacity = 1;
}

void ResizeStack_push(ResizeStack* st, int value){
    if (st->capacity == st->top)
        _resizeStack(st, 2 * st->capacity);
    st->arr[st->top] = value;
    st->top += 1;
}

int ResizeStack_pop(ResizeStack* st){
    if (st->top == 0){
        printf("ResizeStack: ERROR, stack underflow\n");
        return -1;
    }
    int item = st->arr[st->top - 1];
    st->top -= 1;
    if (st->top > 0 && st->top < st->capacity/4)
        _resizeStack(st, st->capacity/2);
    return item;
}

int ResizeStack_peek(ResizeStack* st){
    if (st->top == 0){
        printf("ResizeStack: ERROR, stack underflow\n");
        return -1;
    }
    return st->arr[st->top - 1];
}

int ResizeStack_count(ResizeStack* st){
    return st->top;
}

bool ResizeStack_isEmpty(ResizeStack* st){
    return (st->top == 0);
}

void ResizeStack_show(ResizeStack* st){
    printf("ResizeStack: {");
    for (int i = 0; i < st->top; i++){
        printf(" %d, ", st->arr[i]);
    }
    printf("}\n");
}

void ResizeStack_destroy(ResizeStack* st){                                          
    Free(st->arr);
    st->top = 0;
    st->capacity = 0;
}

/*******************************************************
* SINGLE_LINKLIST - private implementation.
*******************************************************/

void List_init(List* list){
    list->head = NULL;
    list->count = 0;
}

void List_insert_front(List* list, int value){
    Node* node = (Node* )Malloc(sizeof(Node));
    node->data = value;
    node->next = list->head;
    list->head = node;
    list->count += 1;
}

void List_insert(List* list, Node* insert_after, int value){
    Node* node = (Node*)Malloc(sizeof(Node));
    node->data = value;
    node->next = insert_after->next;
    insert_after->next = node;
    list->count += 1;
}

int List_delete(List* list, Node* delete_node){
    Node* previous = NULL;
    Node* current = list->head;
    int deleted_item = delete_node->data;
    if (delete_node == current){
        list->head = current->next;
    }
    else{
        while (current != delete_node){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
    list->count -= 1;
    Free(current);
    return deleted_item;
}

bool List_isEmpty(List* list){
    return (list->head == NULL);
}

int List_size(List* list){
    return list->count;
}

Node* List_getNode(List* list, int value){
    for (Node* node = list->head; node != NULL; node = node->next){
        if (node->data == value) return node;
    }
    return NULL;
}

void List_show(List* list){
    printf("List: {");
    for (Node* node = list->head; node != NULL; node = node->next){
        printf(" %d,", node->data);
    }
    printf("}\n");
}

void List_destroy(List* list){
    while (list->head != NULL){
        List_delete(list, list->head);
    }
    list->count = 0;
}

/********************************************************************
* QUEUE: private implementation.
********************************************************************/
void Queue_init(Queue* q){
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
}

void Queue_enqueue(Queue* q, int value){
    Node* node = (Node* )Malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (q->tail == NULL){
        q->head = node;
        q->tail = node;
    }
    else{
        q->tail->next = node;
        q->tail = node;
    }
    q->count += 1;
}

int Queue_dequeue(Queue* q){
    if (q->head == NULL){
        printf("QUEUE: Error, already Empty\n");
        return -1;
    }
    Node* temp = q->head;
    int item = temp->data;
    q->head = temp->next;
    if (q->head == NULL) 
        q->tail = NULL;
    Free(temp);
    q->count -= 1;
    return item;
}

int Queue_size(Queue* q){
    return q->count;
}

bool Queue_isEmpty(Queue* q){
    return (q->head == NULL);
}

void Queue_show(Queue* q){
    printf("Queue: {");
    for (Node* node = q->head; node != NULL; node = node->next){
        printf(" %d,", node->data);
    }
    printf("}\n");
}

void Queue_destroy(Queue* q){
    while(q->head != NULL){
        Queue_dequeue(q);
    }
}

/***************************************************************
* DOUBLY_LIST: private implementation.
***************************************************************/
void DoublyList_init(DoublyList* dlist){
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->count = 0;
}

void DoublyList_insert(DoublyList* dlist, int value){
    DoublyList_insert_after(dlist, NULL, value);
}

void DoublyList_insert_after(DoublyList* dlist, DNode* node, int value){
    DNode* n = (DNode* )Malloc(sizeof(DNode));
    n->data = value;
    if (node == NULL){
        if (dlist->head == NULL){
            dlist->head = n;
            n->next = NULL;
            n->prev = NULL;
            dlist->tail = n;
        }
        else{
            n->next = dlist->head;
            dlist->head->prev = n;
            n->prev = NULL;
            dlist->head = n;
        }
    } 
    else if (node == dlist->tail){
        n->next = NULL;
        n->prev = node;
        node->next = n;
        dlist->tail = n;
    }
    else{
        n->next = node->next;
        n->prev = node;
        node->next = n;
        n->next->prev = n;
    }
    dlist->count += 1;
}

int DoublyList_delete(DoublyList* dlist, DNode* node){
    if (node == NULL){
        printf("DoublyList: Error, node to delete is NULL\n");
        return -1;
    }
    else{
        int item = node->data;
        if (node == dlist->head && node == dlist->tail){
            dlist->head = NULL;
            dlist->tail = NULL;
        }
        else if (node == dlist->head){
            dlist->head = node->next;
            node->next->prev = NULL;
        }
        else if (node == dlist->tail){
            dlist->tail = node->prev;
            dlist->tail->next = NULL;
        }
        else{ 
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        Free(node);
        dlist->count -= 1;
        return item;
    }
}

int DoublyList_size(DoublyList* dlist){
    return dlist->count;
}

bool DoublyList_isEmpty(DoublyList* dlist){
    return (dlist->head == NULL);
}

void DoublyList_show(DoublyList* dlist){
    printf("DoublyList: {");
    for (DNode* node = dlist->head; node != NULL; node = node->next){
        printf(" %d,", node->data);
    }
    printf("}\n");
}

DNode* DoublyList_getNode(DoublyList* dlist, int key){
    for (DNode* node = dlist->head; node != NULL; node = node->next){
        if (key == node->data){
            return node;
        }
    }
    return NULL;
}
void DoublyList_destroy(DoublyList* dlist){
    while(dlist->head != NULL){
        DoublyList_delete(dlist, dlist->head);
    }
}


/*****************************************************************
 * DEQUEUE: Private implementation.
 *****************************************************************/
void Dequeue_init(Dequeue* dq){
    DoublyList_init(dq);
}

void Dequeue_pushBack(Dequeue* dq, int value){
    DNode* node = (DNode* )Malloc(sizeof(DNode));
    node->data = value;
    if (dq->tail == NULL){
        dq->tail = node;
        dq->head = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else{
        node->next = dq->tail->next;
        node->prev = dq->tail;
        dq->tail->next = node;
        dq->tail = node;
    }
    dq->count += 1;
}

void Dequeue_pushFront(Dequeue* dq, int value){
    DNode* node = (DNode* )Malloc(sizeof(DNode));
    node->data = value;
    if (dq->head == NULL){
        dq->head = node;
        dq->tail = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else{
        node->next = dq->head;
        node->prev = NULL;
        dq->head->prev = node;
        dq->head = node;
    }
    dq->count += 1;
}

int Dequeue_popBack(Dequeue* dq){
    if (dq->tail == NULL){
        printf("DEQUEUE: ERROR popback, underflow\n");
        return -1;
    }
    DNode* temp = dq->tail;
    int item = temp->data;
    if (dq->tail == dq->head){
        dq->tail = NULL;
        dq->head = NULL;
    }
    else{
        dq->tail = temp->prev;
        dq->tail->next = NULL;
    }
    Free(temp);
    dq->count -= 1;
    return item;
}

int Dequeue_popFront(Dequeue* dq){
    if (dq->head == NULL){
        printf("DEQUEUE: ERROR popFront, underflow\n");
        return -1;
    }
    DNode* temp = dq->head;
    int item = temp->data;
    if (dq->head == dq->tail){
        dq->head = NULL;
        dq->tail = NULL;
    }
    else{
        dq->head = dq->head->next;
        dq->head->prev = NULL;
    }
    Free(temp);
    dq->count -= 1;
    return item;
}

int Dequeue_size(Dequeue* dq){
    return dq->count;
}

bool Dequeue_isEmpty(Dequeue* dq){
    return (dq->head == NULL);
}

void Dequeue_show(Dequeue* dq){
    printf("Dequeue: {");
    for (DNode* node = dq->head; node != NULL; node = node->next){
        printf(" %d,", node->data);
    }
    printf("}\n");
}

void Dequeue_destroy(Dequeue* dq){
    DoublyList_destroy(dq);
}


