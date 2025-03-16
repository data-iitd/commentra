
package main  // Define the main package

import "fmt"  // Import the standard input/output library for printf and scanf

func main(){  // Define the main function, the entry point of the program
  var a,b,c int  // Declare three integer variables
  fmt.Scan(&a,&b,&c)  // Read three integers from the standard input and store them in a, b, and c

  if a<b && b<c{  // Check if a is less than b and b is less than c
    fmt.Println("Yes")  // If true, print "Yes"
  }else{  // Otherwise
    fmt.Println("No")  // Print "No"
  }
}

