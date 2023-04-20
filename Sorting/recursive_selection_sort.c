int get_min_index(int *arr, int start, int end) {
    if(start == end) {
        return start;
    }
    int min_index = get_min_index(arr, start + 1, end);
    if(arr[min_index] > arr[start]) {
        return start;
    } else {
        return min_index;
    }
}

void selection_sort(int *arr, int start, int end) {
    if(end < start) {
        return;
    }

    // finding the smallest element in the array
    int min_index = get_min_index(arr, start, end);

    // moving the smallest element to the front of the array
    int temp = arr[start];
    arr[start] = arr[min_index];
    arr[min_index] = temp;

    // sorting the further array
    selection_sort(arr, start + 1, end);
}
