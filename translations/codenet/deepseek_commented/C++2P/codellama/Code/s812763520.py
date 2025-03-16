#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, ans = 0; // Declare integer n and initialize ans to 0
  string a, b, c; // Declare three strings a, b, and c
  cin >> n; // Read the integer n from standard input
  cin >> a >> b >> c; // Read the three strings a, b, and c from standard input
  
  # Loop through each character position up to n
  for i in range(n):
    # Check if all three characters at position i are the same
    if a[i] == b[i] and b[i] == c[i]:
      # Do nothing
      pass
    # Check if any two characters at position i are the same
    elif a[i] == b[i] or b[i] == c[i] or a[i] == c[i]:
      ans += 1 # Increment ans by 1
    # If all three characters at position i are different
    else:
      ans += 2 # Increment ans by 2
  print(ans) # Print the final value of ans
}

