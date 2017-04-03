#include "sort.h"
#include "helper.h"
#include<stdio.h>

/***************************************************
* SELECTION SORT private implementation.
***************************************************/
void selection_sort(int* array, int length){
    for (int i = 0; i < length; i++){
        int min = i;
        for (int j = i+1; j < length; j++){
            if (array[j] < array[min]){
                min = j;
            }
            exchange(array, i, min);
        }
    }
}

/***************************************************
* INSERTION SORT private implementation.
***************************************************/
void insertion_sort(int* array, int length){
    for (int i = 1; i < length;i++){
        for (int j = i; j > 0 && (array[j] < array[j-1]) ; j--){
            exchange(array, j, j-1);
        }
    }
}
 
/***************************************************
* SHELL SORT private implementation.
***************************************************/
void shell_sort(int* array, int length){
    int h = 1;
    while (h < length/3){
        h = 3 * h + 1;
    }
    while (h >= 1){
        for (int i = h; i < length; i++){
            for (int j = i; j >= h && array[j] < array[j-h]; j -= h){
                exchange(array, j, j-h);
            }
        }
        h = h/3;
    }
}

/********************************************************
* MERGE SORT private implementation.
********************************************************/
void _merge(int* array, int* aux, int low, int mid, int high){
    for (int i = low; i <= high; i++){
        aux[i] = array[i];
    }
    for (int k = low, i = low, j = mid+1; k <= high; k++){
        if (i > mid){
            array[k] = aux[j++];
        }
        else if (j > high){
            array[k] = aux[i++];
        }
        else if (aux[i] < aux[j]){
            array[k] = aux[i++];
        }
        else{
            array[k] = aux[j++];
        }
    }
}

void _merge_sort(int* array, int* aux, int low, int high){
    if (low >= high) return;
    int mid = low + (high - low)/2;
    _merge_sort(array, aux, low, mid);
    _merge_sort(array, aux, mid+1, high);
    _merge(array, aux, low, mid, high);
}

void merge_sort(int* array, int length){
    int aux[length];
    _merge_sort(array, aux, 0, length-1);
}

/**********************************************************
* OPTIMIZED_MERGE_SORT private implementation
**********************************************************/
void _helper_insertion_sort(int* array, int low, int high){
    for (int i = low+1; i <= high;i++){
        for (int j = i; j > low && (array[j] < array[j-1]) ; j--){
            exchange(array, j, j-1);                                            
        }
    }
}

void _optimize_merge_sort(int* array, int* aux, int low, int high){
    if (low >= high) return;
    if ((high - low) < 15){
        _helper_insertion_sort(array, low, high);
        return;
    }
    int mid = low + (high - low)/2;
    _optimize_merge_sort(array, aux, low, mid);
    _optimize_merge_sort(array, aux, mid+1, high);
    if (array[mid] < array[mid+1]){
        return;
    }
    _merge(array, aux, low, mid, high);
}

void optimize_merge_sort(int* array, int length){
    int aux[length];
    _optimize_merge_sort(array, aux, 0, length-1);
}

/***************************************************************
 * BOTTOM_UP_MERGE_SORT private implementation.
 ***************************************************************/
void bottom_up_merge_sort(int* array, int length){
    int aux[length];
    for (int size = 1; size < length; size = 2*size){
        for (int low = 0; low < length - size; low += 2 * size){
            _merge(array, aux, low, low+size-1, min(low+size+size-1, length-1));
        }
    }
}

/***************************************************************
* QUICK_SORT private implementation.
***************************************************************/
int _partition(int* array, int low, int high){
    int k = low;
    int i = low+1;
    int j = high;
    while (true){
        while (array[i] < array[k]){
            i++;
            if (i == high+1) break;
        }
        while (array[j] > array[k]){
            j--;
            if (j == low) break;
        }
        if (i >= j) break;
        exchange(array, i, j);
    }
    exchange(array, k, j);
    return j;
}

void _quick_sort(int* array, int low, int high){
    if (low >= high) return;
    int partition_index = _partition(array, low, high);
    _quick_sort(array, low, partition_index-1);
    _quick_sort(array, partition_index+1, high);
}

void quick_sort(int* array, int length){
    Shuffle_array(array, length);
    _quick_sort(array, 0, length-1);
}

/*****************************************************
 * OPTIMIZE_QUICK_SORT private implementation.
 *****************************************************/
void _optimize_quick_sort(int* array, int low, int high){
    if (low >= high) return;
    if ((high - low) < 10){
        _helper_insertion_sort(array, low, high);
        return;
    }
    int partition_index = _partition(array, low, high);
    _optimize_quick_sort(array, low, partition_index-1);
    _optimize_quick_sort(array, partition_index+1, high);
}

void optimize_quick_sort(int* array, int length){
    Shuffle_array(array, length);
    _optimize_quick_sort(array, 0, length-1);
}

/*****************************************************
* QUICK_SORT_3_WAY private implementation.
*****************************************************/
void _quick_sort_3_way(int* array, int low, int high){
    if (low >= high) return;
    int v = array[low];
    int less_than_v = low;
    int greater_than_v = high;
    int index = low+1;
    while (index <= greater_than_v){
        if (array[index] < v){
            exchange(array, less_than_v, index);
            index++;
            less_than_v++;
        }
        else if (array[index] > v){
            exchange(array, greater_than_v, index);
            greater_than_v--;
        }
        else{
            index++;
        }
    }
    _quick_sort_3_way(array, low, less_than_v-1);
    _quick_sort_3_way(array, greater_than_v+1, high);
}

void quick_sort_3_way(int* array, int length){
    Shuffle_array(array, length);
    _quick_sort_3_way(array, 0, length-1);
}
