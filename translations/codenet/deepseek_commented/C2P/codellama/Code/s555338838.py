#include <stdio.h>

int main():
  int key, i, j, len, a[101];
  
  # Step 1: Read the length of the array
  scanf("%d", &len);
  
  # Step 2: Read the elements of the array
  for i in range(len):
    scanf("%d", a + i);

  # Step 3: Perform Insertion Sort
  for j in range(1, len):
    # Print the array before each iteration
    for i in range(len):
      printf(i != 0 ? " %d":"%d", a[i]);
    puts("");
    
    # Store the current element to be inserted
    key = a[j];
    
    # Shift elements to the right to make space for the key
    for i in range(j - 1, -1, -1):
      if a[i] > key:
        a[i + 1] = a[i];
      else:
        break;
    
    # Insert the key into the correct position
    a[i + 1] = key;

  # Step 4: Print the sorted array
  for i in range(len):
    printf(i != 0 ? " %d": "%d", a[i]);
  puts("");
  return 0;

