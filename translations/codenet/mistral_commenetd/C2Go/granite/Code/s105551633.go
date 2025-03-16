

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to find the number of digits in a given number
func digit(n int64) int {
	res := 0 // Initialize result
	for n > 0 { // While number is not zero
		res++ // Increment result by 1
		n /= 10 // Divide number by 10 to get next digit
	}
	return res // Return the result
}

// Function to run the program
func run() {
	reader := bufio.NewReader(os.Stdin) // Initialize reader for standard input
	fmt.Print("Enter a number: ") // Prompt user to enter a number
	text, _ := reader.ReadString('\n') // Read number from standard input
	n, _ := strconv.ParseInt(text, 10, 64) // Convert input to integer
	min := digit(n) // Initialize minimum with the number of digits in the number
	for i := 1; int64(i)*int64(i) <= n; i++ { // Loop from 1 to square root of the number
		if n%int64(i)!= 0 {
			continue // If current number is not a factor of the given number, skip to next iteration
		}
		a := int64(i) // Initialize first factor
		b := n / int64(i) // Initialize second factor
		min = int(math.Min(float64(min), math.Max(float64(digit(a)), float64(digit(b))))) // Update minimum with the maximum of digits in first and second factors
	}
	fmt.Println(min) // Print the minimum number of digits in any factor of the given number
}

// Main function
func main() {
	run() // Call run function to execute the program
}

