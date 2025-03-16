
package main

import (
        "fmt"
)

// Function to find the maximum number of occurrences of a number in the array
func solution(n int, a []int) int {
        // Initialize a memo table to store the number of occurrences of each number
        var memo [1e5 + 2]int

        // Iterate through the array and update the memo table
        for _, num := range a {
                // Increment the memo table for the current number and the next two numbers
                memo[num]++
                memo[num+1]++
                memo[num+2]++
        }

        // Initialize output variable to store the maximum number of occurrences found
        var out int

        // Iterate through the memo table and update the output variable if a larger number is found
        for _, num := range memo {
                if num > 0 {
                        // Update the output variable with the maximum number found so far
                        out = max(out, num)
                }
        }

        // Return the maximum number of occurrences found
        return out
}

// Function to find the maximum of two numbers
func max(x, y int) int {
        // Return the larger number between x and y
        if x > y {
                return x
        }
        return y
}

// Main function to read input and call the solution function
func main() {
        // Read the size of the array from the standard input
        var n int
        fmt.Scan(&n)

        // Allocate memory for the array and read its elements from the standard input
        a := make([]int, n)
        for i := range a {
                fmt.Scan(&a[i])
        }

        // Call the solution function and print the result
        fmt.Println(solution(n, a))
}

