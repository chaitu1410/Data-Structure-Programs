#include<stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int l, int h)
{
    int i = l, j = h;
    int p = array[l];
    while(i < j)
    {
        do
        {
            i++;
        } while(array[i] <= p);

        do
        {
            j--;
        } while(array[j] > p);

        if(i < j)
        {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[l], &array[j]);
    return j;
}

void quickSort(int array[], int l, int h)
{
    int p;
    if(l < h)
    {
        p = partition(array, l, h);
        quickSort(array, l, p);
        quickSort(array, p+1, h);
    }
}

int main()
{
    int *arr, n;
    printf("\n\n  How many numbers you want to sort: ");
    scanf("%d", &n);

    arr = (int*)malloc((n+1)*sizeof(int));
    printf("\n  Enter %d numbers (space separated): ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    arr[n] = 65535;
    quickSort(arr,0,n);

    printf("\n\n  Array After Quick Sort\n ");
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n\n");

    free(arr);
    return 0;
}
