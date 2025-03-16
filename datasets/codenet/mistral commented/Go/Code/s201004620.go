// Package main is the entry point of the program
package main 

import "fmt"

// Function main initializes the program and starts the execution flow
func main(){
  // Declare a variable named S of type string
  var S string

  // Read a string input from the standard input using fmt.Scan
  fmt.Scan(&S)

  // Switch statement to check the value of the string S and print the corresponding weather condition
  switch S {
  case "Sunny" : // If the input string is "Sunny"
    fmt.Println("Cloudy") // Print "Cloudy" as the output
  case "Cloudy" : // If the input string is "Cloudy"
    fmt.Println("Rainy") // Print "Rainy" as the output
    case "Rainy" : // If the input string is "Rainy"
      fmt.Println("Sunny") // Print "Sunny" as the output
  }
}

// End of the code
