package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read n and k, convert them to ints
	fmt.Print("Enter n: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter k: ")
	input, _ = reader.ReadString('\n')
	k, _ := strconv.Atoi(strings.TrimSpace(input))

	// Increment n by 1
	n++

	// Initialize a variable z to store the adjustment needed to make n divisible by k
	z := 0

	// Check if n is not divisible by k
	if n%k!= 0 {
		// Calculate the adjustment needed to make n divisible by k
		z = k - n%k
	}

	// Output the final result, which is n plus the adjustment z
	fmt.Println(n + z)
}

