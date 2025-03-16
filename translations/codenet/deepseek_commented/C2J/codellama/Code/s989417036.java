#include <stdio.h>
public class Main {
  public static void main(String[] args) {
    int a, b, c, d, e, i; // Declare integer variables to store input values and loop counter
    scanf("%d%d%d", &a, &b, &c); // Read three integer inputs from the user
    
    // Check if the second input (b) is less than or equal to the third input (c)
    if (b <= c) {
      printf("NO\n"); // If true, print "NO" and terminate the program
      return 0;
    } else {
      d = a; // Initialize variable d with the value of a
      e = d % b; // Calculate the remainder of d divided by b
      
      // Loop that runs b times
      for (i = 0; i < b; i++) {
        d = d % b; // Update the value of d by taking the remainder of d divided by b
        
        // Check if d equals c
        if (d == c) {
          printf("YES\n"); // If true, print "YES" and terminate the program
          return 0;
        } else if (i != 0 && d == c) { // Check if d equals c and it's not the first iteration
          printf("NO\n"); // If true, print "NO" and terminate the program
          return 0;
        }
        
        d += a; // Increment d by the value of a
      }
    }
    
    printf("NO\n"); // If the loop completes without finding a solution, print "NO" and terminate the program
    return 0;
  }
}
