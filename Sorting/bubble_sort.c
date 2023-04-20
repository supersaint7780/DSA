void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Time Complexity O(n^2)
// Space Complezity O(1)
void bubble_sort(int *arr, int start, int end) {
    int isSwapped = 0;
    for(int i=start;i<end;i++) {
        for(int j=start;j<end;j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSwapped = 1;
            }
        }
        if(isSwapped == 0) {
            break;
        }
    }   
}