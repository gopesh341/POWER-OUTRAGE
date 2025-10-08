#include <stdio.h>
#include "dfs_bfs.h"

// ---- Depth-First Search ----
void dfs(int nodeIndex, int visited[]) {
    visited[nodeIndex] = 1;
    printf("%s (P%d) -> ", graph[nodeIndex].name, graph[nodeIndex].priority);

    AdjNode* current = graph[nodeIndex].adjList;
    while (current != NULL) {
        int neighborIndex = findNodeIndex(current->name);
        if (visited[neighborIndex] == 0) {
            dfs(neighborIndex, visited);
        }
        current = current->next;
    }
}

// ---- Find All Clusters / Isolated Areas ----
void findIsolatedClusters() {
    int visited[MAX_NODES] = {0};
    int clusterNumber = 1;

    printf("\n--- Isolated Clusters ---\n");
    for (int i = 0; i < nodeCount; i++) {
        if (visited[i] == 0) {
            printf("Cluster %d: ", clusterNumber);
            dfs(i, visited);
            printf("NULL\n");
            clusterNumber++;
        }
    }
}
