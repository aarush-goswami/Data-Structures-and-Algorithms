#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void insert(int *arr, int *size)
{
    int pos, value, i;
    printf("Enter Position :");
    scanf("%d", &pos);
    printf("Enter Value :");
    scanf("%d", &value);
    if (pos > *size || pos <= 0)
        printf("Invalid position !!");
    else
    {
        for (i = *size; i >= pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = value;
        (*size)++;
        printf("Element inserted\n");
    }
}
void printList(int *arr, int n)
{
    if (n == 0)
        printf("List is Empty \n");
    else
    {
        int i;
        printf("List ELements are : ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
void deleteElement(int *arr, int *size)
{
    int pos, i;
    printf("Enter position : ");
    scanf("%d", &pos);
    if (pos > *size || pos <= 0)
        printf("Invalid position !!");
    else
    {
        for (i = pos - 1; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element Deleted \n");
    }
}
void search(int *arr, int size)
{
    int n, ind = 0;
    printf("Enter element to search : ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            ind = 1;
            break;
        }
    }
    if (ind == 0)
        printf("Element not found");
    else
        printf("Element found");
}
int main()
{
    int arr[MAX_SIZE], size, i;
    printf("Enter list size :");
    scanf("%d", &size);
    printf("Enter list elements : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Transversing \n");
        printf("4. Searching \n");
        printf("5. Exit \n");
        int choice;
        printf("Enter Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(arr, &size);
            break;
        case 2:
            deleteElement(arr, &size);
            break;
        case 3:
            printList(arr, size);
            break;
        case 4:
            search(arr, size);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invaild Choice !!!!!\n");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
