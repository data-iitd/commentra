
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize an empty map to store the frequency of each number
	m := make(map[int]int)

	// Read the number of test cases N
	N := ReadInt()
	// Read the N integers and store their frequencies in the map
	for i := 0; i < N; i++ {
		num := ReadInt()
		m[num]++
	}

	// Read the number of queries M
	M := ReadInt()
	// For each query, read the number B and the index C, and update the frequency of the number at index C in the map
	for i := 0; i < M; i++ {
		B, C := ReadInt(), ReadInt()
		m[C] += B
	}

	// Create a slice of integers from the map keys
	ints := make([]int, len(m))
	i := 0
	// Populate the slice with the map keys
	for k, _ := range m {
		ints[i] = k
		i++
	}

	// Sort the slice in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(ints)))

	// Initialize variables for calculating the sum
	rest := N
	sum := 0
	// Iterate through the sorted slice of integers
	for _, i := range ints {
		num := m[i]
		// If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
		if num >= rest {
			sum += rest * i
			break
		}
		// Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
		sum += num * i
		rest -= num
	}

	// Print the result
	fmt.Println(sum)
}

var reader = bufio.NewReader(os.Stdin)

func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err)
	}
}
func ReadInt() (i int) { Scan(&i); return }

