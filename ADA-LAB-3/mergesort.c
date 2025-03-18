#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[20], n;

void simple_sort(int[], int, int, int);
void merge_sort(int[], int, int);

int main() {
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. The number of elements must be positive.\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_sort(a, low, mid, high);
    }
}

void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int* c = (int*)malloc((high - low + 1) * sizeof(int)); // Dynamic memory allocation

    if (c == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Handle memory allocation failure
    }

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }

    free(c); // Free dynamically allocated memory
}
