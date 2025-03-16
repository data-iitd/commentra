#include <iostream> // Include iostream for input/output operations
#include <vector>   // Include vector for dynamic array
using namespace std; // Use standard namespace

int main(){
  int n, i; // Declare variables for number of elements and loop index
  vector<int> h(100001); // Declare a vector to store heights of elements
  int max = -1; // Initialize max to -1 to store the maximum height found
  bool flag = false; // Initialize flag to false to indicate whether the condition is met

  cin >> n; // Read the number of elements from the standard input

  // Loop to read heights and update the maximum height found
  for(i = 0; i < n; i++){
    cin >> h[i]; // Read the height of the i-th element
    if(max < h[i]) max = h[i]; // Update max if the current height is greater than max

    if(max - h[i] >= 2) flag = true; // Check if the difference between max and current height is at least 2
  }

  if(flag) cout << "No" << endl; // Print "No" if the condition is met
  else cout << "Yes" << endl; // Print "Yes" if the condition is not met

  return 0; // Return 0 to indicate successful execution
}
