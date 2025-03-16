

package main

import "fmt"

func main() {
  var i, a, b, s int
  var count [4]int

  // Initialize the count array with zeros
  for i = 0; i < 4; i++ {
    count[i] = 0
  }

  // Read three pairs of numbers from the user and update the count array accordingly
  for i = 0; i < 3; i++ {
    fmt.Scan(&a, &b) // Read two numbers a and b from the user
    count[a-1]++ // Increment the count of number a in the count array
    count[b-1]++ // Increment the count of number b in the count array
  }

  // Calculate the product of all counts in the count array
  s = 1
  for i = 0; i < 4; i++ {
    s *= count[i]
  }

  // Check if the product of all counts is equal to 4
  if s == 4 {
    fmt.Println("YES") // If yes, print "YES" to the console
  } else {
    fmt.Println("NO") // Else, print "NO" to the console
  }
}

// 