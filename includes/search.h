/**@file search.h
 * @brief Search Algorithms Interface.
 *
 * It covers following search algorithms:
 * @see binary_search
 * 
 * @author Gagaron
 * @note All search algorithms only support <b>INTEGER</b> type key and 
 * <b>STRING</b> type value , (key, value) pair.
 */

#ifndef _SEARCH_H
#define _SEARCH_H

#include<stdbool.h>
#include<stdlib.h>
#include"helper.h"

/**
 * @brief BINARY SEARCH
 * 
 * Time Complexity:
 * all cases : O(lgn)
 *
 * @param array Pointer to array of integers.
 * @param length Length of array of integers.
 * @param key The integer value to search in array.
 * @return The index of the key in the array if found, else -1.
 * @code 
 * int index = binary_search(array, length, key);
 * @endcode
 */
int binary_search(int* array, int length, int key);

/**
 * @brief SEQUENTIAL SEARCH SYMBOL TABLE
 * This data structure is single link list, with each node as key-value pair.
 */

/**
 * @brief Definition of Node in Sequential search symbol table.
 */
typedef struct _SequentialSeachST_node{
  int key;       /**< Node containing interger Key. */
  char* value;   /**< Node containing string value corresponding to Key */
  struct _SequentialSeachST_node* next; /**< Pointer of type self pointing to next node in list */
} UnorderST_node;

/**
 * @brief Definition of Sequential search symbol table.
 */
typedef struct _SequentialSearchST{
  UnorderST_node* head;  /**< Head poniter to the start of the single link list */
  int size;    /**< The size of Single link list (Sequential Symbol table) */
} UnorderST;

/**
 * @brief This funtion initial the symbol table with NULL pointer for head and size 0, 
 * in #UnorderST
 * 
 * @param st pointer to symbol table structure #UnorderST.
 * @return Void.
 * @code
 * UnorderST_init(&st);
 * @endcode
 */
void UnorderST_init(UnorderST* st);

/**
 * @brief This function puts the (key, value) pair in the symbol table.
 * 
 * Time complexity: O(1), as it just append the node in front.
 *
 * @param st pointer to symbol table structure #UnorderST
 * @param key  Key to be inserted in the symbol table.
 * @param value Value to reference corresponding to the key.
 * @return Void.
 * @code 
 * UnorderST_put(&st, key, value);
 * @endcode
 */
void UnorderST_put(UnorderST* st, int key, char* value);

/**
 * @brief This function gets the value corresponding to give key.
 * 
 * Time complexity : O(n).
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @param key Key to be inserted in symbol table.
 * @return string value corresponding to the given key.
 * @code
 * char * value = UnorderST_get(&st, key);
 * @endcode
 * 
 */ 
char* UnorderST_get(UnorderST* st, int key);

/**
 * @brief This function deletes the given node with (key, value) pair.
 * 
 * Time complexity : O(n)
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @param key Key to be deleted from the symbol table.
 * @return Void
 * @code
 * UnorderST_delete(&st, key);
 * @endcode
 */
void UnorderST_delete(UnorderST* st, int key);

/**
 * @brief This function checks if given key is in symbol table.
 * 
 * Time complexity : O(n)
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @param key Key to be checked in symbol table.
 * @return boolean  value true if key is in table else return false.
 * @code
 * bool val = UnordereST_contains(&st, key);
 * @endcode
 */ 
bool UnorderST_contains(UnorderST* st, int key);

/**
 * @brief This function checks if symbol table is empty.
 * 
 * Time complexity: O(1)
 * 
 * @param st pointer to symbol table structure #UnorderST.
 * @return boolean  value true if table is empty else return false.
 * @code 
 * bool val = UnorderedST_isEmpty(&st);
 * @endcode
 */ 
bool UnorderST_isEmpty(UnorderST* st);

/**
 * @brief This function returns the size of symbol table.
 * 
 * Time complexity: O(1)
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @return integer value representing the size of symbol table
 * @code 
 * int size = UnorderST_size(&st);
 * @endcode
 */ 
int UnorderST_size(UnorderST* st);

/**
 * @brief This function iterates the symbol table and display all the key-value pair.
 * 
 * Time complexity: O(n)
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @return Void
 * @code
 * UnorderST_show(&st);
 * @endcode
 */ 
void UnorderST_show(UnorderST* st);

/**
 * @brief This function deletes all the entries of symbol table and free memory to heap.
 * 
 * Time complexity: O(n)
 *
 * @param st pointer to symbol table structure #UnorderST.
 * @return Void
 * @code 
 * UnorderST_destroy(&st);
 * @endcode
 */
void UnorderST_destroy(UnorderST* st);


typedef struct _OrderedArrayElement{
  int key;
  char* value;
} Element;

typedef struct _OrderedArrayST{
  Element* array;
  int size;
  int capacity;
} OrderedST;

void OrderedST_init(OrderedST* ost, int capacity);
int OrderedST_rank(OrderedST* ost, int key);
char* OrderedST_get(OrderedST* ost, int key);
void OrderedST_put(OrderedST* ost, int key, char* value);
void OrderedST_delete(OrderedST* ost, int key);
bool OrderedST_contains(OrderedST* ost, int key);
bool OrderedST_isEmpty(OrderedST* ost);
int OrderedST_size(OrderedST* ost);
int OrderedST_min(OrderedST* ost);
int OrderedST_max(OrderedST* ost);
int OrderedST_floor(OrderedST* ost, int key);
int OrderedST_ceiling(OrderedST* ost, int key);
int OrderedST_select(OrderedST* ost, int k);
int OrderedST_no_of_keys(OrderedST* ost, int low_key, int high_key);
void OrderedST_deleteMin(OrderedST* ost);
void OrderedST_deleteMax(OrderedST* ost);
void OrderedST_show(OrderedST* ost);
void OrderedST_destroy(OrderedST* ost);

/**
 * @brief BINARY SEARCH TREE SYMBOL TABLE.
 * This symbol table implementation uses binary search tree to store 
 * key value pair.
 */

typedef struct _Binary_search_tree_node{
  int key;
  char* value;
  int size;
  struct _Binary_search_tree_node* left;
  struct _Binary_search_tree_node* right;
} BST_node;

typedef struct _Binary_search_tree{
  BST_node* root;
} BST;

void BST_init(BST* tree);
char* BST_get_recursive(BST* tree, int key);
char* BST_get_iterative(BST* tree, int key);
int BST_get_min_key(BST* tree);
int BST_get_max_key(BST* tree);
void BST_insert_recursive(BST* tree, int key, char* value);
void BST_insert_iterative(BST* tree, int key, char* value);
void BST_delete_min_recursive(BST* tree);
void BST_delete_min_iterative(BST* tree);
void BST_delete_max_recursive(BST* tree);
void BST_delete_max_iterative(BST* tree);
void BST_delete_recursive(BST* tree, int key);
int BST_tree_height(BST* tree);
void BST_show(BST* tree);
void BST_destroy(BST* tree);

#endif
