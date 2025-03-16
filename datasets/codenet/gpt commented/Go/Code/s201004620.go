package main 

import "fmt"

func main() {
  // Declare a variable to hold the weather condition input
  var S string
  
  // Read the weather condition from standard input
  fmt.Scan(&S)
  
  // Use a switch statement to determine the next weather condition based on the input
  switch S {
  case "Sunny":
    // If the input is "Sunny", print "Cloudy" as the next condition
    fmt.Println("Cloudy")
  case "Cloudy":
    // If the input is "Cloudy", print "Rainy" as the next condition
    fmt.Println("Rainy")
  case "Rainy":
    // If the input is "Rainy", print "Sunny" as the next condition
    fmt.Println("Sunny")
  }
}
