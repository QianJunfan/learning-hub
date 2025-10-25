#include <stdlib.h>

/* Sat Oct 25, 2025. by Guaitan1st :) */
/* Solution 0 - Brute Force */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int *two_sum = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize - 1; i++) {
		int j = i + 1;
		while (j < numsSize) {
			if (nums[i] + nums[j] == target) {
				two_sum[0] = i;
				two_sum[1] = j;
				return two_sum;
			} else {
				j++;
			}
		}	
	}
}


/* Sat Oct 25, 2025. By QianJunfan */
/* Solution 0 - Brute Force */
#include <stdlib.h>
int* twoSum_bf(int *nums, int num_size, int target, int *r) {
	*r = 2;
	for (int i = 0; i < num_size; i++) {
		int cur = target - nums[i];
		for (int j = i + 1; j < num_size; j++)
			if (nums[j] == cur) {
				int *result = (int*)malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;
				return result;
			}
	}

	return NULL;
}

/* Solution 1 - Hash Table (mini) */
#define SIZE 10007


struct node {
	int key;	// -> value
	int val;	// -> index
	struct node *next;
};

struct node *table[SIZE];

int cal(int key)
{
	return (key % SIZE + SIZE) % SIZE;
}

void put(int key, int idx)
{
	int h = cal(key);

	struct node *new = (struct node *)malloc(sizeof(struct node));
	
	new -> key = key;
	new -> val = idx;

	new -> next = table[h];
	table[h] = new;
}

int get(int key)
{
	int h = cal(key);
	struct node *cur = table[h];

	while (cur != NULL) {
		if (cur->key == key)
			return cur->val;
		cur = cur->next;
	}
	return -1;
}

void hfree(void)
{
	for (int i = 0; i < SIZE; i++) {
		struct node *cur = table[i];
		while (cur != NULL) {
			struct node *tmp = cur;
			cur = cur->next;
			free(tmp);
		
		}
		table[i] = NULL;
	}
}

void init(void)
{
	for (int i = 0; i < SIZE; i++)
		table[i] = NULL;
}

int *twoSum(int *nums, int size, int target, int *r_size)
{
	*r_size = 2;
	init();

	for (int i = 0; i < size; i++) {
		int complement = target - nums[i];
		int key = get(complement);
		
		if (key != -1) {
			int *result = (int *)malloc(sizeof(int) * 2);
			result[0] = key;
			result[1] = i;

			hfree();
			return result;
		}

		put(nums[i], i);
	}

	hfree();
	return NULL;
}

