#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int vertex_count = 0;
    int row, column;
    int cost_matrix[MAX][MAX];
    int edge_count = 0, count = 1;
    int sum_cost = 0, min_cost;
    int row_no, column_no, edge1, edge2;

    printf("Implementation of Kruskal's Algorithm\n\n");
    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    if (vertex_count <= 0 || vertex_count > MAX) {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }

    printf("\nEnter the Cost Matrix (%d x %d):\n", vertex_count, vertex_count);
    for (row = 0; row < vertex_count; row++) {
        for (column = 0; column < vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
            if (cost_matrix[row][column] == 0 && row != column) {
                cost_matrix[row][column] = INF;
            }
        }
    }

    edge_count = vertex_count - 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (count <= edge_count) {
        min_cost = INF;

        // Find the smallest edge
        for (row = 0; row < vertex_count; row++) {
            for (column = 0; column < vertex_count; column++) {
                if (cost_matrix[row][column] < min_cost) {
                    min_cost = cost_matrix[row][column];
                    edge1 = row;
                    edge2 = column;
                }
            }
        }

        row_no = find(edge1);
        column_no = find(edge2);

        // Add the edge if it doesn't form a cycle
        if (uni(row_no, column_no)) {
            printf("Edge %d: (%d -> %d) with cost: %d\n", count++, edge1 + 1, edge2 + 1, min_cost);
            sum_cost += min_cost;
        }

        // Mark the edge as used
        cost_matrix[edge1][edge2] = cost_matrix[edge2][edge1] = INF;
    }

    printf("\nMinimum cost of the spanning tree: %d\n", sum_cost);
    return 0;
}
