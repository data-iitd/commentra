

package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  // Read input from the standard input stream using a Scanner object
  reader := bufio.NewReader ( os.Stdin )
  fmt.Fscanf ( reader, "%d %d\n", & n, & m )

  // Create an array ans of size n to store the processed strings
  ans := make ( [] string, n )

  // Iterate through each string in the input
  for i := 0 ; i < n ; i ++ {
    str, _ := reader.ReadString ( '\n' ) // Read a string from the input
    temp := "" // Initialize an empty string

    // Iterate through each character in the string
    for j := 0 ; j < m ; j ++ {
      if str [ j ] == '-' { // If the character is a '-'
        temp += "-" // Append a '-' character to temp
      } else {
        if ( i + j ) % 2 == 1 { // If the index i + j is odd
          temp += "W" // Append 'W' character to temp
        } else {
          temp += "B" // Otherwise, append 'B' character to temp
        }
      }
    }

    // Store the final string in the ans array using the index i
    ans [ i ] = temp
  }

  // Iterate through each string in the ans array and print it to the standard output stream
  for i := 0 ; i < n ; i ++ {
    fmt.Println ( ans [ i ] )
  }
}

