#include "collection.h"
#include "helper.h"
#include "sort.h"
#include "search.h"
#include "graph.h"

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
  for (Node* n = Bag_iterator_begin(&b); n != Bag_iterator_end(); n = Bag_iterator_next(n)){
    printf("Bag: %d\n", n->data);
  }
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
  insertion_sort(array, N);
  merge_sort(array, N);
  ShowArray(array, N, "MERGE_SORT"); 

  /********************************************************
   * OPTIMIZED MERGE SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  optimize_merge_sort(array, N);
  ShowArray(array, N, "OPTIMIZE_MERGE_SORT"); 

  /********************************************************                   
   * OPTIMIZED MERGE SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  bottom_up_merge_sort(array, N);
  ShowArray(array, N, "BOTTOM_UP_MERGE_SORT"); 

  /********************************************************                   
   * QUICK SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  quick_sort(array, N);
  ShowArray(array, N, "QUICK_SORT"); 

  /********************************************************                   
   * OPTIMIZE QUICK SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  optimize_quick_sort(array, N);
  ShowArray(array, N, "OPTIMIZE_QUICK_SORT"); 

  /********************************************************                   
   * 3_WAY_QUICK SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  quick_sort_3_way(array, N);
  ShowArray(array, N, "3_WAY_QUICK_SORT"); 

  /********************************************************
   * MAX_PRIORITY_QUEUE test client.
   *******************************************************/
  MaxPQ pq;
  MaxPQ_init(&pq);
  for (int i = 1; i <= 6; i++){
    MaxPQ_insert(&pq, i);
  }
  MaxPQ_show(&pq);
  printf("MaxPQ : isEmpty %d\n", MaxPQ_isEmpty(&pq));
  printf("MaxPQ : size %d\n", MaxPQ_size(&pq));
  printf("MaxPQ : max %d\n", MaxPQ_max(&pq));
  printf("MaxPQ : deleteMax %d\n", MaxPQ_deleteMax(&pq));
  MaxPQ_show(&pq);
  printf("MaxPQ : isEmpty %d\n", MaxPQ_isEmpty(&pq));
  printf("MaxPQ : size %d\n", MaxPQ_size(&pq));
  printf("MaxPQ : max %d\n", MaxPQ_max(&pq));
  printf("MaxPQ : capacity %d\n", pq.capacity);
  /*
   * commenting as this test case will cause programme to exit.
   while (!MaxPQ_isEmpty(&pq)){
   printf("MaxPQ : deleteMax %d\n", MaxPQ_deleteMax(&pq));
   }
   MaxPQ_deleteMax(&pq);
   */
  MaxPQ_destroy(&pq);

  /********************************************************                   
   * HEAP SORT test client.
   ********************************************************/
  Randomly_fill_array(array, N);
  heap_sort(array, N);
  ShowArray(array, N, "HEAP_SORT"); 

  /******************************************************
   * BINARY SEARCH test client.
   *****************************************************/
  int arr[10] = {1,12,33,44,55,66,77,88,99,100};
  printf("BINARY SEARCH: contains key %d ? %d\n",1, binary_search(arr, 10, 1));
  printf("BINARY SEARCH: contains key %d ? %d\n",88, binary_search(arr, 10, 88));
  printf("BINARY SEARCH: contains key %d ? %d\n",100, binary_search(arr, 10, 100));
  printf("BINARY SEARCH: contains key %d ? %d\n",7, binary_search(arr, 10, 7));

  /*****************************************************
   * SEQUENTIAL SEARCH UNORDERED SYMBOL TABLE.
   ****************************************************/
  UnorderST ust;
  UnorderST_init(&ust);
  UnorderST_put(&ust, 1, "Hi");
  UnorderST_put(&ust, 2, "Hello");
  UnorderST_put(&ust, 3, "world");
  UnorderST_put(&ust, 4, "is");
  UnorderST_put(&ust, 5, "good");
  UnorderST_put(&ust, 6, "place");
  for(int i = 1; i <= 6; i++){
    printf("UnorderST: get %d : %s\n", i, UnorderST_get(&ust, i));
  }
  UnorderST_show(&ust);
  printf("UnorderST: get %d : %s\n", 10, UnorderST_get(&ust, 10));
  printf("UnorderST: contains %d : %d\n", 10, UnorderST_contains(&ust, 10));
  printf("UnorderST: contains %d : %d\n", 1, UnorderST_contains(&ust, 1));
  printf("UnorderST: isEmpty %d\n", UnorderST_isEmpty(&ust));
  printf("UnorderST: size %d\n", UnorderST_size(&ust));
  printf("UnorderST: delete %d\n", 5);
  UnorderST_delete(&ust, 5);
  UnorderST_show(&ust);
  printf("UnorderST: isEmpty %d\n", UnorderST_isEmpty(&ust));
  printf("UnorderST: size %d\n", UnorderST_size(&ust));
  printf("UnorderST: delete %d\n", 5);
  UnorderST_delete(&ust, 11);
  UnorderST_destroy(&ust);

  /***********************************************************************
   * ORDERED ARRAY SYMBOL TABLE.
   ***********************************************************************/
  OrderedST ost;
  OrderedST_init(&ost, 10);
  OrderedST_put(&ost, 1, "Hi");
  OrderedST_put(&ost, 11, "Hello");
  OrderedST_put(&ost, 2, "world");
  OrderedST_put(&ost, 5, "is");
  OrderedST_put(&ost, 4, "good");
  OrderedST_put(&ost, 6, "place");
  for(int i = 1; i <= 6; i++){
    printf("OrderedST: get %d : %s\n", i, OrderedST_get(&ost, i));
  }
  OrderedST_show(&ost);
  printf("OrderedST: get %d : %s\n", 10, OrderedST_get(&ost, 10));
  printf("OrderedST: contains %d : %d\n", 10, OrderedST_contains(&ost, 10));
  printf("OrderedST: contains %d : %d\n", 1, OrderedST_contains(&ost, 1));
  printf("OrderedST: isEmpty %d\n", OrderedST_isEmpty(&ost));
  printf("OrderedST: size %d\n", OrderedST_size(&ost));
  printf("OrderedST: delete %d\n", 5);
  OrderedST_delete(&ost, 5);
  OrderedST_show(&ost);
  printf("OrderedST: isEmpty %d\n", OrderedST_isEmpty(&ost));
  printf("OrderedST: size %d\n", OrderedST_size(&ost));
  printf("OrderedST: delete %d\n", 5);
  OrderedST_delete(&ost, 11);
  OrderedST_show(&ost);
  printf("OrderedST: min %d\n", OrderedST_min(&ost));
  printf("OrderedST: max %d\n", OrderedST_max(&ost));
  printf("OrderedST: no of keys %d\n", OrderedST_no_of_keys(&ost, 2, 4));
  printf("OrderedST: deletemin\n");
  OrderedST_deleteMin(&ost);
  OrderedST_show(&ost);
  printf("OrderedST: deleteMax\n");
  OrderedST_deleteMax(&ost);
  OrderedST_show(&ost);
  printf("OrderedST: size %d\n", OrderedST_size(&ost));
  printf("OrderedST: floor %d\n", OrderedST_floor(&ost, 3));
  printf("OrderedST: ceiling %d\n", OrderedST_ceiling(&ost, 3));
  OrderedST_destroy(&ost);

  /******************************************************
   * BINARY SEARCH TREE SYMBOL TABLE.
   *****************************************************/
  BST tree;
  BST_init(&tree);
  BST_insert_iterative(&tree, 10, "Hi");
  BST_insert_iterative(&tree, 5, "Hey");
  BST_insert_iterative(&tree, 6, "hello");
  BST_insert_iterative(&tree, 3, "there");
  BST_insert_iterative(&tree, 4, "where"); 
  BST_insert_iterative(&tree, 15, "whereever"); 
  BST_insert_iterative(&tree, 17, "you"); 
  BST_insert_iterative(&tree, 11, "are"); 
  BST_insert_iterative(&tree, 13, "awesum"); 
  BST_show(&tree);
  printf("BST: tree height= %d\n", BST_tree_height(&tree));
  printf("BST: get key %d: %s\n", 0, BST_get_recursive(&tree, 0));
  printf("BST: get key %d: %s\n", 1, BST_get_recursive(&tree, 11));
  printf("BST: get key %d: %s\n", 2, BST_get_recursive(&tree, 13));
  printf("BST: get key %d: %s\n", 3, BST_get_recursive(&tree, 3));
  printf("BST: get key %d: %s\n", 4, BST_get_recursive(&tree, 4));
  printf("BST: get key %d: %s\n", 5, BST_get_recursive(&tree, 5));
  printf("BST: min key %d\n", BST_get_min_key(&tree));
  printf("BST: max key %d\n", BST_get_max_key(&tree));
  printf("BST: delete min \n");
  BST_delete_min_iterative(&tree);
  BST_show(&tree);
  printf("BST: tree height= %d\n", BST_tree_height(&tree));
  printf("BST: delete max\n");
  BST_delete_max_iterative(&tree);
  BST_show(&tree);
  printf("BST: tree height= %d\n", BST_tree_height(&tree));
  printf("BST: delete %d\n", 5);
  BST_delete_recursive(&tree, 5);
  BST_show(&tree);
  printf("BST: tree height= %d\n", BST_tree_height(&tree));
  BST_destroy(&tree);

  /*******************************************************************
   * LEFT LEANING RED BLACK BINARY SEARCH TREE.
   ******************************************************************/
  RB_BST rb_tree;
  RB_BST_init(&rb_tree);
  RB_BST_insert_recursive(&rb_tree, 1, "A");
  RB_BST_insert_recursive(&rb_tree, 3, "C");
  RB_BST_insert_recursive(&rb_tree, 5, "E");
  RB_BST_insert_recursive(&rb_tree, 8, "H");
  RB_BST_insert_recursive(&rb_tree, 12, "L");
  RB_BST_insert_recursive(&rb_tree, 13, "M");
  RB_BST_insert_recursive(&rb_tree, 16, "P");
  RB_BST_insert_recursive(&rb_tree, 17, "R");
  RB_BST_insert_recursive(&rb_tree, 18, "S");
  RB_BST_insert_recursive(&rb_tree, 24, "X");
  RB_BST_show(&rb_tree);

  /*******************************************************************
   * GRAPH 
   ******************************************************************/
  Graph g;
  Graph_init(&g, 13);
  Graph_add_edge(&g, 0, 5);
  Graph_add_edge(&g, 4, 3);
  Graph_add_edge(&g, 0, 1);
  Graph_add_edge(&g, 9, 12);
  Graph_add_edge(&g, 6, 4);
  Graph_add_edge(&g, 5, 4);
  Graph_add_edge(&g, 0, 2);
  Graph_add_edge(&g, 11, 12);
  Graph_add_edge(&g, 9, 10);
  Graph_add_edge(&g, 0, 6);
  Graph_add_edge(&g, 7, 8);
  Graph_add_edge(&g, 9, 11);
  Graph_add_edge(&g, 5, 3);
  Graph_show(&g);
  printf("GRAPH: degree of %d is %d\n", 0, Graph_degree_of_vertex(&g, 0));
  printf("GRAPH: max degree %d\n", Graph_max_degree(&g));
  printf("GRAPH: average degree %d\n", Graph_average_degree(&g));
  printf("GRAPH: no of self loops %d\n", Graph_no_of_self_loops(&g));

  /*****************************************************************************
   * GRAPH: Depth first search.
   ****************************************************************************/
  Graph_path gp;
  Graph_path_init(&gp, &g, 0);
  Graph_path_search(&gp, DFS);
  printf("GRAPH PATH: has path to %d: %d\n", 5, Graph_path_has_path_to(&gp, 5));
  printf("GRAPH PATH: has path to %d: %d\n", 2, Graph_path_has_path_to(&gp, 2));
  printf("GRAPH PATH: has path to %d: %d\n", 9, Graph_path_has_path_to(&gp, 9));
  printf("GRAPH PATH: connected node %d\n", Graph_path_count(&gp));
  Graph_path_show_path(&gp, 0);
  Graph_path_show_path(&gp, 1);
  Graph_path_show_path(&gp, 2);
  Graph_path_show_path(&gp, 3);
  Graph_path_show_path(&gp, 4);
  Graph_path_show_path(&gp, 5);
  Graph_path_show_path(&gp, 6);
  Graph_path_show_path(&gp, 9);
  Graph_path_destroy(&gp);

  /*******************************************************************************
   * GRAPH: Breadth first search.
   ******************************************************************************/
  Graph_path gp1;
  Graph_path_init(&gp1, &g, 0);
  Graph_path_search(&gp1, BFS);
  printf("GRAPH PATH: has path to %d: %d\n", 5, Graph_path_has_path_to(&gp1, 5));
  printf("GRAPH PATH: has path to %d: %d\n", 2, Graph_path_has_path_to(&gp1, 2));
  printf("GRAPH PATH: has path to %d: %d\n", 9, Graph_path_has_path_to(&gp1, 9));
  printf("GRAPH PATH: connected node %d\n", Graph_path_count(&gp1));
  Graph_path_show_path(&gp1, 0);
  Graph_path_show_path(&gp1, 1);
  Graph_path_show_path(&gp1, 2);
  Graph_path_show_path(&gp1, 3);
  Graph_path_show_path(&gp1, 4);
  Graph_path_show_path(&gp1, 5);
  Graph_path_show_path(&gp1, 6);
  Graph_path_show_path(&gp1, 9);
  Graph_path_destroy(&gp1);

  /*********************************************************************************
   * GRAPH_CONNECTED_COMPONENTS.
   ********************************************************************************/
  CC cc;
  CC_init(&cc, &g);
  CC_create_id(&cc);
  printf("CC: no of connected component %d\n", CC_no_of_connected_component(&cc));
  printf("CC: Is %d and %d connected ? %d \n", 0, 5, CC_is_connected(&cc, 0, 5));
  printf("CC: Is %d and %d connected ? %d \n", 0, 7, CC_is_connected(&cc, 0, 7));
  printf("CC: Is %d and %d connected ? %d \n", 7, 9, CC_is_connected(&cc, 7, 9));
  CC_show_components(&cc);
  CC_destroy(&cc);
  Graph_destroy(&g);

  printf("Time taken : %g\n", CPU_time_taken(clock_begin));

  return 0;
}
