#include<stdio.h>
#define INF 999

void dijkstra(int n, int a[11][11], int source) {
    int d[11], s[11], i, j, u = 0, v, minval;

    for(i = 1; i <= n; i++) {
        if(i == source)d[i] = 0;
        else if(a[source][i] == 0)d[i] = INF;
        else d[i] = a[source][i];
        s[i] = 0;
    }
    s[source] = 1;
    for(i = 1; i < n; i++) {
        minval = INF;
        for(j = 1; j <= n; j++)
            if(s[j] == 0 && d[j] < minval) {
                minval = d[j];
                u = j;                               //Dijkstra's Algorithm
            }
        s[u] = 1;
        for(v = 1; v <= n; v++)
            if(s[v] == 0 && a[u][v] != 0)
                if(d[v] > d[u] + a[u][v])
                    d[v] = d[u] + a[u][v];
    }
    for(i = 1; i <= n; i++)
        if(d[i] == INF)
            printf("There is no path from %d to %d\n", source, i);
        else
            printf("The shortest distance from %d to %d is %d\n", source, i, d[i]);
}

int main() {
    int n, a[11][11], i, j, source;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source node:\n");
    scanf("%d", &source);
    dijkstra(n, a, source);
    return 0;
}
