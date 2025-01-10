#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} node;

node *head = NULL;
int count = 0;

void display()
{
    node *temp = head;
    if (temp == NULL)
    {
        printf("Empty Linked List\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void in_beg()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->pre = NULL;

    if (head != NULL)
    {
        head->pre = newnode;
    }
    head = newnode;
    printf("\nNode inserted at the beginning..\n");
    count++;
}

void in_end()
{
    node *newnode = (node *)malloc(sizeof(node));
    node *temp = head;
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->pre = NULL;
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->pre = temp;
    }
    printf("\nNode inserted at the end..\n");
    count++;
}

void in_pos()
{
    int pos;
    node *newnode = (node *)malloc(sizeof(node));
    node *temp = head;

    printf("Enter the position at which the data is to be inserted: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1)
    {
        printf("Invalid position\n");
        return;
    }

    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = head;
        newnode->pre = NULL;
        if (head != NULL)
        {
            head->pre = newnode;
        }
        head = newnode;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->pre = temp;
        if (temp->next != NULL)
        {
            temp->next->pre = newnode;
        }
        temp->next = newnode;
    }
    printf("\nNode inserted at position %d..\n", pos);
    count++;
}

void del_in()
{
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->pre = NULL;
    }
    free(temp);
    printf("\nNode deleted from the beginning..\n");
    count--;
}

void del_end()
{
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->pre != NULL)
    {
        temp->pre->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
    printf("\nNode deleted from the end..\n");
    count--;
}

void del_pos()
{
    int pos;
    printf("Enter the position at which the node has to be deleted: ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }

    node *temp = head;
    if (pos == 1)
    {
        del_in();
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        if (temp->pre != NULL)
        {
            temp->pre->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->pre = temp->pre;
        }
        free(temp);
        printf("\nNode deleted from position %d..\n", pos);
        count--;
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n*****LINKED LIST*****");
        printf("\n1.Display");
        printf("\n2.Insert at beginning");
        printf("\n3.Insert at end");
        printf("\n4.Insert at a position");
        printf("\n5.Deletion at beginning");
        printf("\n6.Deletion from end");
        printf("\n7.Deletion from a position");
        printf("\n8.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            in_beg();
            break;
        case 3:
            in_end();
            break;
        case 4:
            in_pos();
            break;
        case 5:
            del_in();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_pos();
            break;
        case 8:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 8);
    return 0;
}
