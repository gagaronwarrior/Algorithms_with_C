#ifndef _HELPER_H
#define _HELPER_H

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

void* Malloc(size_t size);
void Free(void* ptr);
void ShowArray(int* array, int array_length, char* sort_name);
void Randomly_fill_array(int* array, int array_length);
int Random_integer(int low, int high);
void Shuffle_array(int* array, int length);
double CPU_time_taken(clock_t start_time);
int min(int x, int y);
#endif
