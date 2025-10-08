#ifndef GRAPH_H
#define GRAPH_H

// ---- Constants ----
#define MAX_NODES 100        // Maximum number of locations in the grid
#define MAX_NAME_LEN 50      // Maximum length of a location name

// ---- Adjacency List Node ----
// This represents a single connection to another location.
typedef struct AdjNode {
    char name[MAX_NAME_LEN];      // Name of the connected location
    int priority;                 // Priority of that location
    struct AdjNode* next;         // Pointer to the next connected location
} AdjNode;

// ---- Main Graph Node ----
// This represents one location (e.g., hospital, school, residential area).
typedef struct {
    char name[MAX_NAME_LEN];  // Name of this location
    int priority;             // Priority: 3 = hospital, 2 = school, 1 = residential
    AdjNode* adjList;         // Pointer to list of its connected neighbours
} GraphNode;

// ---- Function Declarations ----
void addNode(char* name, int priority);
void addEdge(char* from, char* to);
void displayGraph();
int findNodeIndex(char* name);

#endif
