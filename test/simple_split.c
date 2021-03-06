// test.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 7
#define THRESHOLD 4
#define THRESHOLD_SECOND 2
#define MAXDEPTH 2

#define N_NODES 15 // 2^(depth) -1
#define INIT_LOSS INT_MAX

#define DEFAULT_FIDX 0

void print_content(int*, int);
int compare_func(const void* a, const void* b);
void copy(int arr[], int arr2[], size_t len);
float loss_func(int left[], int left_length, int right[], int right_length);
float _std(float arr[], int length);


typedef struct split
{
	int* left;
	int left_len;

	int* right;
	int right_len;
} split;

typedef struct node
{
	int id; // node id
	float threshold;
	int feature_idx; // target dimension that splits data space
} node;

typedef struct model
{
	node nodes[N_NODES];
} model;


split split_array(int arr[], size_t length, int threshold);
//void split_array_recursive(int arr[], size_t len, int threshold, int depth);

int split_array_offset(int* arr, size_t length, int threshold);

int split_array_offset(float arr[], size_t length, int threshold) 
{
	int slice = 0;
	for (size_t i = 0; i < length; i++)
	{
		float value = arr[i];
		if (arr[i] <= threshold)
		{
			continue;
		}
			// update slice
		return i;
		//break;
	}
	//return slice;
	return -1;
}

float hoge()
{
	// INPUT DATA
	float arr[] = { 3.0,10.0,4.0,50.0,90.0,2.0, 6.0 };

	int arr_original[LENGTH];

	// INITIALIZATION	
	int length = LENGTH;
	float threshold = THRESHOLD;
	float bloss = INIT_LOSS;
	float best_threshold;
	int best_offset;

	int node_counter = 0;
	int depth = 0;
	// START

	copy(arr, arr_original, LENGTH);
	qsort(arr, LENGTH, sizeof(float), compare_func);

	//split_array_recursive(arr, LENGTH, THRESHOLD, 1);

	// do grow the tree for root node
	float loss = 0;
	// choose threshold from the values in the data
	for (size_t i = 0; i < LENGTH - 1; i++)
	{
		threshold = arr[i];
		//split spl = split_array(arr, LENGTH, threshold);
		int offset = split_array_offset(arr, LENGTH, threshold);
		//printf("offset: %d\n", offset);
		//printf("threshold: %f\n", threshold);

		int llen = offset + 1;
		int rlen = LENGTH - offset;
		// evaluate the split
		//float loss = loss_func(spl.left, spl.left_len, spl.right, spl.right_len);

		loss = loss_func_offset(arr, offset, llen, rlen);

		if (loss < bloss)
		{
			bloss = loss;

			best_offset = offset;
			best_threshold = threshold;
		}
	}

	return bloss;
}

int main()
{
	float val = 0;
	val = hoge();
	printf("%f\n", val);

	// Now you've found the best split.
	// Having this result, you go on to register node
	
	// register node
	
	//node nod = { .threshold = best_threshold,.id = node_counter,.feature_idx = DEFAULT_FIDX };
	//mod.nodes[node_counter] = nod;
	// update counter
//	node_counter++;

	//depth++;
	

	//printf("best threshold: %f\n", best_threshold);
	//printf("best split... left:%d, right:%d\n", *best_split.left, *best_split.right);
	//printf("best loss: %g\n", bloss);

	
	// execute the same thing 
};

//struct split split_array(int arr[], size_t length, int threshold) 
//{
//	/// split sorted array
//
//	// init slice
//	int slice = 0;
//	for (size_t i = 0; i < length; i++)
//	{
//		if (arr[i] <= threshold)
//		{
//			continue;
//		}
//		else
//		{
//			// update slice
//			slice = i;
//			break;
//		}
//	}
//	int* firsthalf = arr;
//	int* secondhalf = arr + slice;
//
//	struct split spl = { .left = arr, .left_len = slice, .right = arr + slice, .right_len = length - slice};
//	return spl;
//}


//void print_content(int* arr, int length)
//{
//	for (size_t j = 0; j < length; j++)
//	{
//		printf("%d \n", *(arr+j));
//	}
//}

void copy(int original[], int target[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		target[i] = original[i];
	}
}

int compare_func(const void* a, const void* b)
{
	return (*(float*)a - *(float*)b);
}

float loss_func(int* left, int left_length, int* right, int right_length)
{
	float left_loss = _std(left, left_length);
	float right_loss = _std(right, right_length);
	float total = left_loss + right_loss;

	printf("%f\n", total);
	return total;
}

float loss_func_offset(float arr[], int offset, int left_length, int right_length)
{
	float left_loss= _std(arr, left_length);
	float right_loss = _std(arr + offset, right_length);

	float total = left_loss + right_loss;

	return total;
}


float mean(int arr[], int length) 
{
	float sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum / (float)length;
}

float _std(float arr[], int length) 
{
	float sum = 0;
	float squared_sum = 0;
	if (length == 0)
	{
		return 0;
	}
	for (size_t i = 0; i < length; i++)
	{
		float val = arr[i];
		sum += val;
		squared_sum += val * val;
	}
	float lengthf = (float)length;
	float res = (lengthf * squared_sum - sum * sum) / (lengthf * lengthf);
	return res;
}


//void split_array_recursive(int arr[], size_t length, int threshold, int depth)
//{
//	/// split sorted array
//
//	if (depth > MAXDEPTH)
//	{
//		return;
//	}
//	else
//	{
//		// init slice
//		int slice = 0;
//		for (size_t i = 0; i < length; i++)
//		{
//			if (arr[i] <= threshold)
//			{
//				continue;
//			}
//			else
//			{
//				// update slice
//				slice = i;
//				break;
//			}
//		}
//		int* firsthalf = arr;
//		int* secondhalf = arr + slice;
//
//		printf("left: \n");
//		print_content(firsthalf, slice);
//		printf("right: \n");
//		print_content(secondhalf, length - slice);
//
//		depth++;
//
//		// find threshold
//
//		split_array_recursive(firsthalf, slice, THRESHOLD_SECOND, depth);
//
//		split_array_recursive(secondhalf, length - slice, THRESHOLD_SECOND, depth);
//
//
//		//		split spl = { .left = arr,.left_len = slice,.right = arr + slice,.right_len = length - slice };
//
//
//		//return;
//	}
//
//	
//}