
#include <iostream>

// Main function starts here
int main() {
  // Declare and initialize variables
  int n;

  // Read an integer value from the user
  std::cout << "Enter the number of integers: ";
  std::cin >> n;

  int cnt4=0, cnt2=0; // Initialize counters for 4's and 2's multiples

  // Iterate through each integer input
  for(int i=0;i<n;i++){
    int wk; // Declare and initialize a variable to store the current integer input

    // Read an integer value from the user
    std::cout << "Enter an integer: ";
    std::cin >> wk;

    // Check if the current integer is a multiple of 4
    if(wk%4==0)
      cnt4++; // Increment the counter for 4's multiples
    // Check if the current integer is a multiple of 2
    else if(wk%2==0)
      cnt2++; // Increment the counter for 2's multiples
  }

  // Check the condition to determine the output
  if(cnt4+cnt2/2 >= n/2)
    std::cout << "Yes\n"; // Output "Yes" if the condition is true
  else
    std::cout << "No\n"; // Output "No" if the condition is false

	// Main function ends here
	return 0;
}
