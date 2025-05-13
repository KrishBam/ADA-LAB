#include <stdio.h>
#include <time.h>

void heapify(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int item = a[i];
        int j = i;
        int parent = (j - 1) / 2;

        while (j > 0 && item > a[parent]) {
            a[j] = a[parent];
            j = parent;
            parent = (j - 1) / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n) {
    int item = a[0];
    int j = 0;
    int i = 2 * j + 1;

    while (i < n) {
        if (i + 1 < n && a[i] < a[i + 1])
            i++;

        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        } else {
            break;
        }
    }
    a[j] = item;
}

void heapsort(int a[], int n) {
    heapify(a, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjust(a, i);
    }
}

int main() {
    int a[100], n, ch = 1;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        clock_t start = clock();
        heapsort(a, n);
        clock_t end = clock();

        printf("Sorted elements:\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]);

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken: %lf seconds\n", time_taken);

        printf("Do you want to run again? (1/0): ");
        scanf("%d", &ch);
    }

    return 0;
}
