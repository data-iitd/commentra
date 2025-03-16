package main

import "fmt"

// Function to check if a given string is a palindrome
func isPalindrome(s string) bool {
  // Loop through the first half of the string
  for i := 0; i < len(s)/2; i++ {
    // Compare characters from the start and end of the string
    if s[i] == s[len(s)-1-i] {
      continue // If they match, continue to the next iteration
    } else {
      return false // If they don't match, return false
    }
  }
  return true // If all characters matched, return true
}

func main() {
  var s string // Declare a string variable to hold user input
  fmt.Scan(&s) // Read input from the user

  // Check if the entire string is a palindrome and if the first half is also a palindrome
  if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
    fmt.Println("Yes") // Output "Yes" if both conditions are true
  } else {
    fmt.Println("No") // Output "No" if either condition is false
  }
}

