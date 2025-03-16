
// C++ program to find the maximum sum of a subarray

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray
// of size c+1, where c ranges from 1 to n-2
int maxSum(int n, int s[])
{
  // Initialize two integer variables m and f
  int m = 0, f = 0;

  // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for (int c = 1; c < n-1; c++) {
    // Initialize a variable f to 0
    f = 0;

    // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for (int k = 0; c < n-1-k*c; k++) {
      // Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c];

      // Update the value of m if the current sum is greater than the previous maximum sum
      if (m < f) { m = f; }
    }
  }

  // Return the maximum sum
  return m;
}

// Driver code
int main()
{
  // Initialize the input stream
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // Read the first integer from the input
  int n;
  cin >> n;

  // Read the second integer array from the input
  int s[n];
  for (int i = 0; i < n; i++) { cin >> s[i]; }

  // Find the maximum sum of a subarray of size c+1, where c ranges from 1 to n-2
  cout << maxSum(n, s);

  return 0;
}

// C++ program to find the maximum sum of a subarray ends here

