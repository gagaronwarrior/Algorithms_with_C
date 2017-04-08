#include "search.h"

/********************************************
 * BINARY SEARCH.
 ********************************************/
int _binary_search(int* array, int low, int high, int key){
  int ret_val = -1;
  int mid;

  while (low <= high){
    mid = low + (high-low)/2;
    if (key < array[mid]) high = mid-1;
    else if (key > array[mid]) low = mid+1;
    else {
      ret_val = mid;
      break;
    }
  }
  return ret_val;
}

int binary_search(int* array, int length, int key){
  return _binary_search(array, 0, length-1, key);
}

/********************************************************
 * SEQUENTIAL SEARCH SYMBOL TABLE.
 ********************************************************/
void UnorderST_init(UnorderST* st){
  st->head = NULL;
  st->size = 0;
}

void UnorderST_put(UnorderST* st, int key, char* value){
  for (UnorderST_node* node = st->head; node != NULL; node = node->next){
    if (node->key == key){
      node->value = value;
      return;
    }
  }

  UnorderST_node* node = (UnorderST_node* )Malloc(sizeof(UnorderST_node));
  node->key = key;
  node->value = value;
  node->next = st->head;
  st->head = node;
  st->size += 1;
}
   

char* UnorderST_get(UnorderST* st, int key){
  for (UnorderST_node* node = st->head; node != NULL; node = node->next){
    if (node->key == key)
      return node->value;
  }
  return NULL;
} 

void UnorderST_delete(UnorderST* st, int key){
  UnorderST_node* prev = NULL;
  UnorderST_node* curr = st->head;
  while (curr != NULL && curr->key != key){
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL){
    printf("UnorderST: ERROR, cannot delete, key not present\n");
  }
  else if (prev == NULL){
    st->head = curr->next;
    st->size -= 1;
  }
  else{
    prev->next = curr->next;
    st->size -= 1;
    Free(curr);
  }
}

bool UnorderST_contains(UnorderST* st, int key){
  return (UnorderST_get(st, key) != NULL);
}

bool UnorderST_isEmpty(UnorderST* st){
  return (st->head == NULL);
}

int UnorderST_size(UnorderST* st){
  return st->size;
}

void UnorderST_show(UnorderST* st){
  printf("UnorderST: {");
  for (UnorderST_node* node = st->head; node != NULL; node = node->next){
    printf("(%d, %s), ", node->key, node->value);
  }
  printf("}\n");
}

void UnorderST_destroy(UnorderST* st){
  while (st->head != NULL){
    UnorderST_node* temp = st->head;
    st->head = st->head->next;
    Free(temp);
  }
  st->size = 0;
}

/***********************************************************************
* ORDERED ARRAY SEARCH.
***********************************************************************/
void _OrderedST_exchange(Element* array, int i, int j){
  Element temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int _modified_OrderedST_rank(OrderedST* ost, int key){
  int low = 0;
  int high = ost->size-1;
  Element* array = ost->array;

  while (low <= high){                                                          
    int mid = low + (high - low)/2;
    if (key < array[mid].key){
      high = mid - 1;
    }
    else if (key > array[mid].key){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return low;
}


void OrderedST_init(OrderedST* ost, int capacity){
  ost->array = (Element* )Malloc(sizeof(Element)*capacity);
  ost->size = 0;
  ost->capacity = capacity;
}

int OrderedST_rank(OrderedST* ost, int key){
  int low = 0;
  int high = ost->size-1;
  Element* array = ost->array;

  while (low <= high){
    int mid = low + (high - low)/2;
    if (key < array[mid].key){
      high = mid - 1;
    }
    else if (key > array[mid].key){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

char* OrderedST_get(OrderedST* ost, int key){
  int index = OrderedST_rank(ost, key);
  if (ost->size == 0 || index == -1) return NULL;
  else return ost->array[index].value;
}

void OrderedST_put(OrderedST* ost, int key, char* value){
  if (ost->size == ost->capacity){
    printf("OrderedST: ERROR, cannot put, capacity FULL\n");
    exit(EXIT_FAILURE);
  }
  int index = OrderedST_rank(ost, key);
  if (index != -1){
    ost->array[index].value = value;
  }
  else{
    int j = ost->size - 1;
    ost->array[j+1].key = key;
    ost->array[j+1].value = value;

    while (j >=0 && ost->array[j+1].key < ost->array[j].key){
      _OrderedST_exchange(ost->array, j, j+1);
      j--;
    }
    ost->size += 1;
  }
}

void OrderedST_delete(OrderedST* ost, int key){
  int index = OrderedST_rank(ost, key);
  if (index == -1){
    printf("OrderedST: ERROR, key not found, cannot delete\n");
    return;
  }
  for(int i = index; i < ost->size-1; i++){
    ost->array[i] = ost->array[i+1];
  }
  ost->size -= 1;
}


bool OrderedST_contains(OrderedST* ost, int key){
int rank = OrderedST_rank(ost, key);
return (rank != -1);
}

bool OrderedST_isEmpty(OrderedST* ost){
return (ost->size == 0);
}

int OrderedST_size(OrderedST* ost){
return ost->size;
}

int OrderedST_min(OrderedST* ost){
return ost->array[0].key;
}

int OrderedST_max(OrderedST* ost){
return ost->array[ost->size-1].key;
}

int OrderedST_floor(OrderedST* ost, int key){
  int rank = _modified_OrderedST_rank(ost, key);
  if (rank >= ost->size){
    printf("OrderedST: Floor ERROR, key not present\n");
    return -1;
  }
  return ost->array[rank-1].key;
}

int OrderedST_ceiling(OrderedST* ost, int key){
  int rank = _modified_OrderedST_rank(ost, key);
  if (rank >= ost->size ){
    printf("OrderedST: Ceiling ERROR, key not present\n");
    return -1;
  }
  return ost->array[rank].key;
}


int OrderedST_select(OrderedST* ost, int k){
  return ost->array[k].key;
}

int OrderedST_no_of_keys(OrderedST* ost, int low_key, int high_key){
  int rank_low = OrderedST_rank(ost, low_key);
  int rank_high = OrderedST_rank(ost, high_key);
  return (rank_high - rank_low)+1;
}

void OrderedST_deleteMin(OrderedST* ost){
  OrderedST_delete(ost, ost->array[0].key);
}

void OrderedST_deleteMax(OrderedST* ost){
  if (ost->size == 0){
    printf("OrderedST: deleteMax ERROR, symbol table empty\n");
  }
  else{
    ost->size -= 1;
  }
}

void OrderedST_show(OrderedST* ost){
  printf("OrderedST: {");
  for (int i = 0; i < ost->size; i++){
    printf("(%d, %s), ", ost->array[i].key, ost->array[i].value);
  }
  printf("}\n");
}

void OrderedST_destroy(OrderedST* ost){
  Free(ost->array);
  ost->size = 0;
  ost->capacity = 0;
}
