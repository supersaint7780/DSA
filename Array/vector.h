#ifndef VECTOR_H
#define VECTOR_H

// all vector will have default capacity of 16
#define DEFAULT_VECTOR_CAPACITY 16

struct dynamic_array{
    int size;
    int capacity;
    int *array;
};

// Vector is the pointer to the dynamic_array struct it makes it
// easy to pass the dynamic_array to function and manipulate it
typedef struct dynamic_array* Vector;

// function returns a vector of default size 16
Vector createVector();

// function takes vector as input and returns its size
// size = number of elements present in the vector at any time
int size(Vector vector);

// function takes vector as input and returns its capacity
// total amount of elements which the vector can hold
int capacity(Vector vector);

// returns 1 if no element present
// return 0 if any element present
int is_empty(Vector vector);

// returns element at the given index
// if index >= size exits the program with index out of bound error
// if vector empty exits the program with error
int at(Vector vector, int index);

// adds an element at the end of the array
// if size equals capacity it resizes the vector to double capacity
// O(1) : amortized time complexity
void push(Vector vector, int item);

// inserts an element at the specified index in the vector
// if size equals capacity it resizes the vector to double capacity
// O(n) : amortized time complexity
void insert(Vector vector, int index, int item);

// inserts an element in the front of the vector
// if size equals capacity it resizes the vector to double capacity
// O(n) : amortized time complexity
void prepend(Vector vector, int item);

// returns and removes the last element from the vector 
// if size becomes one-fourth of the capacity it reduces the capacity to half
// if vector empty return -1
int pop(Vector vector);

// function to remove first occurence of a given element from the vector
// step-1 finds the first index of element in the array using linear search
// step-2 removes the element from the vector
// O(n) : amortized time complexity
// if size becomes one-fourth of the capacity it reduces the capacity to half
void delete(Vector vector, int item);

// removes element from the given index in the vector
// O(n) : amortized time complexity
// if size becomes one-fourth of the capacity it reduces the capacity to half
void deleteIndex(Vector vector, int index);

// returns the index of first occurence of an element present in the vector
// uses linear search O(n) : amortized time complexity
int find(Vector vector, int item);

// function to resize the vector to desired size where size > 0
// step 1 : allocate memory for new vector array
// step 2 : copy old vector into new vector array
// step 3 : free the old vector arrat memory
// (on size reduction old elements with index greater than new size are lost)
void resize(Vector vector, int capacity);

// function to free the memory occupied by hte vector
void freeVector(Vector vector);

// function to print the elements of the array in proper format
// Eg. [1, 2, 3]
void printVector(Vector vector);

#endif