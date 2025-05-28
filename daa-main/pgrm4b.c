#include <stdio.h>
int a[10][10], visited[10], stack[10], top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    for(int i = 1; i <= n; i++) {
        if(a[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}                                             // DFS for Topological Sort

int main() {
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++)
        visited[i] = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    printf("The Topological Order of the graph is:\n");
    while(top >= 0) {
        printf("%d\t", stack[top--]);
    }
    return 0;
}
