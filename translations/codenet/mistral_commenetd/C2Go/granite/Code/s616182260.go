

package main

import "fmt"

func main() {
  var a, b, c [3][3]int // Declare three 3x3 matrices 'a', 'b', and 'c'
  var i, j int // Declare two integer variables 'i' and 'j'

  // Initialize the matrix 'c' with user input
  for i = 0; i < 3; i++ {
    fmt.Printf("Enter the elements of row %d: ", i+1)
    fmt.Scan(&c[i][0], &c[i][1], &c[i][2])
    // Scan the three elements of each row and store them in the matrix 'c'
  }

  // Initialize array 'a' with the first row of matrix 'c'
  a[0][0] = 0
  for i = 0; i < 3; i++ {
    b[0][i] = c[0][i] // Store the elements of the first row of matrix 'c' in array 'b'
  }

  // Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
  for i = 1; i < 3; i++ {
    a[i][0] = c[i][0] - b[0][0] // Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b' and store the result in array 'a'
  }

  // Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
  for i = 0; i < 3; i++ {
    for j = 0; j < 3; j++ {
      if c[i][j]!= a[i][0]+b[0][j] { // Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
        fmt.Println("No") // If not, print "No" and exit the program
        return
      }
    }
  }

  // If all the elements in matrix 'c' match the condition, print "Yes"
  fmt.Println("Yes")
}

