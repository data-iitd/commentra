
package main

import "fmt"

func main() {
 var m, n int // Declare variables to store the dimensions of matrix A and vector B
 var i, j int // Declare loop variables
 var A [100][100]int // Declare a 2D array to store matrix A
 var B [100]int // Declare an array to store vector B
 var S [100]int // Declare an array to store the result of matrix multiplication

 fmt.Scan(&m, &n) // Read the dimensions of matrix A and vector B

 // Read the elements of matrix A row by row
 for i = 0; i < m; i++ {
   for j = 0; j < n-1; j++ {
     fmt.Scan(&A[i][j])
   }
   fmt.Scan(&A[i][n-1]) // Read the last element of the row with a newline character
 }

 // Read the elements of vector B
 for i = 0; i < n; i++ {
   fmt.Scan(&B[i])
 }

 // Perform matrix multiplication of A and B and store the result in array S
 for i = 0; i < m; i++ {
   for j = 0; j < n; j++ {
     S[i] = S[i] + A[i][j]*B[j]
   }
 }

 // Print the elements of array S
 for i = 0; i < m; i++ {
   fmt.Println(S[i])
 }

}

