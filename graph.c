#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// ---- Global Variables ----
GraphNode graph[MAX_NODES];  // Array to hold all locations
int totalNodes = 0;          // Keeps track of how many nodes are added

// ---- Add a New Node ----
void addNode(char* name, int priority) {
    // Copy the name into the graph array
    strcpy(graph[totalNodes].name, name);
    graph[totalNodes].priority = priority;
    graph[totalNodes].adjList = NULL;  // No connections yet
    totalNodes++;
}

// ---- Find the Index of a Node by Name ----
int findNodeIndex(char* name) {
    for (int i = 0; i < totalNodes; i++) {
        if (strcmp(graph[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

// ---- Add an Edge (Undirected) ----
void addEdge(char* from, char* to) {
    int indexFrom = findNodeIndex(from);
    int indexTo   = findNodeIndex(to);

    if (indexFrom == -1 || indexTo == -1) {
        printf("Error: One or both nodes not found (%s, %s)\n", from, to);
        return;
    }

    // Add 'to' into the adjacency list of 'from'
    AdjNode* newNode1 = (AdjNode*)malloc(sizeof(AdjNode));
    strcpy(newNode1->name, to);
    newNode1->priority = graph[indexTo].priority;
    newNode1->next = graph[indexFrom].adjList;
    graph[indexFrom].adjList = newNode1;

    // Add 'from' into the adjacency list of 'to' (because undirected)
    AdjNode* newNode2 = (AdjNode*)malloc(sizeof(AdjNode));
    strcpy(newNode2->name, from);
    newNode2->priority = graph[indexFrom].priority;
    newNode2->next = graph[indexTo].adjList;
    graph[indexTo].adjList = newNode2;
}

// ---- Display the Entire Graph ----
void displayGraph() {
    printf("\n--- Power Grid Connections ---\n");

    for (int i = 0; i < totalNodes; i++) {
        printf("%s (Priority %d): ", graph[i].name, graph[i].priority);

        AdjNode* current = graph[i].adjList;
        while (current != NULL) {
            printf("%s (P%d) -> ", current->name, current->priority);
            current = current->next;
        }

        printf("NULL\n");
    }
}
