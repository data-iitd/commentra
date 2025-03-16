
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare character arrays to hold two strings and a temporary string for manipulation
	str1 := make([]byte, 100)
	str2 := make([]byte, 100)
	temp := make([]byte, 100)

	// Read two strings from user input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, str1)
	fmt.Fscanln(reader, str2)

	// Get the length of the first string and calculate the last index
	i := len(str1)
	t := i - 1

	// Check if the lengths of the two strings are different
	if len(str1)!= len(str2) {
		// If lengths are different, they cannot be anagrams
		fmt.Println("NO")
	} else {
		// Reverse the first string and store it in the temporary array
		for j := 0; j < i; j++ {
			temp[j] = str1[t] // Copy characters from the end of str1 to temp
			t--
		}
		// Null-terminate the reversed string
		temp[i] = '\0' // Ensure the reversed string is properly terminated

		// Reset counters for comparison
		t = 0
		i = 0

		// Compare the reversed string with the second string
		for i < len(temp) {
			if temp[i] == str2[i] {
				t++ // Count matching characters
			}
			i++
		}

		// Check if all characters matched
		if len(str2) == t {
			// If all characters match, the strings are anagrams
			fmt.Println("YES")
		} else if len(str2)!= t {
			// If not all characters match, they are not anagrams
			fmt.Println("NO")
		}
	}
}

// 