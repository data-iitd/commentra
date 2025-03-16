package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

func main() {
	// Reading input from standard input
	reader := bufio.NewReader(os.Stdin)
	arr, _ := reader.ReadString('\n')
	arr = arr[:len(arr)-1] // Remove the newline character
	N := len(arr) // Store the length of the character array
	
	// Initialize a map to store unique strings and read the number of test cases
	set := make(map[string]bool)
	var K int
	fmt.Scan(&K)
	
	// Initialize the result variable to store the final count
	res := 0
	
	// Loop to process each test case
	for k := 0; k < K; k++ {
		input, _ := reader.ReadString('\n')
		input = input[:len(input)-1] // Remove the newline character
		a := 0 // Counter for the first character of the input
		b := 0 // Counter for the second character of the input
		
		// Iterate over the characters of the input array
		for i := 0; i < N; i++ {
			if arr[i] == input[0] { // If the character matches the first character of the input
				a++
			} else if arr[i] == input[1] { // If the character matches the second character of the input
				b++
			} else { // If the character does not match either of the input characters
				res += int(math.Min(float64(a), float64(b))) // Add the minimum of a and b to the result
				a, b = 0, 0 // Reset the counters
			}
		}
		res += int(math.Min(float64(a), float64(b))) // Add the minimum of a and b to the result after the loop
	}
	
	// Print the final result
	fmt.Println(res)
}
