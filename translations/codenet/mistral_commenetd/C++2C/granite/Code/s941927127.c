

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *W; // Declare a character pointer variable named W to store the input word

  // Allocate memory for the input word using the malloc function from the <stdlib.h> library
  W = (char *)malloc(sizeof(char) * 101);

  // Read the input word from the standard input stream using scanf
  scanf("%s", W);

  // Sort the characters in the string W in ascending order using the qsort function from the <stdlib.h> library
  qsort(W, strlen(W), sizeof(char), compare);

  // Initialize a character pointer variable named itr to point to the first character in the sorted string W
  char *itr = W;

  // Loop through the sorted string W using a while loop, with the loop condition that the current character pointed to by itr is not the null character '\0'
  while(*itr!= '\0')
  {
    // Check if the current character and the next character in the string are the same
    if(*itr!= *(itr+1))
    {
      // If they are not the same, print "No" to the standard output stream and return from the main function
      printf("No\n");
      free(W); // Free the memory allocated for the input word
      return 0;
    }
    // Increment the character pointer itr to point to the next character in the string
    itr++;
  }

  // If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
  printf("Yes\n");

  // Free the memory allocated for the input word
  free(W);

  // Return 0 to indicate successful execution of the main function
  return 0;
}

// Define a comparison function for qsort to compare two characters
int compare(const void *a, const void *b)
{
  return (*(char *)a - *(char *)b);
}

