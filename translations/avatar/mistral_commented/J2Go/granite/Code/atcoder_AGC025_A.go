

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

// Function to find the sum of digits of a given number
func sum(a int) int {
 ans := 0 // Initialize answer variable
 for a >= 10 { // While number has digits greater than 0
 ans += a % 10 // Add current digit to answer
 a /= 10 // Remove current digit from number
 }
 ans += a // Add the last digit to answer
 return ans // Return the sum of digits
}

// Main function starts here
func main() {
 scanner := bufio.NewScanner(os.Stdin) // Initialize scanner to read input
 scanner.Scan() // Read the first integer from the standard input
 N, _ := strconv.Atoi(scanner.Text()) // Convert the input to an integer
 n := 0 // Initialize variable to store half of the number
 if N%2 == 0 { // Check if the number is even or odd and calculate n accordingly
 n = N / 2 // If even, n is the number divided by 2
 } else {
 n = (N + 1) / 2 // If odd, n is the number divided by 2 and rounded up
 }
 ans := sum(1) + sum(N-1) // Calculate the sum of digits of 1 and the number N-1
 for A := 1; A <= n; A++ { // Find the answer by checking all possible pairs of subarrays
 if sum(A)+sum(N-A) < ans { // If the sum of digits of current subarray and its complement is less than the current answer
 ans = sum(A) + sum(N-A) // Update the answer if a new pair is found with a greater sum
 }
 }
 fmt.Println(ans) // Print the answer
}

