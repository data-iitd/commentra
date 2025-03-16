
#include <stdio.h> // Include the standard input/output library

int main() {
  	char str[100]; // Declare a string variable named 'str'

  	scanf("%s", str); // Read a string input from the standard input and assign it to the 'str' variable

  	// Check if the third and fourth characters of the string are identical
  	if (str[2] == str[3]) {
      // If the condition is true, proceed to the next check
      if (str[4] == str[5]) { // Check if the fifth and sixth characters are identical
         printf("Yes\n"); // If both conditions are true, print 'Yes' to the standard output
      }
      else {
         printf("No\n"); // If not, print 'No' instead
      }
  	}
}

