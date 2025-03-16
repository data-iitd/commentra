#include<iostream>
#include<cstdio>
#define LEN 300
#define TRUE 1
#define FALSE -1

// Function prototype for solve
int solve(int, int);

// Global variables
int n, A[LEN];
int flag;

int main()
{
  // Variables for input
  int q, M;
  int i, j, k;

  // Read the number of elements in the array
  scanf("%d", &n);
  // Read the elements of the array
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  // Read the number of queries
  scanf("%d", &q);
  // Iterate over each query
  for(i=0; i<q; i++)
    {
      // Read the target sum for the current query
      scanf("%d", &M);
      // Initialize the flag to FALSE
      flag = FALSE;

      // Call the solve function to find a subset that sums up to M
      solve(-1, M);
      // Print "yes" if a subset is found, otherwise print "no"
      if(flag == TRUE) printf("yes\n");
      else printf("no\n");
    }

  return 0;
}

// Recursive function to find a subset that sums up to m
int solve(int i, int m)
{
  // Base case: if index i exceeds the number of elements, return FALSE
  if(i > n) return FALSE;
  // If the remaining sum m is negative, return FALSE
  else if(m < 0) return FALSE;
  // If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
  else if(m == 0 || m - A[i+1] == 0)
    {
      flag = TRUE;
      return TRUE;
    }
  else
    {
      // Recursive call without using the current element A[i]
      solve(i+1, m);
      // Recursive call using the current element A[i]
      solve(i+1, m-A[i]);
    }
}

