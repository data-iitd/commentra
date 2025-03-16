
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MOD = 1000000007
	reader := bufio.NewReader(os.Stdin)

	// Read the size of the array
	N, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Create a slice to store the input values
	A := make([]int, N)

	// Read the input values and store them in the slice
	for i, s := range bufio.NewScanner(reader) {
		if i == 0 {
			continue
		}
		A[i-1], _ = strconv.Atoi(s)
	}

	// Initialize the result variable to 0
	result := 0

	// Loop over each bit position from 0 to 59
	for b := 0; b < 60; b++ {
		// Count the number of set bits at the current bit position
		bs := 0
		for _, a := range A {
			if a&(1<<uint(b))!= 0 {
				bs++
			}
		}

		// Calculate the contribution of the current bit position to the result
		result = (result + bs*(N-bs)*(1<<uint(b))) % MOD
	}

	// Print the final result
	fmt.Println(result)
}

