
package main

import "fmt"

func main() {
 var m, n int
 fmt.Scanf("%d %d\n", &m, &n)

 A := make([][]int, m)
 for i := 0; i < m; i++ {
  A[i] = make([]int, n-1)
  for j := 0; j < n-1; j++ {
   fmt.Scanf("%d ", &A[i][j])
  }
  fmt.Scanf("%d\n", &A[i][n-1])
 }

 B := make([]int, n)
 for i := 0; i < n; i++ {
  fmt.Scanf("%d\n", &B[i])
 }

 S := make([]int, m)
 for i := 0; i < m; i++ {
  for j := 0; j < n; j++ {
   S[i] += A[i][j] * B[j]
  }
 }

 for i := 0; i < m; i++ {
  fmt.Printf("%d\n", S[i])
 }
}

