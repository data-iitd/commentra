#include <stdio.h>

// The main function is the entry point of the program
int main(){
  // Declare variables
  int key, i, j, len, a[101];

  // Read the length of the array from the user
  printf("Enter the length of the array: ");
  scanf("%d", &len);

  // Read the elements of the array from the user
  printf("Enter %d integers: ", len);
  for(i = 0;i < len;i++) {
    scanf("%d", a + i);
  }

  // Sort the array using bubble sort algorithm
  for(j = 1;j < len;j++){
    // Iterate through the array and compare each element with the current key
    for(i = 0;i < len;i++) {
      // If the current element is not the first one, print it with a space
      if(i != 0) printf(" %d", a[i]);
      // Otherwise, print it without a space
      else printf("%d", a[i]);
    }
    // Print a new line after each pass
    puts("");

    // Set the current key to the next element
    key = a[j];

    // Swap the current key with the previous element if it is greater
    for(i = j - 1;i >= 0 && a[i] > key;i--) {
      a[i + 1] = a[i];
    }

    // Swap the current key with the previous element
    a[i + 1] = key;
  }

  // Print the sorted array
  for(i = 0;i < len;i++) {
    // If the current index is not the first one, print it with a space
    if(i != 0) printf(" %d", a[i]);
    // Otherwise, print it without a space
    else printf("%d", a[i]);
  }
  // Print a new line after printing the sorted array
  puts("");

  // Return 0 to indicate successful execution
  return 0;
}

