
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var str1, str2, temp string
	var i, j, t int

	// Read the first string from the user input
	reader := bufio.NewReader(os.Stdin)
	str1, _ = reader.ReadString('\n')
	str1 = strings.TrimSpace(str1)

	// Read the second string from the user input
	str2, _ = reader.ReadString('\n')
	str2 = strings.TrimSpace(str2)

	// Calculate the length of the first string
	i = len(str1)

	// Initialize the index for reversing the first string
	t = i - 1

	// Check if the lengths of the two strings are not equal
	if len(str1)!= len(str2) {
		// Print "NO" if the lengths are not equal
		fmt.Println("NO")
	} else {
		// Reverse the first string and store it in temp
		for j = 0; j < i; j++ {
			temp = string(str1[t]) + temp
			t--
		}

		// Reset the index for comparing the strings
		t = 0
		i = 0

		// Compare each character of the reversed string and the second string
		for i = 0; i < len(str2); i++ {
			if string(temp[i]) == string(str2[i]) {
				t++
			}
		}

		// Check if the number of matching characters is equal to the length of the second string
		if len(str2) == t {
			// Print "YES" if all characters match
			fmt.Println("YES")
		} else {
			// Print "NO" if not all characters match
			fmt.Println("NO")
		}
	}
}

