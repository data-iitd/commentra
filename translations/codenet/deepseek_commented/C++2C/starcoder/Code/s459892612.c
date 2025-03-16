#include <stdio.h>
#include <stdlib.h>

int main(){
  // Declare three integer variables to store user input
  int a, b, c;
  
  // Read three integers from the standard input
  scanf("%d %d %d", &a, &b, &c);

  // Check if the sum of a and b is greater than or equal to c
  if (a + b >= c){
    // If true, print "Yes"
    printf("Yes\n");
  } else {
    // Otherwise, print "No"
    printf("No\n");
  }
  
  // Return 0 to indicate successful execution
  return 0;
}
