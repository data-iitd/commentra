package main 

import "fmt"

func main() {
  // Declare a variable to hold the input string
  var s string
  
  // Read input from the user and store it in the variable 's'
  fmt.Scan(&s)
  
  // Check if the first three characters are the same or the last three characters are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]) {
    // If the condition is true, print "Yes"
    fmt.Println("Yes")
  } else {
    // If the condition is false, print "No"
    fmt.Println("No")
  }
}
