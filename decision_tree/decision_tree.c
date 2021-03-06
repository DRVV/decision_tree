// decision_tree.c : Defines the entry point for the console application.
//

#include <stdio.h>

// parameters

#define INIT_INDEX 999
#define INIT_BEST_VAL 999
#define INIT_BEST_SCORE 999
#define INIT_BEST_GROUP -1

// structs
struct model_parameters
{
	int max_depth;
	int min_size;
	int n_estimators;
};

struct node
{
	int index_to_split;
	float value;
	float groups[]; // array of pointers
};

struct node_r //  'r' == recursive
{
	int index_to_split;
	float value;
	struct node_r nodes[]; // array of pointers
};


//struct node
//{
//	int index;
//	float threshold;
//};
//struct tree
//{
//	struct node nodes[];
//};


//struct GBRT
//{
//	struct tree trees[];
//};

float cost(float samples[]); // cost function to measure how good the split is.
void split_samples(int feature_index, float threshold, float samples[]
	, float *splitted_samples); // devide the sample space into two.  The last argument is a pointer to the result array to fill in.

//struct split_info get_split(float samples[]);
struct node get_split(float samples[]);

void to_terminal(struct node n);
void grow_tree();

// interfaces

void predict(struct tree model, float samples[]);
struct node fit(float training_samples[]);

int main()
{
	// some preprocessing


    return 0;
}

struct node fit(float training_samples[])
{
	struct node root = get_split(training_samples);
	grow_tree(&root);
	return root;
}

void predict(struct node model, float test_samples[], float *predictions, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		predictions[i] = traverse_tree(test_samples[i]);
	}
	//return 0;
}

float traverse_tree(float test_sample)
{
	// 
	return 0;
}

void save_model(struct node model, FILE fl) {
	// save node into storage
	// TODO: implement
	;
}



