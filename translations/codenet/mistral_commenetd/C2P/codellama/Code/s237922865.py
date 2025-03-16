#include <stdio.h>

# Main function starts here
int main() {
  # Declare and initialize variables
  n = 0

  # Read an integer value from the user
  print("Enter the number of integers: ")
  scanf("%d",&n)

  cnt4 = 0 # Initialize counters for 4's and 2's multiples
  cnt2 = 0

  # Iterate through each integer input
  for i in range(n):
    wk = 0 # Declare and initialize a variable to store the current integer input

    # Read an integer value from the user
    print("Enter an integer: ")
    scanf("%d",&wk)

    # Check if the current integer is a multiple of 4
    if wk%4 == 0:
      cnt4 += 1 # Increment the counter for 4's multiples
    # Check if the current integer is a multiple of 2
    elif wk%2 == 0:
      cnt2 += 1 # Increment the counter for 2's multiples

  # Check the condition to determine the output
  if cnt4 + cnt2/2 >= n/2:
    print("Yes\n") # Output "Yes" if the condition is true
  else:
    print("No\n") # Output "No" if the condition is false

  # Main function ends here
  return 0
}
