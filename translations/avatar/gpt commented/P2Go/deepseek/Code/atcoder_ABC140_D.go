package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Generator function to parse input data
func parser() func() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return func() string {
		if scanner.Scan() {
			return scanner.Text()
		}
		return ""
	}
}

// Function to get the next value from the input parser as a string
func gw() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	if scanner.Scan() {
		return scanner.Text()
	}
	return ""
}

// Function to get the next value from the input parser and convert it to an integer
func gi() int {
	data := gw()
	num, _ := strconv.Atoi(data)
	return num
}

// Define a constant for the modulo operation
const MOD = int(1e9 + 7)

func main() {
	// Read the number of elements N and the integer K from input
	N := gi()
	K := gi()
	// Read the string S from input
	S := gw()

	// Initialize a counter for segments
	segCnt := 0

	// Count the number of segments in the string S
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}

	// Calculate the current happiness based on the number of segments
	curHappy := N - 1 - segCnt

	// Determine the final answer based on the relationship between K and segCnt
	var ans int
	if 2*K >= segCnt {
		ans = N - 1 // If K is sufficient to cover all segments
	} else {
		ans = curHappy + 2*K // Otherwise, calculate based on current happiness and K
	}

	// Print the final answer
	fmt.Println(ans)
}
