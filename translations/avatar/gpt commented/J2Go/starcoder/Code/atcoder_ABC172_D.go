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
	sc := bufio.NewScanner(os.Stdin)

	// Read the first line of input from stdin
	sc.Scan()

	// Convert the input string to an integer
	n, _ := strconv.Atoi(sc.Text())

	// Initialize a variable to hold the final result
	ans := 0

	// Loop through each integer from 1 to n (inclusive)
	for i := 1; i < n+1; i++ {
		// Calculate the contribution of the current integer i to the result
		// This involves multiplying i by the number of times i fits into n
		// and summing up the series of numbers from 1 to (n / i)
		ans += i * (n/i) * ((n/i)+1) / 2
	}

	// Output the final result
	fmt.Println(ans)
}

