package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a constant for modulo operations
const mod = 1000000007

func main() {
	// Read the integer k from input
	k, _ := strconv.Atoi(readLine())

	// Initialize a variable to hold the current value of t
	t := 0

	// Loop through numbers from 1 to k
	for i := 1; i <= k; i++ {
		// Update t by appending a '7' at the end and taking modulo k
		t = (t % k) * 10 + 7

		// Check if the current value of t is divisible by k
		if t%k == 0 {
			fmt.Println(i) // Print the current index if divisible
			break
		}
	} else {
		// If no index was found, print -1
		fmt.Println(-1)
	}
}

func readLine() string {
	buf := new(bytes.Buffer)
	_, err := buf.ReadBytes('\n')
	if err!= nil {
		panic(err)
	}
	return buf.String()
}

