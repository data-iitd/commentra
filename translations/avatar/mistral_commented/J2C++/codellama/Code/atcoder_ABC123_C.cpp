
#include <iostream>
#include <cmath>

using namespace std;

int main() {

  // Reading the first long integer input N
  long N;
  cin >> N;

  // Initializing the minimum long integer variable with the first input value
  long min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      min = 0; // Set the minimum value to the current input value
    } else { // Otherwise
      min = min < 0 ? min : 0; // Update the minimum value with the current input value if it's smaller
    }
  }

  // Printing the answer using the p method
  cout << (long)ceil((double)N/min)+4 << endl;

  return 0;
}

