#include <stdio.h>
public class Main {
  public static void main(String[] args) {
    int n, r, p, c;
    int i, j, k, l;
    int a[] = new int[51];
    int b[] = new int[51];

    while(true){ // Loop until both n and r are zero
      scanf("%d %d", &n, &r); // Read the number of elements and the number of operations
      if(n == 0 && r == 0)
        break; // Exit the loop if both n and r are zero

      // Initialize array a with elements from 1 to n
      for(i = 0; i < n; i++)
        a[i] = i + 1;

      // Perform r operations
      for(i = 0; i < r; i++){
        scanf("%d %d", &p, &c); // Read the position and count of elements to be moved

        // Copy the last c elements to be moved to array b
        for(j = 0; j < c; j++)
          b[j] = a[n - p - c + 1 + j];

        // Shift the first p-1 elements before the position where the c elements will be moved
        for(j = 0; j < p - 1; j++)
          a[n - p - c + 1 + j] = a[n - p + j + 1];

        // Place the elements from b back into array a at the correct position
        for(j = n - p - c + 1 + j, k = 0; k < c; j++, k++)
          a[j] = b[k];

        // Uncomment the following block to print the array after each operation for debugging
        /*
        for(j = 0; j < n; j++)
          printf("%d\n", a[j]);
        printf("---\n");
        */
      }
      // Print the last element of the array a after all operations
      printf("%d\n", a[n - 1]);
    }
  }
}
