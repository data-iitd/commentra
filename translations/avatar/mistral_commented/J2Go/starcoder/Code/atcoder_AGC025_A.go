
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

// Function to find the sum of digits of a given number
func sum(a int) int {
ans := 0
for a >= 10 {
ans += a % 10
a /= 10
}
ans += a
return ans
}

// Main function starts here
func main() {
var N int
var n int
var ans int
var A int

// Read the first integer from the standard input
fmt.Scanln(&N)

// Check if the number is even or odd and calculate n accordingly
if N%2 == 0 {
n = N / 2
} else {
n = (N + 1) / 2
}

// Calculate the sum of digits of 1 and the number N-1
ans = sum(1) + sum(N-1)

// Find the answer by checking all possible pairs of subarrays
for A = 1; A <= n; A++ {
if sum(A) + sum(N-A) < ans {
ans = sum(A) + sum(N-A)
}
}

// Print the answer
fmt.Println(ans)
}

