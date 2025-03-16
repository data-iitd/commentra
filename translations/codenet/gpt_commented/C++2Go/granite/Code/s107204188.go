
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize minA to a value larger than any possible element in A
	minA := int(1e9 + 1)
	num := 0 // Counter for the number of valid pairs

	var n, t int // Declare variables for input size, threshold, and frequency
	var f int = 0 // Frequency variable
	var err error // Error variable for input conversion

	// Read the size of the array and the threshold value
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	input = strings.TrimSpace(input)
	inputSlice := strings.Split(input, " ")
	n, err = strconv.Atoi(inputSlice[0])
	if err!= nil {
		panic(err)
	}
	t, err = strconv.Atoi(inputSlice[1])
	if err!= nil {
		panic(err)
	}

	// Create a slice to store the elements of the array A
	A := make([]int, n)

	// Input the elements of the array A
	for i := 0; i < n; i++ {
		input, err := reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}
		input = strings.TrimSpace(input)
		A[i], err = strconv.Atoi(input)
		if err!= nil {
			panic(err)
		}
	}

	// Iterate through the array to find the minimum value and count valid pairs
	for i := 0; i < n; i++ {
		// Update minA if the current element is smaller
		if minA > A[i] {
			minA = A[i]
		} else {
			// Check the difference between the current element and minA
			if f == A[i]-minA {
				num++ // Increment the count if the difference matches the previous one
			} else if f < A[i]-minA {
				num = 1 // Reset count if a larger difference is found
				f = A[i] - minA // Update the frequency to the new difference
			}
		}
	}

	// Output the total count of valid pairs
	fmt.Println(num)
}

