// Time Complexity O(n^2)
// Space Complezity O(1)
void insertion_sort(int *arr, int start, int end) {
    for(int i=start+1;i<=end;i++) {
        int j = i;
        int key = arr[i];
        while(j>start && arr[j-1] > key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}
