#include <stdio.h>
#include <stdlib.h>

int sorting_function(int *arr, int arr_len)
{
    int i, j, step, tmp;
    int trans=0;
    for (step = arr_len / 2; step > 0; step /= 2)
    {
        for (i = step; i < arr_len; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                {
                    arr[j] = arr[j - step];
                    trans++;
                }
                else
                    break;
            }
            arr[j] = tmp;
        }
    }
    for (int i = 0; i < arr_len-1; i++)
	{
		printf("%d ", arr[i]);
	}
    printf("%d\n", arr[arr_len-1]);
	return(trans);
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
