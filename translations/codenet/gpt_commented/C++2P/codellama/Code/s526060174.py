#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  // Declare variables for the number of groups (n) and the maximum number (m)
  int n, m;
  // Declare variables for the number of elements in each group (k) and the individual element (a)
  int k, a;
  # Declare an array to count occurrences of each number from 1 to m
  x = [0] * 31
  
  # Read the number of groups (n) and the maximum number (m)
  cin >> n >> m;

  # Loop through each group
  for i in range(n):
    # Read the number of elements in the current group
    cin >> k;
    # Loop through each element in the current group
    for j in range(k):
      # Read the element and increment its count in the array
      cin >> a;
      x[a] += 1;
  
  # Initialize the answer variable to count how many numbers appear in all groups
  ans = 0
  
  # Check each number from 1 to m
  for i in range(1, m + 1):
    # If the number appears in all n groups, increment the answer
    if x[i] == n:
      ans += 1
  
  # Output the final count of numbers that appeared in all groups
  cout << ans << endl;
  
  return 0; # End of the program
}

