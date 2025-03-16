#include <stdio.h>
#include <string.h>

int main()
{
  # Declare a character array to hold the input string (maximum length 20 + 1 for null terminator)
  str = input("Enter a string: ")
  len = len(str)

  # Loop through the string in reverse order
  for i in range(len - 1, -1, -1):
    # Output each character of the string in reverse
    print(str[i], end="")

  # Print a newline character after the reversed string
  print()

  # Return 0 to indicate successful completion of the program
  return 0
}

