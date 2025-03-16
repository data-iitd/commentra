
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read the size of the array
	N, _ := strconv.Atoi(strings.TrimSpace(string(readLine())))

	// Create a slice from the input values
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.ParseInt(strings.TrimSpace(string(readLine())), 10, 64)
	}

	// Initialize the result variable to 0
	result := int64(0)

	// Loop over each bit position from 0 to 59
	for b := 0; b < 60; b++ {
		// Count the number of set bits at the current bit position
		bs := int64(0)
		for i := 0; i < N; i++ {
			if A[i]&(1<<uint(b)) != 0 {
				bs++
			}
		}

		// Calculate the contribution of the current bit position to the result
		result = (result + bs*(N-bs)*int64(math.Pow(2, float64(b)))) % 1000000007
	}

	// Print the final result
	fmt.Println(result)
}

func readLine() string {
	buf := make([]byte, 0, 1000000)
	for {
		line, isPrefix, err := reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}

// 