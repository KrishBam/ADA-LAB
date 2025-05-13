#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20], count = 1;

int place(int k, int j) {
    for (int i = 1; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}

void queens(int k, int n) {
    for (int j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;
            if (k == n) {
                printf("\nSolution %d:\n", count++);
                for (int i = 1; i <= n; i++) {
                    printf("  Row %d ---> Column %d\n", i, x[i]);
                }
                printf("\n");
            } else {
                queens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 19) {
        printf("Please enter a value between 1 and 19.\n");
        return 1;
    }

    queens(1, n);
    return 0;
}
