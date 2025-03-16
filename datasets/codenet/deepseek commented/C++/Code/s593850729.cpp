#include <iostream> // Include necessary headers for input and output operations
using namespace std; // Use the standard namespace

int main()  { // The main function is the entry point of the program
  int A, B, C, X; // Declare variables to store the input values
  cin >> A >> B >> C >> X; // Read the values of A, B, C, and X from the standard input
  
  int cnt = 0; // Initialize a counter to count the number of combinations
  for (int a = 0; a <= A; a++) { // Iterate over the possible values of a (0 to A)
    for (int b = 0; b <= B; b++) { // Iterate over the possible values of b (0 to B)
      for (int c = 0; c <= C; c++) { // Iterate over the possible values of c (0 to C)
        int total = 500*a + 100*b + 50*c; // Calculate the total value of the coins
        if (total == X) cnt++; // If the total equals X, increment the counter
      }
    }
  }
  cout << cnt << endl; // Output the number of combinations that sum up to X
  
}
