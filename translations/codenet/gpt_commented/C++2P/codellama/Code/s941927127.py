#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  // Declare a string variable to hold the input
  string W;
  
  // Read input string from the user
  cin >> W;
  
  // Sort the characters in the string in ascending order
  sort(W.begin(), W.end());

  # <START-OF-CODE>
  # Iterate through the sorted string, checking pairs of characters
  for i in range(len(W)):
    # Check if the current character is not equal to the next character
    if W[i] != W[i+1]:
      # If they are not equal, print "No" and exit the program
      print("No")
      return 0
  # If all pairs are equal, print "Yes"
  print("Yes")
  # Return 0 to indicate successful completion of the program
  return 0
  # 