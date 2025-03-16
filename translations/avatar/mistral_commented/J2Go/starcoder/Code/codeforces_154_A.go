package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	infile := bufio.NewReader(os.Stdin)
	// Creating a BufferedReader object to read input from the standard input stream

	arr := strings.Split(strings.TrimSpace(infile.ReadString()), "")
	// Reading the first line of input as a string and storing it in the 'arr' variable

	N := len(arr)
	// Declaring and initializing the length of the string array 'arr' in the variable 'N'

	set := make(map[string]bool)
	// Creating an empty map to store unique strings

	K, _ := strconv.Atoi(strings.TrimSpace(infile.ReadString()))
	// Reading the second line of input as an integer and storing it in the variable 'K'

	res := 0
	// Declaring and initializing an integer variable'res' to store the result

	for k := 0; k < K; k++ {
		// Starting a for loop that iterates 'K' times

		input := strings.Split(strings.TrimSpace(infile.ReadString()), "")
		// Reading a string as input and storing it in the 'input' variable

		a := 0
		b := 0
		// Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string array 'arr'

		for i := 0; i < N; i++ {
			// Starting a nested for loop that iterates through each index of the string array 'arr'

			if arr[i] == input[0] {
				a++
				// Incrementing the 'a' variable if the character at the current index matches the first character of the input string
			} else if arr[i] == input[1] {
				b++
				// Incrementing the 'b' variable if the character at the current index matches the second character of the input string
			} else {
				res += min(a, b)
				// Adding the minimum of 'a' and 'b' to the'res' variable if the current character is different from both characters in the input string
				a = b = 0
				// Resetting the 'a' and 'b' variables to zero
			}
		}

		res += min(a, b)
		// Adding the minimum of 'a' and 'b' to the'res' variable after the end of the outer for loop
	}

	fmt.Println(res)
	// Printing the final result to the standard output stream
}

func min(a, b int) int {
	// Returning the minimum of 'a' and 'b'
	if a < b {
		return a
	}
	return b
}

