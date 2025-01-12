#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int vertex_array[MAX], counter;
    int vertex_count = 0;
    int row, column;
    int cost_matrix[MAX][MAX];
    int visited[MAX] = {0};
    int edge_count = 0, count = 1;
    int sum_cost = 0, min_cost;
    int row_no = 0, column_no = 0, vertex1, vertex2;

    printf("Total no of vertices: ");
    scanf("%d", &vertex_count);

    if (vertex_count > MAX || vertex_count <= 0) {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }

    printf("\n-- Enter vertex labels --\n");
    for (counter = 0; counter < vertex_count; counter++) {
        printf("vertex[%d]: ", counter + 1);
        scanf("%d", &vertex_array[counter]);
    }

    printf("\n--- Enter Cost Matrix (%d x %d) ---\n", vertex_count, vertex_count);
    for (row = 0; row < vertex_count; row++) {
        for (column = 0; column < vertex_count; column++) {
            printf("Cost[%d][%d]: ", row + 1, column + 1);
            scanf("%d", &cost_matrix[row][column]);
            if (cost_matrix[row][column] == 0 && row != column) {
                cost_matrix[row][column] = INF; // Replace 0 with INF for non-self-loops
            }
        }
    }

    visited[0] = 1; // Start from the first vertex
    edge_count = vertex_count - 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (count <= edge_count) {
        min_cost = INF;

        for (row = 0; row < vertex_count; row++) {
            if (visited[row]) {
                for (column = 0; column < vertex_count; column++) {
                    if (!visited[column] && cost_matrix[row][column] < min_cost) {
                        min_cost = cost_matrix[row][column];
                        vertex1 = row;
                        vertex2 = column;
                    }
                }
            }
        }

        if (!visited[vertex2]) {
            printf("Edge %d: (%d -> %d) with cost: %d\n", count++, vertex_array[vertex1], vertex_array[vertex2], min_cost);
            sum_cost += min_cost;
            visited[vertex2] = 1;
        }

        cost_matrix[vertex1][vertex2] = cost_matrix[vertex2][vertex1] = INF; // Mark edge as used
    }

    printf("\nMinimum cost of the spanning tree: %d\n", sum_cost);
    return 0;
}
