package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Initialize a scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to scan an integer from input
func scanInt() int {
	sc.Scan() // Read the next token from input
	iv, _ := strconv.Atoi(sc.Text()) // Convert the token to an integer
	return iv // Return the integer value
}

// Initialize the scanner to split input by whitespace
func init() {
	sc.Split(bufio.ScanWords)
}

// Main function where the program execution begins
func main() {
	// Read the number of arms
	n := scanInt()
	
	// Define a struct to represent an arm with left and right bounds
	type arm struct{ l, r int }
	
	// Create a slice to hold the arms
	as := make([]arm, n)
	
	// Read the arm data from input
	for i := range as {
		x, l := scanInt(), scanInt() // Read the center and length of the arm
		as[i].l = x - l // Calculate the left bound
		as[i].r = x + l // Calculate the right bound
	}
	
	// Sort the arms based on their right bounds
	sort.Slice(as, func(i, j int) bool { return as[i].r < as[j].r })

	// Initialize the count of non-overlapping arms and the rightmost bound
	ans := 1 // Start with the first arm
	r := as[0].r // Set the rightmost bound to the right of the first arm
	
	// Iterate through the sorted arms to count non-overlapping arms
	for i := 1; i < n; i++ {
		// If the left bound of the current arm is greater than or equal to the rightmost bound
		if as[i].l >= r {
			ans++ // Increment the count of non-overlapping arms
			r = as[i].r // Update the rightmost bound to the current arm's right bound
		}
	}
	
	// Print the total count of non-overlapping arms
	fmt.Println(ans)
}
