#include <stdio.h>


void insertion_sort(int *arr, int start, int current_index, int end) {
    if(end < current_index) {
        return;
    }
    int key = arr[current_index];
    while(current_index > start && key < arr[current_index - 1]) {
        arr[current_index] = arr[current_index - 1];
        current_index--;
    }
    arr[current_index] = key;
    insertion_sort(arr, start, current_index + 1, end);
}

int main() {
    int arr[5] = {5, 4, 1, 2, 3};
    insertion_sort(arr, 0, 0, 4);
    for(int i=0;i<5;i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}