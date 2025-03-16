
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char W[100]; // Declare a character array named W to store the input word

  // Read the input word from the standard input stream using scanf
  scanf("%s",W);

  // Sort the characters in the string W in ascending order using the qsort function from the <stdlib.h> library
  qsort(W,strlen(W),sizeof(char),compare);

  // Initialize a character pointer named itr to point to the first character in the sorted string W
  char *itr = W;

  // Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
  for (; *itr != '\0'; itr++)
  {
    // Check if the current character and the next character in the string are the same
    if(*itr != *(itr+1))
    {
      // If they are not the same, print "No" to the standard output stream and return from the main function
      printf("No\n");
      return 0;
    }
  }

  // If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
  printf("Yes\n");

  // Return 0 to indicate successful execution of the main function
  return 0;
}

int compare(const void *a, const void *b)
{
  return *(char *)a - *(char *)b;
}

