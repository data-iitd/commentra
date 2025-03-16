package main

import (
	"fmt"
	"math"
)

func main() { // The main function to execute the program logic
	var N int
	fmt.Scan(&N) // Read an integer input from the user and assign it to N
	i := 1      // Initialize the variable i to 1
	ans := 0    // Initialize the variable ans to 0

	for int(math.Pow(10, float64(i))) <= N { // Start a while loop that continues as long as 10^i is less than or equal to N
		ans += int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1))) // Add the difference between 10^i and 10^(i-1) to ans
		i += 2 // Increment i by 2 for the next iteration
	}
	ans += max(0, N-int(math.Pow(10, float64(i-1)))+1) // Add the maximum of 0 and N - 10^(i-1) + 1 to ans
	fmt.Println(ans) // Print the final value of ans
}

func max(a, b int) int { // Helper function to return the maximum of two integers
	if a > b {
		return a
	}
	return b
}

// The program will execute the main function when run
