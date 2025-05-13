// C program to implement topological sort using Source Removal method (Kahn's Algorithm)
#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int stack[10], top = -1;

void computeIndegree(int, int [][10]);
void tps_SourceRemoval(int, int [][10]);

int main() {
    printf("Topological sort using source removal\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    printf("Topological Sort (Source Removal): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}

// Function to compute indegree of each node
void computeIndegree(int n, int a[][10]) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[j][i]; // Count incoming edges to node i
        }
        indegree[i] = sum;
    }
}

// Topological sort using source removal
void tps_SourceRemoval(int n, int a[][10]) {
    // Push all nodes with 0 indegree to stack
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    int k = 0;
    while (top != -1) {
        int v = stack[top--];
        t[k++] = v;

        // Decrease indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}
