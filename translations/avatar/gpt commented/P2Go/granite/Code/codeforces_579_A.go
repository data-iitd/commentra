
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	// Initialize a counter variable to track the number of iterations
	x := 1

	// Create a new scanner to read an integer input from the user
	scanner := bufio.NewScanner(os.Stdin)
	if!scanner.Scan() {
		log.Fatal("Failed to read input")
	}
	n, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		log.Fatal("Invalid input")
	}

	// Continue looping while n is not a power of 2
	for math.Log2(float64(n))%1!= 0 {
		x++ // Increment the counter for each iteration
		// Subtract the largest power of 2 less than or equal to n from n
		n -= 1 << uint(math.Log2(float64(n)))
	}

	// Print the final count of iterations
	fmt.Println(x)
}

