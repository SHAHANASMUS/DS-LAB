#include <stdio.h>
#define MAX 10
int graph[MAX][MAX], parent[MAX], key[MAX], n;

int minKey(int key[], int mstSet[]) {
    int min = 999, min_index;
    for (int v = 0; v < n; v++) if (!mstSet[v] && key[v] < min) { min = key[v]; min_index = v; }
    return min_index;
}
void primMST() {
    int mstSet[MAX] = {0};
    for (int i = 0; i < n; i++) { key[i] = 999; mstSet[i] = 0; }
    key[0] = 0; parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet); mstSet[u] = 1;
        for (int v = 0; v < n; v++) if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) { parent[v] = u; key[v] = graph[u][v]; }
    }
}
void printMST() {
    int cost = 0;
    for (int i = 1; i < n; i++) { printf("Edge: %d-%d, weight: %d\n", parent[i], i, graph[i][parent[i]]); cost += graph[i][parent[i]]; }
    printf("Total cost: %d\n", cost);
}
int main() {
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    primMST(); printMST();
    return 0;
}
