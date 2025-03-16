package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const N = 200 + 10 // Initializing the size of the arrays

var f [N]int    // Initializing the failure function array
var b [N]rune   // Initializing the character arrays

func getFail(b []rune, m int) {
	j := 0
	f[0], f[1] = 0, 0 // Initializing the first two elements of the failure function array

	// Main logic of the function
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1] != b[i] {
			j = f[j] // Searching for the longest common prefix of the current and previous strings
		}
		if b[j+1] == b[i] {
			j++ // If the characters match, move to the next character in the current string
		}
		f[i] = j // Updating the failure function for the current index
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader for input
	writer := bufio.NewWriter(os.Stdout) // Creating a buffered writer for output

	var n int
	fmt.Fscan(reader, &n) // Reading the number of characters in the strings

	var s1, str string
	fmt.Fscan(reader, &str, &s1) // Reading the two strings from the input

	cnt := 0 // Initializing a counter for the number of characters in the combined string

	// Concatenating the two strings and creating character arrays for each
	for _, char := range str {
		cnt++
		b[cnt] = char
	}
	for _, char := range s1 {
		cnt++
		b[cnt] = char
	}

	getFail(b[:], cnt) // Calling the getFail function to compute the failure function

	len := min(f[cnt], min(n, n)) // Computing the length of the longest common prefix

	fmt.Fprintln(writer, 2*n-len) // Writing the output to the console
	writer.Flush() // Flushing the output buffer
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
