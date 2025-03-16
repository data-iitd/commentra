package main

import "fmt" // Importing the fmt package for formatted I/O operations

func main() { // The main function is the starting point of the program
  
  var x int // Declaring an integer variable named x

  fmt.Scan(&x) // Reading an integer value from the standard input and storing it in the variable x

  if x == 0 { // If the value of x is 0, then print the value 1 followed by a newline character
    fmt.Println("1")
  }
  if x == 1 { // If the value of x is 1, then print the value 0 followed by a newline character
    fmt.Println("0")
  }
}

