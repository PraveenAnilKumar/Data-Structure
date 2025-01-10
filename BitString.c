#include <stdio.h>
void Union(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe Union of both bit strings of Set A and B are: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] == 1 || y[i] == 1;
    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}
void Intersection(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe Intersection of both bit strings of Set A and B are: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] == 1 && y[i] == 1;
    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}
void Difference(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe difference of both bit strings of set A and B are: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] == 1 && y[i] == 0;
    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

void main()
{
    int n, m, o, i, j, u[20], a[20], b[20], bitA[50], bitB[50], ch;
    printf("Enter the size of the Universal set: ");
    scanf("%d", &n);
    printf("Enter the elements of the Universal set: ");
    for (i = 0; i < n; i++)
        scanf("%d", &u[i]);
    printf("the Elements in the Universal set  are:");
    for (i = 0; i < n; i++)
        printf(" %d ", u[i]);
    printf("\nEnter the size of set A: ");
    scanf("%d", &m);
    while (n < m)
    {
        printf("The size entered is bigger than the Universal set's size. Please Enter the size of set A again.");
        scanf("%d", &m);
    }
    printf("Enter the elements of Set A: ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);
    printf("The set A is :");
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\nEnter the size of set B: ");
    scanf("%d", &o);
    while (n < o)
    {
        printf("The size entered is bigger than the Universal set's size. Please Enter the size of set B again.");
        scanf("%d", &o);
    }
    printf("Enter the elements of Set B: ");
    for (i = 0; i < o; i++)
        scanf("%d", &b[i]);
    printf("The Set B is: ");
    for (i = 0; i < o; i++)
        printf("%d ", b[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (u[i] == a[j])
            {
                bitA[i] = 1;
                break;
            }
            else
                bitA[i] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < o; j++)
        {
            if (u[i] == b[j])
            {

                bitB[i] = 1;
                break;
            }

            else
                bitB[i] = 0;
        }
    }
    printf("\nBit String A : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bitA[i]);
    }
    printf("\nBit String B : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bitB[i]);
    }
    do
    {
        printf("\nEnter the operation to be done:\n (1) For Union\n (2) For Intersection\n (3) For Difference\n (4) To Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Union(bitA, bitB, n);
            break;
        case 2:
            Intersection(bitA, bitB, n);
            break;
        case 3:
            Difference(bitA, bitB, n);
            break;
        case 4:
            printf("\nExiting");
            break;
        default:
            printf("\nInvalid choice!!");
        }
    } while (ch != 4);
}
