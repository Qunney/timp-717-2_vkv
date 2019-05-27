#include <stdio.h>
#include <stdlib.h>

int sorting_function(int *arr, int arr_len)
{
	int trans = 0;
	double p = 1.2473309;
	int step = arr_len;
	while (step >= 1)
	{
		for (int i = 0; i + step < arr_len; ++i)
		{
			if (arr[i] > arr[i + step])
			{
				//swap(arr[i], arr[i + step]);
				int tmp;
				tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
				trans++;
			}
		}
		step = step / p;
	}
	for (int i = 0; i < arr_len - 1; i++)
	{
	    int  exc = 0;
		for (int j = 0; j < arr_len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				//swap(arr[j], arr[j + 1]);
				int tmp;
				tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
				exc = 1;
				++trans;
			}
		}
		if (exc == 0) {
                        break;
                }

	}
	for (int i = 0; i < arr_len-1; i++)
	{
		printf("%d ", arr[i]);
	}
        printf("%d\n",arr[arr_len-1]);
       
	return(trans);
}


int main()
{
	int size,*arr;
	scanf("%d", &size);
	arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	sorting_function(arr, size);
}

