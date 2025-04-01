#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);
void union_sets(int parent[10], int rank[10], int x, int y);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }
    printf("\nSum of minimal spanning tree: %d\n", sum);
    return 0;
}

void kruskal(int cost[10][10], int n) {
    int min, u, v, count, k;
    int parent[10], rank[10];

    k = 0;
    sum = 0;

    // Initialize parent and rank arrays for Union-Find
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    count = 0;

    // Find the minimum edge and add it to the MST
    while (count < n - 1) {
        min = 999;
        u = -1;
        v = -1;

        // Find the minimum edge that doesn't form a cycle
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // Ensure no duplicate edges (i, j) and (j, i)
                if (find(parent, i) != find(parent, j) && cost[i][j] < min && cost[i][j] > 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Add edge to the MST
        if (u != -1 && v != -1) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            sum += min;
            union_sets(parent, rank, u, v);
            count++;
        }
    }
}

int find(int parent[10], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);  // Path compression
    }
    return parent[i];
}

void union_sets(int parent[10], int rank[10], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
