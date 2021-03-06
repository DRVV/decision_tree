// builld_tree_by_global_table.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 10
#define RAND_UPPER_LIMIT 20

#define DEPTH 3
#define N_NODES 7 //pow(2, DEPTH) - 1

typedef struct node
{
	int id;
	int threshold;
	int loss;
};

void create_id_oridnal(int threshold, int ids[]);


int main()
{
	int dataset[LENGTH];

	// generate data
	int seed = 84;
	srand(seed);
	for (size_t i = 0; i < LENGTH; i++)
	{
		dataset[i] = rand() % RAND_UPPER_LIMIT;
	}

	// init `node_nums` (records which sample belongs to which node)
	int node_ids[LENGTH];
	for (size_t i = 0; i < LENGTH; i++)
	{
		// all nodes belong to the root at the start
		node_ids[i] = 0;
	}
	
	// node info
	float best_losses[N_NODES];
	int best_feature[N_NODES];
	int best_threshold[N_NODES];

	//

    return 0;
}

