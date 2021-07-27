#include<stdio.h>
#include <stdlib.h>

void merge(int array[], int l,int p, int h)
{
    int s1Length = p-l+1;
    int s2Length = h-p;
    int subArr1[s1Length], subArr2[s2Length];

    for(int i=0; i < s1Length; i++)
    {
        subArr1[i] = array[l+i];
    }
    for(int i=0; i < s2Length; i++)
    {
        subArr2[i] = array[p+1+i];
    }

    int i = 0, j = 0, k = l;
    while(i < s1Length && j < s2Length)
    {
        if(subArr1[i] < subArr2[j])
        {
            array[k] = subArr1[i];
            i++;
        }
        else
        {
            array[k] = subArr2[j];
            j++;
        }
        k++;
    }

    for(;i < s1Length; i++, k++)
    {
        array[k] = subArr1[i];
    }

    for(;j < s2Length; j++, k++)
    {
        array[k] = subArr2[j];
    }

}

void mergeSort(int array[], int l, int h)
{
    int p;
    if(l == h)
    {
        return;
    }
    p = (l+h)/2;
    mergeSort(array, l, p);
    mergeSort(array, p+1, h);
    merge(array, l, p, h);
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

    mergeSort(arr,0,n-1);

    printf("\n\n  Array After Merge Sort\n ");
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n\n");

    free(arr);
    return 0;
}
