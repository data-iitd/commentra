package main

import (
        "fmt"
)

// solution function takes an integer n and a slice of integers a.
// It calculates the maximum frequency of any number or its two consecutive successors in the array.
func solution(n int, a []int) int {
        // Create a memoization array to count occurrences of numbers and their successors.
        var memo [1e5 + 2]int
        
        // Iterate through each number in the input array.
        for _, num := range a {
                // Increment the count for the current number and its two successors.
                memo[num]++
                memo[num+1]++
                memo[num+2]++
        }
        
        // Initialize the output variable to track the maximum frequency found.
        out := 0
        
        // Iterate through the memoization array to find the maximum frequency.
        for _, num := range memo {
                // Update the output if the current count is greater than the current maximum.
                if num > 0 {
                        out = max(out, num)
                }
        }
        
        // Return the maximum frequency found.
        return out
}

// max function returns the greater of two integers x and y.
func max(x, y int) int {
        if x > y {
                return x
        }
        return y
}

// main function is the entry point of the program.
func main() {
        // Declare a variable to hold the number of elements.
        var n int
        
        // Read the number of elements from standard input.
        fmt.Scan(&n)
        
        // Create a slice to hold the input integers.
        a := make([]int, n)
        
        // Read each integer into the slice.
        for i := range a {
                fmt.Scan(&a[i])
        }
        
        // Call the solution function and print the result.
        fmt.Println(solution(n, a))
}
