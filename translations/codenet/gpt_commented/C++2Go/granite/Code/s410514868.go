
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of characters (n) and the maximum number of operations (k)
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))

	// Read the string of characters
	s := read(reader)

	// Initialize L with the first character of the string
	L := string(s[0])
	cnt := 0 // Initialize a counter for consecutive characters

	// Iterate through the string starting from the second character
	for i := 1; i < n; i++ {
		// If the current character is the same as the last character
		if L == string(s[i]) {
			cnt++ // Increment the counter
		} else {
			// If the character changes, update L and add the count to ans
			L = string(s[i])
			ans += cnt // Add the count of consecutive characters to ans
			ans2++ // Increment the number of distinct character groups
			cnt = 0 // Reset the counter for the new character
		}
	}

	// After the loop, add the count of the last group of characters to ans
	ans += cnt
	ans2++ // Increment for the last group

	// Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
	fmt.Println(ans + min(2*k, ans2-1))
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

