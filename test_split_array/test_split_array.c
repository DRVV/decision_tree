// test_split_array.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5

int main()
{
	int arr[] = { 1,7,3,4,5 };
	
	int threshold = 4;

	// make TF array
	int arr_b[5];


	for (size_t i = 0; i < LENGTH; i++)
	{
		int val = arr[i];
		if (val <= threshold)
		{
			arr_b[i] = 1;
		}
		else
		{
			arr_b[i] = 0;
		}
	}
	
	()

	//// count Ts
	//int t_cnt = sum(arr_b, LENGTH);
	//t_cnt = (const int)t_cnt;

	//const int hoge = 3;
	//int test[hoge];

	//int left[t_cnt];
	//int right[LENGTH - t_cnt];



    return 0;
}


int sum(int arr[], int length)
{
	int val = 0;
	for (size_t i = 0; i < length; i++)
	{
		val += arr[i];
	}
	return val;
}