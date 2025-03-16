
package main

import (
  "fmt"
  "math"
  "os"
  "strconv"
  "strings"
)

func main() {
  // Read the first integer N from the standard input
  N, _ := strconv.Atoi(os.Args[1])

  // Read the second integer K from the standard input
  K, _ := strconv.Atoi(os.Args[2])

  // Read the string S from the standard input
  S := os.Args[3]

  // Initialize a boolean variable firstTime to true
  firstTime := true

  // Initialize an integer variable step to 1
  step := 1

  // Perform the main logic while K is greater than zero
  for K > 0 {
    // Create a new string T to store the reversed version of S
    T := Reverse(S)

    // Create a new string revU to store the concatenation of S and T reversed
    revU := Reverse(S + T)

    // Create a string variable sDash to store the current substring of revU
    sDash := S

    // Iterate through the substrings of revU starting from the end of S
    for i := N; i >= 0; i -= step {
      // Get the substring of revU starting from the current index i and of length N
      tmp := revU[i : i+N]

      // Compare the current substring tmp with the current substring sDash
      if sDash > tmp {
        // Update the current substring sDash with the new substring tmp
        sDash = tmp
      } else {
        // If this is not the first iteration, break the loop
        if !firstTime {
          break
        }
      }
    }

    // Perform some actions based on the comparison of sDash and S
    if firstTime {
      firstTime = false
      // Check if the length of S raised to the power of K is greater than N
      if math.Pow(2, float64(K)) > float64(N) {
        // Print the first character of S N times and exit the program
        for i := 0; i < N; i++ {
          fmt.Print(S[0])
        }
        fmt.Println()
        os.Exit(0)
      }
    } else {
      // Update the value of step
      step += step
    }

    // Decrement the value of K
    K--

    // Update the value of S to be the current substring sDash reversed
    S = Reverse(sDash)
  }

  // Print the reversed version of the final string S
  fmt.Println(Reverse(S))
}

// Reverse returns the reversed version of the input string
func Reverse(s string) string {
  runes := []rune(s)
  for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
    runes[i], runes[j] = runes[j], runes[i]
  }
  return string(runes)
}

