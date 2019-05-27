#include <stdio.h>
#include <stdlib.h>

int quicks(int *arr, int begin, int end)
{
    int left, right, mid;
    int trans = 0;
    if (begin < end)
    {
        left = begin;
        right = end; 
        mid = arr[(left + right) / 2];
        while (left <= right)
        {
            while (arr[left] < mid) 
            left++;
            while (arr[right] > mid) 
            right--;
            if (left <= right)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
                trans++;
            }
        }       
        quicks(arr, begin, right);
        quicks(arr, left, end);
        return (trans);
    }    
}

int sorting_function(int *arr, int arr_len)
{
    int trans = quicks(arr, 0, arr_len-1);
    for (int i = 0; i < arr_len-1; i++)
	{
		printf("%d ", arr[i]);
	}
        printf("%d", arr [arr_len-1]);
	printf("\n");
    return trans;
}

int main()
{
    int size, *arr;
	scanf("%d", &size);
	arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	sorting_function(arr, size);
}


