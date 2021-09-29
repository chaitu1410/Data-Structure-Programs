#include<stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int length)
{
    for(int i = 1; i < length; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(a[j] < a[j-1])
            {
                int t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
            else{
                break;
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

    insertion_sort(arr, n);

    printf("\n\n  Sorted Array: \n ");
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");
    return 0;
}
