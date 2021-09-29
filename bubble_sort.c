#include<stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int length)
{
    for(int i = 0; i < length-1; i++)
    {
        for(int j = 0; j < length-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main()
{
    int *arr, n;
    printf("\n\n  How many numbers you want to sort: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));
    printf("\n  Enter %d numbers (space separated): ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    bubble_sort(arr, n);

    printf("\n\n  Sorted Array: \n ");
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");
    return 0;
}
