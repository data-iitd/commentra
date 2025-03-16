
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from standard input
	infile := bufio.NewReader(os.Stdin)
	arr, _ := infile.ReadString('\n')
	N := len(arr)

	// Initialize a HashSet to store unique strings and read the number of test cases
	set := make(map[string]bool)
	K, _ := infile.ReadString('\n')
	K = strings.TrimSpace(K)
	K, _ = strconv.Atoi(K)

	// Initialize the result variable to store the final count
	res := 0

	// Loop to process each test case
	for k := 0; k < K; k++ {
		input, _ := infile.ReadString('\n')
		input = strings.TrimSpace(input)
		a := 0
		b := 0

		// Iterate over the characters of the input array
		for i := 0; i < N; i++ {
			if arr[i] == input[0] { // If the character matches the first character of the input
				a++
			} else if arr[i] == input[1] { // If the character matches the second character of the input
				b++
			} else { // If the character does not match either of the input characters
				res += min(a, b)
				a = b = 0
			}
		}
		res += min(a, b) // Add the minimum of a and b to the result after the loop
	}

	// Print the final result
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 