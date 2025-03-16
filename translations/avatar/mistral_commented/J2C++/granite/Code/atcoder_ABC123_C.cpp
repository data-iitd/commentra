

#include <iostream> // Including the iostream library for input and output operations
#include <cmath> // Including the cmath library for mathematical operations
#include <queue> // Including the queue container from the standard library
#include <random> // Including the random number generator from the standard library
#include <vector> // Including the vector container from the standard library

using namespace std; // Using the standard namespace for the standard library

int main() {

  // Reading the first integer input N
  int N;
  cin >> N;

  // Initializing the minimum integer variable with the first input value
  int min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      cin >> min; // Set the minimum value to the current input value
    } else { // Otherwise
      int temp;
      cin >> temp; // Read the current input value into a temporary variable
      min = min < temp? min : temp; // Update the minimum value with the current input value if it's smaller
    }
  }

  // Printing the answer using the p method
  cout << (int)ceil((double)N/min)+4 << endl;

  return 0; // Returning 0 to indicate successful program execution
}



