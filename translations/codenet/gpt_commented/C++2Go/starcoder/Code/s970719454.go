package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) (n int, m int, a []int) {
	// Read the first line
	line, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	// Split the line into two parts
	parts := strings.Split(line, " ")
	// Convert the first part into an integer
	n, err = strconv.Atoi(parts[0])
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	// Convert the second part into an integer
	m, err = strconv.Atoi(parts[1])
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	// Initialize an array of size m
	a = make([]int, m)
	// Read m lines
	for i := 0; i < m; i++ {
		// Read the next line
		line, err = reader.ReadString('\n')
		if err!= nil {
			fmt.Println(err)
			os.Exit(1)
		}
		// Convert the line into an integer
		a[i], err = strconv.Atoi(line)
		if err!= nil {
			fmt.Println(err)
			os.Exit(1)
		}
	}
	return
}

// Function to print output to stdout
func printOutput(n int, m int, a []int, maxi1 int, maxi2 int) {
	// If a zero was encountered, print the maximum length considering zero
	if a[0] == 0 {
		fmt.Printf("%d\n", maxi2)
	} else {
		fmt.Printf("%d\n", maxi1)
	}
}

// Function to calculate the maximum length of a sequence of present numbers
func calculateMax(n int, a []int) (maxi1 int, maxi2 int) {
	// Initialize arrays to zero
	dp1 := make([]int, n + 1)
	dp2 := make([]int, n + 1)
	// Loop through the array
	for i := 1; i <= n; i++ {
		// If the number is present, increment the length
		if a[i - 1] == 1 {
			dp1[i] = dp1[i - 1] + 1
		}
		// Update the maximum length
		maxi1 = max(dp1[i], maxi1)
	}
	// Loop through the array
	for i := 1; i <= n; i++ {
		// If the number is present, increment the length
		if a[i - 1] == 1 {
			dp2[i] = dp2[i - 1] + 1
		} else {
			dp2[i] = dp1[i - 1] + 1
		}
		// Update the maximum length
		maxi2 = max(dp2[i], maxi2)
	}
	return
}

// Function to find the maximum of two numbers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Loop to continuously process input until a termination condition is met
	for {
		// Read the values of n and m
		n, m, a := readInput(reader)
		// Break the loop if n is 0 (termination condition)
		if n == 0 {
			break
		}
		// Calculate the maximum length of a sequence of present numbers
		maxi1, maxi2 := calculateMax(n, a)
		// Print the result based on whether a zero was encountered
		printOutput(n, m, a, maxi1, maxi2)
	}
}

