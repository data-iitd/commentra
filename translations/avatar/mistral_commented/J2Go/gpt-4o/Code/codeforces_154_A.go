package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Reading the first line of input as a character array
	arr, _ := reader.ReadString('\n')
	arr = arr[:len(arr)-1] // Remove the newline character

	N := len(arr) // Length of the character array

	var K int
	fmt.Fscanln(reader, &K) // Reading the second line of input as an integer

	res := 0 // Variable to store the result

	for k := 0; k < K; k++ {
		var input string
		fmt.Fscanln(reader, &input) // Reading a string as input

		a, b := 0, 0 // Counters for occurrences of two different characters

		for i := 0; i < N; i++ {
			if arr[i] == input[0] {
				a++ // Incrementing 'a' if the character matches the first character of the input string
			} else if arr[i] == input[1] {
				b++ // Incrementing 'b' if the character matches the second character of the input string
			} else {
				res += int(math.Min(float64(a), float64(b))) // Adding the minimum of 'a' and 'b' to 'res'
				a, b = 0, 0 // Resetting 'a' and 'b' to zero
			}
		}

		res += int(math.Min(float64(a), float64(b))) // Adding the minimum of 'a' and 'b' after the loop
	}

	fmt.Println(res) // Printing the final result
}

// <END-OF-CODE>
