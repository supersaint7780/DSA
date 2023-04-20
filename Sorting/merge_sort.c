void merge(int *arr, int start, int mid, int end) {
    int size = (end - start + 1);
    int temp_array[size];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp_array[k] = arr[i];
            i++;
        } else {
            temp_array[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp_array[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end) {
        temp_array[k] = arr[j];
        j++;
        k++;
    }

    int a = 0;
    for(int x=start;x<=end;x++) {
        arr[x] = temp_array[a];
        a++;
    }
}


// Time Complexity O(n log n)
// Space Complezity O(n)
void merge_sort(int *arr, int start, int end) {
    if(start >= end) {
        return;
    }

    int mid = (end + start)/2;

    // divide the array into two parts
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);

    // merge the two sorted into single array
    merge(arr, start, mid, end);
}
