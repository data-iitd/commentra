package main

import (
 "fmt"
 "math"
 "time"
)

func main() {
 startTime := time.Now().UnixMilli() // Start time measurement
 var n int
 fmt.Scan(&n) // Reading the number of elements in the array
 const div = 1000000007 // Modulus constant for efficient modular arithmetic
 var A = make([]int64, n) // Creating an array of int64 type with size n
 var ans int64 = 0 // Initializing the answer variable to zero

 // Reading the elements of the array A
 for i := 0; i < n; i++ {
 fmt.Scan(&A[i]) // Reading an element of the array A
 }

 // Calculating the answer using the given formula
 for i := 0; i < 60; i++ { // Looping through all the bits from 0 to 59
 var a int64 = 0 // Initializing the variable a to zero
 var count1 int64 = 0 // Initializing the variable count1 to zero

 // Counting the number of elements in the array A with the i-th bit set to 1
 for j := 0; j < n; j++ {
 if (A[j] & (1 << i)) != 0 { // Checking if the i-th bit is set in the j-th element of the array A
 count1++ // Incrementing the count1 variable
 }
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1 * (int64(n) - count1) // a = a + (count1 * (n - count1))

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for j := 0; j < i; j++ {
 a = (a << 1) % div // a = (a << 1) % div
 }

 // Adding the contribution to the answer
 ans += a // ans += a
 ans %= div // ans %= div
 }

 // Printing the answer
 fmt.Println(ans) // Printing the answer
 endTime := time.Now().UnixMilli() // End time measurement
 fmt.Println("Time taken by the program is :", (endTime - startTime), "milliseconds") // Printing the time taken by the program to execute
}

