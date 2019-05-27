#include <stdio.h>
#include<stdlib.h>

int heap_s(int *arr, int root, int size)
{
    int d = 0;
    int max;
    while((root*2<=size) && (!d))
    {
        if (root*2 == size)
        {
            max = root*2;
        }
        else if (arr[root*2]> arr[root*2+1])
        {
            max = root*2;
        }
        else 
        {
            max = root*2 + 1;
        }
        if (arr[root]<arr[max])
        {
            int tmp = arr[root];
            arr[root] = arr[max];
            arr[max] = tmp;
            root = max;
        }
        else d = 1;
        
    }
}

int sorting_function(int *arr, int arr_len)
{
    for (int i = (arr_len/2)-1; i>=0; i--)
    heap_s(arr, i, arr_len);
    for(int i = arr_len - 1; i>=1; i-- )
    {
        int tmp = arr[0];
        arr[0]=arr[i];
        arr[i]=tmp;
        heap_s(arr, 0, i-1);
    }
}

int main()
{
    int size, *arr;
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    for (int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sorting_function(arr, size);
    for (int i=0; i< size-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size-1]);
    return 0;
}

