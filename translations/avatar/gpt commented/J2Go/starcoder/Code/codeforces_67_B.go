package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new instance of bufio.Reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin and save it to our
	// variable, inputString.
	inputString, _ := reader.ReadString('\n')

	// Split the inputString on the space character and convert it
	// to a slice of integers.
	input := strings.Split(inputString, " ")
	input = input[:len(input)-1]
	inputInts := make([]int, len(input))
	for i := range input {
		inputInts[i], _ = strconv.Atoi(input[i])
	}

	// Read the second line of input from stdin and save it to our
	// variable, inputString.
	inputString, _ = reader.ReadString('\n')

	// Split the inputString on the space character and convert it
	// to a slice of integers.
	input = strings.Split(inputString, " ")
	input = input[:len(input)-1]
	inputInts2 := make([]int, len(input))
	for i := range input {
		inputInts2[i], _ = strconv.Atoi(input[i])
	}

	// Initialize an array to hold the input values
	bb := make([]int, len(inputInts))

	// Read n integers into the bb array
	for i := range inputInts {
		bb[i] = inputInts[i]
	}

	// Initialize an array to hold the results and a counter for the results
	aa := make([]int, len(inputInts))
	m := 0

	// Process the input array in reverse order
	for a := len(inputInts) - 1; a >= 0; a-- {
		j := 0
		// While there are still counts left for the current index in bb
		for bb[a] > 0 {
			// Check if the current index in aa is valid
			if aa[j] >= a+inputInts2[0] {
				bb[a]--
			}
			j++
		}
		// Shift elements in aa to make space for the current index
		for j_ := m++; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
	}

	// Output the results, incrementing by 1 for 1-based indexing
	for i := range aa {
		fmt.Printf("%d ", aa[i]+1)
	}
	fmt.Printf("\n")
}

