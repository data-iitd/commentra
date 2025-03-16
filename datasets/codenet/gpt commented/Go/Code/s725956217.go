package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// out is a utility function to print output to the console.
func out(x ...interface{}) {
	fmt.Println(x...)
}

// sc is a scanner for reading input from standard input.
var sc = bufio.NewScanner(os.Stdin)

// getInt reads an integer from input and returns it.
func getInt() int {
	sc.Scan() // Read the next token from input
	i, e := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i // Return the integer
}

// getString reads a string from input and returns it.
func getString() string {
	sc.Scan() // Read the next token from input
	return sc.Text() // Return the string
}

// max returns the maximum of two integers.
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// min returns the minimum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// asub returns the absolute difference between two integers.
func asub(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

// abs returns the absolute value of an integer.
func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

// lowerBound returns the index of the first element in a that is not less than x.
func lowerBound(a []int, x int) int {
	idx := sort.Search(len(a), func(i int) bool {
		return a[i] >= x
	})
	return idx
}

// upperBound returns the index of the first element in a that is greater than x.
func upperBound(a []int, x int) int {
	idx := sort.Search(len(a), func(i int) bool {
		return a[i] > x
	})
	return idx
}

// shop represents a shop with a price (a) and available quantity (b).
type shop struct {
	a, b int
}

// Datas is a slice of shop, implementing sort.Interface.
type Datas []shop

// Len returns the number of elements in the slice.
func (p Datas) Len() int {
	return len(p)
}

// Swap exchanges the elements with indexes i and j.
func (p Datas) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Less reports whether the element with index i should sort before the element with index j.
func (p Datas) Less(i, j int) bool {
	return p[i].a < p[j].a // Sort by price (a)
}

// main is the entry point of the program.
func main() {
	sc.Split(bufio.ScanWords) // Split input by whitespace

	// Read the number of shops (N) and the total quantity needed (M)
	N, M := getInt(), getInt()
	s := make(Datas, N) // Create a slice to hold the shops

	// Read the price and quantity for each shop
	for i := 0; i < N; i++ {
		a, b := getInt(), getInt() // Read price (a) and quantity (b)
		s[i] = shop{a, b} // Store the shop information
	}
	sort.Sort(s) // Sort the shops by price

	total := 0 // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for _, e := range s {
		n := min(e.b, M) // Determine how much can be bought from this shop
		total += n * e.a // Add to total cost
		M -= n // Decrease the remaining quantity needed
		if M == 0 {
			break // Stop if the required quantity is met
		}
	}
	out(total) // Output the total cost
}
