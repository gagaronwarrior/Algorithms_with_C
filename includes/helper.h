/** @file helper.h
 * @brief This file contains the helper functions.
 *
 * These function assist main algorithms.
 * These are not part of main algorithms but abstract things,
 * so that algorithm looks clean and readable.
 *
 * @author Gagaron
 */

#ifndef _HELPER_H
#define _HELPER_H

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

/**
 * @brief Malloc
 * This is wrapper function on stdlib.h malloc.
 * If malloc fails ( returns NULL), then prints error message,and
 * exit.
 *
 * @param size size in bytes to allocate.
 * @return pointer to starting of memory block allocated.
 * @code
 * int* x = (int* )Malloc(size);
 * @endcode
 *
 */
void* Malloc(size_t size);

/**
 * @brief Free
 * This is wrapper function on stdlib.h free.
 *
 * @param ptr pointer to the memory block to free.
 * @return Void.
 * @code
 * Free(ptr);
 * @endcode
 *
 */
void Free(void* ptr);

/**
 * @brief ShowArray
 * This function print the array content to the console.
 * It is used to display the content of sorted array.
 * 
 * @param array  Pointer to the array of integers.
 * @param array_length  Length of the array of integers.
 * @param sort_name  Pointer to string, displaying the sorting name.
 * @return Void.

 * @code
 * ShowArray(array, array_length, sort_name);
 * @endcode
 *
 */
void ShowArray(int* array, int array_length, char* sort_name);

/**
 * @brief Randomly_fill_array
 * This function fills the array with random integers within 
 * range of [-1000, 1000].
 * 
 * @param array Pointer to the array of integers.
 * @param array_length Length of the array of integers.
 * @return Void.

 * @code
 * Randomly_fill_array(array, array_length);
 * @endcode
 *
 */
void Randomly_fill_array(int* array, int array_length);

/**
 * @brief Random_integer
 * This function returns the random integer in the specified range.
 * 
 * @param low  lower limit of range.
 * @param high Upper limit of range.
 * @return random integer within (low, high).

 * @code
 * int i = Random_integer(low, high);
 * @endcode
 *
 */
int Random_integer(int low, int high);

/**
 * @brief Shuffle_array
 * This function randomly shuffle array and distribute elements,
 * uniformily.
 * 
 * @param array pointer to the array of integers.
 * @param array_length length of array of integers.
 * @return Void

 * @code
 * Shuffle_array(array, array_length);
 * @endcode
 *
 */
void Shuffle_array(int* array, int array_length);

/**
 * @brief CPU_time_taken
 * This function returns the differnce between the start time and 
 * current time, taken by CPU in seconds.
 * 
 * @param start_time start time.
 * @return double value of time difference in seconds.

 * @code
 * double diff = CPU_time_taken(start_time);
 * @endcode
 *
 */
double CPU_time_taken(clock_t start_time);

/**
 * @brief min
 * This function returns the minimum of the two specified values.
 * 
 * @param x first value
 * @param y second value.
 * @return integer.

 * @code
 * int i = min(x, y);
 * @endcode
 *
 */
int min(int x, int y);

/**
 * @brief exchange
 * This function exchange the content of two indexes in array.
 * 
 * @param array pointer to the array of integers.
 * @param x index in array.
 * @param y another index in array.
 * @return Void.

 * @code
 * exchnage(array, x, y);
 * @endcode
 *
 */
void exchange(int* array, int x, int y);

#endif
