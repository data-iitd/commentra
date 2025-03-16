
#include <iostream> // Include the standard input/output library

using namespace std; // Use the standard namespace

int main(){ // Start of the main function
  int K, X; // Declare two integer variables K and X
  cin >> K >> X; // Read two integers from the standard input and store them in variables K and X

  for(int i=X-K+1;i<=X+K-1;i++){ // Start of the for loop
    cout << i; // Print the current value of i to the standard output
    if(i<X+K-1) cout << " "; // If the current value of i is less than X+K-1, print a space before the number
  }

  cout << endl; // Print a newline character to move the cursor to the next line
  return 0; // End of the main function with a successful return status
}

