#include <stdio.h>

int a[10][10], visited[10], stack[10], top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}

void kahn_topology(int n, int a[10][10], int sc[10]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        if (sc[i] == 0) {
            printf("%d\t", i);
            sc[i] = -1;
            for (j = 1; j <= n; j++) {
                if (a[i][j] == 1)
                    sc[j] = sc[j] - 1;
            }
            i = 0;
        }
    }
}

int main() {
    int n, i, j, sc[10];

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        sc[i] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] == 1)
                sc[j]++;
        }
    }

    printf("Topological Order using Kahn's Algorithm:\n");
    kahn_topology(n, a, sc);
    printf("\n");

    for (i = 1; i <= n; i++)
        visited[i] = 0;
    top = -1;

    for (i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i, n);
    }

    printf("Topological Order using DFS:\n");
    while (top >= 0) {
        printf("%d\t", stack[top--]);
    }

    return 0;
}
