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


/****************************************************************
 * BINARY SEARCH TREE.
 ****************************************************************/
/*************************************************
 * BST_INIT: This function initialize the BST.
 ************************************************/
void BST_init(BST* tree){
  tree->root = NULL;
}

/***************************************************
 * BST_SIZE: This function returns the size of tree.
 ***************************************************/ 
int _BST_size(BST_node* root){
  if (root == NULL) return 0;
  return root->size;
}

int BST_size(BST* tree){
  return _BST_size(tree->root);
}

/********************************************************
 * BST_GET_RECURSIVE: This reture the value for the key.
 ********************************************************/
BST_node* _BST_get_recursive(BST_node* node, int key){
  if (node == NULL){
    return NULL;
  }
  if (key < node->key) return _BST_get_recursive(node->left, key);
  else if (key > node->key) return _BST_get_recursive(node->right, key);
  else return node;
}

char* BST_get_recursive(BST* tree, int key){
  BST_node* node = _BST_get_recursive(tree->root, key);
  if (node == NULL){
    printf("BST: ERROR, key not present in tree \n");
    return NULL;
  }
  else{
    return node->value;
  }
}
/****************************************************************
 * BST_GET_ITERATIVE: The iterative version of BST_GET_RECURSIVE
 ****************************************************************/
char* BST_get_iterative(BST* tree, int key){
  BST_node* root = tree->root;

  while (root != NULL){
    if (key < root->key) root = root->left;
    else if (key > root->key) root = root->right;
    else return root->value;
  }
  printf("BST:ERROR, key not present in tree\n");
  return NULL;
}
/*******************************************************************
 * BST_GET_MIN_KEY: This function get the minimum key value from the BST.
 ********************************************************************/
BST_node* _BST_get_min_key(BST_node* root){
  if (root->left == NULL){
    return root;
  }
  return  _BST_get_min_key(root->left);
}

int BST_get_min_key(BST* tree){
  if (tree->root == NULL){
    printf("BST: ERROR, get from empty tree, returning -1\n");
    return -1;
  }
  return _BST_get_min_key(tree->root)->key;
}

/**********************************************************************
 * BST_GET_MAX_KEY: This function get the maximum key value from the BST.
 ************************************************************************/
BST_node* _BST_get_max_key(BST_node* root){
  if (root->right == NULL) return root;
  return _BST_get_max_key(root->right);
}

int BST_get_max_key(BST* tree){
  if (tree->root == NULL){
    printf("BST: ERROR, get from empty tree, returning -1\n");
    return -1;
  }
  return _BST_get_max_key(tree->root)->key;
}
/****************************************************************************
 * BST_INSERT_RECURSIVE: This function insert new key or update existing key.
 ****************************************************************************/
BST_node* _BST_insert_recursive(BST_node* root, int key, char* value){
  if (root == NULL){
    BST_node* node = (BST_node* )Malloc(sizeof(BST_node));
    node->key = key;
    node->value = value;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
  }
  if (key < root->key) root->left = _BST_insert_recursive(root->left, key, value);
  else if (key > root->key) root->right = _BST_insert_recursive(root->right, key, value);
  else root->value = value;

  root->size = _BST_size(root->left) + _BST_size(root->right) + 1;
  return root;
}

void BST_insert_recursive(BST* tree, int key, char* value){
  tree->root = _BST_insert_recursive(tree->root, key, value);
}

/*********************************************************************
 * BST_INSERT_ITERATIVE: The iterative version of BST_INSERT_RECURSIVE.
 **********************************************************************/
void BST_insert_iterative(BST* tree, int key, char* value){
  BST_node* root = tree->root;
  BST_node* parent_of_root = NULL;
  while (root != NULL){
    if (key < root->key ){
      parent_of_root = root;
      root = root->left;
    }
    else if (key > root->key) {
      parent_of_root = root;
      root = root->right;
    }
    else{
      root->value = value;
      return;
    }
  }
  BST_node* node = (BST_node* )Malloc(sizeof(BST_node));
  node->key = key;
  node->value = value;
  node->size = 1;
  node->left = NULL;
  node->right = NULL;
  if (parent_of_root == NULL) tree->root = node;
  else {
    if (key < parent_of_root->key) parent_of_root->left  = node;
    else parent_of_root->right = node;
  }

  root = tree->root;
  while (root != node){
    root->size += 1;
    if (key < root->key) root = root->left;
    else if (key > root->key) root = root->right;
    else break;
  }
}

/*******************************************************************
 * BST_DELETE_MIN_RECURSIVE: This deletes the minimum key in the BST.
 ********************************************************************/
BST_node* _BST_delete_min_recursive(BST_node* root){
  if (root->left == NULL){
    BST_node* temp = root->right;
    Free(root);
    return temp;
  }
  root->left = _BST_delete_min_recursive(root->left);
  root->size = _BST_size(root->left) + _BST_size(root->right) + 1;
  return root;
}

void BST_delete_min_recursive(BST* tree){
  if (tree->root == NULL){
    printf("BST: ERROR, Empty tree - deletion not possible\n");
    return;
  }
  tree->root = _BST_delete_min_recursive(tree->root);
}

/*********************************************************************************
 * BST_DELETE_MIN_ITERATIVE: This is iterative verison of BST_DELETE_MIN_RECURSIVE.
 **********************************************************************************/
void BST_delete_min_iterative(BST* tree){
  BST_node* root = tree->root;
  BST_node* parent_of_root = NULL;
  if (root == NULL) return;

  while(root->left != NULL){
    parent_of_root = root;
    root = root->left;
  }
  BST_node* temp = root->right;
  if (parent_of_root != NULL) parent_of_root->left = temp;
  else tree->root = temp;
  Free(root);

  BST_node* update_root = tree->root;
  while ((parent_of_root != NULL) && (update_root != temp)){
    update_root->size -= 1;
    update_root = update_root->left;
  }
}

/****************************************************************************
 * BST_DELETE_MAX_RECURSIVE: This function deletes the maximum key from BST.
 ****************************************************************************/
BST_node* _BST_delete_max_recursive(BST_node* root){
  if (root->right == NULL) {
    BST_node* temp = root->left;
    Free(root);
    return temp;
  }
  root->right = _BST_delete_max_recursive(root->right);
  root->size = _BST_size(root->left) + _BST_size(root->right) + 1;
  return root;
}

void BST_delete_max_recursive(BST* tree){
  if (tree->root == NULL){
    printf("BST: ERROR, empty tree, deletion not possible\n");
    return;
  }
  tree->root = _BST_delete_max_recursive(tree->root);
}

/*********************************************************************************
 * BST_DELETE_MAX_ITERATIVE: This is iterative version of BST_DELETE_MAX_RECURSIVE.
 **********************************************************************************/
void BST_delete_max_iterative(BST* tree){
  BST_node* root = tree->root;
  BST_node* parent_of_root = NULL;
  if (root == NULL) return;

  while(root->right != NULL){
    parent_of_root = root;
    root = root->right;
  }
  BST_node* temp = root->left;
  if (parent_of_root != NULL) parent_of_root->right = temp;
  else tree->root = temp;
  Free(root);

  BST_node* update_root = tree->root;
  while ((parent_of_root != NULL) && (update_root != temp)){
    update_root->size -= 1;
    update_root = update_root->right;
  }
}

/**************************************************************************
 * BST_DELETE_RECURSIVE: This function deletes any node with key.
 *************************************************************************/
BST_node* _BST_delete_recursive(BST_node* root, int key){
  if (root == NULL) return NULL;
  if (key < root->key) root->left = _BST_delete_recursive(root->left, key);
  else if (key > root->key) root->right = _BST_delete_recursive(root->right, key);
  else {
    if (root->left == NULL){
      BST_node* temp = root->right;
      Free(root);
      return temp;
    }
    if (root->right == NULL) {
      BST_node* temp = root->left;
      Free(root);
      return temp;
    }
    BST_node* succ = _BST_get_min_key(root->right);
    root->key = succ->key;
    root->value = succ->value;
    root->right = _BST_delete_min_recursive(root->right);
  }
  root->size = _BST_size(root->left) + _BST_size(root->right) + 1;
  return root;
}

void BST_delete_recursive(BST* tree, int key){
  if (tree->root == NULL){
    printf("BST: ERROR, deleting from empty tree\n");
    return;
  }
  tree->root = _BST_delete_recursive(tree->root, key);
}

/*************************************************************************
 * BST_TREE_HEIGHT: This will find the height of the tree.
 *************************************************************************/
int _BST_tree_height(BST_node* root){
  if (root == NULL) return -1;
  int max;
  int left_height = _BST_tree_height(root->left);
  int right_height = _BST_tree_height(root->right);
  if (left_height > right_height) max = left_height;
  else max = right_height;
  return (max + 1);
}

int BST_tree_height(BST* tree){
  return _BST_tree_height(tree->root);
}

/*************************************************************************
 * BST_SHOW: will display tree in ascending order with inorder traversal.
 **************************************************************************/
void _BST_show(BST_node* root){
  if (root == NULL) return;
  _BST_show(root->left);
  printf("     Node: key[%d]->value[%s] size[%d] childnode-(left, right)-> (%d, %d)\n", \
         root->key, root->value, root->size, ((root->left != NULL)?root->left->key:-1), ((root->right != NULL)?root->right->key:-1));
  _BST_show(root->right);
}

void BST_show(BST* tree){
  printf("BST: { \n");
  _BST_show(tree->root);
  printf("  }\n");
}
/*************************************************************
 * BST_DESTROY: This will destroy the tree(deleting all nodes.
 ************************************************************/
void BST_destroy(BST* tree){
  if (tree->root == NULL) {
    printf("BST: ERROR, empty tree.Cannot destroy\n");
    return;
  }

  while (tree->root != NULL){
    BST_delete_min_recursive(tree);
  }
}

