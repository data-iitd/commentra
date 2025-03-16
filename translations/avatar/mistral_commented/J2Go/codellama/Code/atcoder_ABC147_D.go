
package main

import (
 "fmt"
 "math"
 "os"
 "strconv"
 "strings"
)

func main() {

 // Declaring the variables
 var n int
 var div int
 var A []int
 var ans int

 // Reading the input
 fmt.Scan(&n)
 A = make([]int, n)
 for i := 0; i < n; i++ {
 fmt.Scan(&A[i])
 }

 // Calculating the answer
 for i := 0; i < 60; i++ {
 var a int
 var count1 int

 // Counting the number of elements in the array A with the i-th bit set to 1
 for j := 0; j < n; j++ {
 if (A[j] >> i & 1) == 1 {
 count1++
 }
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1*(n-count1)

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for j := 0; j < i; j++ {
 a = (a << 1) % div
 }

 // Adding the contribution to the answer
 ans += a
 ans %= div
 }

 // Printing the answer
 fmt.Println(ans)

 // End of code
 fmt.Println("