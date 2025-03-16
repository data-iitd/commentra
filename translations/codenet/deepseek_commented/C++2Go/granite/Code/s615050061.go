
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	B = 13131 // Define a constant base for hashing
	N = 500000 + 7 // Define the maximum length of the string + 7 for safety
)

var (
	n int // Declare an integer to store the length of the string
	s string // Declare a string to store the input string
	f [N]int64 // Declare an array of int64 to store the hash values
	g [N]int // Declare an array of int to store position-dependent values
	m = make(map[int64]int) // Declare a map to store the frequency of hash values
	cnt int64 // Declare an int64 to count the number of valid substrings
)

func pow(a, k int64) int64 {
	if k < 0 {
		k += (1 << 63) - 1
	}
	t := int64(1) // Initialize the result to 1
	for ; k > 0; a = a * a, k >>= 1 { // Square and halve the exponent
		if k&1 == 1 {
			t = t * a // If the exponent is odd, multiply the result
		}
	}
	return t // Return the result
}

func main() {
	data, _ := os.Open(os.Args[1]) // Open the input file
	defer data.Close() // Close the input file after use
	scanner := bufio.NewScanner(data) // Create a scanner to read the input file
	for scanner.Scan() { // Iterate through the lines of the input file
		text := scanner.Text() // Get the current line of the input file
		if text[0] == '#' { // Check if the line starts with '#'
			continue // Skip this line if it starts with '#'
		}
		fields := len(text)
		sp := 0
		n, _ = strconv.Atoi(text[sp:fields]) // Convert the first field to an integer
		sp = fields + 1
		s = text[sp:fields] // Get the second field as a string
		for i := 1; i <= n; i++ { // Iterate through the string
			if s[i-1] == '+' || s[i-1] == '-' { // Check if the character is '+' or '-'
				f[i] = f[i-1] + (int64(s[i-1])-43)*pow(int64(B), int64(g[i-1])) // Compute the hash value
			} else {
				f[i] = f[i-1]
				g[i] = g[i-1] + (int(s[i-1])-60)
			}
		}
		for i := n; i > 0; i-- { // Iterate through the string in reverse
			m[f[i]]++ // Increment the frequency of the hash value
			cnt += int64(m[f[n]*pow(int64(B), int64(g[i-1]))+f[i-1]]) // Count the valid substrings
		}
	}
	fmt.Println(cnt) // Print the count of valid substrings
}

