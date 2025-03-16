
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Define macros for maximum and minimum values
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

// Function to compare integers in descending order
func compare_int(a, b int) int {
	return b - a // Bigger first
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Main function
func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input values
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.ParseInt(read(reader), 10, 64)
	q, _ := strconv.Atoi(read(reader))
	a := make([]int, q)

	// Process each query to update points
	for i := 0; i < q; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}

	// Determine if each player can reach the required points
	for i := 0; i < n; i++ {
		if k-(int64(q)-int64(count(a, i+1))) > 0 {
			fmt.Println("Yes") // Player can reach the required points
		} else {
			fmt.Println("No") // Player cannot reach the required points
		}
	}
}

// Function to read input from the reader
func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

// Function to count the occurrences of a specific value in an array
func count(arr []int, val int) int {
	count := 0
	for _, v := range arr {
		if v == val {
			count++
		}
	}
	return count
}

// Translate the above Go code to Rust and end with comment "