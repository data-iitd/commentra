
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
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	arr := []rune(str)
	N := len(arr)

	// Initialize a HashSet to store unique strings and read the number of test cases
	set := make(map[string]bool)
	K, _ := strconv.Atoi(reader.ReadString('\n'))

	// Initialize the result variable to store the final count
	res := 0

	// Loop to process each test case
	for k := 0; k < K; k++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a := 0
		b := 0

		// Iterate over the characters of the input array
		for i := 0; i < N; i++ {
			if arr[i] == rune(input[0]) { // If the character matches the first character of the input
				a++
			} else if arr[i] == rune(input[1]) { // If the character matches the second character of the input
				b++
			} else { // If the character does not match either of the input characters
				res += min(a, b)
				a = b = 0
			}
		}
		res += min(a, b)
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

