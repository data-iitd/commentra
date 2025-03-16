
#include<iostream> // Include standard input/output library for input/output operations
#include<string> // Include string library for string manipulation
#include<vector> // Include vector library for dynamic array operations

using namespace std; // Use the standard namespace for convenience

int main(){
  int n; // Declare variable for number of elements
  cin >> n; // Read the number of elements from the standard input

  vector<int> h(n); // Declare a dynamic array to store heights of elements
  int max = -1; // Initialize max to -1 to store the maximum height found
  int flag = 0; // Initialize flag to 0 to indicate whether the condition is met

  // Loop to read heights and update the maximum height found
  for(int i = 0; i < n; i++){
    cin >> h[i]; // Read the height of the i-th element
    if(max < h[i]) max = h[i]; // Update max if the current height is greater than max

    if(max - h[i] >= 2) flag = 1; // Check if the difference between max and current height is at least 2
  }

  if(flag == 1) cout << "No" << endl; // Print "No" if the condition is met
  else cout << "Yes" << endl; // Print "Yes" if the condition is not met

  return 0; // Return 0 to indicate successful execution
}

