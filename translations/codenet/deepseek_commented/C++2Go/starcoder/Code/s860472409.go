<<<<<<< HEAD
import "fmt"
func main() {
  var N, ans, i, count int // Declare variables to store the number of elements, answer, index, and count
  fmt.Scanf("%d", &N) // Read the number of elements N
  var A [N]int // Declare an array A with N elements
  for i = 0; i < N; i++ { // Loop to read N elements into the array A
    fmt.Scanf("%d", &A[i])
  }
  i = 0 // Initialize index i to 0
  ans = 0 // Initialize answer variable ans to 0
  count = 0 // Initialize count variable to 0
  for i < N; i++ { // Continue the loop until the next element is NULL
    if A[i] == A[i+1] { // Check if the current element is equal to the next element
      count++ // Increment the count
      if count % 2!= 0 { // Check if the count is odd
        ans++ // Increment the answer variable ans
      }
    } else {
      count = 0 // Reset the count to 0 if the current element is not equal to the next element
    }
  }
  fmt.Printf("%d\n", ans) // Print the value of ans
=======
package main
import (
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  var N int
  fmt.Scanf("%d\n", &N)
  var A [N]int
  for i := 0; i < N; i++ {
    fmt.Scanf("%d\n", &A[i])
  }
  i := 0
  ans := 0
  count := 0
  for i < N-1 {
    if A[i] == A[i+1] {
      count++
      if count%2!= 0 {
        ans++
      }
    } else {
      count = 0
    }
    i++
  }
  fmt.Printf("%d\n", ans)
>>>>>>> 98c87cb78a (data updated)
}
