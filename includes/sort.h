 /**@file sort.h
 * @brief Sorting Algorithms Interface.
 *
 * It covers following sorting algorithms:
 * @see selection_sort
 * @see insertion_sort
 * @see shell_sort
 * @see merge_sort
 * @see optimized_merge_sort
 * @see bottom_up_merge_sort
 * @see quick_sort
 * @see optimized_quick_sort
 * @see quick_sort_3_way
 * @see heap_sort
 *
 * @author Gagaron
 * @note All the sorting function only support <b>INTEGER</b> type only.
 */

#ifndef _SORT_H
#define _SORT_H

/**
 * @brief SELECTION SORT.
 *
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(n^2)
 * Average case(array is partially sorted)  : O(n^2)
 * Best case   (array is already sorted)    : O(n^2)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * selection_sort(array, array_length);
 * @endcode
 */
void selection_sort(int* array, int array_length);

/**
 * @brief INSERTION SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(n^2)
 * Average case(array is partially sorted)  : O(n^2)
 * Best case   (array is already sorted)    : O(n)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * insertion_sort(array, array_length);
 * @endcode
 */
void insertion_sort(int* array, int array_length);

/**
 * @brief SHELL SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : NA
 * Average case(array is partially sorted)  : NA
 * Best case   (array is already sorted)    : O(n)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * shell_sort(array, array_length);
 * @endcode
 */
void shell_sort(int* array, int array_length);

/**
 * @brief MERGE SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(nlgn)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * merge_sort(array, array_length);
 * @endcode
 */
void merge_sort(int* array, int array_length);

/**
 * @brief OPTIMIZE MERGE SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(nlgn)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * optimize_merge_sort(array, array_length);
 * @endcode
 */
void optimize_merge_sort(int* array, int array_length);

/**
 * @brief BOTTOM UP MERGE SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(nlgn)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * bottom_up_merge_sort(array, array_length);
 * @endcode
 */
void bottom_up_merge_sort(int* array, int array_length);

/**
 * @brief QUICK SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(n^2)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * quick_sort(array, array_length);
 * @endcode
 */
void quick_sort(int* array, int array_length);

/**
 * @brief OPTIMIZE QUICK SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(n^2)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * optimize_quick_sort(array, array_length);
 * @endcode
 */
void optimize_quick_sort(int* array, int array_length);

/**
 * @brief 3-WAY QUICK SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(n^2)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(n)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * quick_sort_3_way(array, array_length);
 * @endcode
 */
void quick_sort_3_way(int* array, int array_length);

/**
 * @brief HEAP SORT.
 * Time Complexity:
 * Worst case  (array is reverse sorted)    : O(nlgn)
 * Average case(array is partially sorted)  : O(nlgn)
 * Best case   (array is already sorted)    : O(nlgn)
 *
 * @param array Pointer to array of integers.
 * @param array_length Length of array of intergers.
 * @return void.
 * @code
 * heap_sort(array, array_length);
 * @endcode
 */
void heap_sort(int* array, int array_length);                                                           
#endif
