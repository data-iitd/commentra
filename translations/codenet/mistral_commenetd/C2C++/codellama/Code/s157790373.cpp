
#include<iostream>
#define LEN 300
#define TRUE 1
#define FALSE -1

using namespace std;

int solve(int i, int m); // Function to check if there is a subsequence of given length 'm' in the array 'A' starting from index 'i'
int n, A[LEN]; // 'n' is the size of the array 'A' and 'A' is the array to be checked
int flag; // Flag to check if a subsequence of given length 'm' is found

int main()
{
  int q, M; // 'q' is the number of queries and 'M' is the length of subsequence to be checked in each query
  int i, j, k; // Loop variables

  cin>>n; // Reading the size of the array 'A'
  for(i=0; i<n; i++)cin>>A[i]; // Reading the elements of the array 'A'

  cin>>q; // Reading the number of queries
  for(i=0; i<q; i++) // Loop through all the queries
    {
      cin>>M; // Reading the length of subsequence to be checked in the current query
      flag=FALSE; // Initializing the flag to false

      solve(0, M); // Calling the function 'solve' to check if there is a subsequence of given length 'M' in the array 'A'

      if(flag==TRUE)cout<<"yes\n"; // If a subsequence of given length 'M' is found, print 'yes'
      else cout<<"no\n"; // If no subsequence of given length 'M' is found, print 'no'
    }


  return 0;
}

int solve(int i, int m)
{
  // Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
  if(i>n)return FALSE;

  // Base case: If length 'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
  else if(m<0)return FALSE;

  // Base case: If length 'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to 'm', a subsequence of length 'm' can be formed starting from index 'i'
  else if(m==0 || m-A[i+1]==0)
    {
      flag=TRUE; // Setting the flag to true as a subsequence of length 'm' is found
      return TRUE; // Returning true to indicate that a subsequence of length 'm' is found
    }

  // Recursive case: If length 'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
  else
    {
      // Not using the element at index 'i' to form the subsequence of length 'm'
      solve(i+1, m);

      // Using the element at index 'i' to form the subsequence of length 'm'
      solve(i+1, m-A[i]);
    }
}

