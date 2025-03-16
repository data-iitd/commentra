#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cctype>
#define INF 1000000000
using namespace std;
bool debug=false; // Global variable to enable/disable debug mode

int main(){
  // Initialize variables
  int n, k, x, y;
  cin >> n >> k >> x >> y; // Read input values for n, k, x, and y from standard input

  int sum = 0; // Initialize sum variable to 0

  # Initialize a for loop to iterate through numbers from 1 to n
  for i in range(1,n+1):
    # If the current number i is greater than k, add y to the sum
    if i>k:
      sum+=y
    # Otherwise, add x to the sum
    else:
      sum+=x

  # Output the final sum value to the standard output
  print(sum)

  return 0
}

