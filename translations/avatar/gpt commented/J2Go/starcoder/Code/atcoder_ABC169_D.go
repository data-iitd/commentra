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
	// Read a long integer input from stdin
	input, _ := reader.ReadString('\n')
	// Convert the input to a long integer
	n, _ := strconv.ParseInt(strings.TrimSpace(input), 10, 64)
	// Calculate the integer square root of n
	sqrt := int(math.Sqrt(float64(n)))
	// Initialize the answer variable to count the number of prime factors
	answer := 0
	// Loop through all integers from 2 to the square root of n
	for i := 2; i <= sqrt; i++ {
		// Initialize a count for the number of times i divides n
		count := 0
		// While n is divisible by i, divide n by i and increment count
		for n%i == 0 {
			n /= i
			count++
		}
		// For each count of prime factor i, calculate the number of unique factors
		for j := 1; count-j >= 0; j++ {
			count -= j
			answer++
		}
	}
	// If n is greater than 1, it means n is a prime number itself
	if n > 1 {
		answer++
	}
	// Print the total number of unique prime factors
	fmt.Println(answer)
}

