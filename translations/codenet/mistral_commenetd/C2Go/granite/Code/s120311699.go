

package main // Starting the main package

import "fmt" // Importing the standard input output library

func main(){ // Starting the main function
  var a,b,c int // Declaring three integer variables a, b, and c
  fmt.Scan(&a,&b,&c) // Reading three integers from the standard input and storing them in variables a, b, and c

  if a<b && b<c{ // Starting the if condition block
    fmt.Println("Yes") // If the condition is true, print "Yes" to the standard output
  }else{ // Starting the else condition block
    fmt.Println("No") // If the condition is false, print "No" to the standard output
  }
}

