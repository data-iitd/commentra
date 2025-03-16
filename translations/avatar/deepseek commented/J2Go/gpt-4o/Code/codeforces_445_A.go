package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a BufferedReader to read input from the console
	input, _ := reader.ReadString('\n')  // Reading the first line
	inp := strings.Fields(input)          // Splitting the input into fields

	n, _ := strconv.Atoi(inp[0]) // Extracting the integer n from the input
	m, _ := strconv.Atoi(inp[1]) // Extracting the integer m from the input

	ans := make([]string, n) // Initializing a slice to store the resulting strings

	for i := 0; i < n; i++ { // Looping through each row
		str, _ := reader.ReadString('\n') // Reading the current row as a string
		str = strings.TrimSpace(str)      // Trimming any whitespace/newline characters
		var temp strings.Builder           // Creating a strings.Builder to build the resulting string for the current row

		for j := 0; j < m; j++ { // Looping through each character in the row
			if str[j] == '-' { // Checking if the character is a '-'
				temp.WriteByte('-') // Appending '-' to the strings.Builder
			} else {
				if (i+j)%2 == 1 { // Checking if the sum of indices is odd
					temp.WriteByte('W') // Appending 'W' if the sum is odd
				} else {
					temp.WriteByte('B') // Appending 'B' if the sum is even
				}
			}
		}
		ans[i] = temp.String() // Converting the strings.Builder to a string and storing it in the ans slice
	}

	for i := 0; i < n; i++ { // Looping through each row again to print the results
		fmt.Println(ans[i]) // Printing the resulting string for the current row
	}
}

// <END-OF-CODE>
