#include <stdio.h>
#define max 20

int adj[max][max] = {0};
int n;

void create_graph()
{
    int i, max_edges, origin, destin;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d (0 0 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if (origin == 0 && destin == 0)
            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge! Try again.\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

void insert_edge()
{
    int origin, destin;

    printf("Enter an edge (origin destination): ");
    scanf("%d %d", &origin, &destin);

    if (origin > n || destin > n || origin <= 0 || destin <= 0)
    {
        printf("Invalid edge! Nodes should be between 1 and %d.\n", n);
        return;
    }

    adj[origin][destin] = 1;
    printf("Edge (%d -> %d) added successfully.\n", origin, destin);
}

void display()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
}

void insert_node()
{
    int i;
    n++;
    printf("The inserted node is %d\n", n);

    for (i = 1; i <= n; i++)
    {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}

void delete_node(int u)
{
    int i, j;

    if (n == 0)
    {
        printf("Graph is empty!\n");
        return;
    }

    if (u > n || u <= 0)
    {
        printf("Node %d is not present in the graph.\n", u);
        return;
    }

    // Shift rows and columns to remove the node
    for (i = u; i < n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            adj[j][i] = adj[j][i + 1];
            adj[i][j] = adj[i + 1][j];
        }
    }

    // Clear the last row and column
    for (i = 1; i <= n; i++)
    {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }

    n--;
    printf("Node %d deleted successfully.\n", u);
}

int main()
{
    int choice, node;

    create_graph();
    while (1)
    {
        printf("\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Insert an edge\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_node();
            break;
        case 2:
            printf("Enter the node to be deleted: ");
            scanf("%d", &node);
            delete_node(node);
            break;
        case 3:
            insert_edge();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}
