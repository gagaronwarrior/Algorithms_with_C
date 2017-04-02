#include "collection.h"
#include "helper.h"
#include "sort.h"

int main(){

    /*************************************************
     * BAG - test client.
     ************************************************/
    clock_t clock_begin = clock();
    Bag b;
    Bag_init(&b);
    for (int i = 1; i <= 11; i++){
        Bag_add(&b, i);
    }
    printf("Bag: count = %d\n", Bag_count(&b));
    printf("Bag: isEmpty = %d\n", Bag_isEmpty(&b));
    Bag_show(&b);
    Bag_destroy(&b);

    /*****************************************************
    * FIXSTACK test client.
    *****************************************************/
    FixStack st;
    FixStack_init(&st, 10);
    for (int i = 1; i <= 11; i++){
        FixStack_push(&st, i);
    }
    printf("FixStack Pop: %d\n", FixStack_pop(&st));
    printf("FixStack count: %d\n", FixStack_count(&st));
    printf("FixStack peek: %d\n", FixStack_peek(&st));
    FixStack_show(&st);
    while (! FixStack_isEmpty(&st)){
        printf("FixStack pop: %d\n", FixStack_pop(&st));
    }
    printf("FixStack peek: %d\n", FixStack_peek(&st));
    FixStack_destroy(&st);

    /*************************************************
    * RESIZESTACK test client.
    *************************************************/
    ResizeStack rst;
    ResizeStack_init(&rst);
    for (int i = 1; i <=10; i++){
        ResizeStack_push(&rst, i);
    }
    ResizeStack_show(&rst);
    printf("ResizeStack count: %d capacity: %d\n", ResizeStack_count(&rst), rst.capacity);
    for (int i = 1; i <= 7; i++){
        printf("ResizeStack pop: %d\n", ResizeStack_pop(&rst));
    }
    ResizeStack_show(&rst);
    printf("ResizeStack count: %d capacity: %d\n", ResizeStack_count(&rst), rst.capacity);
    ResizeStack_destroy(&rst);    

    /**************************************************
     * LIST test client.
     *************************************************/
    List list;
    List_init(&list);
    for (int i = 1; i <= 10; i++){
        List_insert_front(&list, i);
    }
    printf("List: list_isEmpty? %d\n", List_isEmpty(&list));
    printf("List: list_count %d\n", List_size(&list));
    List_show(&list);
    printf("List: deleted %d\n",List_delete(&list, List_getNode(&list, 10)));
    printf("List: list_isEmpty? %d\n", List_isEmpty(&list));
    printf("List: list_count %d\n", List_size(&list));
    List_show(&list);
    printf("List: delete %d\n", List_delete(&list, List_getNode(&list, 5)));
    printf("List: list_isEmpty? %d\n", List_isEmpty(&list));
    printf("List: list_count %d\n", List_size(&list));
    List_show(&list);
    List_destroy(&list);

    /********************************************************
     * Queue test client.
     ********************************************************/
    Queue q;
    Queue_init(&q);
    for (int i = 1; i <= 10; i++){
        Queue_enqueue(&q, i);
    }
    printf("Queue: size %d\n", Queue_size(&q));
    printf("Queue: isEmpty %d\n", Queue_isEmpty(&q));
    Queue_show(&q);
    printf("Queue: dequeue %d\n", Queue_dequeue(&q));
    printf("Queue: dequeue %d\n", Queue_dequeue(&q));
    printf("Queue: size %d\n", Queue_size(&q));
    printf("Queue: isEmpty %d\n", Queue_isEmpty(&q));
    Queue_show(&q);
    Queue_destroy(&q);

    /************************************************************
     * DoublyList test client.
     ************************************************************/
    DoublyList dlist;
    DoublyList_init(&dlist);
    for (int i = 1; i <= 10; i++){
        DoublyList_insert(&dlist, i);
    }
    printf("DoublyList: count %d\n", DoublyList_size(&dlist));
    printf("DoublyList: isEmpty %d\n", DoublyList_isEmpty(&dlist));
    DoublyList_show(&dlist);
    DoublyList_insert_after(&dlist, DoublyList_getNode(&dlist, 1), 64);
    printf("DoublyList: count %d\n", DoublyList_size(&dlist));
    printf("DoublyList: isEmpty %d\n", DoublyList_isEmpty(&dlist));
    DoublyList_show(&dlist);
    DoublyList_insert_after(&dlist, DoublyList_getNode(&dlist, 5), 555);
    printf("DoublyList: count %d\n", DoublyList_size(&dlist));
    printf("DoublyList: isEmpty %d\n", DoublyList_isEmpty(&dlist));
    DoublyList_show(&dlist);
    DoublyList_delete(&dlist, DoublyList_getNode(&dlist, 555));
    printf("DoublyList: count %d\n", DoublyList_size(&dlist));
    printf("DoublyList: isEmpty %d\n", DoublyList_isEmpty(&dlist));
    DoublyList_show(&dlist);
    DoublyList_delete(&dlist, DoublyList_getNode(&dlist, 64));
    printf("DoublyList: count %d\n", DoublyList_size(&dlist));
    printf("DoublyList: isEmpty %d\n", DoublyList_isEmpty(&dlist));
    DoublyList_show(&dlist);
    DoublyList_destroy(&dlist);

    /********************************************************************
     * DEQUEUE test client.
     ********************************************************************/
    Dequeue dq;
    Dequeue_init(&dq);
    for (int i = 1; i <= 5; i++){
        Dequeue_pushBack(&dq, i);
        Dequeue_pushFront(&dq, i);
    }
    printf("Dequeue: count %d\n", Dequeue_size(&dq));
    printf("Dequeue: isEmpty %d\n", Dequeue_isEmpty(&dq));
    Dequeue_show(&dq);
    printf("Dequeue: popFront %d\n", Dequeue_popFront(&dq));
    printf("Dequeue: popback %d\n", Dequeue_popBack(&dq));
    printf("Dequeue: count %d\n", Dequeue_size(&dq));
    printf("Dequeue: isEmpty %d\n", Dequeue_isEmpty(&dq));
    Dequeue_show(&dq);
    while (!Dequeue_isEmpty(&dq)){
        printf("Dequeue: popback %d\n",Dequeue_popFront(&dq));
    }
    printf("Dequeue: count %d\n", Dequeue_size(&dq));                           
    printf("Dequeue: isEmpty %d\n", Dequeue_isEmpty(&dq));
    Dequeue_show(&dq);
    Dequeue_destroy(&dq);

    /********************************************************
     * SELECTION SORT test client.
     ********************************************************/
    const int N = 10;
    int array[N];
    Randomly_fill_array(array, N);
    selection_sort(array, N);
    ShowArray(array, N, "SELECTION_SORT");

    /********************************************************
     * INSERTION SORT test client.
     ********************************************************/
    Randomly_fill_array(array, N);
    insertion_sort(array, N);
    ShowArray(array, N, "INSERTION_SORT");

    /********************************************************
     * SHELL SORT test client.
     ********************************************************/
    Randomly_fill_array(array, N);
    shell_sort(array, N);
    ShowArray(array, N, "SHELL_SORT"); 

    /********************************************************
     * MERGE SORT test client.
     ********************************************************/
    Randomly_fill_array(array, N);
    printf("calling merge\n");
    merge_sort(array, N);
    ShowArray(array, N, "MERGE_SORT"); 


    printf("Time taken : %g\n", CPU_time_taken(clock_begin));
    return 0;
}
