#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insert_at_end(int n)
{
    struct node *temp, *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = n;

    if (head == NULL)
    {
        head = t;
        head->link = NULL;
    }
    else
    {
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = t;
        t->link = NULL;
    }
}
void delete(int value)
{
    struct node *temp = head, *prev = NULL;

    if (temp == NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    if (temp != NULL && temp->data == value)
    {
        head = temp->link;
        free(temp);
        printf("Deleted node with value %d\n", value);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->link = temp->link;
    free(temp);
    printf("Deleted node with value %d\n", value);
}

void display()
{
    struct node *t = head;
    if (t == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (t != NULL)
    {
        printf("%d -> ", t->data);
        t = t->link;
    }
    printf("NULL\n");
}

void main()
{
    int d, data;
    for (;;)
    {
        printf("Enter 1 to insert, 2 to display, 3 to  delete, 4 to Exit: ");
        scanf("%d", &d);

        if (d == 1)
        {
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insert_at_end(data);
        }
        else if (d == 2)
        {
            display();
        }
        else if (d == 3)
        {
            printf("Enter the value to delete: ");
            scanf("%d", &data);
            delete (data);
        }
        else if (d == 4)
        {
            printf("Exiting");
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
}
