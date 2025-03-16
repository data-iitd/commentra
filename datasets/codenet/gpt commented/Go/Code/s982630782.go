package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize a map to count occurrences of integers
	m := make(map[int]int)

	// Read the number of initial integers (N) and the number of operations (M)
	N, M := ReadInt(), ReadInt()

	// Read N integers and count their occurrences in the map
	for i := 0; i < N; i++ {
		m[ReadInt()]++
	}

	// Process M operations, where each operation adds B occurrences of integer C
	for i := 0; i < M; i++ {
		B, C := ReadInt(), ReadInt()
		m[C] += B
	}

	// Create a slice to hold the unique integers from the map
	ints := make([]int, 0, len(m))
	for i := range m {
		ints = append(ints, i)
	}

	// Sort the integers in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(ints)))

	// Initialize variables to keep track of remaining integers and the total sum
	rest := N
	sum := 0

	// Calculate the maximum sum based on the sorted integers
	for _, i := range ints {
		num := m[i]
		// If the number of occurrences is greater than or equal to the remaining count
		if num >= rest {
			sum += rest * i // Add the product of remaining count and the integer
			break // Exit the loop as we have used all remaining integers
		}
		sum += num * i // Add the product of occurrences and the integer to the sum
		rest -= num // Decrease the remaining count by the number of occurrences
	}

	// Output the final calculated sum
	fmt.Println(sum)
}

// Initialize a buffered reader for input
var reader = bufio.NewReader(os.Stdin)

// Scan reads input and handles any errors
func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err) // Panic if there is an error during scanning
	}
}

// ReadInt reads an integer from input and returns it
func ReadInt() (i int) { Scan(&i); return }
