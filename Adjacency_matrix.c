//
// Created by aliss on 15.05.2025.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 0

struct Edge {
    int from;
    int to;
    int weight;
};

// Function to create the adjacency matrix
void createAdjacencyMatrix(int n, struct Edge edges[], int edgeCount, int matrix[MAX_VERTICES][MAX_VERTICES]) {
    // Initialize matrix with INF (no connection)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = INF;
        }
    }

    // Fill matrix with edges
    for (int i = 0; i < edgeCount; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int weight = edges[i].weight;
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }
}

// Function to print the adjacency matrix
void printMatrix(int n, int matrix[MAX_VERTICES][MAX_VERTICES]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 7;

    // Example list of edges
    struct Edge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {2, 3, 7},
        {3, 4, 3}
    };

    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    int matrix[MAX_VERTICES][MAX_VERTICES];

    // Create and print the adjacency matrix
    createAdjacencyMatrix(n, edges, edgeCount, matrix);
    printMatrix(n, matrix);

    return 0;
}
