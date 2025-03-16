package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

func main() {
	// Create a new Scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the first line of input and convert it to a character array
	scanner.Scan()
	arr := []rune(scanner.Text())
	
	// Get the length of the character array
	N := len(arr)
	
	// Read the number of queries K
	scanner.Scan()
	K := 0
	fmt.Sscanf(scanner.Text(), "%d", &K)
	
	// Initialize the result counter
	res := 0
	
	// Loop through each query
	for k := 0; k < K; k++ {
		// Read the input string for the current query
		scanner.Scan()
		input := scanner.Text()
		
		// Initialize counters for characters in the input string
		a := 0
		b := 0
		
		// Iterate through the character array
		for i := 0; i < N; i++ {
			// Count occurrences of the first character of the input string
			if arr[i] == rune(input[0]) {
				a++
			} else if arr[i] == rune(input[1]) { // Count occurrences of the second character of the input string
				b++
			} else { // If neither character is found, update the result and reset counters
				res += int(math.Min(float64(a), float64(b)))
				a = b = 0
			}
		}
		// Add the minimum count of the two characters to the result
		res += int(math.Min(float64(a), float64(b)))
	}
	
	// Output the final result
	fmt.Println(res)
}
