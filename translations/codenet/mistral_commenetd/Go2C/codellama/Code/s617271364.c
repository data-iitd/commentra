
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int N, ss, ans, A, B, C;

// sort function is used to sort an array in ascending order
// typedef struct {
// 	int *arr;
// 	int size;
// } IntSlice;
// void swap(int *xp, int *yp)
// {
// 	int temp = *xp;
// 	*xp = *yp;
// 	*yp = temp;
// }
// void bubbleSort(int arr[], int n)
// {
// 	int i, j;
// 	for (i = 0; i < n - 1; i++)
// 	{
// 		for (j = 0; j < n - i - 1; j++)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				swap(&arr[j], &arr[j + 1]);
// 			}
// 		}
// 	}
// }

// dfs function is used for depth-first search
void dfs(int dp[], int times, int arr[])
{
	// Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
	if (times >= N)
	{
		ans = min(ans, calc(dp, arr));
		return;
	}

	// Recursive case: try all possible values for the current element
	for (int i = 0; i < 4; i++)
	{
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

// calc function is used to calculate the cost
int calc(int dp[], int arr[])
{
	// Initialize the cost and the variables to store the sum of elements with each value in dp
	int cost, AA, BB, CC;

	// Initialize the memo array to store the number of elements with each value in dp
	int memo[4];

	// Iterate through the dp array and update the variables
	for (int i = 0; i < N; i++)
	{
		// Update the variables based on the current value in dp
		int a = dp[i];
		memo[a]++;
		if (a == 1)
		{
			AA += arr[i];
		}
		else if (a == 2)
		{
			BB += arr[i];
		}
		else if (a == 3)
		{
			CC += arr[i];
		}
	}

	// Calculate the cost based on the variables
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Update the cost based on the number of elements with each value in dp
	for (int i = 1; i < 4; i++)
	{
		int a = memo[i];
		if (a < 1)
		{
			cost += 10000;
		}
		else
		{
			cost += (a - 1) * 10;
		}
	}

	// Return the cost
	return cost;
}

// Helper functions
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
int com(int a, int b)
{
	if (a > b)
	{
		return 0;
	}
	return 0; //abs(a - b)
}
int abs(int a)
{
	if (a < 0)
	{
		return a * -1;
	}
	return a;
}
int sum(int a[])
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	// Read the first line which contains the number of tests and the number of elements in the array
	char *X = malloc(100 * sizeof(char));
	scanf("%s", X);

	// Initialize the global variables
	N = atoi(strtok(X, " "));
	A = atoi(strtok(NULL, " "));
	B = atoi(strtok(NULL, " "));
	C = atoi(strtok(NULL, " "));
	ss = A + B + C;

	// Initialize the array and the dp array
	int *arr = malloc(N * sizeof(int));
	int *dp = malloc(N * sizeof(int));

	// Initialize the answer variable
	ans = 10000;

	// Read the next N lines which contain the elements of the array
	for (int i = 0; i < N; i++)
	{
		char *Y = malloc(100 * sizeof(char));
		scanf("%s", Y);

		// Read an element of the array
		arr[i] = atoi(strtok(Y, " "));
	}

	// Call the dfs function to find the minimum cost
	dfs(dp, 0, arr);

	// Print the answer
	printf("%d\n", ans);

	// Free the memory
	free(X);
	free(arr);
	free(dp);

	return 0;
}

