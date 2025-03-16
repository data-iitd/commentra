
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Initializing scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to split input into words
func sc.Split(split func(string) []string) {
	sc.Scan()
	sc.Text() // Read the whole line
	data := strings.Fields(sc.Text()) // Split the line into words
	split(data)
}

// Function to read next integer from input
func nextInt() int {
	// Reading next token as a string
	sc.Scan()
	// Converting the string to integer
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// Main function
func main() {
	// Initializing scanner for reading input from stdin
	sc.Split(bufio.ScanWords)

	// Reading the number of elements in the array
	n := nextInt()

	// Allocating memory for the array
	ar := make([]int, 3*n)

	// Reading elements of the array
	for i := range ar {
		// Reading next integer and storing it in the array
		ar[i] = nextInt()
	}

	// Sorting the array in ascending order
	sort.Ints(ar)

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	sum := 0
	for i := 0; i < n; i++ {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3*n-(i+1)*2]
	}

	// Printing the result
	fmt.Println(sum)
}

