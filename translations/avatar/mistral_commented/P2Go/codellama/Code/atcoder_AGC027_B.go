package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func main() {
	// Read the input file
	data, err := ioutil.ReadFile("input.txt")
	if err != nil {
		panic(err)
	}

	// Split the input data into a slice of strings
	lines := strings.Split(string(data), "\n")

	// Define input variables
	N, X := 0, 0
	A := make([]int, 0)

	// Iterate through each line of the input data
	for _, line := range lines {
		// Split the line into a slice of strings
		fields := strings.Split(line, " ")

		// Convert the first field to an integer
		N, err = strconv.Atoi(fields[0])
		if err != nil {
			panic(err)
		}

		// Convert the second field to an integer
		X, err = strconv.Atoi(fields[1])
		if err != nil {
			panic(err)
		}

		// Iterate through each field after the first two fields
		for _, field := range fields[2:] {
			// Convert the field to an integer
			a, err := strconv.Atoi(field)
			if err != nil {
				panic(err)
			}

			// Append the integer to the slice A
			A = append(A, a)
		}
	}

	// Create a new slice S by applying the accumulate function to the slice A
	S := make([]int, 0)
	for i := 0; i < len(A); i++ {
		if i == 0 {
			S = append(S, A[i])
		} else {
			S = append(S, S[i-1]+A[i])
		}
	}

	// Initialize a variable ans with a large value
	ans := 1000000000000000000

	// Iterate through each element s in the slice S
	for k := 1; k <= len(S); k++ {
		// Calculate the energy consumption E for the current index k
		E := k*X + 2*sum(S, len(S)-2*k-1, -1, -k)

		// Update the minimum energy consumption ans if the current energy consumption E is smaller
		if E < ans {
			ans = E
		}
	}

	// Print the result
	fmt.Println(ans + N*X + 5*S[len(S)-1])
}

func sum(S []int, start, end, step int) int {
	sum := 0
	for i := start; i != end; i += step {
		sum += S[i]
	}
	return sum
}

