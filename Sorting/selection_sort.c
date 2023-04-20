void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Time Complexity O(n^2)
// Space Complezity O(1)
void selection_sort(int *arr, int start, int end) {
    int min = 0;
    for(int i=start;i<end;i++) {
        min = i;
        for(int j=i+1;j<=end;j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
