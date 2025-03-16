
#include <iostream>
using namespace std;

// The main function is the starting point of the program
int main(void){
  int i, N, x; // Declare and initialize three integer variables: i, N, and x
  x = 0; // Initialize x to 0

  // Prompt the user to enter a number
  cout << "Enter a number: ";
  cin >> N;

  // Use a for loop to iterate from 1 to N and sum up the numbers
  for(i=1; i<=N; i++){
    x += i; // Add the current value of i to x
  }

  // Print the sum of the numbers to the console
  cout << "The sum of numbers from 1 to " << N << " is: " << x << endl;

  // Return 0 upon successful execution
  return 0;
}

