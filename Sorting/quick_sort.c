void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Space Complexity : O(1)
// Average Time Complexity : Theta(n log n) for majority of cases
// Worst case Complexity (if pivot is largest or smallest element) : O(n^2)
void quick_sort(int *arr, int start, int end) {
    if(start >= end) {
        return;
    }
    int i = start;
    int j = end;
    int mid = (i + j)/2;
    int pivot = arr[mid];
    while(i <= j) {
        while(arr[i] < pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, start, j);
    quick_sort(arr, i, end);
}