#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "dfs_bfs.h"

int main() {
    int n, edges, i, priority;
    char name1[MAX_NAME], name2[MAX_NAME];

    printf("=== Power Outage Infrastructure ===\n");

    printf("Enter number of locations: ");
    scanf("%d", &n);
    getchar();
    for(i=0;i<n;i++){
        printf("\nEnter name for location %d: ", i+1);
        fgets(name1, sizeof(name1), stdin);
        name1[strcspn(name1, "\n")] = 0;

        printf("Enter priority for %s (3=Hospital/Substation, 2=School, 1=Residential): ", name1);
        scanf("%d", &priority);
        getchar();

        addNode(name1, priority);
    }

    printf("\nEnter number of connections: ");
    scanf("%d", &edges);
    getchar();
    for(i=0;i<edges;i++){
        printf("\nEnter connection %d (name1 name2): ", i+1);
        scanf("%s %s", name1, name2);
        getchar();

        addEdge(name1, name2);
    }

    displayGraph();
    findClusters();

    return 0;
}
