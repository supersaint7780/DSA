#include <stdio.h>

void bubble_sort(int *arr, int start, int current, int end)  {
    if(end <= start) {
        return;
    }
    if(current < end) {
        if(arr[current] > arr[current + 1]) {
            int temp = arr[current];
            arr[current] = arr[current + 1];
            arr[current + 1] = temp;
            bubble_sort(arr, start, current + 1, end);
        }
    } else {
        bubble_sort(arr, start, start, end-1);
    }
}