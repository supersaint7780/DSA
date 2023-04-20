#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector createVector() {
    int *array = (int *)calloc(DEFAULT_VECTOR_CAPACITY, sizeof(int));
    if(array != NULL) {
        Vector vector = (Vector)malloc(sizeof(struct dynamic_array));

        if(vector != NULL) {
            vector->array = array;
            vector->capacity = DEFAULT_VECTOR_CAPACITY;
            vector->size = 0;
            return vector;
        } else {
            fprintf(stderr, "Memory Allocation Failed\n");
            exit(EXIT_FAILURE);
        }

    } else {
        fprintf(stderr, "Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
}

int size(Vector vector) {
    return vector->size;
}

int capacity(Vector vector) {
    return vector->capacity;
}

int is_empty(Vector vector) {
    if(vector->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int at(Vector vector, int index) {
    if(is_empty(vector)) {
        fprintf(stderr, "Vector is empty\n");
        exit(EXIT_FAILURE);
    } else if(index >= vector->size) {
        fprintf(stderr, "Index Out of Bounds for %d of %d\n", index, vector->size);
        exit(EXIT_FAILURE);
    } else {
        return vector->array[index];
    }
}

void push(Vector vector, int item) {
    if(vector->size == vector->capacity) {
        resize(vector, vector->capacity*2);
    }
    vector->array[vector->size] = item;
    vector->size++;
}

int pop(Vector vector) {
    if(is_empty(vector)) {
        return -1;
    } else {
        int element = vector->array[vector->size-1];
        vector->array[vector->size-1] = 0;
        vector->size = vector->size - 1;
        if(vector->size == (vector->capacity)/4) {
            printf("size:%d capacity:%d\n", vector->size, vector->capacity);
            resize(vector, (vector->capacity)/2);
        }
        return element;
    }
}

int find(Vector vector, int item) {
    if(vector->size != 0) {
        for(int i=0;i<vector->size;i++) {
            if(vector->array[i] == item) {
                return i;
            }
        }
    }
    return -1;
}

void insert(Vector vector, int index, int item) {
    if(vector->size == vector->capacity) {
        resize(vector, vector->capacity*2);
    }
    for(int i=vector->size;i>index;i--) {
        vector->array[i] = vector->array[i-1];
    }
    vector->array[index] = item;
}

void prepend(Vector vector, int item) {
    insert(vector, 0, item);
}

void deleteIndex(Vector vector, int index) {
    if(index >= vector->size) {
        fprintf(stderr, "Index Out of Bounds for deletion\n");
        exit(EXIT_FAILURE);
    } else {
        for(int i=index;i<vector->size;i++) {
            vector->array[i] = vector->array[i+1];
        }
        vector->array[vector->size-1] = 0;
        vector->size--;

        if(vector->size == (vector->capacity)/4) {
            printf("size:%d capacity:%d\n", vector->size, vector->capacity);
            resize(vector, (vector->capacity)/2);
        }
    }
}

void delete(Vector vector, int item) {
    int item_index = find(vector, item);
    if(item_index == -1) {
        fprintf(stderr, "Element not present in the vector\n");
        exit(EXIT_FAILURE);
    } else {
        deleteIndex(vector, item_index);
    }
}

void resize(Vector vector, int capacity) {
    if(capacity == 0) {
        fprintf(stderr, "Error: Cannot resize the vector to 0 capacity\n");
        exit(EXIT_FAILURE);
    } else if(vector->capacity == capacity) {
        return;
    } else {
        int *resized_array = (int *)calloc(capacity, sizeof(int));

        int cap = (vector->capacity > capacity) ? capacity : vector->size;
        for(int i=0;i<cap;i++) {
            resized_array[i] = vector->array[i];
        }
        free(vector->array);
        
        if(vector->size > capacity) {
            vector->size = capacity;
        }
        vector->array = resized_array;
        vector->capacity = capacity;
    }
}

void printVector(Vector vector) {
    printf("[");
    for(int i=0;i<vector->size-1;i++) {
        printf("%d, ",at(vector, i));
    }
    printf("%d]\n", at(vector, size(vector)-1));
} 

void freeVector(Vector vector) {
    free(vector->array);
    free(vector); 
}