#include<stdio.h>

int main(){
  // Declare three integer variables to hold the input values
  int a, b, c;

  // Read three integers from user input
  scanf("%d %d %d", &a, &b, &c);

  // Check if the first number is less than the second and the second is less than the third
  if(a < b && b < c){
    // If the condition is true, print "Yes"
    printf("Yes\n");
  } else {
    // If the condition is false, print "No"
    printf("No\n");
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}
