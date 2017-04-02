#ifndef _SORT_H
#define _SORT_H

void exchange(int* array, int index_x, int index_y);

/****************************************************
* SELECTION SORT public interface.
****************************************************/
void selection_sort(int* array, int array_length);

/**************************************************
* INSERTION_SORT public interface.
**************************************************/
void insertion_sort(int* array, int array_length);

/*************************************************
* SHELL_SORT public interface.
*************************************************/
void shell_sort(int* array, int array_length);

/***********************************************
* MERGE SORT public interface.
***********************************************/
void merge_sort(int* array, int array_length);

/***********************************************
* OPTIMIZE MERGE SORT public interface.
***********************************************/
void optimize_merge_sort(int* array, int array_length);

/*********************************************
* BOTTOM_UP_MERGE_SORT public interface.
*********************************************/
void bottom_up_merge_sort(int* array, int array_length);

/******************************************************
* QUICK_SORT public interface.
******************************************************/
void quick_sort(int* array, int array_length);

/****************************************************
* OPTIMIZE_QUICK_SORT public interface.
****************************************************/
void optimize_quick_sort(int* array, int array_length);

/****************************************************
* 3_WAY__QUICK_SORT public interface.
****************************************************/
void quick_sort_3_way(int* array, int array_length);
                                                           
#endif
