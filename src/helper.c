#include "helper.h"

void* Malloc(size_t size){
    void* memory = malloc(size);
    if (memory == NULL){
        printf("ERROR: Memory allcoation failed\n");
        exit(EXIT_FAILURE);
    }
    return memory;
}

void Free(void* ptr){
    free(ptr);
}

void ShowArray(int* array, int length, char* sort_name){
    printf("%s: ", sort_name);
    for (int i = 0; i < length; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void Randomly_fill_array(int* array, int length){
    printf("Array: ");
    for (int i = 0; i < length; i++){
        array[i] = Random_integer(-1000, 1000);
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int Random_integer(int low, int high){
    double d = rand() / ((double)RAND_MAX + 1);
    double scale = d * ((double)high - low + 1);
    return (int)(floor(scale + low));
}

void Shuffle_array(int* array, int length){
    for (int i = 0; i < length; i++){
        int random_index = Random_integer(0, i);
        int temp = array[random_index];
        array[random_index] = array[i];
        array[i] = temp;
    }
}

double CPU_time_taken(clock_t begin){
    clock_t end = clock();
    return (end - begin)/(double)CLOCKS_PER_SEC;
}
 
int min(int x, int y){
    return (x < y) ? x: y;
}

void exchange(int* array, int x, int y){
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

