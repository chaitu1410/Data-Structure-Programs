#include<stdio.h>

int binary_search(int a[], int low, int high, int key)
{
    if(high < low){
        return -1;
    }
    int mid = (low+high)/2;

    if(a[mid] == key)
    {
        return mid;
    }
    else if(key < a[mid]){
        return binary_search(a, low, mid-1, key);
    }
    else{
        return binary_search(a, mid+1, high, key);
    }
}

int main()
{
    int a[] = {1, 3, 6, 8, 11, 45, 88, 98, 101, 127};
    int key = 45;
    int index = binary_search(a, 0, 9, key);

    if(index >= 0){
        printf("\n  %d found at position %d.\n", key, index+1);
    }else{
        printf("\n  %d is not in the array.\n", key);
    }
    return 0;
}
